cmake_minimum_required(VERSION 3.20)
project(lab7)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab7 main.cpp Tests.cpp Students.cpp Students.h StudentFirstSession.cpp StudentFirstSession.h StudentSecondSession.cpp StudentFirstSession.h AverageScore.cpp AverageScore.h)

# 'Google_test' is the subproject name
project(Google_Tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
add_executable(Google_Tests_run Tests.cpp Students.cpp Students.h StudentFirstSession.cpp StudentFirstSession.h StudentSecondSession.cpp StudentFirstSession.h AverageScore.cpp AverageScore.h )
target_link_libraries(Google_Tests_run gtest gtest_main)