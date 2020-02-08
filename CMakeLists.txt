cmake_minimum_required(VERSION 3.15)
project(TradeSummarizer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
        ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)

# Back to TradeSummarizer, include header directory and create executable accordingly
include_directories(include)

set(SOURCE src/weighted_average_price.cc src/quantity_at_price.cc src/trade_info.cc src/trade_summary.cc src/trade_stream_parser.cc)
set(HEADERS include/weighted_average_price.h include/quantity_at_price.h include/trade_info.h include/trade_summary.h include/trade_stream_parser.h include/util.h)
set(TEST_FILES test/quantity_at_price_tests.cc test/weighted_average_price_tests.cc test/trade_info_tests.cc test/trade_summary_tests.cc test/trade_stream_parser_tests.cc)

add_executable(${PROJECT_NAME} src/main.cc ${SOURCE} ${HEADERS})
target_link_libraries(${PROJECT_NAME} stdc++fs)

# Point unit tests to TradeSummarizer then create all applicable tests
add_executable(UnitTests ${SOURCE} ${HEADERS} ${TEST_FILES})
# Link test executable against gtest & gtest_main
target_link_libraries(UnitTests gtest gtest_main stdc++fs)
add_test(UnitTests UnitTests)