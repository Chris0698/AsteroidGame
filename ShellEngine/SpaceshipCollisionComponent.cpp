//cpp file for spaceship collision class
//w16005124

#include "SpaceshipCollisionComponent.h"
#include "GameObject.h"
#include "ObjectManager.h"

SpaceshipCollisionComponent::SpaceshipCollisionComponent( std::shared_ptr<Circle2D> collisionShape) : collisionShape(collisionShape)
{
	CollisionComponent::isCollidable = true;
}

void SpaceshipCollisionComponent::Update(std::shared_ptr<GameObject> gameObject, float frameTime)
{
	if (gameObject->IsActive())
	{
		collisionShape->PlaceAt(gameObject->GetPosition(), gameObject->GetScale() * 64);
		//MyDrawEngine::GetInstance()->FillCircle(collisionShape->GetCentre(), collisionShape->GetRadius(), MyDrawEngine::WHITE);
	}
}

void SpaceshipCollisionComponent::ProcessCollision (std::shared_ptr<GameObject> gameObject, std::shared_ptr<GameObject> gameObjectCollided)
{
	gameObject->GetHealthComponent()->TakeDamage1HP(gameObject);
}

std::shared_ptr<IShape2D> SpaceshipCollisionComponent::GetHitBoxShape()
{
	return SpaceshipCollisionComponent::collisionShape;
}
