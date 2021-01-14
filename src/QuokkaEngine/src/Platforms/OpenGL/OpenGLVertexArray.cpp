#include "Platforms/OpenGL/OpenGLVertexArray.h"
#include <glad/glad.h>

namespace QuokkaEngine {
        
    OpenGLVertexArray::OpenGLVertexArray()
    {
        glGenVertexArrays(1, &m_renderId);
    }

    void OpenGLVertexArray::AddPosition(const std::shared_ptr<OpenGLVertexBuffer> &vertexBuffer)
    {
        vertexBuffer->Bind();
        
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
    }

    void OpenGLVertexArray::Bind()
    {
        glBindVertexArray(m_renderId);
    }

}
