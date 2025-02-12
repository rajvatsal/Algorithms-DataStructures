project 'App'
  kind "ConsoleApp"
  language "C"
  targetdir ("../bin/" .. outputdir .. "/App")
  objdir ("../bin/intermediates/" .. outputdir .. "/App")

  files {
    "source/**.c",
    "source/**.h"
  }

  includedirs {
    "source/",
    "../core/source/"
  }

  links { "Core" }

  filter "configurations:Debug"
    defines "DEBUG"
    symbols "On"
    runtime "Debug"

  filter "configurations:Release"
    defines "NDEBUG"
    optimize "On"
    runtime "Release"
