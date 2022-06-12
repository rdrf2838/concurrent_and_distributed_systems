add_executable(daytime_client daytime_client.cpp)
target_include_directories(daytime_client PRIVATE ${BOOST_ROOT})
target_link_libraries(daytime_client Threads::Threads)

add_executable(daytime_server daytime_server.cpp)
target_include_directories(daytime_server PRIVATE ${BOOST_ROOT})
target_link_libraries(daytime_server Threads::Threads)
