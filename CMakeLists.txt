cmake_minimum_required(VERSION 4.0.2)

project(clox VERSION 0.0.1)

# Set compiler standard
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Set where built files should be places
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Build options that can be set when generating the build files
# e.g. `cmake -DBUILD_TESTS=True ..`
option(BUILD_TESTS "Build the unit tests" OFF)

# Build application and test executables
add_subdirectory(src)

if (BUILD_TESTS)
    add_subdirectory(lib/Unity)
    target_compile_definitions(unity PUBLIC UNITY_OUTPUT_COLOR)
    add_subdirectory(tests)
endif()
