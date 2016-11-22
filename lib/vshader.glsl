in vec2 vPosition;
in vec3 vColor;
out vec3 color;

void main() {
	gl_Position = vec4( vPosition.xy, 0.0, 1.0);
	color = vec3( vColor);
}
