//cpp file to bullet physics component
//w16005124

#include "BulletPhysicsComponent.h"
#include "GameObject.h"

BulletPhysicsComponent::BulletPhysicsComponent()
{
	//Set the timer to  equal 0
	BulletPhysicsComponent::bulletLifeTimer = 0.0f;
}

void BulletPhysicsComponent::Update(std::shared_ptr<GameObject> gameObject, float frameTime)
{
	if (gameObject->IsActive())
	{
		float angle = gameObject->GetAngle();
		Vector2D position = gameObject->GetPosition();
		Vector2D velocity = gameObject->GetVelocity();

		if (BulletPhysicsComponent::bulletLifeTimer <= BulletPhysicsComponent::BULLET_LIFE_TIME)
		{
			Vector2D velocity;

			velocity.setBearing(angle, 900.0f);

			position = position + velocity * frameTime;

			BulletPhysicsComponent::bulletLifeTimer = BulletPhysicsComponent::bulletLifeTimer + frameTime;
		}
		else
		{
			gameObject->SetActive(false);
		}

		gameObject->SetPosition(position);
	}
}
