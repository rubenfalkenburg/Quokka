#pragma once

#include "qkpch.h"

namespace QuokkaEngine {
    
    class Scene
    {
    public:
        Scene(std::string name);
        ~Scene() = default;
    private:
        std::string m_name;
    };

}
