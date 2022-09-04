#pragma once

#include <string>
#include <vector>

namespace GraphicsCourseEngine
{
    class Scene
    {
    public:
        Scene(std::string sceneName);
        void UpdateScene();

    private:
    
    public:
        class Camera* mainCamera;

    private:
        std::vector<class GameObject*> gameObjects;

    };
}