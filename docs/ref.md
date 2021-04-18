https://github.com/pvallet/gourdin/blob/master/CMakeLists.txt
https://internalpointers.com/post/modern-cmake-beginner-introduction
https://alandefreitas.github.io/moderncpp/utilities/networking/build-script/
https://dev.to/noah11012/using-sdl2-opening-a-window-79c
https://lazyfoo.net/tutorials/SDL/01_hello_SDL/index2.php

https://discourse.libsdl.org/t/delta-time/14895
https://stackoverflow.com/questions/29302203/sdl-delta-time-reset/29306509
https://thenumbat.github.io/cpp-course/sdl2/08/08.html
https://www.cplusplus.com/reference/cstdio/printf/
https://www.voyagingmind.com/posts/cmake-and-sdl2/
https://stackoverflow.com/questions/19024259/how-to-change-the-build-type-to-release-mode-in-cmake
https://blog.conan.io/2019/06/26/An-introduction-to-the-Dear-ImGui-library.html

https://github.com/Qihoo360/evpp

https://github.com/ValveSoftware/GameNetworkingSockets



https://partner.steamgames.com/doc/features/multiplayer/networking

https://www.reddit.com/r/vulkan/comments/5873ic/psa_as_of_version_37_cmake_supports_vulkan_out_of/


https://vulkan-tutorial.com/Development_environment


# physic
https://github.com/DanielChappuis/reactphysics3d

https://www.reactphysics3d.com/usermanual.html#x1-50004

# SDL add ons:
https://github.com/libsdl-org/SDL_image
https://github.com/libsdl-org/SDL_ttf
https://bugzilla.libsdl.org/
https://github.com/Tangent128/luasdl2

https://metacpan.org/release/SDL-Tutorial-3DWorld
https://marcelbraghetto.github.io/a-simple-triangle/2019/03/02/part-01/

# vulkan
https://developer.tizen.org/development/guides/native-application/graphics/simple-directmedia-layer-sdl/sdl-graphics-vulkan%C2%AE
https://docs.tizen.org/application/native/guides/graphics/vulkan/
https://marcelbraghetto.github.io/a-simple-triangle/2019/06/09/part-14/
https://github.com/MarcelBraghetto/a-simple-triangle
https://gist.github.com/YukiSnowy/dc31f47448ac61dd6aedee18b5d53858


https://www.voyagingmind.com/posts/cmake-and-sdl2/
```
# cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -GNinja ..

cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# Pulling down SDL2
include(FetchContent)

FetchContent_Declare(
        SDL2
        GIT_REPOSITORY "https://github.com/SDL-mirror/SDL.git"
        GIT_TAG release-2.0.10
)

FetchContent_GetProperties(SDL2)
if (NOT sdl2_POPULATED)
    FetchContent_Populate(SDL2)
    add_subdirectory(${sdl2_SOURCE_DIR} ${sdl2_BINARY_DIR})
endif ()

project(game1)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#
#  Pong
#
add_executable(pong
        src/main.c
        src/input.c
        src/rand.c
        src/gfx.c
        src/text.c
        src/texture.c
        src/time.c
        src/base/arena.c
        src/base/hash_table.c
        src/base/implementations.c
        )

target_link_libraries(pong SDL2main SDL2-static m)
target_compile_options(pong PRIVATE -Wall -Wextra)
# TODO eventually remove this
target_include_directories(pong PRIVATE ${sdl2_SOURCE_DIRS}/include external/glad/include)
```












