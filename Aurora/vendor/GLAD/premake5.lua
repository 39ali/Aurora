project "GLAD"
    kind "StaticLib"
    language "C"
	staticruntime "on"
	systemversion "latest"

	targetdir ("bin/" .. outdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outdir .. "/%{prj.name}")

	files
	{
        "include/glad/glad.h",
		"include/KHR/khrplatform.h",
		"src/glad.c"
        
    }
	includedirs{
		"include"
	}
    

	filter "configurations:Debug"
		symbols "on"
		runtime "Debug"


	filter "configurations:Release"
		optimize "on"
		runtime "Release"

