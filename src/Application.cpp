#define GLEW_STATIC 1 // Removes error defaultlib 'MSVCRT' conflicts with use of other libs; use /NODEFAULTLIB:library
					  // Since we are not dynamic linking we need this

//#include <GLFW\include\glfw3.h>
//#include <Dependencies/GLFW/include/glfw3.h>
//#include <GLFW/glfw3.h>
#include <../Dependencies/GLEW/include/GL/glew.h>
#include <../Dependencies/GLFW/include/GLFW/glfw3.h>
//#include <glofw3.h>

#include <stdio.h>  /* defines FILENAME_MAX */
// #define WINDOWS  /* uncomment this line to use it for windows.*/ 
#include <direct.h>
#define GetCurrentDir _getcwd
#include<iostream>
 
std::string GetCurrentWorkingDir( void ) {
  char buff[FILENAME_MAX];
  GetCurrentDir( buff, FILENAME_MAX );
  std::string current_working_dir(buff);
  return current_working_dir;
}

int main(void)
{
	std::cout << "Path:" << GetCurrentWorkingDir() << std::endl;
	
	
	
	GLFWwindow* window;

	// Initialize the library
	if (!glfwInit())
		return -1;
	
	// Create a windowed mode window and its OpenGL context 
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}
	
	// Make the window's context current 
	glfwMakeContextCurrent(window);

	// We need to call glewInit after we have a valid context
	if(glewInit() != GLEW_OK)
		std::cout << "Error !GLEW_OK" << std::endl;
	
	std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;

	// Loop until the user closes the window 
	while (!glfwWindowShouldClose(window))
	{
		// Render here 
		glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();

		// Swap front and back buffers 
		glfwSwapBuffers(window);

		// Poll for and process events 
		glfwPollEvents();
	}

	glfwTerminate();
	
	
	return 0;
}