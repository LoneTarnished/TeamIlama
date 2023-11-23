// 3D Graphics and Animation - Debugger Template
// Does error checking for OpenGL.

#pragma once


#define GL_SILENCE_DEPRECATION
#include <glad/glad.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;


class Debugger{
	public:
		Debugger();
	
		void APIENTRY OpenGLDebugCallback(GLenum source,
								  GLenum type,
								  GLuint id,
								  GLenum severity,
								  GLsizei length,
								  const GLchar *message,
								  const GLvoid *userParam);		

		virtual ~Debugger();

		void GlGetError(GLenum errorCode, const char *file, int line);

	protected:

	private:

		

};