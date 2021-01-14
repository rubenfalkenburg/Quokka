#pragma once

namespace QuokkaEngine {

    class OpenGLElementBuffer
    {
    public:
        OpenGLElementBuffer(uint32_t* indices, uint32_t size);
    private:
        uint32_t m_bufferId;
    };

}
