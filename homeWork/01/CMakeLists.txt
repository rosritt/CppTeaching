cmake_minimum_required (VERSION 3.23)
project(cpp_template VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})

################################
# build type
################################

# Set a default build type if not passed
set(default_build_type "Release")
if(NOT CMAKE_BUILD_TYPE)
  message(STATUS "Setting build type to '${default_build_type}' as none was specified.")
  set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
    "Debug" "Release")
endif()



################################
# src
################################


add_executable(cmatrix
  ${CMAKE_CURRENT_SOURCE_DIR}/matrixMult/main.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/matrixMult/func.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/matrixMult/func.hpp
)

add_executable(cstack
  ${CMAKE_CURRENT_SOURCE_DIR}/cstack/main.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/cstack/cstack.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/cstack/cstack.hpp
)

#target_link_libraries(cmatrix    NumCpp::NumCpp)

################################
# GTest
################################

file(GLOB_RECURSE TEST_SOURCES test/**.cpp)
file(GLOB_RECURSE TEST_HEADERS test/**.h)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()

add_executable(
  Google_Tests_run_cmatrix
  ${CMAKE_CURRENT_SOURCE_DIR}/matrixMult/func.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/matrixMult/func.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/main.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_cmatrix.cpp
)

add_executable(
  Google_Tests_run_cstack
  ${CMAKE_CURRENT_SOURCE_DIR}/cstack/cstack.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/cstack/cstack.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/main.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_cstack.cpp
)

target_include_directories(Google_Tests_run_cstack PRIVATE  
  ${CMAKE_CURRENT_SOURCE_DIR}/cstack
)

target_include_directories(Google_Tests_run_cmatrix PRIVATE  
  ${CMAKE_CURRENT_SOURCE_DIR}/matrixMult
)

target_link_libraries(
  Google_Tests_run_cmatrix
  GTest::gtest
  GTest::gmock
  GTest::gtest_main
  GTest::gmock_main
)


target_link_libraries(
  Google_Tests_run_cstack
  GTest::gtest
  GTest::gmock
  GTest::gtest_main
  GTest::gmock_main
)

include(GoogleTest)
gtest_discover_tests(Google_Tests_run_cmatrix)
gtest_discover_tests(Google_Tests_run_cstack)
