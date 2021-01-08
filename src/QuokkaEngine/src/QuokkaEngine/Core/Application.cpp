#include "QuokkaEngine/Core/Application.h"

#include "QuokkaEngine/Scene/GameObject.h"

namespace QuokkaEngine
{
    Application* Application::s_instance = nullptr;

    Application::Application(std::string applicationName)
    {
        s_instance = this;
        
        m_graphicsContext = GraphicsContext::Create();
        m_window = Window::Create(1920, 1080, applicationName);
    }

    Application::~Application()
    {
        
    }

    Application& Application::GetInstance()
    {
        return *s_instance;
    }

    void Application::Run()
    {
        StartUp();
        
        while (m_isRunning)
        {
            m_graphicsContext->Update();
            m_window->Update();
        }
        
        ShutDown();
    }

    void Application::StartUp()
    {
        
    }

    void Application::ShutDown()
    {
        delete s_instance;
    }
    
    void Application::Close()
    {
        m_isRunning = false;
    }
}
