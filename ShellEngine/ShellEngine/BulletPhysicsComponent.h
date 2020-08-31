//Physics class for any bullets
//w16005124

#pragma once
#include "PhysicsComponent.h"

//Class for handling bullet physics
class BulletPhysicsComponent : public PhysicsComponent
{
public:
	//Constructor
	BulletPhysicsComponent();

	//Update called once per frame
	//gameObject -> The game object the physics component belongs to.
	//frameTime -> Time between the last 2 frames
	void Update(std::shared_ptr<GameObject> gameObject, float frameTime) override;

private:
	//How long the bullet will last before it is set inactive
	const float BULLET_LIFE_TIME = 2.5f;

	//timer for the bullet
	float bulletLifeTimer;
};