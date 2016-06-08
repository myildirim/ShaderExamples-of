#version 150

uniform sampler2D textureArray[3];

in vec4 colorVarying;
out vec4 outputColor;

in mat2 rotn;
in vec2 corner;
in float type;
in float alpha;

void main()
{
    vec2 p_centre = vec2(0.5, 0.5);
    vec2 rot_coord = rotn * (gl_PointCoord - p_centre) + p_centre;
    vec4 texc;
    int imgType = int(type);
    
    if(imgType  == 0){
        texc = texture(textureArray[0], (rot_coord + corner));
    } else if(imgType  == 1) {
        texc = texture(textureArray[1], (rot_coord + corner));
    } else if(imgType  == 2) {
        texc = texture(textureArray[2], (rot_coord + corner));
  }
    //    texc = texture(texture3, (rot_coord + corner));
    
    outputColor = texc;
    outputColor.a = alpha;
}
