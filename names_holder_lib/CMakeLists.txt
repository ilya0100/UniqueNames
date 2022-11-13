project(names_holder_library)

set(LIB_NAME names_holder_lib)
set(SOURCES src/names_holder.cpp)
set(INCLUDE_DIR include)

add_library(${LIB_NAME} ${SOURCES})

target_include_directories(${LIB_NAME} PUBLIC ${INCLUDE_DIR})

set(NAMES_HOLDER_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${INCLUDE_DIR} PARENT_SCOPE)
set(NAMES_HOLDER_LIBRARY ${LIB_NAME} PARENT_SCOPE)
