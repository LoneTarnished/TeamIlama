#include "Debugger.hpp"

Debugger::Debugger() {

}


void APIENTRY Debugger::OpenGLDebugCallback(GLenum source,
								  GLenum type,
								  GLuint id,
								  GLenum severity,
								  GLsizei length,
								  const GLchar *message,
								  const GLvoid *userParam)
{

	cout << "ERROR - OpenGL: " << endl;
	cout << "Message: " << message << endl;
	cout << "type: ";
	switch (type)
	{
		case GL_DEBUG_TYPE_ERROR: cout << "ERROR"; break;
		case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: cout << "DEPRECATED_BEHAVIOR"; break;
		case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR: cout << "UNDEFINED_BEHAVIOR"; break;
		case GL_DEBUG_TYPE_PORTABILITY: cout << "PORTABILITY"; break;
		case GL_DEBUG_TYPE_PERFORMANCE: cout << "PERFORMANCE"; break;
		case GL_DEBUG_TYPE_OTHER: cout << "OTHER"; break;
	}
	cout << "id: " << id << " --- ";
	cout << "severity: ";
	switch (severity)
	{
		case GL_DEBUG_SEVERITY_LOW: cout << "LOW"; break;
		case GL_DEBUG_SEVERITY_MEDIUM: cout << "MEDIUM"; break;
		case GL_DEBUG_SEVERITY_HIGH: cout << "HIGH"; break;
		case GL_DEBUG_SEVERITY_NOTIFICATION: cout << "NOTIFICATION";
	}
	cout << endl;
}

void Debugger::GlGetError(GLenum errorCode, const char *file, int line)
{
	auto error = "UNKNOWN"s;
	switch (errorCode)
		{
			case GL_INVALID_ENUM: error = "INVALID_ENUM"s; break;
			case GL_INVALID_VALUE: error = "INVALID_VALUE"s; break;
			case GL_INVALID_OPERATION: error = "INVALID_OPERATION"s; break;
			case GL_STACK_OVERFLOW: error = "STACK_OVERFLOW"s; break;
			case GL_STACK_UNDERFLOW: error = "STACK_UNDERFLOW"s; break;
			case GL_OUT_OF_MEMORY: error = "OUT_OF_MEMORY"s; break;
			case GL_INVALID_FRAMEBUFFER_OPERATION: error = "INVALID_FRAMEBUFFER_OPERATION"s; break;
		}
	std::cout << "ERROR - OpenGL: " << error << " - source file: " << file << " (Code line: " << line << ")" << std::endl;
}


Debugger::~Debugger(){
	
}


