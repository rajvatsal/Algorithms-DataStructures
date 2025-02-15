project "Core"
  language "C"
  kind "StaticLib"
  targetdir("../bin/" .. outputdir .. "/Core")
  objdir("..bin/intermediates/" .. outputdir .. "/Core")
  staticruntime "off"

	defines     { "LUA_USE_POSIX", "LUA_USE_DLOPEN" }
  links { "m:static" }
	linkoptions { "-rdynamic" }

  files {
    "source/**.c",
    "source/**.h"
  }

  includedirs { "source/" }

  filter "configurations:Debug"
    defines "DEBUG"
    symbols "On"
    runtime "Debug"

  filter "configurations:Release"
    defines "NDEBUG"
    optimize "On"
    runtime "Release"
