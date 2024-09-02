cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Vcpkg toolchain file")
set(VCPKG_TARGET_TRIPLET "x64-windows" CACHE STRING "Vcpkg target triplet")
message("CMAKE_TOOLCHAIN_FILE: ${CMAKE_TOOLCHAIN_FILE}")

project(AP)
find_package(GTest CONFIG REQUIRED)

file(GLOB_RECURSE CURRENT_HEADERS  include/*)
file(GLOB_RECURSE SOURCES  src/*)
source_group("Include" FILES ${CURRENT_HEADERS})
source_group("Source" FILES ${SOURCES}) 

include_directories(include/)

enable_testing()

add_executable(AP ${SOURCES} ${CURRENT_HEADERS})
target_link_libraries(AP
        PRIVATE
        GTest::gtest GTest::gtest_main
)
add_test(AllTestsInMain AP)