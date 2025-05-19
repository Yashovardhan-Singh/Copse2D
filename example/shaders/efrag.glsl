// example fragment shader

#version 330 core

in vec2 vTexCoord;
in vec3 vRandomColor;
in vec4 vColor;

out vec4 fragColor;

uniform sampler2D uTexture;

void main() {
    vec4 texColor = texture(uTexture, vTexCoord);
    vec3 finalColor = vColor.rgb * texColor.rgb * vRandomColor;
    float finalAlpha = texColor.a * vColor.a;
    fragColor = vec4(finalColor, finalAlpha);
}