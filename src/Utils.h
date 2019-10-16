#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>  /* defines FILENAME_MAX */
#include <direct.h>				// This is to print working dir
#define GetCurrentDir _getcwd	// This is to print working dir

// Needed for GL_VERSION and glGetString
#include <../Dependencies/GLEW/include/GL/glew.h>

#include<iostream>

class Utils
{
 public:

    Utils(){};

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