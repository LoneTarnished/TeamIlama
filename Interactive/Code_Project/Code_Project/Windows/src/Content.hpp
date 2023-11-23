#pragma once

#define GL_SILENCE_DEPRECATION
#include <glad/glad.h>

#include <tinygltf/tiny_gltf.h> // Model loading library - tiny gltf - https://github.com/syoyo/tinygltf
using namespace tinygltf;

#include <string>
#include <iostream>
#include <vector>
using namespace std;

#define BUFFER_OFFSET(i) ((char *)NULL + (i))

class Content {
	public:
		Content();

		pair<GLuint, std::map<int, GLuint>> vaoAndEbos;
		Model model;

		void LoadGLTF(string filename);
		void DrawModel(const pair<GLuint, map<int, GLuint>> &vaoAndEbos, Model &model);
		void UseTexture();

	virtual ~Content();
	protected:

	private:

		// Loading
		pair<GLuint, map<int, GLuint>> BindModel(Model &model);
		void BindModelNodes(map<int, GLuint> &vbos, Model &model, Node &node);
		void BindMesh(map<int, GLuint> &vbos, Model &model, Mesh &mesh);


		// Drawing
		
		void DrawModelNodes(const pair<GLuint, map<int, GLuint>> &vaoAndEbos, Model &model, Node &node);
		void DrawMesh(const map<int, GLuint> &vbos, Model &model, Mesh &mesh);

private:
		GLuint textureID;
};	