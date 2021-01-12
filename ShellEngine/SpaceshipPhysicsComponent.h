//For spaceship physics
//w16005124

#pragma once
#include "PhysicsComponent.h"

//Handles physics for the spaceship
class SpaceshipPhysicsComponent : public PhysicsComponent
{
public:
	//Constructor
	SpaceshipPhysicsComponent();

	//Update is called once per frame
	//gameObject -> gameObject that will conatain the input component
	//frameTime -> time between last 2 frames
	void Update(std::shared_ptr<GameObject> gameObject, float frameTime) override;

private:
	//How strong gravity will be in this game
	const float GRAVITY = 0.35f;
};