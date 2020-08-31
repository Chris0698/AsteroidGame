//cpp file to game object class
//w16005124

#include "GameObject.h"

//constructor
GameObject::GameObject(
	std::shared_ptr<RenderComponent> renderComponent,
	std::shared_ptr<PhysicsComponent> physicsComponent,
	std::shared_ptr<CollisionComponent> collisionComponent,
	std::shared_ptr<InputComponent> inputComponent,
	std::shared_ptr<HealthComponent> healthComponent
) : 
	renderComponent(renderComponent), 
	physicsComponent(physicsComponent),
	collisionComponent(collisionComponent), 
	inputComponent(inputComponent),
	healthComponent(healthComponent)
{
	//empty constructor
}

void GameObject::Update(float frameTime)
{
	if (GameObject::renderComponent != nullptr)
	{
		GameObject::renderComponent->Render(GetPointer(), frameTime);
	}

	if (GameObject::physicsComponent != nullptr)
	{
		GameObject::physicsComponent->Update(GetPointer(), frameTime);
	}
	
	if (GameObject::inputComponent != nullptr)
	{
		GameObject::inputComponent->Update(GetPointer(), frameTime);
	}

	if (GameObject::collisionComponent != nullptr)
	{
		GameObject::collisionComponent->PlaceHitboxShape(GetPointer());
	}

	if (GameObject::healthComponent != nullptr)
	{
		GameObject::healthComponent->CheckIfStillAlive(GetPointer());
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

std::shared_ptr<PhysicsComponent> GameObject::GetPhysicsComponent()
{
	if (GameObject::physicsComponent != nullptr)
	{
		return GameObject::physicsComponent;
	}
	else
	{
		return nullptr;
	}
}

std::shared_ptr<RenderComponent> GameObject::GetRenderComponent()
{
	if (GameObject::renderComponent != nullptr)
	{
		return GameObject::renderComponent;
	}
	else
	{
		return nullptr;
	}
}

std::shared_ptr<InputComponent> GameObject::GetInputComponent()
{
	if (GameObject::inputComponent != nullptr)
	{
		return GameObject::inputComponent;
	}
	else
	{
		return nullptr;
	}
}

std::shared_ptr<HealthComponent> GameObject::GetHealthComponent()
{
	if (GameObject::healthComponent != nullptr)
	{
		return GameObject::healthComponent;
	}
	else
	{
		return nullptr;
	}
}

std::shared_ptr<GameObject> GameObject::GetPointer()
{
	return shared_from_this();
}