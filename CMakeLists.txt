cmake_minimum_required(VERSION 3.16)
project(opencv_demo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find_package 会读取 /usr/lib/x86_64-linux-gnu/cmake/opencv4/OpenCVConfig.cmake
find_package(OpenCV 4 REQUIRED)
message(STATUS "OpenCV version: ${OpenCV_VERSION}")
message(STATUS "OpenCV include dirs: ${OpenCV_INCLUDE_DIRS}")

add_executable(opencv_demo src/main.cpp)
target_include_directories(opencv_demo PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(opencv_demo PRIVATE ${OpenCV_LIBS})

add_executable(version_cpp version_cpp.cpp)
target_include_directories(version_cpp PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(version_cpp PRIVATE ${OpenCV_LIBS})
