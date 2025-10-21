cmake_minimum_required(VERSION 3.27.1)

project(local VERSION 0.0.1 LANGUAGES CXX)

include(cmake/package.cmake)
include(cmake/toolchain.cmake)
include(cmake/quality.cmake)
include(cmake/test.cmake)
include(cmake/coverage.cmake)
include(cmake/cpack.cmake)

find_package(nil-clix CONFIG REQUIRED)
find_package(nil-service CONFIG REQUIRED)

add_subdirectory(sandbox/xit-service)
add_subdirectory(sandbox/xit-gtest)