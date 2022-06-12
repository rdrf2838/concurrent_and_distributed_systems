add_executable(mmap_file mmap_file.cpp)
target_include_directories(mmap_file PRIVATE "${BOOST_ROOT}")
target_link_libraries(mmap_file PRIVATE rt)
