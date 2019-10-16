#ifndef MAIN_LOOPS_H
#define MAIN_LOOPS_H

#define GLEW_STATIC 1 // Removes error defaultlib 'MSVCRT' conflicts with use of other libs; use /NODEFAULTLIB:library
					  // Since we are not dynamic linking we need this

// Library dependencies included by cmake
// myTODO revisit if I want to change cmake to make these paths a bit cleaner
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
	
	// Draws triangle using modern opengl
	// Returns true if successfull, false otherwise
	bool modernOpenGLTriangle();
	
 private:

	static const int m_NumVerticies = 6;
	const static float m_Possitions[];
};

#endif // MAIN_LOOPS_H