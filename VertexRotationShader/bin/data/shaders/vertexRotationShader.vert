#version 150

uniform mat4 modelViewProjectionMatrix;
uniform mat4 textureMatrix;

in vec4 position;
in vec3 normal;
in vec4 color;
in vec2 texcoord;

out vec4 colorVarying;

out mat2 rotn;
out vec2 corner;
out float type;
out float alpha;

void main(){
    colorVarying = color;
    gl_Position = modelViewProjectionMatrix * position;
    gl_PointSize = normal[1];

    rotn = mat2(cos(normal[0]), sin(normal[0]),
                -sin(normal[0]), cos(normal[0]));
    corner = texcoord;
    type = normal[2];
    alpha = color.a;
}

