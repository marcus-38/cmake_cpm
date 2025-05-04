cmake_minimum_required(VERSION 4.0)
project(cmake_cpm)

set(CMAKE_CXX_STANDARD 23)

set(LIBS)

# -- add cpm --
include(cmake/CPM.cmake)

# -- add dependencies --
# spdlog
CPMAddPackage("gh:gabime/spdlog@1.15.2")
list(APPEND LIBS spdlog)

# imgui
CPMAddPackage(
        NAME imgui
        GITHUB_REPOSITORY ocornut/imgui
        GIT_TAG docking
        DOWNLOAD_ONLY
)
if(imgui_ADDED)
    add_library(imgui STATIC)
    target_sources(imgui PRIVATE
            ${imgui_SOURCE_DIR}/imgui.cpp
            ${imgui_SOURCE_DIR}/imgui_draw.cpp
            ${imgui_SOURCE_DIR}/imgui_tables.cpp
            ${imgui_SOURCE_DIR}/imgui_widgets.cpp
            ${imgui_SOURCE_DIR}/imgui_demo.cpp
            # SDL 3
            ${imgui_SOURCE_DIR}/backends/imgui_impl_sdl3.cpp
            # SDL 3 renderer
            ${imgui_SOURCE_DIR}/backends/imgui_impl_sdlrenderer3.cpp
    )
    target_include_directories(imgui PUBLIC "${imgui_SOURCE_DIR}")
    target_include_directories(imgui PUBLIC "${imgui_SOURCE_DIR}/backends")
    list(APPEND LIBS imgui)
endif()

# sdl
CPMAddPackage("gh:libsdl-org/SDL#57346f2")
list(APPEND SDL3::SDL3)
if(imgui_ADDED)
    target_link_libraries(imgui PRIVATE SDL3::SDL3)
endif()
CPMAddPackage("gh:libsdl-org/SDL_image#d345579")
list(APPEND LIBS SDL3_image::SDL3_image)

# -- executable --
add_executable(cmake_cpm
        src/main.cpp
        src/lib/Log.cpp
        src/lib/Log.h
        src/gui/testWindows.cpp
        src/gui/testWindows.h
)

# -- target compile features
target_compile_features(cmake_cpm PRIVATE cxx_std_23)

# -- link libraries --
target_link_libraries(${CMAKE_PROJECT_NAME} ${LIBS})