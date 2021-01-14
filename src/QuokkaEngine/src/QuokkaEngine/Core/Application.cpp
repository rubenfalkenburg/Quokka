#include "QuokkaEngine/Core/Application.h"
#include "QuokkaEngine/Scene/SceneManager.h"

namespace QuokkaEngine {

    Application* Application::s_instance = nullptr;

    Application::Application(std::string applicationName)
    {
        s_instance = this;
        
        m_window = Window::Create(1920, 1080, applicationName);
        
        // --------- TEST ----------
        Scene* scene = new Scene();
        SceneManager::SetActiveScene(scene);
    }

    Application::~Application()
    {
        m_window->Dispose();
    }
    
    void Application::Run()
    {
        while (m_isRunning)
        {
            // Clear
            
            SceneManager::GetActiveScene().Update();
            
            m_window->Update();
        }
    }

    void Application::Close()
    {
        m_isRunning = false;
    }

}
