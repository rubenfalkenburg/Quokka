#include "QuokkaEngine/Graphics/Window.h"

#include "Platforms/MacOS/MacOSWindow.h"

namespace QuokkaEngine {
    
    std::unique_ptr<Window> Window::Create(const std::uint32_t width, const std::uint32_t height, const std::string title)
    {
        return std::make_unique<MacOSWindow>(width, height, title);
    }

}
