#version 150

uniform sampler2D textureArray[3];

in vec4 colorVarying;
in mat2 angle;
in vec2 corner;
in float type;
in float alpha;

out vec4 outputColor;

void main()
{
    int imgType = int(type); // can't pass int to fragment shader

    vec2 pCenter = vec2(0.5, 0.5);
    vec2 rotCoord = angle * (gl_PointCoord - pCenter) + pCenter;
    vec2 rotatedTexCoord = (rotCoord + corner);

    vec4 texCoord;
    // not possible to iterate over arrays in version 150
    if(imgType  == 0){
        texCoord = texture(textureArray[0], rotatedTexCoord);
    } else if(imgType  == 1) {
        texCoord = texture(textureArray[1], rotatedTexCoord);
    } else if(imgType  == 2) {
        texCoord = texture(textureArray[2], rotatedTexCoord);
    }
    
    outputColor = texCoord;
    outputColor.a = alpha;
}
