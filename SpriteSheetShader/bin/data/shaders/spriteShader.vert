#version 150
// based on https://stackoverflow.com/questions/9609423/applying-part-of-a-texture-sprite-sheet-texture-map-to-a-point-sprite-in-ios

uniform mat4 modelViewProjectionMatrix;
uniform mat4 textureMatrix;

uniform float pointSize;
uniform vec2 textureCoordPointSize;
uniform vec2 textureCoordIn;
uniform float numRows;
uniform float numCols;


in float imgType; // type
in vec4 position;

out vec2 textureCoord;
out vec2 textureSize;

void main(void)
{
    float row = int(imgType/numCols) * 1/numRows;
    float col = mod(imgType, numCols) * 1/numCols;
    // this is the coordinate offset, modify this to change different parts
    // of the sprite sheet
    vec2 calculatedCoordinates = vec2(col,row);

    textureCoord = calculatedCoordinates;
    gl_Position = modelViewProjectionMatrix * position;
    textureSize = vec2(textureCoordPointSize.x, textureCoordPointSize.y);

    gl_PointSize = pointSize;
}
