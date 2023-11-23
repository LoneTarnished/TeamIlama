The individual contributions are listed here.

Spandan Rivoncar

1. Exported the room as a glTF 2.0 format.
2. Applied all modifiers before combining the entire room.
3. Created a UV map.
4. Used the shading tab to bake.
5. created an image texture for every colour slot.
6. selected the UV map and image textures then proceeded to Render settings.
7. under bake settings used cycles engine and bake type as diffuse.
8. clicked bake.
9. exported to openGl.

Chris Moore

As all of the parts of the doraemon were separated and mirrored on to the reflecting side, I had to go into each piece of the model and change the mirror settings to then enable me to join all the parts together as one object.
Once combined, I then created a new uv map and used the shading tool to change the materials from individual into a single material that could be saved as a texture map and used in opengl.
After the setup, I changed the render to cycles and edited the bake options to only include colour. Then I clicked bake.
After baking the texture, I saved it and then in the shader I linked up the image texture to the base colour.
Last step was to export it in gltf format, with the gltf, bin and textures separate and then send it over to Leon to import into opengl.
