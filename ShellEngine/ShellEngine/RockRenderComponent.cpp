//cpp file for rock rendering
//w16005124

#include "RockRenderComponent.h"
#include "GameObject.h"

RockRenderComponent::RockRenderComponent()
{
}

void RockRenderComponent::LoadRockImage(std::shared_ptr<GameObject> gameObject)
{
	//No need to srand again
	int pictureIndexNumber = rand() % 4;

	switch (pictureIndexNumber)
	{
	case 0:
		RenderComponent::LoadImage(gameObject, L"rock0.bmp");
		break;
	case 1:
		RenderComponent::LoadImage(gameObject, L"rock1.bmp");
		break;
	case 2:
		RenderComponent::LoadImage(gameObject, L"rock2.bmp");
		break;
	case 3:
		RenderComponent::LoadImage(gameObject, L"rock3.bmp");
		break;
	default:
		RenderComponent::LoadImage(gameObject, L"rock0.bmp");
		break;
	}
}
