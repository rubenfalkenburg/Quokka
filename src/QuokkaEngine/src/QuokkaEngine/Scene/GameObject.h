#pragma once

#include "qkpch.h"

#include "QuokkaEngine/Scene/Components.h"

#include <entt/entt.hpp>

namespace QuokkaEngine {
    
    class GameObject
    {
    public:
        GameObject();
        GameObject(std::string name);
        ~GameObject();
        
        template<typename T, typename... Args>
        T& AddComponent(Args&&... args)
        {
            return nullptr;
        }
        
        template<typename T>
        T& GetComponent()
        {
            return nullptr;
        }
        
        template<typename T>
        void RemoveComponent()
        {
            
        }
        
        template<typename T>
        bool HasComponent()
        {
            return true;
        }
    private:
        
    private:
        entt::entity m_entityHandle;
        std::string m_name;
    };

}
