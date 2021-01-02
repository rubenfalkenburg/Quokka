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
        "%{wks.location}/QuokkaEngine/src",
        "%{wks.location}/QuokkaEngine/vendor",
        "%{IncludeDir.glfw}"
    }

    links
    {
        "QuokkaEngine",
    }

    filter "system:windows"
        systemversion "latest"

    filter "system:macosx"

        sysincludedirs
        {
            "%{wks.location}/QuokkaEngine/src",
            "%{wks.location}/QuokkaEngine/vendor",
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