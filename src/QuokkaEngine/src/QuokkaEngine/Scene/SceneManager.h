#pragma once

#include "qkpch.h"

#include "QuokkaEngine/Scene/Scene.h"

namespace QuokkaEngine {
    
    class SceneManager
    {
    public:
        static Scene& GetActiveScene();
        static void SetActiveScene(Scene* scene);
        static void LoadScene(const std::string sceneName);
    private:
        static Scene* s_activeScene;
    };
}
