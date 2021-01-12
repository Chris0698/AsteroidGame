//cpp file to rock physics
//w16005124

#include "RockPhysicsComponent.h"
#include "GameObject.h"

RockPhysicsComponent::RockPhysicsComponent()
{
	//I want my rocks to rotate around
	//Generate either a 0 or 1. If 1 then rotate left is true or rotate right instead
	RockPhysicsComponent::isRotatingLeft = rand() % 2;		//Generate a odd or even number
}

void RockPhysicsComponent::Update(std::shared_ptr<GameObject> gameObject, float frameTime)
{
	const float ROTATION_CONSTANT = 2.0f;	//Some constant for the rock to rotate, higher this value the quicker

	if (gameObject->IsActive())
	{
		float angle = gameObject->GetAngle();
		float scale = gameObject->GetScale();

		if (isRotatingLeft)
		{
			angle = angle + (ROTATION_CONSTANT / scale) * frameTime;
		}
		else
		{
			angle = angle + (-ROTATION_CONSTANT / scale) * frameTime;
		}

		//set the angle back
		gameObject->SetAngle(angle);
	}
}
