#include "Transform.h"
#include "GameObject.h"
#include "ComponentOptimizer.h"
#include "Scene.h"
#include <glm.hpp>
#include <gtx/euler_angles.hpp>

using namespace GraphicsCourseEngine;

glm::mat4 Transform::CalculateGlobalTransformationMatrix() const
{
    glm::mat4 globalTransformationMatrix(1.0);

    globalTransformationMatrix = glm::translate(globalTransformationMatrix, position);
    globalTransformationMatrix *= glm::yawPitchRoll(rotation.x, rotation.y, rotation.z);
    globalTransformationMatrix = glm::scale(globalTransformationMatrix, scale);

    if (parentTransform)
    {
        globalTransformationMatrix = parentTransform->CalculateGlobalTransformationMatrix() * globalTransformationMatrix;
    }

    return globalTransformationMatrix;
}

Transform::Transform(GameObject* holdingGameObject) : Component (holdingGameObject)
{
    position = glm::vec4(0.0);
    rotation = glm::vec4(0.0);
    scale = glm::vec4(1.0);
}