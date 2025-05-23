#ifndef DSHADERS_H
#define DSHADERS_H

static const char* defaultVertShader = "#version 330 core\n\
    layout(location = 0) in vec2 aPos;\n\
    layout(location = 1) in vec2 aTexCoord;\n\
    layout(location = 2) in vec4 aColor;\n\
    out vec2 vTexCoord;\n\
    out vec4 vColor;\n\
    void main() {\n\
        gl_Position = vec4(aPos, 0.0, 1.0);\n\
        vTexCoord = aTexCoord;\n\
        vColor = aColor;\n\
    }";

// static const char* defaultVertShader = "#version 330 core\n\
//     layout(location = 0) in vec2 aPos;\n\
//     layout(location = 1) in vec2 aTexCoord;\n\
//     layout(location = 2) in vec4 aColor;\n\
//     void main() {\n\
//         gl_Position = vec4(aPos, 0.0, 1.0);\n\
//     }";

static const char* defaultFragShader = "#version 330 core\n\
    in vec2 vTexCoord;\n\
    in vec4 vColor;\n\
    uniform sampler2D uTexture;\n\
    uniform bool useTexture;\n\
    out vec4 FragColor;\n\
    void main() {\n\
        if (useTexture) {\n\
            FragColor = texture(uTexture, vTexCoord) * vColor;\n\
        } else {\n\
            FragColor = vColor;\n\
        }\n\
    }";


// static const char* defaultFragShader = "#version 330 core\n\
//     out vec4 FragColor;\n\
//     void main() {\n\
//         FragColor = vec4(1.0, 0.0, 1.0, 1.0);\n\
//     }\n";


#endif