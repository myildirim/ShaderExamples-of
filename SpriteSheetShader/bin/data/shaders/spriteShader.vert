#version 150
uniform mat4 modelViewProjectionMatrix;
uniform mat4 textureMatrix;

uniform mat4 Projection;
uniform mat4 Modelview;
// The radius of the point in OpenGL units, eg: "20.0"
uniform float PointSize;
// The size of the sprite being rendered. My sprites are square
// so I'm just passing in a float.  For non-square sprites pass in
// the width and height as a vec2.
uniform vec2 TextureCoordPointSize;
uniform vec2 TextureCoordIn;

in vec4 Position;
in vec4 ObjectCenter;
// The top left corner of a given sprite in the sprite-sheet
//in vec2 TextureCoordIn;

out vec2 TextureCoord;
out vec2 TextureSize;

void main(void)
{
    gl_Position = modelViewProjectionMatrix * Position;
    TextureCoord = TextureCoordIn;
    TextureSize = vec2(TextureCoordPointSize.x, TextureCoordPointSize.y);

    // This is optional, it is a quick and dirty way to make the points stay the same
    // size on the screen regardless of distance.
    gl_PointSize = PointSize;
}

// based on https://stackoverflow.com/questions/9609423/applying-part-of-a-texture-sprite-sheet-texture-map-to-a-point-sprite-in-ios
