

if (NOT sdl_FOUND) # If there's none, fetch and build raylib
  include(FetchContent)
  FetchContent_Declare(
    sdl
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG ${SDL_VERSION}
  )
  FetchContent_GetProperties(sdl)
  if (NOT SDL2_POPULATED) # Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(sdl)
    #add_library(sdl INTERFACE) #nope
    FetchContent_MakeAvailable(sdl)
    message("sdl_SOURCE_DIR: " ${sdl_SOURCE_DIR}) # pass
    message("sdl_BINARY_DIR: " ${sdl_BINARY_DIR}) # pass
    message("sdl_LIBRARY_DIR: " ${sdl_LIBRARY_DIR}) # fail
    message("sdl_LIBRARIES: " ${sdl_LIBRARIES}) # fail
    message("sdl_INCLUDES: " ${sdl_INCLUDES}) # fail
    message("sdl_INCLUDE_DIRS: " ${sdl_INCLUDE_DIRS}) # fail
    message("sdl_DIR: " ${sdl_DIR}) # fail
    message("sdl_LIB: " ${sdl_LIB}) # fail
    message("sdl_LIBS: " ${sdl_LIBS}) # fail
    message("sdl_DEFINITIONS: " ${sdl_DEFINITIONS}) # fail
    
    # build SDL2
    add_subdirectory(${sdl_SOURCE_DIR} ${sdl_BINARY_DIR})
    #find_library(LIBRARY_SDL SDL2)
    #message("SUB LIBRARY_SDL: " ${LIBRARY_SDL})
  endif()
endif()