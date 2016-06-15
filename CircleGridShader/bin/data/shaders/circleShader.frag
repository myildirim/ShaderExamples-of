#version 150
out vec4 fragColor;

uniform sampler2D src_tex_unit0;
in vec4 colorVarying;

void main(){
    fragColor = texture(src_tex_unit0, gl_PointCoord) * colorVarying;
}
