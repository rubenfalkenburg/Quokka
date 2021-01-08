#include "Platforms/MacOS/MacOSWindow.h"

#include "QuokkaEngine/Core/Application.h"

#include <glad/glad.h>

namespace QuokkaEngine {
    
    MacOSWindow::MacOSWindow(const std::uint32_t width, const std::uint32_t height, const std::string title)
    {
        if(!glfwInit())
            Application::GetInstance().Close();

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        
        m_windowHandle = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
        
        glfwMakeContextCurrent(m_windowHandle);
        
        // TODO move to opengl context
        gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        
        
        glViewport(0.0f, 0.0f, width, height);
        
        glGenVertexArrays(1, &m_vertexArray);
        glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
        
        float vertices[3 * 3] = {
            -0.5f, -0.5f, 0.0f,
             0.5f, -0.5f, 0.0f,
             0.0f,  0.5f, 0.0f,
        };
        
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
        
        glGenBuffers(1, &m_indexBuffer);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indexBuffer);
        
        unsigned int indices[3] = {0, 1, 2};
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        std::string vertexSrc = R"(
            #version 410
            
            layout(location = 0) in vec3 a_Position;
        
            void main()
            {
                gl_Position = vec4(a_Position, 1.0);
            }
            
        )";
        
        std::string fragmentSrc = R"(
            #version 410
            
            layout(location = 0) out vec4 color;
        
            void main()
            {
                color = vec4(0.8, 0.2, 0.3, 1.0);
            }
            
        )";
        
        
        m_shader.reset(new Shader(vertexSrc, fragmentSrc));
    }

    MacOSWindow::~MacOSWindow()
    {
        
    }

    void MacOSWindow::Update()
    {
        glClearColor(0.1f, 0.1f, 0.1f, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        
        m_shader->Bind();
        
        glBindVertexArray(m_vertexArray);
        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);
        
        glfwSwapBuffers(m_windowHandle);
        glfwPollEvents();
    }

    void MacOSWindow::Destroy()
    {
        glfwDestroyWindow(m_windowHandle);
    }

}
