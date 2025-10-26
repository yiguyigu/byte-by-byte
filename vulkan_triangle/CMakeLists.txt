cmake_minimum_required(VERSION 3.10)
project(VulkanTriangle)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Vulkan
find_package(Vulkan REQUIRED)

# Find GLFW
find_package(glfw3 REQUIRED)

# 官方版本（最推荐！从 vulkan-tutorial.com 直接移植）
add_executable(VulkanTriangle official.cpp)
target_link_libraries(VulkanTriangle Vulkan::Vulkan glfw)


# 编译着色器
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/shaders)
find_program(GLSLC glslc HINTS $ENV{VULKAN_SDK}/bin)

if(GLSLC)
    add_custom_command(
        OUTPUT ${CMAKE_BINARY_DIR}/shaders/vert.spv
        COMMAND ${GLSLC} ${CMAKE_SOURCE_DIR}/shaders/shader.vert -o ${CMAKE_BINARY_DIR}/shaders/vert.spv
        DEPENDS ${CMAKE_SOURCE_DIR}/shaders/shader.vert
    )
    add_custom_command(
        OUTPUT ${CMAKE_BINARY_DIR}/shaders/frag.spv
        COMMAND ${GLSLC} ${CMAKE_SOURCE_DIR}/shaders/shader.frag -o ${CMAKE_BINARY_DIR}/shaders/frag.spv
        DEPENDS ${CMAKE_SOURCE_DIR}/shaders/shader.frag
    )
    add_custom_target(Shaders ALL
        DEPENDS ${CMAKE_BINARY_DIR}/shaders/vert.spv ${CMAKE_BINARY_DIR}/shaders/frag.spv
    )
    add_dependencies(VulkanTriangle Shaders)
else()
    message(WARNING "glslc not found, shaders won't be compiled. Install Vulkan SDK to fix this.")
endif()

# Add triangle_demo subproject (small learning demo) if it exists
if(EXISTS "${CMAKE_SOURCE_DIR}/triangle_demo/CMakeLists.txt")
    add_subdirectory(triangle_demo)
else()
    message(STATUS "triangle_demo subdirectory not found; skipping add_subdirectory(triangle_demo).")
endif()
