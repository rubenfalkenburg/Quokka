#include "Platforms/MacOS/MacOSWindow.h"
#include "QuokkaEngine/Core/Application.h"

namespace QuokkaEngine {
    
    MacOSWindow::MacOSWindow(const std::uint32_t width, const std::uint32_t height, const std::string title)
    {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        
        m_windowHandle      = glfwCreateWindow(1920, 1080, title.c_str(), nullptr, nullptr);
        m_graphicsContext   = GraphicsContext::Create(m_windowHandle);
        
        glfwSetWindowCloseCallback(m_windowHandle, [](GLFWwindow* window)
        {
            Application::Instance().Close();
        });
        
        glfwSetFramebufferSizeCallback(m_windowHandle, [](GLFWwindow* window, int width, int height)
        {
            glViewport(0, 0, width, height);
        });
    }

    MacOSWindow::~MacOSWindow()
    {
        glfwDestroyWindow(m_windowHandle);
    }
    
    void MacOSWindow::Update()
    {
        glfwPollEvents();
        m_graphicsContext->SwapBuffers(m_windowHandle);
    }

    void MacOSWindow::Dispose()
    {
        glfwTerminate();
    }
}
