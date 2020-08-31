//global function containing the create ship method
//w16005124

#include "SpaceshipRenderComponent.h"
#include "SpaceshipInputComponent.h"
#include "SpaceshipPhysicsComponent.h"
#include "SpaceshipCollisionComponent.h"
#include "GameObject.h"
#include "HealthComponent.h"

//global function to create a gameobject of the type spaceship 
//objectManager -> object manager of the game
inline std::shared_ptr<GameObject> CreateShip(std::shared_ptr<ObjectManager> &objectManager)
{
	const float SCALE = 1.25f;
	int startingHealth = 1;

	std::shared_ptr<SpaceshipRenderComponent> shipRenderComponent (new SpaceshipRenderComponent());
	std::shared_ptr<SpaceshipInputComponent> shipInputComponent (new SpaceshipInputComponent(objectManager));
	std::shared_ptr<SpaceshipPhysicsComponent> shipPhysicsComponent (new SpaceshipPhysicsComponent());
	std::shared_ptr<HealthComponent> healthComponent(new HealthComponent(objectManager, startingHealth));
	std::shared_ptr<SpaceshipCollisionComponent> shipCollisionComponent 
	(
		new SpaceshipCollisionComponent
		(
			objectManager,
			std::shared_ptr<Circle2D> (new Circle2D())
		)
	);

	//Create the new game object
	std::shared_ptr<GameObject> gameObject
	(
		new GameObject
		(
			shipRenderComponent, 
			shipPhysicsComponent, 
			shipCollisionComponent, 
			shipInputComponent,
			healthComponent
		)
	);

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