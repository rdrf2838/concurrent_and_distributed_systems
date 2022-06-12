list(APPEND CMAKE_PREFIX_PATH "${BOOST_ROOT}/stage/lib/cmake")
find_package(Boost CONFIG REQUIRED thread)

add_executable(multithreading_project main.cpp)
target_include_directories(multithreading_project PRIVATE ${BOOST_ROOT})
target_link_libraries(multithreading_project Threads::Threads Boost::thread)
