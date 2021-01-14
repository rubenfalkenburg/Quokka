#pragma once

#include "qkpch.h"

#include "QuokkaEngine/Graphics/Window.h"

int main();

namespace QuokkaEngine {
    
    class Application
    {
    public:
        Application(std::string applicationName);
        virtual ~Application();
        
        void Close();
    public:
        static Application& Instance() { return *s_instance; };
    private:
        void Run();
    private:
        bool m_isRunning = true;
        std::unique_ptr<Window> m_window;
    private:
        friend int ::main();
        static Application* s_instance;
    };
    
    Application* CreateApplication();
}
