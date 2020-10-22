cmake_minimum_required(VERSION 3.10)
project(raisim_examples LANGUAGES CXX)

find_package(raisim CONFIG REQUIRED)
find_package(Eigen3 REQUIRED)

include_directories (${EIGEN3_INCLUDE_DIRS})

add_executable(raisimExample main.cpp)
target_link_libraries(raisimExample PUBLIC raisim::raisim)

if(NOT WIN32)
  target_link_libraries(raisimExample PUBLIC pthread)
endif()

target_include_directories(raisimExample PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/rsc DESTINATION ${CMAKE_BINARY_DIR})
