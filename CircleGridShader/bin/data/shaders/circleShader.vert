#version 150
uniform mat4 textureMatrix;
uniform mat4 modelViewProjectionMatrix;

in vec4  position;
in vec4  color;
in float pointsize;

out vec4 colorVarying;

void main()
{
    gl_PointSize = pointsize;
    colorVarying = color;
    gl_Position = modelViewProjectionMatrix * position;
}
