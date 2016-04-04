#version 120

// All pixels have the same color.
uniform vec4 color;

void main()
{
	// Output color = color.
	gl_FragColor = color;
}
