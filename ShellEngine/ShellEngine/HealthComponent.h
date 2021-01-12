//Health component class for giving game objects health if they have the component
//w16005124

#pragma once
#include <memory>
#include "mysoundengine.h"
#include "Component.h"

//forward class dec to stop circle dependacy
class GameObject;
class GameObjectFactory;

//Health for each object that contains the component
//Should probably have a health UI to go with this component
class HealthComponent : public Component
{
public:
	//Constructor
	//objectManager -> Object Manager in use
	//startingHealth -> Starting health the object has
	HealthComponent(std::shared_ptr<GameObjectFactory> gameObjectFactory, int startingHealth);

	//Initialise the component
	void Initialise();

	//Reduce the game object health by 1
	void TakeDamage1HP(std::shared_ptr<GameObject> gameObject);

	//redce the game object by the parameter
	void TakeDamage(int damage, std::shared_ptr<GameObject> gameObject);

	//Check if the game object still alive
	//gameObject -> game object to be checked
	void Update(std::shared_ptr<GameObject> gameObject, float frameTime) override;

	//Death for the game object
	//gameobject -> Game object that dead
	virtual void Death(std::shared_ptr<GameObject> gameObject);

	//getters and setters for health
	int GetCurrentHealth();
	void SetHealth(int newHealth);

private:
	//General variables that maybe used
	int currentHealth;
//	std::shared_ptr<ObjectManager> objectManager;	//reference to the object manager in use
	SoundIndex destructionSound;
};