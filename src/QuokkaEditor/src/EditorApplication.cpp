#include <QuokkaEngine.h>

namespace QuokkaEditor
{
    class EditorApplication : public QuokkaEngine::Application
    {
    public:
        EditorApplication() : QuokkaEngine::Application("QuokkaEngine Editor")
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
