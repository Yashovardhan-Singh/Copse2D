// example vertex shader

#version 330 core

layout(location = 0) in vec2 aPosition;
layout(location = 1) in vec2 aTexCoord;
layout(location = 2) in vec4 aColor;

out vec2 vTexCoord;
out vec4 vColor;
out vec3 vRandomColor;

float hash(vec2 p) {
    return fract(sin(dot(p, vec2(127.123509, 311.723847))) * 438958.2355);
}

vec3 randomColor(vec2 seed) {
    return vec3(
        hash(seed),
        hash(seed + vec2(12423.234, 329848.12321)),
        hash(seed + vec2(32484.124, 124235.12639))
    );
}

void main() {
    gl_Position = vec4(aPosition, 0.0, 1.0);
    vTexCoord = aTexCoord;
    vColor = aColor;
    vRandomColor = randomColor(aPosition);
}