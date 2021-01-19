//For spaceship input
//w16005124

#pragma once
#include "InputComponent.h"
#include "ObjectManager.h"
#include "GameObjectFactory.h"
#include "mysoundengine.h"

//Class for user input for spaceship
class SpaceshipInputComponent : public InputComponent
{
public:
	//Constructor for the input component
	//objectManager -> object manager that stores the objects
	SpaceshipInputComponent(std::shared_ptr<ObjectManager> objectManager);

	//Update the game object
	//gameObject -> the reference to the game object to be updated. 
	void Update(std::shared_ptr<GameObject> gameObject, float frameTime) override;

	//Initialise the component
	void Initialise();

private:
	
	const float SHOT_TIMER = 1.0f;

	float timer;

	SoundIndex shootSound;

	//Object manager required because bullets are created in this class
	std::shared_ptr<ObjectManager> objectManager;
};