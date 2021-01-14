#include <QuokkaEngine.h>

namespace QuokkaEngine {
    
    class EditorApplication : public Application
    {
    public:
        EditorApplication() : Application("Quokka Editor")
        {
            
        }
        
        ~EditorApplication()
        {
            
        }
    };

    Application* CreateApplication()
    {
        return new EditorApplication();
    }
}
