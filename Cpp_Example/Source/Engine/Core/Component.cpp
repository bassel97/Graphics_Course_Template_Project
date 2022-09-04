#include "Component.h"
#include "GameObject.h"

using namespace GraphicsCourseEngine;

Component::Component(GameObject* holdingGameObject)
{
    this->holdingGameObject = holdingGameObject;
    this->holdingGameObject->AddComponent(this);
}

void Component::SetIsActive(bool isActive)
{
    this->isActive = isActive;
}

bool Component::IsActive()
{
    return isActive;
}