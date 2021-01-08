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
IncludeDir["spdlog"]    = "%{wks.location}/QuokkaEngine/vendor/spdlog/include"
IncludeDir["glfw"]      = "%{wks.location}/QuokkaEngine/vendor/glfw/include"
IncludeDir["glad"]      = "%{wks.location}/QuokkaEngine/vendor/glad/include"
IncludeDir["imgui"]     = "%{wks.location}/QuokkaEngine/vendor/imgui"
IncludeDir["entt"]      = "%{wks.location}/QuokkaEngine/vendor/entt/include"
IncludeDir["glm"]       = "%{wks.location}/QuokkaEngine/vendor/glm"

group "Dependencies"
    include "QuokkaEngine/vendor/glfw"
    include "QuokkaEngine/vendor/glad"
    include "QuokkaEngine/vendor/imgui"
group ""

include "QuokkaEngine"
include "QuokkaEditor"