#version 150

out vec4 outputColor;
uniform float u_Time;
uniform vec2 u_resolution;
uniform float u_ATime;


void main()
{

vec2 UV = gl_FragCoord / u_resolution;


	outputColor = vec4(vec3(uv.x),1.0);


}