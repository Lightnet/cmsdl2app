https://stackoverflow.com/questions/48754619/what-are-cmake-build-type-debug-release-relwithdebinfo-and-minsizerel

https://stackoverflow.com/questions/7724569/debug-vs-release-in-cmake


https://stackoverflow.com/questions/4905340/cmake-regex-to-convert-lower-case-to-upper-case















```cmake
#message("SDL_LIBRARY: " ${SDL_LIBRARY}) # fail but define in cmake
#message("SDL_INCLUDE_DIR: " ${SDL_INCLUDE_DIR}) #pass
#message("sdl_SOURCE_DIR: " ${sdl_SOURCE_DIR}) #pass
#message("sdl_BINARY_DIR: " ${sdl_BINARY_DIR}) #pass
#message("sdl_LIBRARY_DIR: " ${sdl_LIBRARY_DIR}) # fail
#message("sdl_LIBRARIES: " ${sdl_LIBRARIES}) # fail
#message("sdl_INCLUDES: " ${sdl_INCLUDES}) # fail
#message("sdl_INCLUDE_DIRS: " ${sdl_INCLUDE_DIRS}) # fail
#message("sdl_DIR: " ${sdl_DIR}) # fail
#message("sdl_LIB : " ${sdl_LIB}) # fail
#message("sdl_LIBS: " ${sdl_LIBS}) # fail
#message("sdl_DEFINITIONS: " ${sdl_DEFINITIONS}) # fail
```