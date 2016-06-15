#version 150
// based on https://stackoverflow.com/questions/9609423/applying-part-of-a-texture-sprite-sheet-texture-map-to-a-point-sprite-in-ios

uniform sampler2D textureIn;

in vec2 textureCoord;
in vec2 textureSize;

out vec4 outColor;

void main(void)
{
    vec2 realTexCoord = textureCoord + (gl_PointCoord * textureSize);
    vec4 fragColor = texture(textureIn, realTexCoord);

    if(fragColor.a == 0.0){
        discard;
    }

    outColor = fragColor;
}


