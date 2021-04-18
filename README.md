# cmdsdlapp

# license: MIT

# Packages:
 * SDL 2.0.14 https://github.com/libsdl-org/SDL
 * SDL TTF 
 * SDL IMAGE 
 * SDL MIXER 
 * IMGUI 1.82 https://github.com/ocornut/imgui
 * Flecs https://github.com/SanderMertens/flecs
 * Vulkan 1.2.170.0 https://vulkan.lunarg.com/sdk/home

 * IMGUI SDL 2.0 https://github.com/Tyyppi77/imgui_sdl (remove)

# Created by: Lightnet

# Information:
  Using the cmake to auto build the application.

  Simple get sdl 2.0 github src build to run simple window render.

# Notes:
 * simple build.
 * window 10 64 bit vs2019 tested.
 * CMakeLists.txt is not clean up. Work on window 10 64bit.

# set up and build:
  Need to install cmake and compiler on window or other os tools.

  Open current project dir and open terimal to current to CMakelists.txt.
```
mkdir build 
cd build
cmake .. 
cmake --build .
```

```
  cmake .. <- this get the CMakeList.txt from project dir root
  cmake --build . <-build project
```

  Enter the commnand line. It should auto build execute application. But if you have firewalll or security it most likely block compile and program.

  By default the execute program is in build/Debug folder.

  If wanted to release

```
cd build
cmake ..
cmake --build . --config Release
```
# Config:
sdl_mixer CMakeList.txt:
```
#add_library(SDL2_mixer SHARED) # dll
add_library(SDL2_mixer STATIC) # lib

```







# Note: 
 * conflict build debug and release error if same build folder.
 * There are differen build config 

# GameNetworkingSockets:
 * https://github.com/ValveSoftware/GameNetworkingSockets/blob/master/BUILDING.md

```bat
::note download from cmakelist is tricky to setup. There is no cmake on sub third parties.


```


# Credits:
 * https://github.com/aminosbh/sdl2-mixer-sample
