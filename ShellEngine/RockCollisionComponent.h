//Handles rock collision
//w16005124

#pragma once
#include "CollisionComponent.h"

//Rock collision component for handling all collision with rocks
class RockCollisionComponent : public CollisionComponent
{
public:
	//constructor for the collision component
	//collisionShape -> collision shape for the rock
	RockCollisionComponent (std::shared_ptr<Circle2D> collisionShape);

	//Places a hit box shape
	//gameObject -> rock the collision component belongs to.
	void Update(std::shared_ptr<GameObject> gameObject, float frameTime) override;

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
	//The hitbox shape. 
	std::shared_ptr<Circle2D> collisionShape;

	//destruction sound for the rock
	SoundIndex destructionSound;
};