#ifndef _SPRITE_SHEET_
#define _SPRITE_SHEET_

//https://thatgamesguy.co.uk/cpp-game-dev-11/

#include "mydrawengine.h"

class SpriteSheet
{
public:
	SpriteSheet();

	void LoadSpriteSheet();

	void TestDrawSpriteSheet();

	void TestGetRock();

	void GetImage();

	~SpriteSheet();
private:
	PictureIndex spriteSheet;

	PictureIndex rock;
};

#endif // !_SPRITE_SHEET_
