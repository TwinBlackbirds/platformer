cmake_minimum_required(VERSION 3.30)
project(BouncingBall)

set(CMAKE_CXX_STANDARD 11)

find_package(SFML 2.6.2 REQUIRED COMPONENTS graphics window system)


add_executable(BouncingBall main.cpp)
target_link_libraries(BouncingBall sfml-graphics sfml-window sfml-system)