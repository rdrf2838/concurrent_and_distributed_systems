add_executable(monitor monitor.cpp)
target_include_directories(monitor PRIVATE "${BOOST_ROOT}")
target_link_libraries(monitor PRIVATE rt Threads::Threads)