#include "QuokkaEngine/Graphics/GraphicsContext.h"

#include "Platforms/OpenGL/OpenGLGraphicsContext.h"

namespace QuokkaEngine {
    
    std::unique_ptr<GraphicsContext> GraphicsContext::Create(void *nativeWindow)
    {
        return std::make_unique<OpenGLGraphicsContext>(nativeWindow);
    }
}
