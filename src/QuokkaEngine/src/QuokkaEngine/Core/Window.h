#pragma once

#include "qkpch.h"

namespace QuokkaEngine {
    
    class Window
    {
    public:
        virtual ~Window() = default;
        
        virtual void OnUpdate() = 0;
        
        static std::unique_ptr<Window> Create(std::uint32_t width, std::uint32_t height, std::string title);
    };

}
