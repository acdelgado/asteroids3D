#version 330 core 
out vec4 color;
in vec3 pos;
in vec2 fragTex;


uniform sampler2D tex;
uniform vec2 offset;


void main()
{
	
	color = texture(tex, vec2(fragTex.x/5+offset.x,fragTex.y/5+offset.y));
	color.a= (color.r + color.g + color.b)/3.0;
	
}
