add_library(patterns semaphore.cpp)
target_include_directories(patterns PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
target_link_libraries(patterns PRIVATE Threads::Threads)