//Level class is for levels. Different levels with different difficulty is created from here
//w16005124

#pragma once
#include "GameObject.h"
#include "mysoundengine.h"
#include "ObjectManager.h"

/*
Level controls and manages the level
Multiple different levels would probably be handled by a level manager class 
for values such as number of starting rocks, players lives,
due to a lack of level manager the values will come straight from the game code
class
*/
class Level
{
public:
	//Construct a new level
	Level();

	//Initialise the created level
	//startingNumberOfRocks -> Starting number of rocks in the level
	//numberOfPlayersLives -> the starting number of lives a player would have. Defaults to 1
	//*backgroundMusic -> background music for the game. Defaults to nothing
	void Initialise(int startingNumberOfRocks, int numberOfPlayerLives = 1, wchar_t *backgroundMusic = L"");

	//Called once per frame
	//frameTime -> time bwteen 2 frames
	void Update(float frameTime);

	//Displays the HUD to the user such as scrore, player health etc
	void DisplayHUD();

	//Call to end the level
	void EndLevel();

	//The game is over
	void GameOver();

	//Probably needed
	~Level();

private:
	//Create some rocks and displays them
	void CreateRocks();

	//Background music
	SoundIndex backgroundMusic;

	//Number of rocks in the level
	int numberOfRocks;

	//Players score
	int score;

	//Number of lives the player has remaining
	int playerLivesRemaining;

	//reference to the object manager 
	std::shared_ptr<ObjectManager> objectManager;

	//Max time limit before all inactive objects are deleted, 2 seconds
	const float TIME_BEFORE_DELETE_INACTIVE_OBJECTS = 2.0F;

	//Timer for the level, used for deleting inactive objects
	float timer;
};