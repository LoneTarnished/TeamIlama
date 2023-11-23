Models loading


The models are modelled using Blender and exported to the gltf format, which is essentially a JSON file. It describes an entire 3D scene, such as how many meshes a model uses, the rotation and displacement of the meshes and other information. Then, the vertex data, including vertex coordinates, normals, texture coordinates and, if the model has a texture map, the corresponding texture object needs to be created, is loaded and parsed in the program using the tinygltf library. Once these data are obtained, they can be used to populate OpenGL's VBO, EBO, assign vertex properties and finally draw. However, I have failed to export the desk and the sky wheel in former works. Eventhough I have spent some time to figure out the problem, I can not find the solution.

Scene building


The scene is composed by loading different models with multiple Content objects, scaling, rotating and panning them to get the right size and position, and assembling them into a simple, life-like scene.

Shaders and lighting


The objects in the scene that have textures are the floor,the Shinigami, the rem, the SpandanAnimeRoom and the Seedot. The entire application uses only one Vertex Shader and one Fragment Shader. Fragment implements the Lambertian Diffuse and Blinn-Phong lighting models, enabling the mixing of multiple light sources (one point source and three spotlights).

Interaction


Camera: The exploraion camera used in the program can be controlled by "W,S,A,D" keys to move the camera forward and backward, left and right, and "Q,E" keys to lift and lower. You can rotate the view by dragging the mouse while holding down the right mouse button. The FOV of the camera can be modified by using the mouse wheel keys.
dog: Left and right keys can control the dog to rotate, up and down keys can control the dog to move forward in the direction of rotation.
Light: "1,2,3" keys can change the colour of lights
