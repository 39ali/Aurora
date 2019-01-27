workspace "Aurora"
	architecture "x64"

	configurations{
		"Debug","Release","Dist"
		}


outdir="%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Aurora"
	location "Aurora"
	kind "SharedLib"
	language "C++"
	targetdir ("bin/" .. outdir .. "/%{prj.name}")
	objdir ("bin-init/" .. outdir .. "/%{prj.name}")

	files {
	"%{prj.name}/src/**.h",
	"%{prj.name}/src/**.cpp",
	}

	includedirs {
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "c++17"
		staticruntime "On"
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

	filter "configurations:Release"
			defines "AUR_RELEASE"
			optimize "On"
	
	filter "configurations:Dist"
			defines "AUR_DIST"
			optimize "On"
	
	--[[
	filter{"system:windows", "configurations:Release"}
		buildoptions "/MT" --]]


project "SandBox"
	location "SandBox"
	kind "ConsoleApp"
	language "C++"
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
		staticruntime "On"
		systemversion "latest"
	
		defines
		{
				"AUR_PLATFORM_WINDOWS"	
		}
		

	filter "configurations:Debug"
			defines "AUR_DEBUG"
			symbols "On"

	filter "configurations:Release"
			defines "AUR_RELEASE"
			optimize "On"
	
	filter "configurations:Dist"
			defines "AUR_DIST"
			optimize "On"
