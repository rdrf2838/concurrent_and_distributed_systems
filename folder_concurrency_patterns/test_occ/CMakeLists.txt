add_executable(test_occ test_occ.cpp)
target_include_directories(test_occ PRIVATE ${Boost_INCLUDE_DIRS} ${APP_OCC_DIR})
target_link_libraries(test_occ PRIVATE ${Boost_LIBRARIES} occ)
target_compile_options(test_occ PRIVATE "-fsanitize=address")