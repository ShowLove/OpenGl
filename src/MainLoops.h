#ifndef MAIN_LOOPS_H
#define MAIN_LOOPS_H

#define GLEW_STATIC 1 // Removes error defaultlib 'MSVCRT' conflicts with use of other libs; use /NODEFAULTLIB:library
					  // Since we are not dynamic linking we need this

// Library dependencies included by cmake
#include <../Dependencies/GLEW/include/GL/glew.h>
#include <../Dependencies/GLFW/include/GLFW/glfw3.h>

#include<iostream>

class MainLoops
{
 public:
    MainLoops(){ };
	
	// Drwaws triangle using calls from opengl 1.1
	// Returns true if successfull, false otherwise
	bool legacyTriangle();
	
private:

};

#endif // MAIN_LOOPS_H