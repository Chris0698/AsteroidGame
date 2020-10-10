//physics component class is the base class for all physics components
//w16005124

#pragma once
#include <memory>
#include "Component.h"

class GameObject;	//forward dec of game object class otherwise hit dependcy issues

//Abstract class for managing physics
class PhysicsComponent : public Component
{
public:
	//Constructor for physics component
	PhysicsComponent();

	//Update is called once per frame
	//gameObject -> gameObject that will conatain the input component
	//frameTime -> time between last 2 frames
	virtual void Update(std::shared_ptr<GameObject> gameObject, float frameTime) override {}

	//destructor
	virtual ~PhysicsComponent() {}
};