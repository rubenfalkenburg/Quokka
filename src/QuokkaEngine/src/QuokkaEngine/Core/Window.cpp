#include "QuokkaEngine/Core/Window.h"

#include "Platforms/MacOS/MacOSWindow.h"

namespace QuokkaEngine {

    std::unique_ptr<Window> Window::Create(std::uint32_t width, std::uint32_t height, std::string title)
    {
        return std::make_unique<MacOSWindow>(width, height, title);
    }
    
}
