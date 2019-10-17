#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>  /* defines FILENAME_MAX */
#include <direct.h>				// This is to print working dir
#define GetCurrentDir _getcwd	// This is to print working dir

#define GLEW_STATIC 1 // Removes error defaultlib 'MSVCRT' conflicts with use of other libs; use /NODEFAULTLIB:library
					  // Since we are not dynamic linking we need this

#include <../Dependencies/GLEW/include/GL/glew.h>     // Needed for GL_VERSION and glGetString
#include <../Dependencies/GLFW/include/GLFW/glfw3.h>  // Needed for the Create and Compile shader functions

#include<iostream> // Used for cout
#include <fstream> // Used to read in from a file
#include <string>  // used for getline
#include <sstream> // Used for  string stream. Add the strings that we"re reading into a buffer
class Utils
{
 public:

    Utils(){};
	
	// Here we are actuall giving the code to the GPU in the form of stringstream
	// Provide openGL with our shader source code, we want opengl to compile that program
	// then like these two together into a single shader program and give us a unique id back for that shader
	// so that we can bind that shader and use it.
	// Returns a program represented as an unsigned int
	static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	
	// Get the id, specify the source code and compile the shader
	// returns the id for the shader
	static unsigned int CompileShader(unsigned int type, const std::string& source);

	// Used to return 2 variables in the ParseShader function
	struct ShaderProgramSource
	{
		std::string VertexSource;
		std::string FragmentSource;
	};

	// Parse a shader from a file
	ShaderProgramSource ParseShader(const std::string& filepath);

	// return a Vertex shader in the form of a string
	std::string getVertexShaderString();
	
	// returns a Fragment shader in the form of a string
	std::string getFragmentShaderString();
	
	/////////////////////////////////////////////////////
	// General utility functions
	///////////////////////////////////////////////////

    // This function is used by printWorkingDir
	std::string GetCurrentWorkingDir( void );

	// This prints the current openGL version
	// This must be called after glewInit()
	// And glewInit must be called after glfwMakeContextCurrent
	void printOpenGLVersion();
	
	// Print what cmake sees as the working directory from which to include files
	void printWorkingDir();
	
private:


};

#endif // UTILS_H