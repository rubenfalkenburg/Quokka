#pragma once

namespace QuokkaEngine {
    
    class OpenGLVertexBuffer
    {
    public:
        OpenGLVertexBuffer(float* vertices, uint32_t size);
        
        void Bind();
    private:
        unsigned int m_bufferId;
    };

}
