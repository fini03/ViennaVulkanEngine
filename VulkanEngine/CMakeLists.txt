
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

file(GLOB VulkanEngineSRC ./*.cpp ./*.c ./*.h)
add_library(vulkanengine STATIC ${VulkanEngineSRC} ${CMAKE_SOURCE_DIR}/external/threadpool/ThreadPool.cpp)

# include directories
target_include_directories(vulkanengine PUBLIC ${CMAKE_SOURCE_DIR}/external/nuklear)
target_include_directories(vulkanengine PUBLIC ${CMAKE_SOURCE_DIR}/external/stb)
target_include_directories(vulkanengine PUBLIC ${CMAKE_SOURCE_DIR}/external/threadpool)

find_package(Vulkan REQUIRED)
target_include_directories(vulkanengine PUBLIC ${Vulkan_INCLUDE_DIRS})
target_link_libraries(vulkanengine Vulkan::Vulkan)

find_package(assimp REQUIRED)
target_include_directories(vulkanengine PUBLIC ${assimp_INCLUDE_DIRS})
target_link_libraries(vulkanengine assimp::assimp)

find_package(glfw3 CONFIG REQUIRED)
target_include_directories(vulkanengine PUBLIC ${glfw_INCLUDE_DIRS})
target_link_libraries(vulkanengine glfw)

set_target_properties(vulkanengine PROPERTIES
            LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib
            ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib
            )

find_package(Doxygen OPTIONAL_COMPONENTS dot mscgen dia)
#if(DOXYGEN_FOUND)
add_custom_target(doxygen
           COMMAND ${DOXYGEN_EXECUTABLE}
           WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
           COMMENT "Generating API documentation with Doxygen"
           VERBATIM)
#endif()
