add_executable(distribution main.cpp)
target_link_libraries(distribution PRIVATE project_options project_warnings
                                           raylib)
set_target_properties(distribution PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                              "${CMAKE_BINARY_DIR}/bin")
