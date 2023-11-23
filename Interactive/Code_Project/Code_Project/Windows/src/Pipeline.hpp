// 3D Graphics and Animation - Pipeline Template
// Create a program and attach shaders.

#pragma once


#define GL_SILENCE_DEPRECATION
#include <glad/glad.h>

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#define GLM_ENABLE_EXPERIMENTAL	 // Enable all functions include non LTS
#include <glm/glm.hpp>			 // Add helper maths library - GLM 0.9.9.9 - https://github.com/g-truc/glm - for example variables vec3, mat and operators.
#include <glm/gtx/transform.hpp> // Help us with transforms

 struct Pipe{
	public:
		GLuint program;										// Pipeline reference
		std::string vsName = "";								// name of file for vertex shader
		std::string fsName = "";								// name of file for fragment shader
		bool error = false;									// Flag any errors.
	private:

 };

class Pipeline{
	public:
		Pipeline();
	
		Pipe pipe;											// Save all information.

		void CreatePipeline();								// Create OpenGL Pipeline Program
		void LoadShaders(std::string vs, std::string fs);				// Load shaders using files		
		void ReloadShaders();								// Reload Shaders for debugging...			

		virtual ~Pipeline();

		// utility uniform functions
   // ------------------------------------------------------------------------
		void setBool(const std::string& name, bool value) const
		{
			glUniform1i(glGetUniformLocation(pipe.program, name.c_str()), (int)value);
		}
		// ------------------------------------------------------------------------
		void setInt(const std::string& name, int value) const
		{
			glUniform1i(glGetUniformLocation(pipe.program, name.c_str()), value);
		}
		// ------------------------------------------------------------------------
		void setFloat(const std::string& name, float value) const
		{
			glUniform1f(glGetUniformLocation(pipe.program, name.c_str()), value);
		}
		// ------------------------------------------------------------------------
		void setVec2(const std::string& name, const glm::vec2& value) const
		{
			glUniform2fv(glGetUniformLocation(pipe.program, name.c_str()), 1, &value[0]);
		}
		void setVec2(const std::string& name, float x, float y) const
		{
			glUniform2f(glGetUniformLocation(pipe.program, name.c_str()), x, y);
		}
		// ------------------------------------------------------------------------
		void setVec3(const std::string& name, const glm::vec3& value) const
		{
			glUniform3fv(glGetUniformLocation(pipe.program, name.c_str()), 1, &value[0]);
		}
		void setVec3(const std::string& name, float x, float y, float z) const
		{
			glUniform3f(glGetUniformLocation(pipe.program, name.c_str()), x, y, z);
		}
		// ------------------------------------------------------------------------
		void setVec4(const std::string& name, const glm::vec4& value) const
		{
			glUniform4fv(glGetUniformLocation(pipe.program, name.c_str()), 1, &value[0]);
		}
		void setVec4(const std::string& name, float x, float y, float z, float w)
		{
			glUniform4f(glGetUniformLocation(pipe.program, name.c_str()), x, y, z, w);
		}
		// ------------------------------------------------------------------------
		void setMat2(const std::string& name, const glm::mat2& mat) const
		{
			glUniformMatrix2fv(glGetUniformLocation(pipe.program, name.c_str()), 1, GL_FALSE, &mat[0][0]);
		}
		// ------------------------------------------------------------------------
		void setMat3(const std::string& name, const glm::mat3& mat) const
		{
			glUniformMatrix3fv(glGetUniformLocation(pipe.program, name.c_str()), 1, GL_FALSE, &mat[0][0]);
		}
		// ------------------------------------------------------------------------
		void setMat4(const std::string& name, const glm::mat4& mat) const
		{
			glUniformMatrix4fv(glGetUniformLocation(pipe.program, name.c_str()), 1, GL_FALSE, &mat[0][0]);
		}

	protected:

	private:
		std::string ReadShader(std::string name);
		void CheckErrorShader(GLuint shader, std::string name);
		void CheckErrorLinking();
};