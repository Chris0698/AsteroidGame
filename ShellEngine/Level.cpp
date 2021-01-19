//cpp file for the level class containing the different functions
//w16005124

#include "Level.h"

#include <thread>

Level::Level()
{
}

void Level::Initialise(int startingNumberOfRocks, int numberOfPlayerLives, wchar_t *backgroundMusic)
{
	//Check to see if background music is empty
	if (!(wcslen(backgroundMusic) == 0))
	{
		MySoundEngine *pMySoundEngine = MySoundEngine::GetInstance();
		Level::backgroundMusic = pMySoundEngine->LoadWav(backgroundMusic);
		pMySoundEngine->Play(Level::backgroundMusic, true);
	}

	Level::score = 0;
	Level::timer = 0.0f;
	Level::objectManager = std::shared_ptr<ObjectManager>(new ObjectManager());
	Level::numberOfRocks = startingNumberOfRocks;
	Level::playerLivesRemaining = numberOfPlayerLives; //Code relating to players lives ain't used elsewhere in game


	//cant do GameObjectFactory* gameObjectFactory = GameObjectFactory::GetInstance(); , crashes the thing dead
	std::shared_ptr<GameObjectFactory> gameObjectFactory(GameObjectFactory::GetInstance());
	gameObjectFactory->RegisterAllObjects();
	std::shared_ptr<GameObject> spaceship = gameObjectFactory->Create(GameObjectType::SHIP);

	objectManager->AddObject(spaceship);


	//Create some rocks to shoot at
	CreateRocks();



	//spriteSheet = new SpriteSheet();
	//spriteSheet->LoadSpriteSheet();


}

void Level::Update(float frameTime)
{
	//spriteSheet->TestDrawSpriteSheet();
	//Timer, if timer exceeds a limit then delete all inactive game objects
	Level::timer = Level::timer + frameTime;  

	if (Level::numberOfRocks <= 0)
	{
		CreateRocks();
	}

	Level::objectManager->UpdateAll(frameTime);
//	Level::objectManager->RenderAll();
	Level::objectManager->CheckAllCollisions();

	//std::thread collisionThread(&ObjectManager::CheckAllCollisions, &objectManager);

	//collisionThread.join();

//	Level::objectManager->RunThreads(frameTime);

	//if the timer is greater then a time to delete inactive game objects, then enter this loop 
	if (Level::timer >= Level::TIME_BEFORE_DELETE_INACTIVE_OBJECTS)
	{
		//delete the objects and reset the timer
		Level::objectManager->DeleteInactive();
		Level::timer = 0.0f;
	}

	//You ran out lives
	if (Level::playerLivesRemaining == 0)
	{
		Level::GameOver();
	}
}

void Level::DisplayHUD()
{
	//If there was a scoreboard class then it would probably be managed here i guess. 
	//Didn't include it, not part of the assigment

	//MyDrawEngine::GetInstance()->WriteText(Vector2D(-1500, 900), L"Score: " + Level::score, MyDrawEngine::WHITE);
	//MyDrawEngine::GetInstance()->WriteText(Vector2D(-1400, 800), L"Rocks Remaining: " + Level::numberOfRocksRemaining, MyDrawEngine::WHITE);

	//DEBUG
	MyDrawEngine::GetInstance()->WriteDouble(0, 0 , MyDrawEngine::GetInstance()->GetScreenHeight(), MyDrawEngine::WHITE);
	MyDrawEngine::GetInstance()->WriteDouble(0, 20 , MyDrawEngine::GetInstance()->GetScreenWidth(), MyDrawEngine::WHITE);
}


void Level::EndLevel()
{
	//Delete all objects at the end of the level
	Level::objectManager->DeleteAll();
}

void Level::GameOver()
{
	MyDrawEngine *pMyDrawEngine = MyDrawEngine::GetInstance();
	if (pMyDrawEngine)
	{
		//Get the screen width and height
		int screenWidth = pMyDrawEngine->GetScreenWidth();
		int screenHeight = pMyDrawEngine->GetScreenHeight();

		//50 substracted to make it more "central"
		MyDrawEngine::GetInstance()->WriteText((screenWidth / 2) - 50, (screenHeight / 2), L"Game Over!", MyDrawEngine::WHITE);
	}
	else
	{
		//Put game over text somewhere sensible (hopefully)
		MyDrawEngine::GetInstance()->WriteText( 450, 350, L"Game Over!", MyDrawEngine::WHITE);
	}
	
}

Level::~Level()
{
}

void Level::CreateRocks()
{
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

	//Create rocks and place them with in the screen 
	for (int i = 0; i < Level::numberOfRocks; i++)
	{
		//std::shared_ptr<GameObjectFactory> gameObjectFactory(GameObjectFactory::GetInstance());
		//std::shared_ptr<GameObject> rock = gameObjectFactory->Create(GameObjectType::ROCK);
		//objectManager->AddObject(rock);
	}
}