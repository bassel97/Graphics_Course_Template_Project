#pragma once

namespace GraphicsCourseEngine
{
    const char* vertexShaderSource = 
    "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "layout (location = 1) in vec2 aTexCoord;\n"
    "layout (location = 2) in vec3 aNormal;\n"
    "out vec2 TexCoord;\n"
    "out vec3 Normal;\n"
    "uniform mat4 model;\n"
    "uniform mat4 view;\n"
    "uniform mat4 projection;\n"
    "void main()\n"
    "{\n"
    "   Normal = aNormal;"
    "	gl_Position = projection * view * model * vec4(aPos, 1.0f);\n"
    "	TexCoord = vec2(aTexCoord.x, aTexCoord.y);\n"
    "}";

    const char* fragmentShaderSource = 
    "#version 330 core\n"
    "out vec4 FragColor;\n"
    "in vec2 TexCoord;\n"
    "in vec3 Normal;\n"
    "uniform vec3 diffuseColor;\n"
    "uniform float alpha;\n"
    "uniform sampler2D diffTexture;\n"
    "void main()\n"
    "{\n"
    "	FragColor = vec4(Normal, 1.0);//vec4(texture(diffTexture, TexCoord).rgb, alpha);\n"
    "}";
}