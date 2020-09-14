cmake_minimum_required(VERSION 3.10)

project(bc)

add_subdirectory(vendor)

add_library(settings INTERFACE)
target_compile_options(settings INTERFACE "-Wall" "-Werror" "-std=c++17")

add_library(bc src/bc.cc)
target_compile_options(bc PUBLIC "-fembed-bitcode")
target_link_options(bc PUBLIC "-fembed-bitcode")

target_include_directories(bc PUBLIC src)
target_link_libraries(bc PUBLIC settings crypto++)

add_executable(bc-test src/bc.test.cc)
target_link_libraries(bc-test
  PRIVATE
    bc
    doctest::doctest
)

add_executable(bc-gtest src/bc.gtest.cc)
target_link_libraries(bc-gtest
  PRIVATE
    bc
    gtest gtest_main
)

# add_custom_target(run-test ALL COMMAND bc-test)
