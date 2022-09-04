#pragma once

#include <string>
#include <vector>

namespace GraphicsCourseEngine
{
    class Scene;
    class Component;
    class Transform;

    class GameObject
    {
    public:
        GameObject(std::string, Scene*);
        GameObject(const GameObject &) = delete;
        GameObject &operator=(const GameObject &) = delete;

        inline Transform* GetTransform() { return transform; }
        void AddComponent(Component* component);
        void UpdateGameObject();
        void DestroyGameObject();

        void SetActive(bool);
        bool IsActive() const;

    private:
        ~GameObject();

    private:
        bool isActive = true;

        Transform* transform;
        Scene* sceneToExistIn;
        std::vector<Component*> components;

    };
}