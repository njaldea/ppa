cmake_minimum_required(VERSION 3.27.1)

project(local VERSION 0.0.1 LANGUAGES CXX)

include(cmake/package.cmake)
include(cmake/toolchain.cmake)
include(cmake/quality.cmake)
include(cmake/test.cmake)
include(cmake/coverage.cmake)
include(cmake/cpack.cmake)

add_subdirectory(sandbox/service)
add_subdirectory(sandbox/xit-gtest)
