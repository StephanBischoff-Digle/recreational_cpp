add_executable(noise main.cpp)
target_link_libraries(noise PRIVATE project_options project_warnings raylib
                                    FastNoise)
set_target_properties(noise PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                       "${CMAKE_BINARY_DIR}/bin")
