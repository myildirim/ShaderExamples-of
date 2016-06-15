# IXDS Openframeworks Shader Examples

These examples are smaller snippets for some features that were we needed in our projects and explored a bit further.
Detailied explanations are in each example application's folder.
All examples are based on latest openframeworks/openframeworks master and comes with QT configuration files to be edited/compiled in QT.
- CircleGridShader: Passing vertex point size for each vertex
- LineThicknessShader: Setting line thickness on the geometry shader
- MeshGradientShader: Manipulating the color of the mesh depending on the mouse position
- SpriteSheetShader: Loading only one spritesheet to the shader and accessing different parts depending on vertex type
- VertexRotationShader: Loading multiple textures on shader and rotating each vertex independently depending on mouse position.

All of them uses GLSL ```#version 150```

`git clone` these into your `openFrameworks/apps` directory, e.g. `openFrameworks/apps/ShaderExamples-of`
