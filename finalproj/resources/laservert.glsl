#version  450 core
layout(location = 0) in vec4 vertPos;
uniform mat4 P;
uniform mat4 M;
uniform mat4 V;
out vec3 pos;
out vec3 globePos;

void main()
{
pos=vertPos.xyz;
	gl_Position = P * V * M * vertPos;
	globePos = gl_Position.xyz;
}
