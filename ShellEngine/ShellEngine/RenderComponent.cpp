//cpp file for render component
//w16005124

#include "RenderComponent.h"
#include "GameObject.h"

RenderComponent::RenderComponent()
{
}

void RenderComponent::Update(std::shared_ptr<GameObject> gameObject, float frameTime)
{
	if (gameObject->IsActive())
	{
		MyDrawEngine* pMyDrawEngine = MyDrawEngine::GetInstance();
		pMyDrawEngine->DrawAt
		(
			gameObject->GetPosition(),
			gameObject->GetImage(),
			gameObject->GetScale(),
			gameObject->GetAngle(),
			gameObject->GetTransparency()
		);
	}
}

void RenderComponent::LoadImage(std::shared_ptr<GameObject> gameObject, wchar_t *fileName)
{
	MyDrawEngine *pDrawEngine = MyDrawEngine::GetInstance();
	PictureIndex image = pDrawEngine->LoadPicture(fileName);
	
	if (!image)
	{
		MyDrawEngine::GetInstance()->WriteText(0, 0, L"Error loading " + *fileName, MyDrawEngine::RED);
	}
	else
	{
		gameObject->SetImage(image);
	}
}
