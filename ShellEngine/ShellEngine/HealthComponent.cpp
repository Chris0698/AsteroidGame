#include "HealthComponent.h"
#include "ObjectManager.h"
#include "GameObject.h"

HealthComponent::HealthComponent(std::shared_ptr<ObjectManager> objectManager, int startingHealth)
	:objectManager(objectManager), currentHealth(startingHealth)
{

}

void HealthComponent::Initialise()
{
	MySoundEngine *pMySoundEngine = MySoundEngine::GetInstance();
	HealthComponent::destructionSound = pMySoundEngine->LoadWav(L"rockExplosion.wav");
}

void HealthComponent::TakeDamage1HP(std::shared_ptr<GameObject> gameObject)
{
	HealthComponent::currentHealth--;

	if (currentHealth <= 0)
	{
		Death(gameObject);
	}
}

void HealthComponent::TakeDamage(int damage, std::shared_ptr<GameObject> gameObject)
{
	currentHealth = currentHealth - damage;

	if (currentHealth <= 0)
	{
		Death(gameObject);
	}
}

void HealthComponent::Update(std::shared_ptr<GameObject> gameObject, float frameTime)
{
	/*
	if (currentHealth <= 0)
	{
		Death(gameObject);
	}
	*/
}

void HealthComponent::Death(std::shared_ptr<GameObject> gameObject)
{
	//create an explosion
//	std::shared_ptr<GameObject> explosion = objectManager->Create(GameObjectType::EXPLOSION);

//	explosion->SetPosition(gameObject->GetPosition());
//	explosion->SetScale(gameObject->GetScale());

	//Play a sound, in space, in a vacuum, where no one can here you. 
	//But hey if we adding friction then might as well. Who knows maybe a space monster can hear it.... 
	MySoundEngine::GetInstance()->Play(destructionSound, false);

//B	objectManager->AddObject(explosion);

	gameObject->SetActive(false);
}

int HealthComponent::GetCurrentHealth()
{
	return HealthComponent::currentHealth;
}

void HealthComponent::SetHealth(int newHealth)
{
	HealthComponent::currentHealth = newHealth;
}
