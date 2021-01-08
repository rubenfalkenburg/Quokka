#pragma once

#include "qkpch.h"

namespace QuokkaEngine {
    
    class Window
    {
    public:
        Window() = default;
        Window(const std::uint32_t width, const std::uint32_t height, const std::string title);
        virtual ~Window() = default;
        
        virtual void Update() = 0;
        virtual void Destroy() = 0;
        
        static std::unique_ptr<Window> Create(const std::uint32_t width, const std::uint32_t height, const std::string title);
    };
}
