#include "QuokkaEngine/Core/Application.h"

namespace QuokkaEngine {

    Application::Application()
    {
        Initialize();
    }

    Application::~Application()
    {
        Dispose();
    }

    void Application::Run()
    {
        while (m_isRunning)
        {
            m_window->OnUpdate();
        }
    }

    void Application::Initialize()
    {
        m_window = Window::Create(480, 640, "Quokka Engine");
    }

    void Application::Dispose()
    {
        
    }
        
}
