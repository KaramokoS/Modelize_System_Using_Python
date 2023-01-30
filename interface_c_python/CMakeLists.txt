cmake_minimum_required(VERSION 3.10)


set(CMAKE_BUILD_TYPE Release)
project (swig_poc)

set(${PROJECT_NAME}_HEADERS
    matrix.h
)

set(${PROJECT_NAME}_SOURCES
    matrix.cpp
)

add_library(${PROJECT_NAME} SHARED
            ${${PROJECT_NAME}_HEADERS}
            ${${PROJECT_NAME}_SOURCES})

add_executable(mainFunc main.cpp) 

install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/mainFunc
  DESTINATION bin
  RENAME ${CMAKE_PROJECT_NAME}-mainFunc)


  