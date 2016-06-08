#version 150

uniform vec4 globalColor;
uniform vec2 center;
uniform float maxDistance;

out vec4 outputColor;

void main()
{
    float alpha = 1.0;
    vec2 d = gl_FragCoord.xy - center;
    float dist =  sqrt(d.x*d.x + d.y*d.y);
    dist = 1 - (dist/maxDistance);
    alpha = dist;

    outputColor = vec4 (globalColor.rgb,alpha);
}
