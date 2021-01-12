//cpp file to explosion render class
//w16005124

#include "ExplosionRenderComponent.h"
#include "GameObject.h"

ExplosionRenderComponent::ExplosionRenderComponent()
{
	ExplosionRenderComponent::currentImageNunber = 0.0f;
}

void ExplosionRenderComponent::Update(std::shared_ptr<GameObject> gameObject, float frameTime)
{
	//I cant think of a decent name. Just read the code, higher the number quicker the animation
	const float ANIMATION_SPEED_RATE = 15.0f;

	ExplosionRenderComponent::currentImageNunber =
		ExplosionRenderComponent::currentImageNunber + ANIMATION_SPEED_RATE * frameTime;

	if (ExplosionRenderComponent::currentImageNunber >= ExplosionRenderComponent::NUMBER_OF_EXPLOSION_IMAGES)
	{
		gameObject->SetActive(false);
	}
	else
	{
		//Draw the image to the screen
		MyDrawEngine::GetInstance()->DrawAt
		(
			gameObject->GetPosition(),
			ExplosionRenderComponent::explosionImages[(int)ExplosionRenderComponent::currentImageNunber],
			gameObject->GetScale() * 2,	//multiply by 2 due to difference in sprite scale 
			gameObject->GetTransparency()
		);
	}
}

void ExplosionRenderComponent::LoadImages()
{
	//for loop to initialise the explosions instead of writing it out line by line 
	for (int i = 0; i < NUMBER_OF_EXPLOSION_IMAGES; i++)
	{
		std::wstring baseName = L"explosion";
		std::wstring ext = L".bmp";
		std::wstring index = std::to_wstring(i);		//convert the index to wstring 
		std::wstring fileName = baseName + index + ext;		//congat the names together by magic

		//Converts the fileName wstring to whcat_t*, again by magic by using &name[0]
		wchar_t *name = &fileName[0];

		PictureIndex explosionImage = MyDrawEngine::GetInstance()->LoadPicture(name);
		ExplosionRenderComponent::explosionImages.push_back(explosionImage);
	}
}