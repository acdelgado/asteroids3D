#version 450 core 

out vec4 color;

in vec3 pos;
in vec2 fragTex;
in vec3 fragNor;

uniform vec3 campos;

layout(location = 0) uniform sampler2D tex;

void main()
{
	vec3 normal = normalize(fragNor);

	vec3 lp = vec3(1000,1000,1000);
	vec3 ld = normalize(lp - pos);
	float light = dot(ld,normal);	
	light = clamp(light,0,1);

	vec3 camvec = normalize(campos - pos);
	vec3 h = normalize(camvec+ld);
	float spec = pow(dot(h,normal),20);
	spec = clamp(spec,0,1);
	
	color = texture(tex,fragTex) * light + vec4(1,1,1,1)*spec;
	color.a=1;
}
