#ifndef _GAME_OBJECT_FACTORY_
#define _GAME_OBJECT_FACTORY_

#include <list>
#include "GameObject.h"
#include <algorithm>
#include <memory>
#include <map>

class GameObjectFactory : public std::enable_shared_from_this<GameObjectFactory>
{
public:	
	static GameObjectFactory* GetInstance();

	void RegisterAllObjects();

	//Create a game object that is registered in the game
	//gameObjectType -> the key of the object
	std::shared_ptr<GameObject> Create(GameObjectType gameObjectType);
	
	~GameObjectFactory();
private:
	GameObjectFactory();

	//posh way to rename things
	//typedef {variableType} (VariableTypeNewName)
	typedef std::shared_ptr<GameObject>(*GameObjectCreationMethod) (std::shared_ptr<GameObjectFactory>&);

	void RegisterObject(GameObjectType gameObjectType, GameObjectCreationMethod gameObjectCreation);

	static GameObjectFactory* Instance;

	//Map to store each object 
	std::map<GameObjectType, GameObjectCreationMethod> objectMap;

	//Get a reference to the object manager
	std::shared_ptr<GameObjectFactory> GetPointer();
};

//globals to create GameObjects
std::shared_ptr<GameObject> CreateExplosion(std::shared_ptr<GameObjectFactory>& gameObjectFactory);
std::shared_ptr<GameObject> CreateShip(std::shared_ptr<GameObjectFactory>& gameObjectFactory);
std::shared_ptr<GameObject> CreateBullet(std::shared_ptr<GameObjectFactory>& gameObjectFactory);
std::shared_ptr<GameObject> CreateRock(std::shared_ptr<GameObjectFactory>& gameObjectFactory);

#endif // !_GAME_OBJECT_FACTORY_
