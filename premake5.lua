workspace "Aurora"
	architecture "x64"

	configurations{
		"Debug","Release","Dist"
		}


outdir="%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir={}
IncludeDir["GLFW"]= "Aurora/vendor/GLFW/include"

include "Aurora/vendor/GLFW"

project "Aurora"
	location "Aurora"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outdir .. "/%{prj.name}")
	objdir ("bin-init/" .. outdir .. "/%{prj.name}")

	files {
	"%{prj.name}/src/**.h",
	"%{prj.name}/src/**.cpp",
	}

	includedirs {
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links{
	"GLFW",
	"opengl32.lib"
	}
	pchheader "aurpch.h"
	pchsource ("Aurora/src/aurpch.cpp")

	filter "system:windows"
		cppdialect "c++17"	
		systemversion "latest"
	
		defines
		{
				"AUR_PLATFORM_WINDOWS",
				"AUR_BUILD_DLL"
		}
		postbuildcommands
		{
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outdir .. "/SandBox")	
		}
		
	filter "configurations:Debug"
			defines "AUR_DEBUG"
			symbols "On"
			runtime "Debug"

	filter "configurations:Release"
			defines "AUR_RELEASE"
			optimize "On"
			runtime "Release"
			 
	filter "configurations:Dist"
			defines "AUR_DIST"
			optimize "On"
			runtime "Release"

	filter{"system:windows", "configurations:Release","configurations:Debug"}
		
			defines
			{
				"AUR_ENABLE_ASSERT"
			}	
	--[[
	filter{"system:windows", "configurations:Release"}
		buildoptions "/MT" --]]


project "SandBox"
	location "SandBox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outdir .. "/%{prj.name}")
	objdir ("bin-init/" .. outdir .. "/%{prj.name}")
	
	files {
	"%{prj.name}/src/**.h",
	"%{prj.name}/src/**.cpp",
	}

	includedirs {
		"Aurora/vendor/spdlog/include",
		"Aurora/src"
	}

	links {
		"Aurora"
	}

	filter "system:windows"
		cppdialect "c++17"
		systemversion "latest"
	
		defines
		{
				"AUR_PLATFORM_WINDOWS"	
		}
		

	filter "configurations:Debug"
			defines "AUR_DEBUG"
			symbols "On"
			runtime "Debug"


	filter "configurations:Release"
			defines "AUR_RELEASE"
			optimize "On"
			runtime "Release"
	
	filter "configurations:Dist"
			defines "AUR_DIST"
			optimize "On"
			runtime "Release"
