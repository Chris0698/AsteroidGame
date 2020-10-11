//cpp for rock collision class
//w16005124

#include "RockCollisionComponent.h"
#include "GameObject.h"
#include "ObjectManager.h"

RockCollisionComponent::RockCollisionComponent(std::shared_ptr<ObjectManager> objectManager,
	std::shared_ptr<Circle2D> collisionShape) : objectManager(objectManager)
{
	RockCollisionComponent::collisionShape = collisionShape;
	CollisionComponent::isCollidable = true;
}

void RockCollisionComponent::Update(std::shared_ptr<GameObject> gameObject, float frameTime)
{
	if (gameObject->IsActive())
	{
		collisionShape->PlaceAt(gameObject->GetPosition(), 64 * gameObject->GetScale());
		//MyDrawEngine::GetInstance()->FillCircle(gameObject->GetPosition(), collisionShape->GetRadius(), MyDrawEngine::WHITE);
	}
}

void RockCollisionComponent::ProcessCollision (std::shared_ptr<GameObject> gameObject, std::shared_ptr<GameObject> gameObjectCollided)
{
	//If a rock hits anything that not another rock
	if (gameObjectCollided->GetGameObjectType() != GameObjectType::ROCK)
	{
		//reduce it HP by 1
		gameObject->GetHealthComponent()->TakeDamage1HP();
	}
}

std::shared_ptr<IShape2D> RockCollisionComponent::GetHitBoxShape()
{
	return RockCollisionComponent::collisionShape;
}
