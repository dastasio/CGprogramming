#version 400 core
in vec3 vPosition;
in vec3 vColor;
out vec3 color;

void main() {
	gl_Position = vec4(vPosition.xyz, 1.0);
	color = vec3( vColor);
}
