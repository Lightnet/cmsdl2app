#================================================
# CMAKE BUILD
# WINDOW BUILD CURRENTLY
#================================================
cmake_minimum_required(VERSION 3.20) # FetchContent is available in 3.11+

project(sdl2app VERSION 0.0.1)
message("START OF CMAKELIST...")
set(SDL_VERSION release-2.0.14) # SDL GIT RELEASE TAG

#================================================
# ENTERY POINTS
#================================================

# entry point file.cpp
#set(ENTRYPOINT main.cpp) 
#set(ENTRYPOINT sdl2window.cpp) 
set(ENTRYPOINT windowimguisdl.cpp)

message("ENTRYPOINT: ${ENTRYPOINT}") # console log
# config IDE ext 
#include(CTest)
#enable_testing()

#================================================
# CONFIGS
#================================================
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/modules)

message("CMAKE_SYSTEM_NAME == " ${CMAKE_SYSTEM_NAME})

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
  #target_compile_options(myApp PRIVATE /W4)
  #message("WINDOW")
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
  #target_compile_options(myApp PRIVATE -Wall -Wextra -Wpedantic)
  #message("Linux")
elseif (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
  # other macOS-specific flags for Clang
  #message("Darwin")
endif()

#build compiler tool
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# to deal with error log that rechecks paths
option(BUILD_CHECK_SDL "BUILD Check SDL path" ON)
option(BUILD_CHECK_FLECS "BUILD Check FLECS path" ON)
option(BUILD_CHECK_IMGUI "BUILD Check IMGUI path" ON)
option(BUILD_CHECK_IMGUISDL "BUILD Check IMGUI SDL path" ON)
option(BUILD_CHECK_VALKUN "BUILD Check VALKUN path" ON)

# headers and paths
set(INCLUDE_HEADERS "")
set(INCLUDE_PATHS "")

message("[[[=== CHECKING SDL DIR === ]]]")
if (BUILD_CHECK_SDL)
  # base on environment system path variable set.
  find_package(sdl QUIET) # Requires at least version 2.5.0
endif()
message("sdl_FOUND:" ${SDL_FOUND})
if (NOT sdl_FOUND) # If there's none, fetch and build sdl
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
    #FetchContent_MakeAvailable(sdl)
    #message("SDL_LIBRARY: " ${sdl_LIBRARY}) # fail but define in cmake
    #message("SDL_INCLUDE_DIR: " ${sdl_INCLUDE_DIR}) #pass
    #message("sdl_SOURCE_DIR: " ${sdl_SOURCE_DIR}) # pass
    #message("sdl_BINARY_DIR: " ${sdl_BINARY_DIR}) # pass
    # build SDL2
    list(APPEND INCLUDE_PATHS ${sdl_SOURCE_DIR}/include)
    add_subdirectory(${sdl_SOURCE_DIR} ${sdl_BINARY_DIR})
    # this will check false if there recheck build dir
    if (BUILD_CHECK_SDL)
      message("TURN OFF CHECKS BUILD CHECK SDL PATH")
      unset(BUILD_CHECK_SDL CACHE)
      option(BUILD_CHECK_SDL "BUILD CHECK SDL PATH" OFF)
    endif()
    #find_library(LIBRARY_SDL SDL2)
    #message("SUB LIBRARY_SDL: " ${LIBRARY_SDL})
  endif()
endif()

message("[[[=== CHECKING FLECS DIR === ]]]")
if (BUILD_CHECK_FLECS)
  find_package(flecs QUIET) # Requires at least version 2.5.0
endif()
if (NOT flecs_FOUND) # If there's none, fetch and build flecs
  include(FetchContent)
  FetchContent_Declare(
    flecs
    GIT_REPOSITORY https://github.com/SanderMertens/flecs.git
    GIT_TAG v2.3.2
  )
  FetchContent_GetProperties(flecs)
  if (NOT flecs_POPULATED) # Have we downloaded flecs yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(flecs)
    # build flecs
    add_subdirectory(${flecs_SOURCE_DIR} ${flecs_BINARY_DIR})
    if (BUILD_CHECK_FLECS)
      message("TURN OFF CHECKS BUILD CHECK FLECS PATH")
      unset(BUILD_CHECK_FLECS CACHE)
      option(BUILD_CHECK_FLECS "BUILD Check FLECS path" OFF)
    endif()

  endif()
endif()

message("[[[=== CHECKING IMGUI DIR === ]]]")

if (BUILD_CHECK_IMGUI)
  find_package(imgui QUIET) # Requires at least version 2.5.0
endif()
if (NOT imgui_FOUND) # If there's none, fetch and build imgui
  include(FetchContent)
  FetchContent_Declare(
    imgui
    GIT_REPOSITORY https://github.com/ocornut/imgui.git
    GIT_TAG v1.82
  )
  FetchContent_GetProperties(imgui)
  if (NOT imgui_POPULATED) # Have we downloaded imgui yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(imgui)
    message("imgui_SOURCE_DIR: " ${imgui_SOURCE_DIR})
    list(APPEND INCLUDE_PATHS ${imgui_SOURCE_DIR})
    list(APPEND INCLUDE_PATHS ${imgui_SOURCE_DIR}/backends)
    #INCLUDE_HEADERS
    list(APPEND INCLUDE_HEADERS ${imgui_SOURCE_DIR}/imconfig.h)
    list(APPEND INCLUDE_HEADERS ${imgui_SOURCE_DIR}/imgui.cpp)
    list(APPEND INCLUDE_HEADERS ${imgui_SOURCE_DIR}/imgui.h)
    list(APPEND INCLUDE_HEADERS ${imgui_SOURCE_DIR}/imgui_internal.h)
    list(APPEND INCLUDE_HEADERS ${imgui_SOURCE_DIR}/imgui_demo.cpp)
    list(APPEND INCLUDE_HEADERS ${imgui_SOURCE_DIR}/imgui_draw.cpp)
    list(APPEND INCLUDE_HEADERS ${imgui_SOURCE_DIR}/imgui_tables.cpp)
    list(APPEND INCLUDE_HEADERS ${imgui_SOURCE_DIR}/imgui_widgets.cpp)
    list(APPEND INCLUDE_HEADERS ${imgui_SOURCE_DIR}/imstb_rectpack.h)
    list(APPEND INCLUDE_HEADERS ${imgui_SOURCE_DIR}/imstb_textedit.h)
    list(APPEND INCLUDE_HEADERS ${imgui_SOURCE_DIR}/imstb_truetype.h)
    list(APPEND INCLUDE_HEADERS ${imgui_SOURCE_DIR}/backends/imgui_impl_sdl.cpp)
    list(APPEND INCLUDE_HEADERS ${imgui_SOURCE_DIR}/backends/imgui_impl_sdl.h)

    if (BUILD_CHECK_IMGUI)
      message("TURN OFF CHECKS BUILD CHECK FLECS PATH")
      unset(BUILD_CHECK_IMGUI CACHE)
      option(BUILD_CHECK_IMGUI "BUILD Check FLECS path" OFF)
    endif()
  endif()
endif()

message("[[[=== CHECKING IMGUI SDL DIR === ]]]")

if (BUILD_CHECK_IMGUISDL)
  find_package(imgui_sdl QUIET) # Requires at least version 2.5.0
endif()
if (NOT imgui_sdl_FOUND) # If there's none, fetch and build imgui_sdl
  include(FetchContent)
  FetchContent_Declare(
    imgui_sdl
    GIT_REPOSITORY https://github.com/Tyyppi77/imgui_sdl.git
    GIT_TAG        master
  )
  FetchContent_GetProperties(imgui_sdl)
  if (NOT imgui_sdl_POPULATED) # Have we downloaded imgui_sdl yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(imgui_sdl)
    # build imgui
    message("imgui_sdl_SOURCE_DIR: " ${imgui_sdl_SOURCE_DIR})

    list(APPEND INCLUDE_PATHS ${imgui_sdl_SOURCE_DIR})

    list(APPEND INCLUDE_HEADERS ${imgui_sdl_SOURCE_DIR}/imgui_sdl.cpp)
    list(APPEND INCLUDE_HEADERS ${imgui_sdl_SOURCE_DIR}/imgui_sdl.h)

    if (BUILD_CHECK_IMGUISDL)
      message("TURN OFF CHECKS BUILD CHECK FLECS PATH")
      unset(BUILD_CHECK_IMGUISDL CACHE)
      option(BUILD_CHECK_IMGUISDL "BUILD Check FLECS path" OFF)
    endif()
  endif()
endif()


#================================================
# EXECUTE APP
#================================================
#add_executable(${PROJECT_NAME} ${ENTRYPOINT})
add_executable(${PROJECT_NAME} ${ENTRYPOINT} ${INCLUDE_HEADERS})
#================================================
# INCLUDE DIRS
#================================================
target_include_directories(${PROJECT_NAME} 
  PRIVATE 
  ${INCLUDE_PATHS}
)
#================================================
# LIBRARIES
#================================================
#target_link_libraries(${PROJECT_NAME} SDL2main SDL2-static)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2main SDL2-static flecs_static)
#================================================
# COMPILER
#================================================
target_compile_options(${PROJECT_NAME} PRIVATE -Wall)

#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)
message("END OF CMAKELIST...")

#find_library(LIBRARY_SDL SDL)
#message("LIBRARY_SDL: " ${LIBRARY_SDL})
#if (LIBRARY_SDL)
  #target_link_libraries(myApp PRIVATE ${LIBRARY_SDL})
  #message("LIBRARY_SDL: " ${LIBRARY_SDL})
#else()
  # throw an error or enable compilation without the library
#endif()