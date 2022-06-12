set(APP_OCC_DIR ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE)

add_library (occ occ.cpp)
target_link_libraries(occ PRIVATE Threads::Threads)

add_executable(occ_main main.cpp)
target_link_libraries(occ_main PRIVATE occ)
# add_executable(occ main.cpp)
# target_include_directories(occ PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)
# target_link_libraries(occ PRIVATE patterns)