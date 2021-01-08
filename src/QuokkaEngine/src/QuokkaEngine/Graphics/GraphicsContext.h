#pragma once

#include "qkpch.h"

namespace QuokkaEngine {
    
    class GraphicsContext
    {
    public:
        GraphicsContext() = default;
        virtual ~GraphicsContext() = default;
        
        virtual void Update() = 0;
        
        static std::unique_ptr<GraphicsContext> Create();
    };
}
