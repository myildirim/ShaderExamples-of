#version 150
in vec2 TextureCoord;
in vec2 TextureSize;
uniform sampler2D Sampler;

out vec4 outColor;

void main(void)
{
    // This is where the magic happens.  Combine all three factors to render
    // just a portion of the sprite-sheet for this point
    vec2 realTexCoord = TextureCoord + (gl_PointCoord * TextureSize);
    vec4 fragColor = texture(Sampler, realTexCoord);

    // Optional, emulate GL_ALPHA_TEST to use transparent images with
    // point sprites without worrying about z-order.
    // see: http://stackoverflow.com/a/5985195/806988
    if(fragColor.a == 0.0){
        discard;
    }

    outColor = fragColor;
}


// based on https://stackoverflow.com/questions/9609423/applying-part-of-a-texture-sprite-sheet-texture-map-to-a-point-sprite-in-ios
