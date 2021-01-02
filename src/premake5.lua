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
IncludeDir["spdlog"] = "%{wks.location}/QuokkaEngine/vendor/spdlog/include"
IncludeDir["glfw"] = "%{wks.location}/QuokkaEngine/vendor/glfw/include"

group "Dependencies"
    include "QuokkaEngine/vendor/glfw"
group ""

include "QuokkaEngine"
include "QuokkaEditor"