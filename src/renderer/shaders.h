#ifndef SHADERS_H
#define SHADERS_H

#include <stdint.h>

typedef uint32_t Shader;

Shader ShaderCreateFromFiles(const char* fragShaderFilePath, const char* vertShaderFilePath);
Shader ShaderCreateFromStrings(const char* fragShaderSource, const char* vertShaderSource);
void ShaderUse(Shader shader);
void ShaderDestory(Shader shader);

#endif