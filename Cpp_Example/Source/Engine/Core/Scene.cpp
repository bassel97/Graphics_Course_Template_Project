#include "Scene.h"
#include "GameObject.h"
#include "Transform.h"
#include "ComponentOptimizer.h"
#include "System/Rendering/MeshRendering.h"
#include "System/Rendering/Camera.h"
#include <iostream>

using namespace GraphicsCourseEngine;

Scene::Scene(std::string sceneName)
{
    GameObject* cameraObject = new GameObject("Camera", this);
    Camera* camera = ComponentOptimizer<Camera>::CreateNewComponentInstance(this, cameraObject);
    cameraObject->GetTransform()->position = glm::vec3(8, 8, -8);
    cameraObject->GetTransform()->rotation = glm::vec3(0.785398, -0.785398, 0);
    this->mainCamera = camera;

    GameObject* landObject = new GameObject("Land", this);
    landObject->GetTransform()->scale = glm::vec3(20, 1, 20);
    MeshRendering* meshRendering = ComponentOptimizer<MeshRendering>::CreateNewComponentInstance(this, landObject);
}

void Scene::UpdateScene()
{
    for (GameObject* gameObject : gameObjects)
    {
        gameObject->UpdateGameObject();   
    }
}