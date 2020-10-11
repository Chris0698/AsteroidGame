//Global function for creating explosion game objects
//w16005124

#include "ExplosionRenderComponent.h"
#include "GameObject.h"

//global function to create a gameobject of the type explosion 
//objectManager -> object manager of the game
inline std::shared_ptr<GameObject> CreateExplosion(std::shared_ptr<ObjectManager>& objectManager)
{
	std::shared_ptr<ExplosionRenderComponent> explosionRenderComponent(new ExplosionRenderComponent());
	explosionRenderComponent->LoadImages();		//load the explosion images into memory

	std::vector<std::shared_ptr<Component>> components;
	components.push_back(explosionRenderComponent);


	std::shared_ptr<GameObject> gameObject(new GameObject(components));

	//angle and starting position would be set by the class that create the explosion e.g rock collision class
	gameObject->SetActive(true);
	gameObject->SetGameObjectType(GameObjectType::EXPLOSION);
	gameObject->SetTransparency(0);
	gameObject->SetVelocity(Vector2D(0, 0));

	return gameObject;
}