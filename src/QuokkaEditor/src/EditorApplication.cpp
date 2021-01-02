#include <QuokkaEngine.h>

namespace QuokkaEditor
{
    class EditorApplication : public QuokkaEngine::Application
    {
    public:
        EditorApplication()
        {
            
        }
        
        ~EditorApplication()
        {
            
        }
    };
}

QuokkaEngine::Application* QuokkaEngine::CreateApplication()
{
    return new QuokkaEditor::EditorApplication();
}
