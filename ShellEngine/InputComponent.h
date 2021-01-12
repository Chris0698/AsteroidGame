//Input component is an abstract base class for any input into the game
//w16005124

#pragma once
#include "myinputs.h"
#include <memory>
#include "Component.h"

class GameObject;	//forward dec for game object

class InputComponent : public Component
{
public:
	//Basic constructor
	InputComponent();

	//Update is called once per frame
	//gameObject -> gameObject that will conatain the input component
	//frameTime -> time between last 2 frames
	virtual void Update(std::shared_ptr<GameObject> gameObject, float frameTime) override {};

	//destructor 
	virtual ~InputComponent() {}
};