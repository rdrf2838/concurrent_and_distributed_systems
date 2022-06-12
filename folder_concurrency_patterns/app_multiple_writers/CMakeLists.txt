add_executable(multiple_writers main_semaphore.cpp)
target_include_directories(multiple_writers PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)
target_link_libraries(multiple_writers PRIVATE patterns)