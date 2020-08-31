//rock.cpp contains a global function used for rock creation in the game
//w16005124

#include "RockRenderComponent.h"
#include "RockCollisionComponent.h"
#include "RockPhysicsComponent.h"
#include "GameObject.h"
#include "HealthComponent.h"

//global function to create a gameobject of the type rock 
//objectManager -> object manager of the game
inline std::shared_ptr<GameObject> CreateRock(std::shared_ptr<ObjectManager> &objectManager) 
{
	int startingHealth = 1;

	//At this point i feel like i should of used raw pointers, sick of writing std::shared_ptr at this stage
	//Anyways create the required components
	std::shared_ptr<RockRenderComponent> rockRenderComponent(new RockRenderComponent());
	std::shared_ptr<RockPhysicsComponent> rockPhysicsComponent(new RockPhysicsComponent());
	std::shared_ptr<HealthComponent> healthComponent(new HealthComponent(objectManager, startingHealth));
	std::shared_ptr<RockCollisionComponent> rockCollisionComponent
	(
		new RockCollisionComponent
		(
			objectManager,
			std::shared_ptr<Circle2D> (new Circle2D())
		)
	);

	//Create the new game object here
	std::shared_ptr<GameObject> gameObject
	(
		new GameObject
		(	
			rockRenderComponent,
			rockPhysicsComponent,
			rockCollisionComponent,
			nullptr,
			healthComponent
		)
	);

	MyDrawEngine *pMyDrawEngine = MyDrawEngine::GetInstance();

	int screenHeight = 0;
	int screenWidth = 0;

	if (pMyDrawEngine)
	{
		//Get height and width
		screenHeight = pMyDrawEngine->GetScreenHeight();
		screenWidth = pMyDrawEngine->GetScreenWidth();
	}
	else
	{
		//if Mydrawengine not initialised then use default hard coded from 
		//values that are similar to my laptop dimensions 
		screenHeight = 800;
		screenWidth = 1200;
	}

	float randomXPosition = rand() % screenWidth * 2 - screenWidth;		//Get a number between the screen width
	float randomYPosition = rand() % screenHeight * 2 - screenHeight;		//Get a number between the screen height
	int randomAngle = rand() % 4;					//Angle is in radians, can't get a random float number
	int randomRockScale = rand() % 3 + 1;			//Either a scale of 1, 2 or 3
	Vector2D rockStartingPosition(randomXPosition, randomYPosition);	//Vector2D of the random numbers

	rockRenderComponent->LoadRockImage(gameObject);		//load the rock image
	healthComponent->Initialise();

	//Set the general attributes
	gameObject->SetActive(true);
	gameObject->SetVelocity(Vector2D(0, 0));
	gameObject->SetPosition(rockStartingPosition);
	gameObject->SetAngle(randomAngle);
	gameObject->SetScale(randomRockScale);
	gameObject->SetTransparency(0);
	gameObject->SetGameObjectType(GameObjectType::ROCK);

	//return the new game object
	return gameObject;
}