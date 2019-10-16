
# OpenGL
FIND_PACKAGE(OpenGL REQUIRED)
if(NOT OPENGL_FOUND)
    message(ERROR " OPENGL not found!")
endif(NOT OPENGL_FOUND)

# Put all libraries into a variable
set(OPENGLLIB opengl32)


set(GLFWDIR ${CMAKE_SOURCE_DIR}/Dependencies/GLFW/include)
set(GLFW3LIB ${CMAKE_SOURCE_DIR}/Dependencies/GLFW/lib-vc2019/glfw3.lib)

# Define the link libraries
target_link_libraries(${PROJECT_NAME} ${OPENGLLIB} ${GLFW3LIB})
target_include_directories(${PROJECT_NAME} PUBLIC ${OPENGL_INCLUDE_DIR} ${GLFWDIR})