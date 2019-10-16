cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(OpenGLExample)

# Add source files
file(GLOB_RECURSE SOURCE_FILES 
	${CMAKE_SOURCE_DIR}/src/*.c
	${CMAKE_SOURCE_DIR}/src/*.cpp)
	
# Add header files
file(GLOB_RECURSE HEADER_FILES 
	${CMAKE_SOURCE_DIR}/src/*.h
	${CMAKE_SOURCE_DIR}/src/*.hpp
	${CMAKE_SOURCE_DIR}/Dependencies/GLEW/include/GL/glew.h
	${CMAKE_SOURCE_DIR}/Dependencies/GLFW/include/GLFW/glfw3.h)

# Define the executable
add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})

# Configure assets header file
include_directories(
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/Dependencies/GLFW/include/GLFW
	${CMAKE_SOURCE_DIR}/Dependencies/GLEW/include/GL)
	

#####################################################
# Include and link needed installed and binary libs #
#####################################################

##########################################
# Find our native installed libs (OpenGL)#
##########################################
FIND_PACKAGE(OpenGL REQUIRED)
if(NOT OPENGL_FOUND)
    message(ERROR " OPENGL not found!")
endif(NOT OPENGL_FOUND)
set(OPENGLLIB opengl32)

############################################################
# set up paths to the binaries we are using (GLFW and GLEW)#
############################################################
# GLFW
set(GLFWDIR ${CMAKE_SOURCE_DIR}/Dependencies/GLFW/include/GLFW)
set(GLFW3LIB ${CMAKE_SOURCE_DIR}/Dependencies/GLFW/lib-vc2019/glfw3.lib)
# GLEW
set(GLEWDIR ${CMAKE_SOURCE_DIR}/Dependencies/GLEW/include/GL)
set(GLEWLIB ${CMAKE_SOURCE_DIR}/Dependencies/GLEW/lib/Release/x64/glew32s.lib)

# Define the link libraries
target_include_directories(${PROJECT_NAME} PUBLIC ${OPENGL_INCLUDE_DIR} ${GLFWDIR} ${GLEWDIR})
target_link_libraries(${PROJECT_NAME} ${OPENGLLIB} ${GLFW3LIB} ${GLEWLIB})