#pragma once

#include <vector>
#include <unordered_map>
#include <mat4x4.hpp>
#include "../../Component.h"

class GameObject;

namespace GraphicsCourseEngine
{
    class Camera : public Component
    {
    public:
        glm::mat4 CalculateProjectMatrix() const;
        glm::mat4 CalculateViewMatrix() const;

    private:
        Camera(GameObject* holdingGameObject);

    public:
        double nearPlane = 0.1;
        double farPlane = 1000.0;
        double fov = 60.0;
        double aspectRatio = (960.0 / 540.0);

        bool isOrthographic = false;

        template <class ComponentChild> friend class ComponentOptimizer;
    };
}