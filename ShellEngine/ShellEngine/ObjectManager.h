//Object manager class
//w16005124

#pragma once
#include <list>
#include "GameObject.h"
#include <algorithm>
#include <memory>
#include <map>

//Object managers handles and manages all game objects in the current game
class ObjectManager /* : public std::enable_shared_from_this<ObjectManager> */
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

private:
	//List of game objects
	std::list<std::shared_ptr<GameObject>> pGameObjectList;
};