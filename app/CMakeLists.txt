project(unique_names_app)

set(EXE_NAME demo_app)
set(SOURCES main.cpp)

add_executable(${EXE_NAME} ${SOURCES})

message("NAMES_HOLDER_INCLUDE_DIR = ${NAMES_HOLDER_INCLUDE_DIR}")

target_include_directories(${EXE_NAME} PUBLIC ${NAMES_HOLDER_INCLUDE_DIR})
target_link_libraries(${EXE_NAME} ${NAMES_HOLDER_LIBRARY})