#version 150
uniform mat4 textureMatrix;
uniform mat4 modelViewProjectionMatrix;

in vec4  position;
in vec2  texcoord;
in vec4  color;
in vec3  normal;
in float pointsize;

out vec4 colorVarying;
out vec2 texCoordVarying;
out vec4 normalVarying;

void main()
{
    gl_PointSize = pointsize;
    colorVarying = color;
    texCoordVarying = (textureMatrix*vec4(texcoord.x,texcoord.y,0,1)).xy;
    gl_Position = modelViewProjectionMatrix * position;
}
