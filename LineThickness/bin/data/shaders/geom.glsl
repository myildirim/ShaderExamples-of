#version 150

uniform float thickness;

layout(lines) in;
layout(triangle_strip, max_vertices = 4) out;

in vec3 vNormal[];

void main() {
    vec3 p0 = gl_in[0].gl_Position.xyz;
    vec3 n0 = vNormal[0];
    vec3 p1 = gl_in[1].gl_Position.xyz;
    vec3 n1 = vNormal[1];

    gl_Position = gl_in[0].gl_Position + (vec4(-n0.x, n0.y, 0.0, 0.0)*thickness);
    EmitVertex();

    gl_Position = gl_in[0].gl_Position - (vec4(-n0.x, n0.y, 0.0, 0.0)*thickness);
    EmitVertex();

    gl_Position = gl_in[1].gl_Position + (vec4(-n1.x, n1.y, 0.0, 0.0)*thickness);
    EmitVertex();

    gl_Position = gl_in[1].gl_Position - (vec4(-n1.x, n1.y, 0.0, 0.0)*thickness);
    EmitVertex();

    EndPrimitive();
}
