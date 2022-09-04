#include "Camera.h"
#include "../../Scene.h"
#include "../../GameObject.h"
#include "../../Transform.h"
#include <gtc/matrix_transform.hpp>
#include <gtx/euler_angles.hpp>

using namespace GraphicsCourseEngine;

glm::mat4 Camera::CalculateProjectMatrix() const
{
    return glm::perspective(glm::radians(fov), aspectRatio, nearPlane, farPlane);  
}

glm::mat4 Camera::CalculateViewMatrix() const
{
    Transform* transform = holdingGameObject->GetTransform();

    glm::vec3 rotation = transform->rotation;

    glm::mat4 rotationMatrix = glm::yawPitchRoll(rotation.y, rotation.x, rotation.z);

    glm::vec3 rotatedForward = rotationMatrix * glm::vec4(0, 0, 1, 0);
    glm::vec3 rotatedUp = rotationMatrix * glm::vec4(0, 1, 0, 0);
    
    return glm::lookAt(transform->position, transform->position + rotatedForward, rotatedUp);
}

Camera::Camera(GameObject* holdingGameObject) : Component (holdingGameObject)
{
    
}