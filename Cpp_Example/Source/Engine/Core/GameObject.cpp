#include "GameObject.h"
#include "Component.h"
#include "ComponentOptimizer.h"
#include "Scene.h"
#include "Transform.h"

using namespace GraphicsCourseEngine;

GameObject::GameObject(std::string name, Scene* sceneToExistIn)
{
    transform = ComponentOptimizer<Transform>::CreateNewComponentInstance(sceneToExistIn, this);
    this->sceneToExistIn = sceneToExistIn;
}

void GameObject::AddComponent(Component* component)
{
    components.push_back(component);
}

void GameObject::UpdateGameObject()
{
    if(!isActive)
    {
        return;
    }

    for(Component* component : components) 
    {
        component->UpdateComponent();
    }
}

void GameObject::DestroyGameObject()
{
    for(Component* component : components) 
    {
        component->DestroyComponent();
    }
    components.clear();

    delete this;
}

void GameObject::SetActive(bool bIsActive)
{
    this->isActive = bIsActive;
}

bool GameObject::IsActive() const
{
    return isActive;
}

GameObject::~GameObject()
{

}