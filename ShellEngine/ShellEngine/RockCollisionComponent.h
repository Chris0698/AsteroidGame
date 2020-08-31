//Handles rock collision
//w16005124

#pragma once
#include "CollisionComponent.h"

//Rock collision component for handling all collision with rocks
class RockCollisionComponent : public CollisionComponent
{
public:
	//constructor for the collision component
	//objectManager -> object manager used for managing objects
	//collisionShape -> collision shape for the rock
	RockCollisionComponent
	(
		std::shared_ptr<ObjectManager> objectManager,
		std::shared_ptr<Circle2D> collisionShape
	);

	//Places a hit box shape
	//gameObject -> rock the collision component belongs to.
	void PlaceHitboxShape(std::shared_ptr<GameObject> gameObject) override;

	//Process the collision between the rock and other game object
	//gameObject -> rock the collision component belongs to.
	//gameObjectCollided -> the game object that caused the collision
	void ProcessCollision
	(
		std::shared_ptr<GameObject> gameObject, 
		std::shared_ptr<GameObject> gameObjectCollided
	) override;

	//Get the hitbox shape
	std::shared_ptr<IShape2D> GetHitBoxShape() override;
private:
	//reference to the object manager in use
	std::shared_ptr<ObjectManager> objectManager;

	//The hitbox shape. 
	std::shared_ptr<Circle2D> collisionShape;

	//destruction sound for the rock
	SoundIndex destructionSound;
};