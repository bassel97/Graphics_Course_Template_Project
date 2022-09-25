#pragma once

#include <stb_image.h>

namespace GraphicsCourseEngine
{
    struct Texture
    {
        Texture(const char* texturePath)
        {
            glGenTextures(1, &textureID);
            glBindTexture(GL_TEXTURE_2D, textureID);
            
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            
            int width, height, nrChannels;
            stbi_set_flip_vertically_on_load(true);

            unsigned char *data = stbi_load(texturePath, &width, &height, &nrChannels, 0);
            if (data)
            {
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
                glGenerateMipmap(GL_TEXTURE_2D);
            }
            else
            {
                std::cout << "Failed to load texture" << std::endl;
            }
            stbi_image_free(data);
        }

        unsigned int textureID;
    };
}