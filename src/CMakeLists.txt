#add_subdirectory()
add_executable(demo demo.cpp)
link_directories(${CMAKE_SOURCE_DIR} /usr/local/lib) 
target_link_libraries(demo pthread boost_system boost_thread )
