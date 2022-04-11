cmake_minimum_required(VERSION 3.14)
project(example)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.10.0
)
FetchContent_MakeAvailable(googletest)

set(CMAKE_CXX_STANDARD 17)
set(TEST_NAME ${PROJECT_NAME}_tests)
add_executable(${TEST_NAME} example_test.cpp)
add_subdirectory(sortings)
target_link_libraries(${TEST_NAME} gtest_main sortings)

enable_testing()
include(GoogleTest)
gtest_discover_tests(${TEST_NAME})
