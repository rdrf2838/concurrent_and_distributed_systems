add_executable(shared_memory shared_memory.cpp)
target_include_directories(shared_memory PRIVATE "${BOOST_ROOT}")
target_link_libraries(shared_memory PRIVATE rt)
