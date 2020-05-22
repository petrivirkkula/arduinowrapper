cmake_minimum_required(VERSION 3.16)
project(arduiwrappertesting)

set(CMAKE_CXX_STANDARD 11)


# Download and unpack googletest at configure time
configure_file(CmakeLists.txt.gtest ${CMAKE_CURRENT_BINARY_DIR}/googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)


set(gtest_disable_pthreads ON CACHE BOOL "" FORCE)

add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
        ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include")
    include_directories("${gmock_SOURCE_DIR}/include")
endif()


file(GLOB SRCFILES ${CMAKE_SOURCE_DIR}/../library/src/*.cpp)
file(GLOB INCLUDEFILES ${CMAKE_SOURCE_DIR}/../library/include/arduinowrapper/*.h)
#set(arduinowrapper_SRCS {SRCFILES})
#set(arduinowrapper_HDRS ${INCLUDESFILES})
include_directories("${CMAKE_SOURCE_DIR}/../library/include")
include_directories(BEFORE "${CMAKE_SOURCE_DIR}/mockarduino")
add_library(library STATIC ${SRCFILES})
#add_dependencies(library ${INCLUDEFILES})

add_executable(TC001_pins mockarduino/mockarduino.cpp testcases/TC001_pins.cpp)
add_dependencies(TC001_pins library)
target_link_libraries(TC001_pins gtest_main)
target_link_libraries(TC001_pins library)

add_executable(TC002_interrupts mockarduino/mockarduino.cpp testcases/TC002_interrupts.cpp)
add_dependencies(TC002_interrupts library)
target_link_libraries(TC002_interrupts gtest_main)
target_link_libraries(TC002_interrupts library)

add_executable(TC003_advancedio mockarduino/mockarduino.cpp testcases/TC003_advancedio.cpp)
add_dependencies(TC003_advancedio library)
target_link_libraries(TC003_advancedio gtest_main)
target_link_libraries(TC003_advancedio library)

enable_testing()

add_test(NAME TC001_pins COMMAND TC001_pins)
add_test(NAME TC002_interrupts COMMAND TC002_interrupts)
add_test(NAME TC003_advancedio COMMAND TC003_advancedio)

