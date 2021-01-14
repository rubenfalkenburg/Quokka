#pragma once

#include "qkpch.h"

namespace QuokkaEngine {
    
    class GraphicsContext
    {
    public:
        GraphicsContext() = default;
        GraphicsContext(void* nativeWindow);
        virtual ~GraphicsContext() = default;
        
        virtual void SwapBuffers(void* nativeWindow) = 0;
    public:
        static std::unique_ptr<GraphicsContext> Create(void* nativeWindow);
    };

}
