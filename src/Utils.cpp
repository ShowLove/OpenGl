#include "Utils.h"

// myTODO create a namespace for all of these classes

unsigned int Utils::CompileShader(unsigned int type, const std::string& source) {
	
	// myTODO error check that this is a valid string
	
	// get an ID for the shader
	unsigned int id = glCreateShader(type);
	
	// Specify the source for the shader
	int count = 1; 	// How many source codes do we want
	const char* src = source.c_str();
	// (nulptr) If length is NULL, each string is assumed to be null terminated
	glShaderSource(id, count, &src, nullptr);
	
	// Compile the shader
	glCompileShader(id);


	// Shader error handling, make sure everything worked correctly
	int result; // i v : i: integer v: vector
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if(!result) {
			int length;
			glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
			// cant dynamically define array 
			char* message = (char*) alloca(length * sizeof(char)); // This is a function that allows you to allocate on the stack dynamically
			glGetShaderInfoLog(id, length, &length, message);
			std::cout << "Errror shader did not compile: " << (type == GL_VERTEX_SHADER ?  "VERTEX" : "RFAGMENT")  << " shader" << std::endl; 
			std::cout << message << std::endl;
			
			// handle error
			glDeleteShader(id);
			return 0;
	}
		
	return id;
}


unsigned int Utils::CreateShader(const std::string& vertexShader, const std::string& fragmentShader) {
	
	// this function is similar to when we Generate a buffer and it gives us back an ID for it via glGenBuffers
	unsigned int program = glCreateProgram();
	
	// Now we create our two shader objects vertex and fragment shader
	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);
	
	// Now we need to attach both of these shaders to our program
	// Think of it like to files being linked into one program
	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);
	
	
	// Shaders have been linked to a program so we can delete the intermediates
	glDeleteShader(vs);
	glDeleteShader(fs);
	
	// Technically you should use glDetachShader after shaders have been linked to a program
	// But we will only do this, because sometimes it's good to keep the source code for debugging
	return program;
}

Utils::ShaderProgramSource Utils::ParseShader(const std::string& filepath)
{
	std::ifstream stream(filepath);
	
	// Keep track of the mode vertex or fragment
	enum class ShaderType
	{
		NONE = -1, VERTEX = 0, FRAGMENT = 1
	};
	
	// Go through file line by line and check which shader we are at
	// Current format of the file is #shader vertex/fragment to indicate a new shader
	
	std::string line;
	std::stringstream ss[2]; // one for vertex and one for fragment
	ShaderType type = ShaderType::NONE; // current shader mode
	while(getline(stream,line)) {
		
		// Check to see if this is a mode line teling us vertex or fragment
		if (line.find("#shader") != std::string::npos) {
				if (line.find("vertex") != std::string::npos) {
					// Set mode for vertex
					type = ShaderType::VERTEX;	
				} 
				else if (line.find("fragment") != std::string::npos) {
					// set mode for fragment
					type = ShaderType::FRAGMENT;
				}
				
		} // It's not a mode line process for either vertex or fragment
		else {
				ss[(int)type] << line << "\n";
		}
	}
	
	// Return the vertex and the fragment string
	return { ss[0].str(), ss[1].str() };
}

std::string Utils::getVertexShaderString()
{
	// line 1 means: we're using glsl (gl shading language version 330) core -> we can't use any depricated functions
	// How you access the attribute pointer that has two points per vertex and starts at index 0 (glVertexAttribPointer) ? layout(location =0) in vec4 position;
	// we use vec4 instead of vec2 because opengl will convert it for us
	std::string vertexShader = 
	"#version 330 core\n"
	"\n"
	"layout(location = 0) in vec4 position;\n"
	"\n"
	"void main()\n"
	"{\n"
	"	gl_Position = position;\n"
	"}\n";
	
	return vertexShader;
}

std::string Utils::getFragmentShaderString()
{
	// line 1 means: we're using glsl (gl shading language version 330) core -> we can't use any depricated functions
	// How you access the attribute pointer that has two points per vertex and starts at index 0 (glVertexAttribPointer) ? layout(location =0) in vec4 position;
	// we use vec4 instead of vec2 because opengl will convert it for us
	// here 0 is white and 255 is 1, vec4(r, g, b, a) 
	std::string fragmentShader = 
	"#version 330 core\n"
	"\n"
	"layout(location = 0) out vec4 color;\n"
	"\n"
	"void main()\n"
	"{\n"
	"	color = vec4(0.0, 0.0, 1.0, 1.0);\n"
	"}\n";
	
	return fragmentShader;
}


/////////////////////////////////////////
// General utility functions
////////////////////////////////////////

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
