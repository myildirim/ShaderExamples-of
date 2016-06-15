#version 150

uniform mat4 modelViewProjectionMatrix;
uniform mat4 textureMatrix;

in vec4 position;
in vec3 normal;
in vec4 color;
in vec2 texcoord;

out vec4 colorVarying;

out mat2 angle;
out vec2 corner;
out float type;
out float alpha;

void main(){
    colorVarying = color;
    gl_Position = modelViewProjectionMatrix * position;

    // normal[0] is the angle
    angle = mat2(cos(normal[0]), sin(normal[0]),
                -sin(normal[0]), cos(normal[0]));

    // normal[1] is the size
    gl_PointSize = normal[1];

    // normal[2] is the type
    type = normal[2];

    corner = texcoord;
    alpha = color.a;
}

