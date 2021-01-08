#pragma once

#include "qkpch.h"

#include "QuokkaEngine/Graphics/Window.h"
#include "QuokkaEngine/Graphics/GraphicsContext.h"

int main();

namespace QuokkaEngine
{
    class Application
    {
    public:
        Application(std::string applicationName);
        virtual ~Application();
        
        virtual void Close();
        
        static Application& GetInstance();
    private:
        void StartUp();
        void Run();
        void ShutDown();
    private:
        bool m_isRunning = true;
        
        std::unique_ptr<Window> m_window;
        std::unique_ptr<GraphicsContext> m_graphicsContext;
        
        static Application* s_instance;
    private:
        friend int ::main();
    };

    Application* CreateApplication();
}
