#pragma once

#include "QuokkaEngine/Core/Window.h"

namespace QuokkaEngine {
    
    class MacOSWindow : public Window
    {
    public:
        MacOSWindow(const std::uint32_t width, const std::uint32_t height, const std::string title);
        ~MacOSWindow();
        
        void OnUpdate() override;
    private:
        void Initialize(const std::uint32_t width, const std::uint32_t height, const std::string title);
        void Dispose();
    private:
        GLFWwindow* m_window;
    };
}
