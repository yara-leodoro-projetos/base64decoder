cmake_minimum_required(VERSION 3.0.0)
project(base64decoder VERSION 0.1.0)

set(B64INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/B64)
find_package(cpprestsdk REQUIRED)
find_package(OpenCV REQUIRED)

include(CTest)
enable_testing()
include_directories( ${OpenCV_INCLUDE_DIRS} ${B64INCLUDE}/include)

add_executable(base64decoder libb64.cpp)

target_link_libraries(base64decoder PRIVATE cpprestsdk::cpprest
${OpenCV_LIBS}
${B64INCLUDE}/libb64.a)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
