//global function containing the create ship method
//w16005124

#include "RenderComponent.h"
#include "SpaceshipInputComponent.h"
#include "SpaceshipPhysicsComponent.h"
#include "SpaceshipCollisionComponent.h"
#include "GameObject.h"
#include "GameObjectFactory.h"
#include "HealthComponent.h"

//global function to create a gameobject of the type spaceship 
inline std::shared_ptr<GameObject> CreateShip(std::shared_ptr<ObjectManager>& objectManager)
{
	const float SCALE = 1.25f;
	int startingHealth = 1;

	std::shared_ptr<RenderComponent> shipRenderComponent (new RenderComponent());
	std::shared_ptr<SpaceshipInputComponent> shipInputComponent (new SpaceshipInputComponent(objectManager));
	std::shared_ptr<SpaceshipPhysicsComponent> shipPhysicsComponent (new SpaceshipPhysicsComponent());
	std::shared_ptr<HealthComponent> healthComponent(new HealthComponent(objectManager, startingHealth));
	std::shared_ptr<SpaceshipCollisionComponent> shipCollisionComponent 
	(
		new SpaceshipCollisionComponent(std::shared_ptr<Circle2D> (new Circle2D()))
	);

	std::vector<std::shared_ptr<Component>> components;
	components.push_back(shipRenderComponent);
	components.push_back(shipInputComponent);
	components.push_back(shipPhysicsComponent);
	components.push_back(healthComponent);
	components.push_back(shipCollisionComponent);

	std::shared_ptr<GameObject> gameObject(new GameObject(components));
	gameObject->SetCollisionComponent(shipCollisionComponent);
	gameObject->SetHealthComponent(healthComponent);

	//Load and spaceship image and apply it to this game object
	shipRenderComponent->LoadImage(gameObject, L"spaceship.bmp");
	
	//Load the sounds, input and collision.
	shipInputComponent->Initialise();
	healthComponent->Initialise();

	//Set the attributes
	gameObject->SetScale(SCALE);
	gameObject->SetPosition(Vector2D(300, 300));
	gameObject->SetActive(true);
	gameObject->SetAngle(0.0f);
	gameObject->SetTransparency(0);
	gameObject->SetGameObjectType(GameObjectType::SHIP);

	return gameObject;
}