add_executable(simplegame simplegame.cpp)

set_target_properties(simplegame PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/Release
            )

# Link the VVE
include_directories(${CMAKE_SOURCE_DIR}/VulkanEngine)
target_link_libraries(simplegame vulkanengine)

# additional include directories
target_include_directories(simplegame PUBLIC ${CMAKE_SOURCE_DIR}/external/stb)
target_include_directories(simplegame PUBLIC ${CMAKE_SOURCE_DIR}/external/threadpool)
target_include_directories(simplegame PUBLIC ${CMAKE_SOURCE_DIR}/external/nuklear)

# list of all dependencies here
find_package(Vulkan REQUIRED)
include_directories(${Vulkan_INCLUDE_DIRS})
target_link_libraries(simplegame Vulkan::Vulkan)

set(IRRKLANG_ROOT ${CMAKE_SOURCE_DIR}/external/irrKlang)
find_package(IrrKlang REQUIRED)
target_include_directories(simplegame PUBLIC ${IRRKLANG_INCLUDE_DIR})
target_link_libraries(simplegame ${IRRKLANG_LIBRARY})

find_package(ZLIB REQUIRED)
target_link_libraries(simplegame ZLIB::ZLIB)

find_package(assimp REQUIRED)
target_include_directories(simplegame PUBLIC ${assimp_INCLUDE_DIRS})
target_link_libraries(simplegame assimp::assimp)

find_package(glm CONFIG REQUIRED)
target_include_directories(simplegame PUBLIC ${glm_INCLUDE_DIRS})
target_link_libraries(simplegame glm)
