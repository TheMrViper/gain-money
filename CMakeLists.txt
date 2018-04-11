cmake_minimum_required(VERSION 3.5)
project(gainmoney)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -m32 -shared -fPIC")
set(SUBHOOK_STATIC 1)

add_subdirectory(mempatch)
include_directories(mempatch)

include_directories(.)

add_library(gainmoney SHARED
	main
)
target_link_libraries(gainmoney mempatch)

#add_executable(test_mempatch test.cpp)
#target_link_libraries(test_mempatch mempatch)
