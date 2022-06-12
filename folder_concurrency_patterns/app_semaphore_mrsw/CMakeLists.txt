add_executable(mrsw_semaphore mrsw_semaphore.cpp)
target_include_directories(mrsw_semaphore PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)
target_link_libraries(mrsw_semaphore PRIVATE patterns)