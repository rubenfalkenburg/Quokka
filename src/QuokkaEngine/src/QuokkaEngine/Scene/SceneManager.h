#pragma once

#include "qkpch.h"

#include "QuokkaEngine/Scene/Scene.h"

namespace QuokkaEngine {
    
    class SceneManager
    {
    public:
        static Scene& GetActiveScene() { return *s_activeScene.get(); };
        static void SetActiveScene(Scene* scene) { s_activeScene.reset(scene); };
    private:
        static std::unique_ptr<Scene> s_activeScene;
    };

}
