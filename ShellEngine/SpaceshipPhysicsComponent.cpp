//cpp file for spaceship physics component 
//w16005124

#include "SpaceshipPhysicsComponent.h"
#include "GameObject.h"

SpaceshipPhysicsComponent::SpaceshipPhysicsComponent()
{
}

void SpaceshipPhysicsComponent::Update(std::shared_ptr<GameObject> gameObject, float frameTime)
{
	if (gameObject->IsActive())
	{
		Vector2D position = gameObject->GetPosition();
		Vector2D velocity = gameObject->GetVelocity();

		Vector2D friction = velocity * -SpaceshipPhysicsComponent::GRAVITY;

		velocity = velocity + friction * frameTime;

		
		gameObject->SetVelocity(velocity);
		gameObject->SetPosition(position);
	}
}
