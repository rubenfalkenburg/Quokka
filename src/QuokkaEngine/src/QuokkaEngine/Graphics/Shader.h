#pragma once

#include "qkpch.h"

namespace QuokkaEngine {
    
    class Shader
    {
    public:
        Shader(const std::string& vertexSrc, const std::string& fragmentSrc);
        ~Shader();
        
        void Bind() const;
        void Unbind() const;
    private:
        std::uint32_t m_renderId;
    };
}
