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
	
	// Draws a box in open gl wihtout an index
	// Returns true if successfull, false otherwise
	bool openGLBox();
	
 private:

	// These values will draw us a triangle
	static const int m_NumVerticies = 6;	// The number of verticies actuall there are 3 with two points on each
	const static float m_Possitions[]; 		// Array holding our 3 (2d) possitions used in modernOpenGLTriangle
	
	// These values will draw a square
	static const int m_NumVerticiesBox = 12;	// The number of verticies actuall there are 6 with two points on each
	const static float m_BoxPossitions[]; 		// Array holding our 6 (2d) possitions used in openGLBox
};

#endif // MAIN_LOOPS_H