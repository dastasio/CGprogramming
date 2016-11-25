#version 400 core
in vec4 vPosition;
out vec4 color;

void main() {
	color = vec4( 0.0, (1.0 + vPosition.z)/2.0 + 0.2, 0.0, 1.0);
	gl_Position = vPosition;
}
