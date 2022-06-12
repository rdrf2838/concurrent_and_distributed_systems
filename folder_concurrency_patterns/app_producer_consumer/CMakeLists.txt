add_executable(reader reader.cpp)
target_include_directories(reader PRIVATE "${BOOST_ROOT}")
target_link_libraries(reader PRIVATE rt Threads::Threads)

add_executable(writer writer.cpp)
target_include_directories(writer PRIVATE "${BOOST_ROOT}")
target_link_libraries(writer PRIVATE rt Threads::Threads)
