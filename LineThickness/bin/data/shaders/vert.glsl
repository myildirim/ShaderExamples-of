// vertex shader

#version 150

uniform mat4 modelViewProjectionMatrix;
uniform mat4 modelViewMatrix;

in vec4 position;
in vec3 normal;
out vec3 vNormal;

void main(){
    vNormal = normal.xyz;
    gl_Position = modelViewProjectionMatrix * position;
}
