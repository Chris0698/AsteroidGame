//Base class for all collisions in the game
//w16005124

#pragma once
#include <memory>
#include "Shapes.h"
#include "mysoundengine.h"

//forward declerations 
class GameObject;
class ObjectManager;

//Abstract class for handling any collision
class CollisionComponent
{
public:
	//Constructor that doesn't really do much, there for completion i guess
	CollisionComponent();

	//PLace a hitbox shape
	//gameObject -> gameObject that has collision
	virtual void PlaceHitboxShape(std::shared_ptr<GameObject> gameObject) = 0;

	//Process a collision
	//gameObject -> gam object that caused the collision
	//gameObjectCollided -> game object that been collided.
	virtual void ProcessCollision
	(
		std::shared_ptr<GameObject> gameObject,
		std::shared_ptr<GameObject> gameObjectCollided
	) = 0;

	//Get the hitbox shape
	virtual std::shared_ptr<IShape2D> GetHitBoxShape() =0;

	//Get if the game object is collidable
	bool GetIfCollidable();

	//deconstructor
	virtual ~CollisionComponent();
protected:
	bool isCollidable;
};