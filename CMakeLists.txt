cmake_minimum_required(VERSION 3.0.0)
project(base64decoder VERSION 0.1.0)

find_package(OpenCV REQUIRED)
find_package(cpprestsdk REQUIRED)

include(CTest)
enable_testing()
include_directories( ${OpenCV_INCLUDE_DIRS} ${B64INCLUDE}/include)

add_executable(base64decoder base64CPPREST.cpp
                              main.cpp)

target_link_libraries(base64decoder PRIVATE cpprestsdk::cpprest
${OpenCV_LIBS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

