# Collect all source files
file(GLOB SRC_FILES CONFIGURE_DEPENDS *.c)

# Remove src/main.c from source files since the main() function can only appear only
# once in every executable. Since we are building and object file that can be linked
# in both the application and test executables (which will both have different main()
# entry points) we want to keep main.c out of the object file.
list(REMOVE_ITEM SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/main.c)

# Build an OBJECT library so we can link the same compiled objects
# into multiple exectuables i.e. the application and test executables
add_library(${CMAKE_PROJECT_NAME}_obj OBJECT ${SRC_FILES})
target_include_directories(${CMAKE_PROJECT_NAME}_obj PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Build the real application exectuable.
# NOTE: we have to link the main.c file since it was excluded from the object file.
add_executable(${PROJECT_NAME}
    $<TARGET_OBJECTS:${PROJECT_NAME}_obj>
    ${CMAKE_CURRENT_SOURCE_DIR}/main.c)
