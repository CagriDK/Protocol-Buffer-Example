cmake_minimum_required(VERSION 3.0.0)

include(CTest)
enable_testing()

add_executable(ClientProtocolBufferP Client.h Client.cpp)

if(WIN32)
    set(BOOST_INCLUDEDIR     "C:/boost_1_71_0/boost")
    set(BOOST_LIBRARYDIR     "C:/boost_1_71_0/stage/lib")
    set(BOOST_ROOT           "C:/boost_1_71_0")
    
    find_package(Boost 1.71 REQUIRED)
    if(MINGW)
    target_link_libraries(ClientProtocolBufferP ${Boost_LIBRARIES} ws2_32 wsock32)
    endif()
    if(Boost_FOUND)
        message(STATUS "Boost Libraries are found")
        message(
        "BOOST package:
            found: ${Boost_FOUND}
            BOOST_INCLUDEDIR: ${BOOST_INCLUDEDIR}
            System Boost Dir: ${Boost_LIBRARIES}
            BOOST_LIBRARYDIR: ${BOOST_LIBRARYDIR}
            BOOST_ROOT: ${BOOST_ROOT}
            CMakeDir: ${CMAKE_CURRENT_LIST_DIR}
            "
        )
    else()
        message(STATUS "Failed to find Boost Libraries")
    endif()
    target_include_directories(ClientProtocolBufferP PUBLIC ${BOOST_ROOT})
else()
    find_package( Boost 1.71 COMPONENTS program_options REQUIRED )
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
    include_directories( ${Boost_INCLUDE_DIR} )
    target_link_libraries(ClientProtocolBufferP LINK_PUBLIC ${Boost_LIBRARIES} )
endif()