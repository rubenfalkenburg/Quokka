workspace "Quokka"
    architecture "x64"
    startproject "QuokkaEditor"

    configurations
    {
        "Debug",
        "Release"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["entt"]          = "%{wks.location}/QuokkaEngine/vendor/entt/single_include"
IncludeDir["glad"]          = "%{wks.location}/QuokkaEngine/vendor/glad/include"
IncludeDir["glfw"]          = "%{wks.location}/QuokkaEngine/vendor/glfw/include"
IncludeDir["glm"]           = "%{wks.location}/QuokkaEngine/vendor/glm"
IncludeDir["imgui"]         = "%{wks.location}/QuokkaEngine/vendor/imgui"
IncludeDir["spdlog"]        = "%{wks.location}/QuokkaEngine/vendor/spdlog/include"
IncludeDir["stb"]           = "%{wks.location}/QuokkaEngine/vendor/stb/"

group "Dependencies"
    include "QuokkaEngine/vendor/glfw"
    include "QuokkaEngine/vendor/glad"
    include "QuokkaEngine/vendor/imgui"
group ""

include "QuokkaEngine"
include "QuokkaEditor"