#pragma once

#include <unordered_map>
#include "Scene.h"

namespace GraphicsCourseEngine
{
    class GameObject;

    class Component
    {
    public:
        virtual void UpdateComponent() {}

        virtual void DestroyComponent() { delete this; }       

        virtual void SetIsActive(bool);
        bool IsActive(); 

    protected:
        Component(GameObject* holdingGameObject);
        Component(const Component &) = delete;
        Component &operator=(const Component &) = delete;
        virtual ~Component() {}

    protected:
        GameObject* holdingGameObject = nullptr;

    private:
        bool isActive = true;
        
    };
}