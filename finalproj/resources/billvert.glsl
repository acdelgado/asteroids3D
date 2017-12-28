#version  450 core
layout(location = 0) in vec4 vertPos;
layout(location = 2) in vec2 vertTex;

uniform mat4 P;
uniform mat4 V;
uniform vec3 vpws;
out vec2 fragTex;
out vec3 pos;
uniform sampler2D tex;

void main()
{
vec3 CameraRight = vec3(V[0][0], V[1][0], V[2][0]);
vec3 CameraUp = vec3(V[0][1], V[1][1], V[2][1]);
vec3 npos = vpws + CameraRight * vertPos.x * 20 + CameraUp * vertPos.y * 20;
vec4 nvp = vec4(npos.x,npos.y,npos.z,1);
gl_Position = P * V * nvp;
fragTex = vertTex;	
}
