#pragma once

#include "qkpch.h"

#include "Platforms/OpenGL/OpenGLVertexBuffer.h"

namespace QuokkaEngine {
    
    class OpenGLVertexArray
    {
    public:
        OpenGLVertexArray();
        
        void Bind();
        
        void AddPosition(const std::shared_ptr<OpenGLVertexBuffer>& vertexBuffer);
    private:
        uint32_t m_renderId;
    };

}
