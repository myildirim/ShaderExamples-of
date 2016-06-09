# Sprite Sheet Shader Example

This example demonstrates:
- Generating a VBO
- Passing vertices to the VBO with additional data for each vertex: ```t = 0.125 * int(ofRandom(8));``` since the spritesheet has ```8``` sprites in the first row and we only use them for demonstration purposes.
-  Each vertext shows a different part of the sprite sheet, instead of passing multiple textures, it is possible to pass only one and access part of the sheet.

Uses GLSL ```#version 150```
![alt tag](https://github.com/ixds/ShaderExamples-of/blob/master/SpriteSheetShader/Screen%20Shot%202016-06-08%20at%2016.19.22.png?raw=true)

## Used Sprite Sheet

![alt tag](https://github.com/ixds/ShaderExamples-of/blob/master/SpriteSheetShader/bin/data/sprite.png?raw=true)

