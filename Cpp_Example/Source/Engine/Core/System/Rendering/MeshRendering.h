#pragma once

#include "../../Component.h"
#include <glm.hpp>

namespace GraphicsCourseEngine
{
    class MeshRendering : public Component
    {
        unsigned int shaderProgram;
        unsigned int VBO, VAO;

        class Shader* ourShader;
        
        public:
        MeshRendering(class GameObject* holdingGameObject);
        ~MeshRendering();
        void Render(glm::mat4 projection, glm::mat4 view);

    };
}
