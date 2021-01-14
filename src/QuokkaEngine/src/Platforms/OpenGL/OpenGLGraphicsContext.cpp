#include "Platforms/OpenGL/OpenGLGraphicsContext.h"

#include <glad/glad.h>

namespace QuokkaEngine {

    OpenGLGraphicsContext::OpenGLGraphicsContext(void* nativeWindow)
    {
        glfwMakeContextCurrent((GLFWwindow*)nativeWindow);
        
        gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    }

    OpenGLGraphicsContext::~OpenGLGraphicsContext()
    {
        
    }
    
    void OpenGLGraphicsContext::SwapBuffers(void* nativeWindow)
    {
        glfwSwapBuffers((GLFWwindow*)nativeWindow);
    }
}
