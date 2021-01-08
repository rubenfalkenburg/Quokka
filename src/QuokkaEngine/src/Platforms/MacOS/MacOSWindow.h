#pragma once

#include "qkpch.h"

#include "QuokkaEngine/Graphics/Window.h"
#include "QuokkaEngine/Graphics/Shader.h"

#include <GLFW/glfw3.h>

namespace QuokkaEngine {
    
    class MacOSWindow : public Window
    {
    public:
        MacOSWindow(const std::uint32_t width, const std::uint32_t height, const std::string title);
        ~MacOSWindow();
        
        void Update() override;
        void Destroy() override;
    private:
        GLFWwindow* m_windowHandle;
        
        unsigned int m_vertexArray, m_vertexBuffer, m_indexBuffer;
        std::unique_ptr<Shader> m_shader;
    };

}
