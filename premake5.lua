workspace "Aurora"
	architecture "x64"

	configurations{
		"Debug","Release","Dist"
		}
	

outdir="%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir={}
IncludeDir["GLFW"]= "Aurora/vendor/GLFW/include"
IncludeDir["GLAD"]= "Aurora/vendor/GLAD/include"
IncludeDir["ImGui"]= "Aurora/vendor/imgui"

include "Aurora/vendor/GLFW"
include "Aurora/vendor/GLAD"
include "Aurora/vendor/imgui"

project "Aurora"
	location "Aurora"
	kind "StaticLib"
	language "C++"
	cppdialect "c++17"	
	staticruntime "on"
	

	targetdir ("bin/" .. outdir .. "/%{prj.name}")
	objdir ("bin-init/" .. outdir .. "/%{prj.name}")

	files {
	"%{prj.name}/src/**.h",
	"%{prj.name}/src/**.cpp",
	}

	includedirs {
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.GLAD}",
		"%{IncludeDir.ImGui}"

	}

	links{
	"GLFW",
	"opengl32.lib",
	"GLAD",
	"ImGui"
	}
	--pchheader "aurpch.h"
	--pchsource ("Aurora/src/aurpch.cpp")

	filter "system:windows"
		cppdialect "c++17"	
		systemversion "latest"
	
		defines
		{
				"AUR_PLATFORM_WINDOWS",
				"AUR_BUILD_DLL",
				"GLFW_INCLUDE_NONE"
		}
	
	
	filter "system:macosx"
		defines
		{
				"AUR_PLATFORM_MACOS",
				"GLFW_INCLUDE_NONE"
		}
		links {"OpenGL.framework","Cocoa.framework","IOKit.framework","CoreFoundation.framework","CoreVideo.framework"}
		buildoptions { "-F ~/MacOSX-SDKs/MacOSX10.15.sdk/System/Library/Frameworks"}
        linkoptions { "-F ~/MacOSX-SDKs/MacOSX10.15.sdk/System/Library/Frameworks"}
	

	filter "configurations:Debug"
			defines "AUR_DEBUG"
			symbols "on"
			runtime "Debug"

	filter "configurations:Release"
			defines "AUR_RELEASE"
			optimize "on"
			runtime "Release"
			 
	filter "configurations:Dist"
			defines "AUR_DIST"
			optimize "on"
			runtime "Release"

	filter{"system:windows", "configurations:Release","configurations:Debug"}

			defines
			{
				"AUR_ENABLE_ASSERT_WINDOWS"
			}	

	filter{"system:macos", "configurations:Release","configurations:Debug"}
			defines
			{
			"AUR_ENABLE_ASSERT_MACOS"
			}


project "SandBox"
	location "SandBox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "c++17"
	staticruntime "on"

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
		systemversion "latest"
	
		defines
		{
				"AUR_PLATFORM_WINDOWS"	
		}

	filter "system:macosx"
		defines
		{
			"AUR_PLATFORM_MACOS"
		}	
		links {"OpenGL.framework","Cocoa.framework","IOKit.framework","CoreFoundation.framework","CoreVideo.framework"}
		buildoptions { "-F ~/MacOSX-SDKs/MacOSX10.15.sdk/System/Library/Frameworks"}
        linkoptions { "-F ~/MacOSX-SDKs/MacOSX10.15.sdk/System/Library/Frameworks"}
	
	filter "configurations:Debug"
			defines "AUR_DEBUG"
			symbols "on"
			runtime "Debug"


	filter "configurations:Release"
			defines "AUR_RELEASE"
			optimize "on"
			runtime "Release"
	
	filter "configurations:Dist"
			defines "AUR_DIST"
			optimize "on"
			runtime "Release"
