project "QuokkaEditor"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir("%{wks.location}/obj/" .. outputdir .. "/%{prj.name}")

    files
    {
        "src/**.h",
        "src/**.cpp"
    }

    includedirs
    {
        "%{wks.location}/QuokkaEngine/src"
    }

    links
    {
        "QuokkaEngine"
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

        links
        {
            "Cocoa.framework",
            "IOKit.framework",
            "OpenGL.framework"
        }

    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        runtime "Release"
        optimize "on"
