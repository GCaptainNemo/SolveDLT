cmake_minimum_required (VERSION 3.3.1)
set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_CXX_FLAGS "/EHsc ${CMAKE_CXX_FLAGS}")

PROJECT(SolveDLT)

add_library(math_operation STATIC ${CMAKE_SOURCE_DIR}/src/solve_dlt.cpp ${CMAKE_SOURCE_DIR}/src/math_operation.cpp)

SET(LIBRARY_OUTPUT_PATH  ${CMAKE_SOURCE_DIR}/lib)

add_executable(SolveDLT ${CMAKE_SOURCE_DIR}/src/main.cpp)

target_link_libraries(SolveDLT math_operation)



# file(GLOB_RECURSE DIR_SRCS    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
# file(GLOB_RECURSE DIR_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)


# add_executable(
#${PROJECT_NAME} 
#${DIR_SRCS}
#${DIR_HEADERS}
#)




