project "QuokkaEditor"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir("%{wks.location}/obj/" .. outputdir .. "/%{prj.name}")

    defines
    {
        "GLFW_INCLUDE_NONE",
        "_CRT_SECURE_NO_WARNINGS"
    }

    files
    {
        "src/**.h",
        "src/**.cpp"
    }

    includedirs
    {
        "%{wks.location}/QuokkaEngine/src",
        "%{wks.location}/QuokkaEngine/vendor",
    }

    links
    {
        "QuokkaEngine",
        "imgui"
    }

    filter "system:windows"
        systemversion "latest"

    filter "system:macosx"
        
        sysincludedirs
        {
            "%{wks.location}/QuokkaEngine/src",
            "%{wks.location}/QuokkaEngine/vendor",
            "%{IncludeDir.spdlog}",
            "%{IncludeDir.glfw}",
            "%{IncludeDir.glad}",
            "%{IncludeDir.imgui}"
        }

        links
        {
            "Cocoa.framework",
            "IOKit.framework",
            "OpenGL.framework",
        }

    filter "configurations:Debug"
        defines "QK_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "QK_RELEASE"
        runtime "Release"
        optimize "on"