#ifndef DSHADERS_H
#define DSHADERS_H

static const char* defaultVertShader = "#version 330 core\n\
    layout(location = 0) in vec2 aPos;\n\
    layout(location = 1) in vec2 aTexCoord;\n\
    layout(location = 2) in vec3 aColor;\n\
    out vec2 vTexCoord;\n\
    void main() {\n\
        gl_Position = vec4(aPos, 0.0, 0.1);\n\
        vTexCoord = aTexCoord;\n\
    }";

static const char* defaultFragShader = "#version 330 core\n\
    in vec2 vTexCoord;\n\
    uniform sampler2D uTexture;\n\
    uniform vec4 uColor;\n\
    out vec4 FragColor;\n\
    void main() {\n\
        FragColor = texture(uTexture, vTexCoord) * uColor;\n\
    }";

#endif