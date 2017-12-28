#version 330 core 
out vec4 color;
in vec3 pos;
in vec2 fragTex;


uniform sampler2D tex;
uniform vec2 offset;


void main()
{
	
	color = texture(tex, vec2(-fragTex.x/10+(offset.x-0.01),fragTex.y/10+(offset.y-0.01)));
	color.a= (color.r + color.g + color.b)/3.0;
	
}
