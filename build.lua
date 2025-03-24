workspace "Algorithms"
  configurations { "Debug", "Release" }
  architecture "x86_64"
  startproject "App"

  -- cfg is a token visit:
  -- https://premake.github.io/docs/Tokens/#value-tokens
  -- for more info
  outputdir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

  group "Algorithms-Core"
    include "./core/build-core.lua"

  group "Algorithms-App"
    include "./app/build-app.lua"

  group ""
