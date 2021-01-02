project "QuokkaEngine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir("%{wks.location}/obj/" .. outputdir .. "/%{prj.name}")

    pchheader "src/qkpch.h"
    pchsource "src/qkpch.cpp"

    defines
    {
        -- "GLFW_INCLUDE_NONE",
        "_CRT_SECURE_NO_WARNINGS"
    }

    files
    {
        "src/**.h",
        "src/**.cpp"
    }

    includedirs
    {
        "src",
        "%{IncludeDir.spdlog}",
        "%{IncludeDir.glfw}"
    }

    links
    {
        "glfw"
    }

    filter "system:windows"
        systemversion "latest"

    filter "system:macosx"

        defines "GL_SILENCE_DEPRECATION"
        
        sysincludedirs
        {
            "src",
            "%{IncludeDir.spdlog}",
            "%{IncludeDir.glfw}"
        }

        links
        {
            "Cocoa.framework",
            "IOKit.framework",
            "OpenGL.framework"
        }

    filter "configurations:Debug"
        defines "QK_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "QK_RELEASE"
        runtime "Release"
        optimize "on"