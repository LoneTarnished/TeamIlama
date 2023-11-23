#version 410 core

layout (location = 0) in vec3 in_vertex;
layout (location = 1) in vec3 in_normals;
layout (location = 2) in vec2 in_tc;

out VS_OUT
{
    vec3 vertex;
    vec3 normals;
    vec2 tc;
} vs_out;

uniform mat4 model_matrix;
uniform mat4 view_matrix;
uniform mat4 proj_matrix;

void main(void)
{
    gl_Position = proj_matrix * view_matrix * model_matrix * vec4(in_vertex, 1.0);

    vs_out.vertex = in_vertex;
    vs_out.normals = in_normals;
    vs_out.tc = in_tc;
}
