//bullet collision class
//w16005124

#pragma once
#include "CollisionComponent.h"

//Class for bullet collisions
class BulletCollisionComponent : public CollisionComponent
{
public:
	//constructor
	//collisionShape -> shape used for object hitbox
	BulletCollisionComponent(std::shared_ptr<Circle2D> collisionShape);

	//Places the collision shape on the game object
	//gameObject -> Game object the collision shape will be applied to
	void PlaceHitboxShape(std::shared_ptr<GameObject> gameObject) override;

	//Process a collision between this game object and another one
	//gameObject -> the game object that has the collision
	//gameObjectCollided -> game object that been collided
	void ProcessCollision
	(
		std::shared_ptr<GameObject> gameObject,
		std::shared_ptr<GameObject> gameObjectCollided
	) override;

	//Get the hitbox shape
	std::shared_ptr<IShape2D> GetHitBoxShape() override;
private:
	//The hitbox
	std::shared_ptr<Circle2D> collisionShape;
};