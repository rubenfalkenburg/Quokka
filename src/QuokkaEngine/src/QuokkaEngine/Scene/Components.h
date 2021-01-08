#pragma once

#include "qkpch.h"

#include <glm/glm.hpp>

namespace QuokkaEngine {
    
    struct TagComponent
    {
        std::string Name;
        
        TagComponent() = default;
        TagComponent(const std::string name) : Name(name) {};
    };

    struct LayerComponent
    {
        std::string Name;
        
        LayerComponent() = default;
        LayerComponent(const std::string name) : Name(name) {};
    };

    struct TransformComponent
    {
        glm::vec3 Translation   = { 0.0f, 0.0f, 0.0f };
        glm::vec3 Rotation      = { 0.0f, 0.0f, 0.0f };
        glm::vec3 Scale         = { 1.0f, 1.0f, 1.0f };
        
        TransformComponent() = default;
        TransformComponent(const glm::vec3 translation) : Translation(translation) {};
    };

    struct CameraComponent
    {
        
    };

    struct LightComponent
    {
        
    };

}
