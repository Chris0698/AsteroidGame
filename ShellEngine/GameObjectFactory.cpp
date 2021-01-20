#include "GameObjectFactory.h"
#include "GameObjectTypes.h"
#include "Spaceship.cpp"
#include "Rock.cpp"
#include "Explosion.cpp"
#include "Bullet.cpp"

GameObjectFactory *GameObjectFactory::Instance = nullptr;

GameObjectFactory::GameObjectFactory()
{
}

GameObjectFactory* GameObjectFactory::GetInstance()
{
    if (!Instance)
    {
        Instance = new GameObjectFactory();
    }

    return Instance;
}

void GameObjectFactory::RegisterAllObjects()
{
    RegisterObject(GameObjectType::SHIP, CreateShip);
    RegisterObject(GameObjectType::ROCK, CreateRock);
    RegisterObject(GameObjectType::BULLET, CreateBullet);
    RegisterObject(GameObjectType::EXPLOSION, CreateExplosion);
}

std::shared_ptr<GameObject> GameObjectFactory::Create(GameObjectType gameObjectType, std::shared_ptr<ObjectManager> pointer)
{
    //Get an interator element to the game object type
    std::pair<GameObjectType, GameObjectCreationMethod> pair = *(objectMap.find(gameObjectType));

    //extract the second element into a function 
    GameObjectCreationMethod function = pair.second;
  
    return function(pointer);
}

void GameObjectFactory::Dispose()
{
    delete Instance;
    Instance = nullptr;
}

/*
GameObjectFactory::~GameObjectFactory()
{
}
*/

void GameObjectFactory::RegisterObject(GameObjectType gameObjectType, GameObjectCreationMethod gameObjectCreation)
{
    objectMap.insert(std::make_pair(gameObjectType, gameObjectCreation));
}
