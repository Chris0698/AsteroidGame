//rock.cpp contains a global function used for rock creation in the game
//w16005124

#include "RenderComponent.h"
#include "RockCollisionComponent.h"
#include "RockPhysicsComponent.h"
#include "GameObject.h"
#include "HealthComponent.h"
#include "GameObjectFactory.h"

//global function to create a gameobject of the type rock 
inline std::shared_ptr<GameObject> CreateRock(std::shared_ptr<ObjectManager>& objectManager)
{
	return nullptr;



	/*
	int startingHealth = 1;

	std::shared_ptr<RenderComponent> renderComponent(new RenderComponent());
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

	std::vector<std::shared_ptr<Component>> components;
	components.push_back(renderComponent);
	components.push_back(rockPhysicsComponent);
	components.push_back(healthComponent);
	components.push_back(rockCollisionComponent);

	std::shared_ptr<GameObject> gameObject (new GameObject(components));

	int pictureNumber = rand() % 4;
	wchar_t* name = L"";
	switch (pictureNumber)
	{
	case 0:
		name = L"rock0.bmp";
		break;
	case 1:
		name = L"rock1.bmp";
		break;
	case 2:
		name = L"rock2.bmp";
		break;
	case 3:
		name = L"rock3.bmp";
		break;
	default:
		name = L"rock0.bmp";
		break;
	}	
	renderComponent->LoadImage(gameObject, name);		//load the rock image

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

	healthComponent->Initialise();

	//Set the general attributes
	gameObject->SetActive(true);
	gameObject->SetVelocity(Vector2D(0, 0));
	gameObject->SetPosition(rockStartingPosition);
	gameObject->SetAngle(randomAngle);
	gameObject->SetScale(randomRockScale);
	gameObject->SetTransparency(0);
	gameObject->SetGameObjectType(GameObjectType::ROCK);

	gameObject->SetCollisionComponent(rockCollisionComponent);
	gameObject->SetHealthComponent(healthComponent);

	return gameObject; */
}