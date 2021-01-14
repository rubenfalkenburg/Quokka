#pragma once

#define GL_SILENCE_DEPRECATION

#include "qkpch.h"

#include "QuokkaEngine/Graphics/Window.h"
#include "QuokkaEngine/Graphics/GraphicsContext.h"

#include <GLFW/glfw3.h>

namespace QuokkaEngine {
    
    class MacOSWindow : public Window
    {
    public:
        MacOSWindow(const std::uint32_t width, const std::uint32_t height, const std::string title);
        ~MacOSWindow();
        
        void Update() override;
        void Dispose() override;
    private:
        GLFWwindow* m_windowHandle;
        std::unique_ptr<GraphicsContext> m_graphicsContext;
    };

}
