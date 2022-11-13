project(unique_names_unit_test)

set(TEST_SOURCES
    test.cpp
)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

add_executable(${PROJECT_NAME} ${TEST_SOURCES})

message("NAMES_HOLDER_INCLUDE_DIR = ${NAMES_HOLDER_INCLUDE_DIR}")

target_include_directories(${PROJECT_NAME} PUBLIC ${NAMES_HOLDER_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} 
    ${NAMES_HOLDER_LIBRARY}
    GTest::GTest
    gtest_main
    Threads::Threads
    -lgtest
)