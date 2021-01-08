#pragma once

#include "QuokkaEngine/Graphics/GraphicsContext.h"

namespace QuokkaEngine {
    
    class OpenGLGraphicsContext : public GraphicsContext
    {
    public:
        OpenGLGraphicsContext();
        ~OpenGLGraphicsContext();
        
        void Update() override;
    };

}
