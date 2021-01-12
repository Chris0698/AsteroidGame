//For spaceship input
//w16005124

#pragma once
#include "InputComponent.h"
#include "GameObjectFactory.h"
#include "mysoundengine.h"

//Class for user input for spaceship
class SpaceshipInputComponent : public InputComponent
{
public:
	//Constructor for the input component
	//objectManager -> object manager that stores the objects
	SpaceshipInputComponent(std::shared_ptr<GameObjectFactory> objectManager);

	//Update the game object
	//gameObject -> the reference to the game object to be updated. 
	void Update(std::shared_ptr<GameObject> gameObject, float frameTime) override;

	//Initialise the component
	void Initialise();

private:
	//Delay between shots
	const float SHOT_TIMER = 1.0f;

	//Timer for shots 
	float timer;

	//Audio sound for each shot
	SoundIndex shootSound;

	//Reference to the object manager
	std::shared_ptr<ObjectManager> objectManager;
};