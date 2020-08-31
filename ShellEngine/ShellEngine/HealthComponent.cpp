#include "HealthComponent.h"
#include "ObjectManager.h"
#include "GameObject.h"

HealthComponent::HealthComponent(std::shared_ptr<ObjectManager> objectManager, int startingHealth)
	:objectManager(objectManager)
{
	HealthComponent::currentHealth = startingHealth;
}

void HealthComponent::Initialise()
{
	MySoundEngine *pMySoundEngine = MySoundEngine::GetInstance();
	HealthComponent::destructionSound = pMySoundEngine->LoadWav(L"rockExplosion.wav");
}

void HealthComponent::TakeDamage1HP()
{
	HealthComponent::currentHealth--;
}

void HealthComponent::TakeDamage(int damage)
{
	HealthComponent::currentHealth = HealthComponent::currentHealth - damage;
}

void HealthComponent::CheckIfStillAlive(std::shared_ptr<GameObject> gameObject)
{
	if (HealthComponent::currentHealth <= 0)
	{
		HealthComponent::Death(gameObject);
	}
}

void HealthComponent::Death(std::shared_ptr<GameObject> gameObject)
{
	//create an explosion
	std::shared_ptr<GameObject> explosion = objectManager->Create(GameObjectType::EXPLOSION);

	explosion->SetPosition(gameObject->GetPosition());
	explosion->SetScale(gameObject->GetScale());

	//Play a sound, in space, in a vacuum, where no one can here you. 
	//But hey if we adding friction then might as well. Who knows maybe a space monster can here it.... 
	MySoundEngine::GetInstance()->Play(HealthComponent::destructionSound, false);

	objectManager->AddObject(explosion);

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
