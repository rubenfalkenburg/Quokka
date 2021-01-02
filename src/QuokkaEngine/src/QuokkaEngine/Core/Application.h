#pragma once

#include "qkpch.h"

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
        GLFWwindow* m_window = nullptr;
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
