add_executable(sleepmutex sleepmutex.cpp)
target_include_directories(sleepmutex PRIVATE "${BOOST_ROOT}")
target_link_libraries(sleepmutex PRIVATE rt Threads::Threads)