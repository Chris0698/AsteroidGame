//For spaceship collision
//w16005124

#pragma once
#include "CollisionComponent.h"

//SpaceshipCollisionComponent handles collision on spaceships
class SpaceshipCollisionComponent : public CollisionComponent
{
public:
	//constructor of the component
	//collisionShape -> collision shape used for spaceship, in this case a circle 
	SpaceshipCollisionComponent(std::shared_ptr<Circle2D> collisionShape);

	//Places the collision shape
	//gameObject -> The shape it belongs to.
	void Update(std::shared_ptr<GameObject> gameObject, float frameTime) override;

	//Process a collision between the spaceship and another game object
	//gameObject -> The spaceship this component belong to
	//gameObjectCollided -> The game object this component collided into
	void ProcessCollision(std::shared_ptr<GameObject> gameObject, std::shared_ptr<GameObject> gameObjectCollided) override;
	
	//Gets the hitbox shape
	std::shared_ptr<IShape2D> GetHitBoxShape() override;
private:
	//Collision shape used for the spaceship
	std::shared_ptr<Circle2D> collisionShape;;

	//destruction sound for the spaceship
	SoundIndex destructionSound;
};