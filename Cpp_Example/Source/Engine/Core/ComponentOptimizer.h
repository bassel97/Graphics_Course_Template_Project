#pragma once

#include <unordered_map>
#include "Scene.h"
#include "GameObject.h"

namespace GraphicsCourseEngine
{
    template <class ComponentChild>
    class ComponentOptimizer
    {
    public:
        static ComponentChild* CreateNewComponentInstance(Scene* sceneToCreateIn, GameObject* holdingGameObject)
        {
            ComponentChild* createdComponent = new ComponentChild(holdingGameObject);

            createdComponentsForScene[sceneToCreateIn].push_back(createdComponent);

            return createdComponent;
        }

        static inline std::vector<ComponentChild*> GetComponentsVector(class Scene* scene)
        {
            return createdComponentsForScene[scene];
        }

    protected:    
        static std::unordered_map<class Scene*, std::vector<ComponentChild*>> createdComponentsForScene;
        
    };

    template <class ComponentChild>
    std::unordered_map<class Scene*, std::vector<ComponentChild*>> ComponentOptimizer<ComponentChild>::createdComponentsForScene = std::unordered_map<class Scene*, std::vector<ComponentChild*>>();
}

