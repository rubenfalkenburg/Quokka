project "QuokkaEngine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir("%{wks.location}/obj/" .. outputdir .. "/%{prj.name}")

    pchheader "src/qkpch.h"
    pchsource "src/qkpch.cpp"

    files
    {
        "src/**.h",
        "src/**.cpp"
    }

    includedirs
    {
        "src",
        "%{IncludeDir.entt}",
        "%{IncludeDir.glad}",
        "%{IncludeDir.glfw}",
        "%{IncludeDir.glm}",
        "%{IncludeDir.imgui}",
        "%{IncludeDir.spdlog}",
        "%{IncludeDir.stb}"
    }

    links
    {
        "glfw",
        "glad",
        "imgui"
    }

    filter "system:windows"
        systemversion "latest"

    filter "system:macosx"

        sysincludedirs
        {
            "%{wks.location}/QuokkaEngine/src",
            "%{IncludeDir.entt}",
            "%{IncludeDir.glad}",
            "%{IncludeDir.glfw}",
            "%{IncludeDir.glm}",
            "%{IncludeDir.imgui}",
            "%{IncludeDir.spdlog}",
            "%{IncludeDir.stb}"
        }

    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        runtime "Release"
        optimize "on"
