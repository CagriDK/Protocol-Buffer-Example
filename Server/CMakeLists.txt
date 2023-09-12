cmake_minimum_required(VERSION 3.24.0)

include(CTest)
enable_testing()

# Find required protobuf package
find_package(protobuf CONFIG REQUIRED)

#if(protobuf_VERBOSE)
#  message(STATUS "Using Protocol Buffers ${protobuf_VERSION}")
#endif()

# .proto dosyasından C++ kodunu üret
add_executable(ServerProtocolBufferP Server.h Server.cpp ${PROTO_SRCS} ${PROTO_HDRS} ServerData.proto)

if(WIN32)
    set(BOOST_INCLUDEDIR     "C:/boost_1_71_0/boost")
    set(BOOST_LIBRARYDIR     "C:/boost_1_71_0/stage/lib")
    set(BOOST_ROOT           "C:/boost_1_71_0")
    
    find_package(Boost 1.71 REQUIRED)
    if(MINGW)
    target_link_libraries(ServerProtocolBufferP ${Boost_LIBRARIES} ws2_32 wsock32  ${PROTOBUF_LIBRARIES} protobuf::libprotobuf)
    protobuf_generate(TARGET ServerProtocolBufferP IMPORT_DIRS ${CMAKE_CURRENT_LIST_DIR} PROTOC_OUT_DIR ${CMAKE_CURRENT_LIST_DIR}/ProtoFiles ) 
    endif()
    if(Boost_FOUND)
        #message(STATUS "Boost Libraries are found")
        #message(
        #"BOOST package:
        #    found: ${Boost_FOUND}
        #    BOOST_INCLUDEDIR: ${BOOST_INCLUDEDIR}
        #    System Boost Dir: ${Boost_LIBRARIES}
        #    BOOST_LIBRARYDIR: ${BOOST_LIBRARYDIR}
        #    BOOST_ROOT: ${BOOST_ROOT}
        #    CMakeDir: ${CMAKE_CURRENT_LIST_DIR}
        #    "
        #)
    else()
        #message(STATUS "Failed to find Boost Libraries")
    endif()
    target_include_directories(ServerProtocolBufferP PUBLIC ${BOOST_ROOT})
else()
    find_package( Boost 1.71 COMPONENTS program_options REQUIRED )
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
    include_directories( ${Boost_INCLUDE_DIR} )
    target_link_libraries(ServerProtocolBufferP ${Boost_LIBRARIES} ws2_32 wsock32  ${PROTOBUF_LIBRARIES} protobuf::libprotobuf)
    protobuf_generate(TARGET ServerProtocolBufferP IMPORT_DIRS ${CMAKE_CURRENT_LIST_DIR} PROTOC_OUT_DIR ${CMAKE_CURRENT_LIST_DIR}/ProtoFiles ) 
endif()