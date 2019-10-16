#include "MainLoops.h"

bool MainLoops::legacyTriangle() {	

	GLFWwindow* window;

	// Initialize the library
	if (!glfwInit()) {
		std::cout << "Error could not init glfw" << std::endl;
		return false;
	}
	
	// Create a windowed mode window and its OpenGL context 
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window) {
		glfwTerminate();
		std::cout << "Error could not create a window" << std::endl;
		return false;
	}
	
	// Make the window's context current 
	glfwMakeContextCurrent(window);

	// We need to call glewInit after we have a valid context
	if(glewInit() != GLEW_OK) {
		std::cout << "Error !GLEW_OK" << std::endl;
		return false;
	}

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
	
	return true;

}  //end legacyTriangle