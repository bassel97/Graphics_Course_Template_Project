cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

######### GLFW Modules #########
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(vendor/glfw)
add_subdirectory(vendor/glad)
######### GLFW Modules #########

project(GraphicsCourseProject)

set(SourceCode
    Source/Engine/Application.cpp

    Source/Engine/Core/Scene.cpp
    Source/Engine/Core/Component.cpp
    Source/Engine/Core/GameObject.cpp
    Source/Engine/Core/Transform.cpp

    Source/Engine/Core/System/Rendering/RenderingSystem.cpp
    Source/Engine/Core/System/Rendering/Camera.cpp
    Source/Engine/Core/System/Rendering/MeshRendering.cpp
    )

set(VendorCode
    vendor/glad/src
    )

add_executable(GraphicsCourseProject source/Main.cpp ${SourceCode} ${VendorCode})

target_include_directories(GraphicsCourseProject
    PUBLIC vendor/glad/include
    PUBLIC vendor/glm
    )

target_link_libraries(GraphicsCourseProject
    PUBLIC glfw
    PUBLIC glad
    )