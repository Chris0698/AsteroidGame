//cpp file to bullet collision
//w16005124

#include "BulletCollisionComponent.h"
#include "GameObject.h"

BulletCollisionComponent::BulletCollisionComponent(std::shared_ptr<Circle2D> collisionShape)
{
	BulletCollisionComponent::collisionShape = collisionShape;
	CollisionComponent::isCollidable = true;
}

void BulletCollisionComponent::PlaceHitboxShape(std::shared_ptr<GameObject> gameObject)
{
	if (gameObject->IsActive())
	{
		collisionShape->PlaceAt(gameObject->GetPosition(), gameObject->GetScale() * 4);
		//MyDrawEngine::GetInstance()->FillCircle(collisionShape->GetCentre(), collisionShape->GetRadius(), MyDrawEngine::WHITE);
	}
}

void BulletCollisionComponent::ProcessCollision(std::shared_ptr<GameObject> gameObject, std::shared_ptr<GameObject> gameObjectCollided)
{
	//No matter what the bullet hit, just set the bullet to inactive
	gameObject->SetActive(false);
}

std::shared_ptr<IShape2D> BulletCollisionComponent::GetHitBoxShape()
{
	return BulletCollisionComponent::collisionShape;
}