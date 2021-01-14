#pragma once

#include "QuokkaEngine/Core/Application.h"

namespace QuokkaEngine {
    
    class Scene
    {
    public:
        Scene();
        ~Scene();
    private:
        void Update();
    private:
        friend class Application;
    };

}
