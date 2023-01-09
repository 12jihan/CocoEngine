#version 330 core
// Poisition/Coordinates
layout (location = 0) in vec3 aPos;
// Colors
layout (location = 1) in vec3 aColor;
// Textures
layout (location = 2) in vec2 aTex;

// outputs the color for the fragment shader
out vec3 color;

// outputs the texture for the fragment shader
out vec2 texCoord;

// controls the scale of the fragment shader
uniform float scale;

void main()
{
   // outputs the positions/coordinates of all vertices
   gl_Position = vec4(aPos.x + aPos.x * scale, aPos.y + aPos.y * scale, aPos.z + aPos.z * scale, 1.0);
   // assigns the colors from the vertex data to "color"
   color = aColor;
   // exports the texture coordinates from the vertex data
   texCoord = aTex;
}