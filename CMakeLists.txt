cmake_minimum_required(VERSION 3.15)
project(raytracingweekend LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

add_executable(raytracingweekend src/main.cpp)

target_include_directories(raytracingweekend PRIVATE src)

if(MSVC)
    target_compile_options(raytracingweekend PRIVATE /W3)
else()
    target_compile_options(raytracingweekend PRIVATE
        -Wall -Wextra
        $<$<CONFIG:Release>:-O3>
        $<$<CONFIG:Release>:-march=native>
    )
endif()
