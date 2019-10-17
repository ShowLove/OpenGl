#include "MainLoops.h"
#include "Utils.h"

const float MainLoops::m_Possitions[MainLoops::m_NumVerticies] = {		 // how big the size is of the array that holds our verticies
	-0.5f, -0.5f,
	-0.0f,  0.5f,
	 0.5f, -0.5f,
};

bool MainLoops::modernOpenGLTriangle() {

	Utils utils;

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
	
	int indexStartV = 0;  // If we wanted to start with the second vertecies it would be 1 used in glDrawArrays
	int numVToBeRedered = 3; // For us Indecies is vertecies we have three points in the triange we are drawing
	int sizeOfBufferMemory = (m_NumVerticies * sizeof(float));
	
	int numBuffers = 1;  // The number of buffers we want to use 
	unsigned int buffer; // We will write into this buffers memory address, 
						 // this is the id of the generated buffer
	 
	// Generate a buffer and give us back an ID for it
	glGenBuffers(numBuffers, &buffer);
	// Select the buffer we have just generated (binding)
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	// Now we need to put data into that buffer
	// We know to use GL_STATIC_DRAW and that 2nd param is in bytes from documentation
	glBufferData(GL_ARRAY_BUFFER, sizeOfBufferMemory, m_Possitions, GL_STATIC_DRAW);
	// We've given opengl data now we need to tell it what kind of data it is. 
	// E.g we've given 3 vertecies, they're floats, we've given 2 vertex m_Possitions per vertex
	// We'd do that using glVertexAttributePointer if we were using shaders
	
	// We only have one vertex attribue, m_Possitions
	int indexVAP = 0;  // this is the first attribute
	int sizeVAP  = 2;  // There ate two points per vertex
	// the type of the data is floats
	// do we want them to be normalized ?  that is if the colors were b/w 0 255 would we want it to be b/w 0 1? 
	int strideVAP = (sizeof(float) * 2);  // How much we have to go forward to get to the second vertex (not the second attribute)
	const void* attributeNumber =  0;     // This is a pointer (which is just number) representing the attribute since we only have 1, pass 0: first attribute
										  // If offset was 8 we'd do (const void*) 8 as the parameter
	glVertexAttribPointer(indexVAP, sizeVAP, GL_FLOAT, GL_FALSE, strideVAP, attributeNumber);
	
	// Now we need to enable this vertex attribute (you could call this above glVertexAttribPointer since opengl is a state machine
	glEnableVertexAttribArray(indexVAP);
	
	// This still works without a shader because the GPU provides a default shader
	// A shader is code that's run on our GPU, usually (vertex shader then fragment shader)
	// Vertex shader will get called once for each vertex, inour case 3 times for each point in the triangle
	// Fragment shader (pixel shader) runs once for each pixel that needs to get rasterized, decides which color for each pixel
	
	// Create the shader using string functions
	//std::string vertexShader = utils.getVertexShaderString();
	//std::string fragmentShader = utils.getFragmentShaderString();
	//unsigned int shader = utils.CreateShader(vertexShader, fragmentShader);
	
	// Create a shader from a filebuffer
	Utils::ShaderProgramSource source = utils.ParseShader("../res/shaders/basic.shader");
	unsigned int shader = utils.CreateShader(source.VertexSource, source.FragmentSource);
	
	// Bind our shader
	glUseProgram(shader);
	
	// Loop until the user closes the window 
	while (!glfwWindowShouldClose(window))
	{
		// Render here 
		glClear(GL_COLOR_BUFFER_BIT);

        // main draw call, we did using openg 1.1 in legacy function
		// but here we use modern opengl
		// Since we do not have an index buffer we use this
		// If we had an index buffer we would use glDrawElements(GL_TRIANGLES, 3, null)
		
		glDrawArrays(GL_TRIANGLES, indexStartV, numVToBeRedered);

		// Swap front and back buffers 
		glfwSwapBuffers(window);

		// Poll for and process events 
		glfwPollEvents();
	}
	
	//clean up
	glDeleteProgram(shader);

	glfwTerminate();
	
	return true;

}  //end modernOpenGLTriangle

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
		
		// Modern opengl would put this in a buffer,
		// send it to opengl vram, and later issue a draw call
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