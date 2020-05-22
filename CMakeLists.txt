cmake_minimum_required(VERSION 3.16)
project(arduiwrapper)

set(CMAKE_CXX_STANDARD 11)

execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" -S ${CMAKE_SOURCE_DIR}/library -B ${CMAKE_BINARY_DIR}-library
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}_DIR}/library
        )

add_custom_target(build-library ALL COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR}-library )

#add_subdirectory(library)

execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" -S ${CMAKE_SOURCE_DIR}/testing -B ${CMAKE_BINARY_DIR}-testing
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/testing
        )

add_custom_target(build-testing ALL COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR}-testing )

add_dependencies(build-testing build-library)

add_custom_target(test ALL COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR}-testing --target test)

add_dependencies(test build-testing)


