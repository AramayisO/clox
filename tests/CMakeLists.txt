project(${CMAKE_PROJECT_NAME}_test)

# Collect all test source files
file(GLOB TEST_SRCS CONFIGURE_DEPENDS *.c)

# Build the test executable and link the previously build application OBJECT library
add_executable(${PROJECT_NAME}
    ${TEST_SRCS}
    $<TARGET_OBJECTS:${CMAKE_PROJECT_NAME}_obj>)
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_link_libraries(${PROJECT_NAME} PRIVATE unity)

# Set where the test executable should be places
set_target_properties(${PROJECT_NAME} PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests)

# Register with CTest
add_test(NAME unit COMMAND ${PROJECT_NAME})
