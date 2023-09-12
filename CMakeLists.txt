cmake_minimum_required(VERSION 3.0.0)
project(ProtocolBufferP VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

# Find required protobuf package
find_package(protobuf CONFIG REQUIRED)

if(protobuf_VERBOSE)
  message(STATUS "Using Protocol Buffers ${protobuf_VERSION}")
endif()

add_subdirectory(Client)
add_subdirectory(Server)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
