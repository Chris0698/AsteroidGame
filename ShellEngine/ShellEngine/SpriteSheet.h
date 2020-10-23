#ifndef _SPRITE_SHEET_
#define _SPRITE_SHEET_

#include "mydrawengine.h"

class SpriteSheet
{
public:
	SpriteSheet();

	void LoadSpriteSheet();

	void TestDrawSpriteSheet();

	void GetImage();

	~SpriteSheet();
private:
	PictureIndex spriteSheet;

	PictureIndex rock;
};

#endif // !_SPRITE_SHEET_
