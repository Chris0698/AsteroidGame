//cpp file for spaceship input component 
//w16005124

#include "SpaceshipInputComponent.h"
#include "GameObject.h"

SpaceshipInputComponent::SpaceshipInputComponent(std::shared_ptr<ObjectManager> objectManager)
	:objectManager(objectManager)
{
	//Allow a bullet to be shot when first spawn in
	SpaceshipInputComponent::timer = SpaceshipInputComponent::SHOT_TIMER;
}

void SpaceshipInputComponent::Update(std::shared_ptr<GameObject> gameObject, float frameTime)
{
	if (gameObject->IsActive())
	{
		const float PI = 3.14159265;
		const float ACCELERATION_MAGITUDE = 60.0f;
		const float BEARING_DIRECTION = 40.0f;

		MyInputs *inputPointer = MyInputs::GetInstance();
		inputPointer->SampleKeyboard();
		MySoundEngine *pSoundEngine = MySoundEngine::GetInstance();
		

		//get the variables
		float angle = gameObject->GetAngle();
		float scale = gameObject->GetScale();
		Vector2D position = gameObject->GetPosition();
		Vector2D velocity = gameObject->GetVelocity();

		//For shooting
		timer = timer + frameTime;

		//Insurance policy, make sure the keyboard is available 
		if (inputPointer->KeyboardIsAvailable())
		{
			if (inputPointer->KeyPressed(DIK_UPARROW) || inputPointer->KeyPressed(DIK_W))
			{
				Vector2D acceleration(0.0f, ACCELERATION_MAGITUDE);

				acceleration.setBearing(angle, BEARING_DIRECTION);

				velocity = velocity + acceleration * frameTime;
			}

			if (inputPointer->KeyPressed(DIK_DOWNARROW) || inputPointer->KeyPressed(DIK_S))
			{
				Vector2D acceleration(0.0f, -ACCELERATION_MAGITUDE);

				acceleration.setBearing(angle, -BEARING_DIRECTION);

				velocity = velocity + acceleration * frameTime;
			}

			if (inputPointer->KeyPressed(DIK_LEFTARROW) || inputPointer->KeyPressed(DIK_A))
			{
				Vector2D acceleration(-60.0f, ACCELERATION_MAGITUDE);

				//2 * PI = 360 degrees. We need a quater of the circle
				acceleration.setBearing(angle + 2 * PI / 4, -BEARING_DIRECTION);

				velocity = velocity + acceleration * frameTime;
			}

			if (inputPointer->KeyPressed(DIK_RIGHTARROW) || inputPointer->KeyPressed(DIK_D))
			{
				Vector2D acceleration(60.0f, ACCELERATION_MAGITUDE);

				acceleration.setBearing(angle + 2 * PI / 4, BEARING_DIRECTION);

				velocity = velocity + acceleration * frameTime;
			}

			if ( inputPointer->KeyPressed(DIK_Q))
			{
				angle = angle - 1.0f * frameTime;
			}

			if ( inputPointer->KeyPressed(DIK_E))
			{
				angle = angle + 1.0f * frameTime;
			}

			//code for ship shooting 
			if (inputPointer->KeyPressed(DIK_SPACE) && timer >= SHOT_TIMER)
			{
				Vector2D shipFront;
				shipFront.setBearing(angle, 105.0f);		//Make sure each bullet starts perfectly infront of the ship

				Vector2D frontOfShip = position + shipFront;
				pSoundEngine->Play(shootSound);

				//GameObjectFactory* factory = GameObjectFactory::GetInstance();
				//std::shared_ptr<GameObject> bullet = factory->Create(GameObjectType::BULLET);

//				std::shared_ptr<GameObject> bullet = objectManager->Create(GameObjectType::BULLET);
				
				//Set the bullet angle and starting position using the ship current angle and position
//				bullet->SetPosition(frontOfShip);
//				bullet->SetAngle(gameObject->GetAngle());
//				objectManager->AddObject(bullet);

				std::shared_ptr<GameObjectFactory> factory(GameObjectFactory::GetInstance());
				std::shared_ptr<GameObject> bullet = factory->Create(GameObjectType::BULLET);
				bullet->SetPosition(frontOfShip);
				bullet->SetAngle(gameObject->GetAngle());
				objectManager->AddObject(bullet);

				timer = 0.0f;
			}

			position = position + velocity * frameTime;
		} //endif, maybe alert the user no keyboard but what if they intended to play with the mouse or touchscreen somehow instead?

		//set the variables back
		gameObject->SetPosition(position);
		gameObject->SetAngle(angle);
		gameObject->SetVelocity(velocity);
	}
}


void SpaceshipInputComponent::Initialise()
{
	MySoundEngine *pMySoundEngine = MySoundEngine::GetInstance();
	shootSound = pMySoundEngine->LoadWav(L"shoot.wav");
}
