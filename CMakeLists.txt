cmake_minimum_required(VERSION 3.0.0)
project(base64decoder VERSION 0.1.0)

find_package(OpenCV REQUIRED)
find_package(Poco REQUIRED Util)

include(CTest)
enable_testing()

add_executable(base64decoder base64decoder.cpp)

target_link_libraries(base64decoder ${OpenCV_LIBS} )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

