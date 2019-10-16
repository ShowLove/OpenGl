cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(OpenGLExample)

link_directories(${CMAKE_SOURCE_DIR}/Dependencies/GLFW/lib-vc2019)

# Add source files
file(GLOB_RECURSE SOURCE_FILES 
	${CMAKE_SOURCE_DIR}/src/*.c
	${CMAKE_SOURCE_DIR}/src/*.cpp)
	
# Add header files
file(GLOB_RECURSE HEADER_FILES 
	${CMAKE_SOURCE_DIR}/src/*.h
	${CMAKE_SOURCE_DIR}/src/*.hpp
	${CMAKE_SOURCE_DIR}/Dependencies/GLFW/include/GLFW/glfw3.h)


# Define the executable
add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})

# Configure assets header file
include_directories(
    ${CMAKE_SOURCE_DIR}/src
	${CMAKE_SOURCE_DIR}/Dependencies
	${CMAKE_SOURCE_DIR}/Dependencies/GLFW
    ${CMAKE_SOURCE_DIR}/Dependencies/GLFW/include/GLFW)
	

#######################################
# LOOK for the packages that we need! #
#######################################
# OpenGL
FIND_PACKAGE(OpenGL REQUIRED)
if(NOT OPENGL_FOUND)
    message(ERROR " OPENGL not found!")
endif(NOT OPENGL_FOUND)

# Put all libraries into a variable
set(OPENGLLIB opengl32)


set(GLFWDIR ${CMAKE_SOURCE_DIR}/Dependencies/GLFW/include/GLFW)
set(GLFW3LIB ${CMAKE_SOURCE_DIR}/Dependencies/GLFW/lib-vc2019/glfw3.lib)

# Define the link libraries
target_include_directories(${PROJECT_NAME} PUBLIC ${OPENGL_INCLUDE_DIR} ${GLFWDIR})
target_link_libraries(${PROJECT_NAME} ${OPENGLLIB} ${GLFW3LIB})