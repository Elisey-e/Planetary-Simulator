cmake_minimum_required(VERSION 3.15)

project(Planetary_Simulator)


if (${PROJECT_SOURCE_DIR} STREQUAL ${PROJECT_BINARY_DIR})
    message(FATAL_ERROR "In-source build is forbidden")
endif()

set(CMAKE_CXX_STANDARD          20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -fopenmp")

#find_package(GTest REQUIRED)
#enable_testing()

# if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
#   set(CMAKE_INSTALL_PREFIX .)
# endif()





#set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/tests/src/e2e_tests)

set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(DATABASE_DIR ${PROJECT_SOURCE_DIR}/include/database)
set(DEMONSTRATION_DIR ${PROJECT_SOURCE_DIR}/include/demonstration)
set(EVALUATOR_DIR ${PROJECT_SOURCE_DIR}/include/evaluating)

include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIR} ${CMAKE_CURRENT_BINARY_DIR})
include_directories(${PROJECT_NAME} PUBLIC ${DATABASE_DIR} ${CMAKE_CURRENT_BINARY_DIR})
include_directories(${PROJECT_NAME} PUBLIC ${DEMONSTRATION_DIR} ${CMAKE_CURRENT_BINARY_DIR})
include_directories(${PROJECT_NAME} PUBLIC ${EVALUATOR_DIR} ${CMAKE_CURRENT_BINARY_DIR})

add_subdirectory(tests)

#add_subdirectory(tests/src/e2e_tests)
#add_subdirectory(tests/src/unit_tests)
