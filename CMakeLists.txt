cmake_minimum_required(VERSION 3.25)

project(Syskos VERSION 0.0.1.0 LANGUAGES CXX)

include(cmake/utilities.cmake)

option(BUILD_EXAMPLES "Build example programs" OFF)
option(BUILD_TESTS "Build test programs" OFF)
option(BUILD_SHARED_LIBS "Build shared libraries instead of static" OFF)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Library variables
set(SYSKOS_ALIAS Syskos)

# Enable `__cplusplus` macro to reflect the actual C++ standard version
if (MSVC)
    add_compile_options(/Zc:__cplusplus)
endif()

convert_pascalcase_to_upper_snakecase(
    ${PROJECT_NAME}
    PROJECT_NAME_UPPER_SNAKECASE
)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/config.hpp.in
    ${CMAKE_CURRENT_BINARY_DIR}/include/Syskos/Config.hpp
)

# Build library
add_library(syskos)
add_library(${SYSKOS_ALIAS} ALIAS syskos)

target_sources(syskos
    PRIVATE
        library/Screen.cpp
        library/Syskos.cpp
        library/WindowStandard.cpp
        library/WindowUtilities.cpp
        library/WindowVisual.cpp
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS include
        FILES
            include/Syskos/Detail/Screen.hpp
            include/Syskos/Detail/WindowStandard.hpp
            include/Syskos/Detail/WindowUtilities.hpp
            include/Syskos/Detail/WindowVisual.hpp
            include/Syskos/Syskos.hpp
            include/Syskos/WindowAnchor.hpp
            include/Syskos/WindowGeometry.hpp
)
target_include_directories(syskos PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Build examples
if (BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

# Build tests
if (BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
