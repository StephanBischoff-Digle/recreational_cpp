add_executable(space main.cpp spaceship.h spaceship.cpp)
target_link_libraries(space PRIVATE project_options project_warnings
        raylib eigen)
set_target_properties(space PROPERTIES RUNTIME_OUTPUT_DIRECTORY
        "${CMAKE_BINARY_DIR}/bin")
