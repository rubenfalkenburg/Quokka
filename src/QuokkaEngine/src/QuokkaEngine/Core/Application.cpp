#include "QuokkaEngine/Core/Application.h"

#include <spdlog/spdlog.h>

namespace QuokkaEngine {

    Application::Application()
    {
        Initialize();
    }

    Application::~Application()
    {
        Dispose();
    }

    void Application::Initialize()
    {
        if (!glfwInit())
        {
            spdlog::error("Initalizing GLFW failed");
            glfwSetWindowShouldClose(m_window, GLFW_TRUE);
            return;
        }
        
        m_window = glfwCreateWindow(640, 480, "Quokka Engine", NULL, NULL);
        
        if(!m_window)
        {
            spdlog::error("GLFW failed creating window");
            glfwSetWindowShouldClose(m_window, GLFW_TRUE);
            return;
        }
        
        glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
        {
            if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
                glfwSetWindowShouldClose(window, GLFW_TRUE);
        });
        
        glfwMakeContextCurrent(m_window);
    }

    void Application::Run()
    {
        while (!glfwWindowShouldClose(m_window))
        {
            glClearColor(1, 1, 0, 0);
            glClear(GL_COLOR_BUFFER_BIT);
            
            glfwSwapBuffers(m_window);
            glfwPollEvents();
        }
    }
    
    void Application::Dispose()
    {
        glfwDestroyWindow(m_window);
        glfwTerminate();
    }

    
}
