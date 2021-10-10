workspace "antgine"
	architecture "x64"

	configurations{
	"Debug",
	"Release",
	"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "antgine"
	location "antgine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
	"%{prj.name}/src/**.h",
	"%{prj.name}/src/**.cpp"
	}

	includedirs{
	"%{prj.name}/TPD/spdlog/include", "%{prj.name}/src/%{prj.name}/Header"
	}
	

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
		"AG_PLATFORM_WINDOWS",
		"AG_BUILD_DLL"
		}

		postbuildcommands{
			("{Copy} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/dasWuseln")
		}


	filter "configurations:Debug"
		defines "AG_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "AG_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "AG_DIST"
		optimize "On"






project "dasWuseln"
	location "dasWuseln"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
	"%{prj.name}/src/**.h",
	"%{prj.name}/src/**.cpp"
	}

	includedirs{ "./antgine/TPD/spdlog/include", "./antgine/src" }

	links{
	"antgine"
	}


	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
		"AG_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "AG_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "AG_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "AG_DIST"
		optimize "On"

