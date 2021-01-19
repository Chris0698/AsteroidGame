//.h file contains the game object class and 4 global functions used for 
//object creation
//w16005124

#pragma once
#include "Shapes.h"
#include <memory>
#include "GameObjectTypes.h"
#include "mysoundengine.h"

#include "RenderComponent.h"
#include "InputComponent.h"
#include "CollisionComponent.h"
#include "PhysicsComponent.h"
#include "HealthComponent.h"

class HealthComponent;

/*
Gameobject class for handling all game objects
	-extends enable_shared_from_this<T> due to *this not being able to be used in smart pointers
*/
class GameObject : public std::enable_shared_from_this<GameObject>
{
public:
	//Constructor, create a brand new game object
	//renderComponent -> Render component for the new game object
	//physicsComponent -> physics component for the new game object
	//collisionComponent -> collision component for the new game object
	//inputComponent -> Input component for the new game object
	//healthComponent -> Health for the game object
	/*
	GameObject
	(
		std::shared_ptr<RenderComponent> renderComponent, 
		std::shared_ptr<PhysicsComponent> physicsComponent,
		std::shared_ptr<CollisionComponent> collisionComponent,
		std::shared_ptr<InputComponent> inputComponent,
		std::shared_ptr<HealthComponent> healthComponent
	);
	*/

	GameObject(std::vector<std::shared_ptr<Component>> components);

	//Update runs once per frame for physics such as movement.
	//frameTime -> time between frames. 
	void Update(float frameTime);

	//get a unique pointer that contains the memory location of the hitbox shape for the gameobject
	std::shared_ptr<IShape2D> GetHitBoxShape();

	//Handle the collision between this game object and the one it has collided with.
	void ProcessCollision(std::shared_ptr<GameObject> gameObjectCollided);

	//Returns if the current game object is active
	bool IsActive();

	//Set if the game object is active
	//active -> a bool is true or false
	void SetActive(bool active);

	//Returns the game object position
	Vector2D GetPosition();

	//Returns the game object angle
	float GetAngle();

	//Get the loaded image
	PictureIndex GetImage();

	//Set the image
	//image -> image of type PictureIndex to be set
	void SetImage(PictureIndex image);

	//Set the scale
	void SetScale(float scale);

	//Get the game object scale
	float GetScale();

	//Get the gameobject transparency
	float GetTransparency();

	//Set the transparency
	//transparency -> how transparent the object will be
	void SetTransparency(float transparency);

	//Get the velocity of the game object
	Vector2D GetVelocity();

	//Set the position of the game object
	//position -> position of the object to be set
	void SetPosition(Vector2D position);

	//Change the angle of the game object
	//angle -> angle of the game object to be set
	void SetAngle(float angle);

	//Chnage the velocity of the game object
	//velocity -> velocity to be set
	void SetVelocity(Vector2D velocity);

	//Destructor 
	virtual ~GameObject();

	//Get if the object is collidable
	bool GetIfCollidable();

	//Set the game object
	void SetGameObjectType(GameObjectType gameObjectType);

	//get the game object type
	GameObjectType GetGameObjectType();

	//Get the collsision component
	std::shared_ptr<CollisionComponent> GetCollisionComponent();

	//Get the physics Component
	//std::shared_ptr<PhysicsComponent> GetPhysicsComponent();

	//Get the render component
	//std::shared_ptr<RenderComponent> GetRenderComponent();

	//get the input component
	//std::shared_ptr<InputComponent> GetInputComponent();

	//get health component
	std::shared_ptr<HealthComponent> GetHealthComponent();

	//Get a reference to the current game object
	std::shared_ptr<GameObject> GetPointer();

	void SetCollisionComponent(std::shared_ptr<CollisionComponent> cc)
	{
		collisionComponent = cc;
	}

	void SetHealthComponent(std::shared_ptr<HealthComponent> hc)
	{
		healthComponent = hc;
	}

private:
	//Component
	//std::shared_ptr<RenderComponent> renderComponent;
	//std::shared_ptr<PhysicsComponent> physicsComponent;
	std::shared_ptr<CollisionComponent> collisionComponent;
	//std::shared_ptr<InputComponent> inputComponent;
	std::shared_ptr<HealthComponent> healthComponent;

	std::vector<std::shared_ptr<Component>> components;

	//General attributes for all game objects
	Vector2D position;

	GameObjectType gameObjectType;

	Vector2D velocity;

	float angle;

	bool isActive;

	float scale;

	float transparency;

	PictureIndex image;
};