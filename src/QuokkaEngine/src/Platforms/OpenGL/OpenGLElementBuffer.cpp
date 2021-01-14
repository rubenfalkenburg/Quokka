#include "Platforms/OpenGL/OpenGLElementBuffer.h"
#include <glad/glad.h>

namespace QuokkaEngine {
    
    OpenGLElementBuffer::OpenGLElementBuffer(uint32_t* indices, uint32_t size)
    {
        glGenBuffers(1, &m_bufferId);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferId);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
    }

}
