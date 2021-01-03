#pragma once

#include "qkpch.h"

#include "QuokkaEngine/Core/Window.h"

int main();

namespace QuokkaEngine
{
    class Application
    {
    public:
        Application();
        virtual ~Application();
    private:
        bool m_isRunning = true;
        std::unique_ptr<Window> m_window;
    private:
        void Initialize();
        void Run();
        void Dispose();
    private:
        friend int ::main();
    };
    
    // Defined in client
    Application* CreateApplication();
}
