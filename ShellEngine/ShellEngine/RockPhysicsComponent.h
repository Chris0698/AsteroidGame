//handles rock physics
//w16005124

#pragma once
#include "PhysicsComponent.h"

//class for handling rock physics
class RockPhysicsComponent : public PhysicsComponent
{
public:
	//Constructor for the rock physics
	RockPhysicsComponent();

	//Update is called once per frame
	//gameObject -> gameObject that will conatain the input component
	//frameTime -> time between last 2 frames
	void Update(std::shared_ptr<GameObject> gameObject, float frameTime) override;
private:
	//My rocks will rotate in a random direction, either left or right
	bool isRotatingLeft;
};