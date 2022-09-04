#pragma once

#include "Scene.h"
#include "Component.h"
#include <vector>
#include <unordered_map>
#include <vec4.hpp>
#include <mat4x4.hpp>

namespace GraphicsCourseEngine {       

    class GameObject;
 
    class Transform : public Component
    {
    public:
        inline GameObject* GetHoldingGameObject() { return holdingGameObject; }
        inline Transform* GetParentTransform() { return parentTransform; }

        glm::mat4 CalculateGlobalTransformationMatrix() const;

    private:
        Transform(GameObject* holdingGameObject);
    
    public:
        glm::vec3 position;
        glm::vec3 rotation;
        glm::vec3 scale;

    private:
        Transform* parentTransform = nullptr;


        template <class ComponentChild> friend class ComponentOptimizer;

    };
}