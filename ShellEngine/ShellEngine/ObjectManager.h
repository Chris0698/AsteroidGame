//Object manager class
//w16005124

#pragma once
#include <list>
#include "GameObject.h"
#include <algorithm>
#include <memory>
#include <map>

//forwards decleration since ObjectManager required by the typedef method 
class ObjectManager;

//Global function for object creation that returns a pointer of gameObjectCreationMethod
//parameter is the reference to the object manager in use throughout the game
typedef std::shared_ptr<GameObject>(*gameObjectCreationMethod) (std::shared_ptr<ObjectManager>&);

//Object managers handles and manages all game objects in the current game
//extends enabled_shared_from_this to enable a this reference from shared_pointer
class ObjectManager : public std::enable_shared_from_this<ObjectManager>
{
public:
	//Empty constructor for Object Manager
	ObjectManager();

	//Run each thread, threads are collision, render and update
	//frameTime -> time between each frame
	void RunThreads(float frameTime);

	//Add a new object to the list
	//pNewObject -> new object reference to be added to the list
	void AddObject(std::shared_ptr<GameObject> pNewObject);

	//Call update method on all game objects
	//frameTime -> is the time between two frames.
	void UpdateAll(float frameTime);

	//Renders all of the gameo bjects in the list
	//void RenderAll();

	//Loop through and delete all the inactive game objects
	void DeleteInactive();

	//Delete all objects in the game object list
	void DeleteAll();

	//Check all collisions between the game objects
	void CheckAllCollisions();

	//Register a new object type to the game
	//gameObjectType -> key of the pair. 
	void Register(GameObjectType gameObjectType, gameObjectCreationMethod gameObjectCreationMethod);

	//Create a game object that is registered in the game
	//gameObjectType -> the key of the object
	std::shared_ptr<GameObject> Create(GameObjectType gameObjectType);

	//Reister all game objects
	void RegisterAllObjects();

private:
	//List of game objects
	std::list<std::shared_ptr<GameObject>> pGameObjectList;

	//Map to store each object 
	std::map<GameObjectType, gameObjectCreationMethod> objectMap;

	//Get a reference to the object manager
	std::shared_ptr<ObjectManager> GetPointer();
};