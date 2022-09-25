#pragma once

#include "../../Component.h"
#include <glm.hpp>

namespace GraphicsCourseEngine
{
    class MeshRendering : public Component
    {
        public:
        MeshRendering(class GameObject* holdingGameObject);

        void Render(glm::mat4 projection, glm::mat4 view);
        virtual void UpdateComponent() override;

        ~MeshRendering();

        private:
        unsigned int shaderProgram;
        unsigned int vertexBufferObject, VAO;

        struct Material* renderingMatrial = nullptr;
        
        float test = 0;
    };
}
