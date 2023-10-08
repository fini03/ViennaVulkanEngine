cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

project(ViennaVulkanEngine)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release")

add_subdirectory(VulkanEngine)
add_subdirectory(examples)
