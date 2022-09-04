#include "RenderingSystem.h"
#include "MeshRendering.h"
#include "Camera.h"
#include "../../../Core/Scene.h"
#include "../../../Core/ComponentOptimizer.h"

using namespace GraphicsCourseEngine;

void RenderingSystem::RenderScene(Scene* sceneToRender)
{
    Camera* renderingCamera = sceneToRender->mainCamera;

    if(!renderingCamera)
    {
        return;
    }

    std::vector<MeshRendering*> meshRenderingComponents = ComponentOptimizer<MeshRendering>::GetComponentsVector(sceneToRender);

    for (MeshRendering* meshRenderingComponent : meshRenderingComponents)
    {
        meshRenderingComponent->Render(renderingCamera->CalculateProjectMatrix(), renderingCamera->CalculateViewMatrix());
    }
}