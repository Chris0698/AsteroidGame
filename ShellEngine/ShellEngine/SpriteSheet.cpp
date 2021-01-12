#include "SpriteSheet.h"

SpriteSheet::SpriteSheet()
{
}

void SpriteSheet::LoadSpriteSheet()
{
	MyDrawEngine* drawEngine = MyDrawEngine::GetInstance();
	spriteSheet = drawEngine->LoadPicture(L"SpriteSheet.png");
}

void SpriteSheet::TestDrawSpriteSheet()
{
	Vector2D pos = Vector2D(0, 0);
	MyDrawEngine* pMyDrawEngine = MyDrawEngine::GetInstance();
	pMyDrawEngine->DrawAt
	(
		pos,
		spriteSheet
	);
}

void SpriteSheet::TestGetRock()
{
	//using 2D Vector get a rock at the top of the sheet, somehow

}



void SpriteSheet::GetImage()
{
	
}

SpriteSheet::~SpriteSheet()
{
}
