cmake_minimum_required(VERSION 3.0.0)
project(ProtocolBufferP VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_subdirectory(Client)
add_subdirectory(Server)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
