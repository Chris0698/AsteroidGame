//function to create bullets
//w16005124

#include "BulletRenderComponent.h"
#include "BulletCollisionComponent.h"
#include "BulletPhysicsComponent.h"
#include "GameObject.h"

//global function to create a gameobject of the type bullet 
//objectManager -> object manager of the game
inline std::shared_ptr<GameObject> CreateBullet(std::shared_ptr<ObjectManager> &objectManager)
{
	const float SCALE = 6.0f;	//scale of the bullets

	//components
	std::shared_ptr<BulletRenderComponent> bulletRenderComponent (new BulletRenderComponent());
	std::shared_ptr<BulletCollisionComponent> bulletCollisionComponent (new BulletCollisionComponent(std::shared_ptr<Circle2D> (new Circle2D())));
	std::shared_ptr<BulletPhysicsComponent> bulletPhysicsComponent (new BulletPhysicsComponent());

	std::shared_ptr<GameObject> gameObject
	(
		new GameObject
		(
			//passing the created components
			bulletRenderComponent, 
			bulletPhysicsComponent, 
			bulletCollisionComponent, 
			nullptr,
			nullptr
		)
	);

	//Bullet image
	bulletRenderComponent->LoadImage(gameObject, L"bullet.bmp");

	//Setting the attribute for the bullet game object
	gameObject->SetActive(true);
	gameObject->SetTransparency(0);
	gameObject->SetScale(SCALE);
	gameObject->SetGameObjectType(GameObjectType::BULLET);

	return gameObject;
}