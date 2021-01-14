#pragma once

#include "QuokkaEngine/Graphics/GraphicsContext.h"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

namespace QuokkaEngine {
    
    class OpenGLGraphicsContext : public GraphicsContext
    {
    public:
        OpenGLGraphicsContext(void* nativeWindow);
        ~OpenGLGraphicsContext();
        
        void SwapBuffers(void* nativeWindow) override;
    };

}
