//cpp file to game object class
//w16005124

#include "GameObject.h"

GameObject::GameObject(std::vector<std::shared_ptr<Component>> components) : components(components)
{
}

void GameObject::Update(float frameTime)
{
	if (components.size() > 0)
	{
		auto pointer = GetPointer();
		for (auto component : components)
		{
			component->Update(pointer, frameTime);
		}
	}
}

std::shared_ptr<IShape2D> GameObject::GetHitBoxShape()
{
	if (GameObject::collisionComponent)
	{
		return GameObject::collisionComponent->GetHitBoxShape();
	}
	else
	{
		return nullptr;
	}
}

void GameObject::ProcessCollision(std::shared_ptr<GameObject> gameObjectCollided)
{
	if (GameObject::collisionComponent)
	{
		GameObject::collisionComponent->ProcessCollision(GetPointer(), gameObjectCollided);
	}
}

bool GameObject::IsActive()
{
	return GameObject::isActive;
}

void GameObject::SetActive(bool active)
{
	GameObject::isActive = active;
}

Vector2D GameObject::GetPosition()
{
	return GameObject::position;
}

float GameObject::GetAngle()
{
	return GameObject::angle;
}

void GameObject::SetImage(PictureIndex image)
{
	GameObject::image = image;
}

void GameObject::SetScale(float scale)
{
	GameObject::scale = scale;
}

PictureIndex GameObject::GetImage()
{
	return GameObject::image;
}

float GameObject::GetScale()
{
	return GameObject::scale;
}

float GameObject::GetTransparency()
{
	return GameObject::transparency;
}

void GameObject::SetTransparency(float transparency)
{
	GameObject::transparency = transparency;
}

Vector2D GameObject::GetVelocity()
{
	return GameObject::velocity;
}

void GameObject::SetPosition(Vector2D position)
{
	GameObject::position = position;
}

void GameObject::SetAngle(float angle)
{
	GameObject::angle = angle;
}

void GameObject::SetVelocity(Vector2D velocity)
{
	GameObject::velocity = velocity;
}

GameObject::~GameObject()
{
}

bool GameObject::GetIfCollidable()
{
	if (GameObject::collisionComponent)
	{
		return GameObject::collisionComponent->GetIfCollidable();
	}
	else
	{
		return false;
	}
}

void GameObject::SetGameObjectType(GameObjectType gameObjectType)
{
	GameObject::gameObjectType = gameObjectType;
}

GameObjectType GameObject::GetGameObjectType()
{
	return GameObject::gameObjectType;
}

std::shared_ptr<CollisionComponent> GameObject::GetCollisionComponent()
{
	if (GameObject::collisionComponent != nullptr)
	{
		return GameObject::collisionComponent;
	}
	else
	{
		return nullptr;
	}
}

std::shared_ptr<HealthComponent> GameObject::GetHealthComponent()
{
	return healthComponent;
}

std::shared_ptr<GameObject> GameObject::GetPointer()
{
	return shared_from_this();
}