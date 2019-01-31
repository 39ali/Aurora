project "GLAD"
    kind "StaticLib"
    language "C"
    
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
    
	filter "system:windows"
        systemversion "latest"
        staticruntime "On"
      
	
	filter { "system:windows", "configurations:Release" }
        buildoptions "/MT"

    filter "system:not windows"
		buildoptions { "-std=c11", "-lgdi32" }	
	

