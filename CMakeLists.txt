cmake_minimum_required(VERSION 3.18)
project(concurrent_and_distributed_systems)

set(CMAKE_CXX_STANDARD 17)
set(BOOST_ROOT "/home/ivin/CLionProjects/boost_1_78_0")  # bad practice as not portable, CLI instead

set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads MODULE REQUIRED Threads)

list(APPEND CMAKE_PREFIX_PATH "${BOOST_ROOT}/lib/cmake")
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_subdirectory(folder_concurrency_patterns)
add_subdirectory(folder_ipc_primitives)
add_subdirectory(folder_multithreading_primitives)