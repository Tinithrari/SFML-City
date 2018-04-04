project(SFML_City)

set(SFML_City_SRCS
    src/main.cpp
)

cmake_minimum_required(VERSION 3.9)
add_executable(sfml_city ${SFML_City_SRCS})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/module" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(sfml_city ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

install(TARGETS sfml_city DESTINATION bin)
