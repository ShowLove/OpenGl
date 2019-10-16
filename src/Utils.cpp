#include "Utils.h"

std::string Utils::GetCurrentWorkingDir( void ) {
  char buff[FILENAME_MAX];
  GetCurrentDir( buff, FILENAME_MAX );
  std::string current_working_dir(buff);
  return current_working_dir;
}

void Utils::printOpenGLVersion() {
	// This must be called after glewInit()
	// And glewInit must be called after glfwMakeContextCurrent
	std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
}

void Utils::printWorkingDir() {
	std::cout << "Path:" << GetCurrentWorkingDir() << std::endl;
}
