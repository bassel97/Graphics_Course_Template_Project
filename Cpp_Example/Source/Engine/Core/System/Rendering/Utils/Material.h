#pragma once

#include "Utils/Shader.h"
#include "Texture.h"
#include <glm.hpp>

namespace GraphicsCourseEngine
{
    struct Material
    {
        Material(
            const char* vShaderCode,
            const char* fShaderCode,
            const char* diffuseTexturePath)
        :renderingShader(vShaderCode, fShaderCode),
        diffuseTexture(diffuseTexturePath)
        {
            
        }

        void Render()
        {
            renderingShader.use();
            renderingShader.setVec3("diffuseColor", diffuseColor);
            renderingShader.setFloat("alpha", alpha);

            renderingShader.setInt("diffTexture", 0);

            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, diffuseTexture.textureID);
            renderingShader.use();
        }

        Shader renderingShader;
        glm::vec3 diffuseColor = glm::vec4(1.0);
        float alpha = 1.0;
        Texture diffuseTexture;
    };
}