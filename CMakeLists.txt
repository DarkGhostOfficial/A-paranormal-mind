cmake_minimum_required(VERSION 3.21)
project(apm VERSION 1.0 LANGUAGES CXX)
 
# ── C++ standard ──────────────────────────────────────────────────────────────
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
 
# ── Find SFML 3 ───────────────────────────────────────────────────────────────
set(SFML_DIR "C:/SFML_CPP/SFML-3.0.0/lib/cmake/SFML")
find_package(SFML 3 REQUIRED COMPONENTS System Window Graphics Audio)
 
# ── Executable (only .cpp files here) ────────────────────────────────────────
add_executable(${PROJECT_NAME}
    src/main.cpp
    src/Game.cpp
    include/Game.hpp
)
 
# ── Include directories ───────────────────────────────────────────────────────
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
 
# ── Link SFML ─────────────────────────────────────────────────────────────────
target_link_libraries(${PROJECT_NAME} PRIVATE
    SFML::Graphics
    SFML::Audio
    SFML::Window
    SFML::System
)
 
# ── Copy SFML DLLs next to the executable on Windows ─────────────────────────
# $<TARGET_RUNTIME_DLLS:...> automatically resolves the correct DLLs
# (requires CMake 3.21+, hence the bumped cmake_minimum_required above)
if(WIN32)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_RUNTIME_DLLS:${PROJECT_NAME}>
            $<TARGET_FILE_DIR:${PROJECT_NAME}>
        COMMAND_EXPAND_LISTS
        COMMENT "Copying SFML DLLs..."
    )
endif()