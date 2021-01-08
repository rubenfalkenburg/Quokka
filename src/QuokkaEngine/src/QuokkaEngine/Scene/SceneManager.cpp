#include "QuokkaEngine/Scene/SceneManager.h"

namespace QuokkaEngine {
    
    Scene* SceneManager::s_activeScene;

    Scene& SceneManager::GetActiveScene()
    {
        return *s_activeScene;
    }

    void SceneManager::SetActiveScene(Scene* scene)
    {
        s_activeScene = scene;
    }
    
    void SceneManager::LoadScene(const std::string sceneName)
    {
        
    }
}
