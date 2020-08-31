//Input component is an abstract base class for any input into the game
//w16005124

#pragma once
#include "myinputs.h"
#include <memory>

class GameObject;	//forward dec for game object

//Inpt Component is an abstract class for managing user input
class InputComponent
{
public:
	//Basic constructor
	InputComponent();

	//Update is called once per frame
	//gameObject -> gameObject that will conatain the input component
	//frameTime -> time between last 2 frames
	virtual void Update(std::shared_ptr<GameObject> gameObject, float frameTime) = 0;

	//destructor 
	virtual ~InputComponent() {}
};