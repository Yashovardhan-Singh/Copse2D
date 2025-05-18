#include "shaders.h"

typedef uint32_t Shader;

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "../../vendor/glad/gl.h"

const char* _ShaderReadSourceFromFile(const char* filePath) {
    FILE *file = fopen(filePath, "r");
    if (!file) {
        fprintf(stderr, "Cannot open file as read: %s\n", filePath);
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    char *buffer = (char *)malloc(fileSize + 1);
    if (!buffer) {
        fprintf(stderr, "Memory Allocation Failed For Shader Source\n");
        fclose(file);
        return NULL;
    }

    fread(buffer, 1, fileSize, file);
    buffer[fileSize] = '\0';
    fclose(file);
    return (const char*) buffer;
}

// Returns type of shader
Shader _ShaderCompile(GLenum shaderType, const char* shaderSource) {
    uint32_t shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &shaderSource, NULL);
    glCompileShader(shader);

    uint32_t success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (!success) {
        char info[512];
        glGetShaderInfoLog(shader, sizeof(info), NULL, info);
        fprintf(stderr, "Shader compilation failed.\nLog:\n%s\n", info);
        glDeleteShader(shader);
        return 0;
    }

    return shader;
}

// Actually returns the shader program with vert and frag linked
Shader ShaderCreateFromFiles(const char* fragShaderFilePath, const char* vertShaderFilePath) {
    const char* fragShaderSource = _ShaderReadSourceFromFile(fragShaderFilePath);
    const char* vertShaderSource = _ShaderReadSourceFromFile(vertShaderFilePath);

    if (!fragShaderSource || !vertShaderSource) {
        free(fragShaderSource);
        free(vertShaderSource);
        fprintf(stderr, "Could not read shader sources\n");
        return 0;
    }

    uint32_t shaderProgram = ShaderCreateFromStrings(fragShaderSource, vertShaderSource);

    free(fragShaderSource);
    free(vertShaderSource);

    return shaderProgram;
}

// Actually returns the shader program with vert and frag linked
Shader ShaderCreateFromStrings(const char* fragShaderSource, const char* vertShaderSource) {
    uint32_t fragShader = _ShaderCompile(GL_FRAGMENT_SHADER, fragShaderSource);
    uint32_t vertShader = _ShaderCompile(GL_VERTEX_SHADER, vertShaderSource);

    if (!fragShader || !vertShader) {
        fprintf(stderr, "Cannot create shader.\n");
        return 0;
    }

    uint32_t shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, fragShader);
    glAttachShader(shaderProgram, vertShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(fragShader);
    glDeleteShader(vertShader);

    uint32_t sucess = 0;
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &sucess);
    if(!sucess) {
        char info[512];
        glGetProgramInfoLog(shaderProgram, sizeof(info), NULL, info);
        fprintf(stderr, "Error linking shaders.\nLog:\n%s\n", info);
        glDeleteProgram(shaderProgram);
        return 0;
    }

    return shaderProgram;
}

void ShaderUse(Shader shader) {
    GLint boundTexture = 0;
    glGetIntegerv(GL_TEXTURE_BINDING_2D, &boundTexture);
    glUseProgram(shader);
    if (boundTexture) {
        glUniform1i(glGetUniformLocation(shader, "useTexture"), GL_TRUE);
    } else {
        glUniform1i(glGetUniformLocation(shader, "useTexture"), GL_FALSE);
    }
}

void ShaderDestory(Shader shader) {
    glDeleteProgram(shader);
}