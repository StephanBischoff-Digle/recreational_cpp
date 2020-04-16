add_executable(raycast main.cpp)
target_link_libraries(raycast PRIVATE project_options project_warnings raylib
                                      raylib_ext)
set_target_properties(raycast PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                         "${CMAKE_BINARY_DIR}/bin")
