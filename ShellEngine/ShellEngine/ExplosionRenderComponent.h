//Explosion rendering class
//w16005124

#pragma once
#include "RenderComponent.h"
#include <vector>

//Class for handling explosion rendering
class ExplosionRenderComponent : public RenderComponent
{
public:
	//constructa
	ExplosionRenderComponent();

	//Overrides the default render method provided in the render component
	//gameObject -> The game object to be rendered
	//frameTime => time between the last 2 frames. 
	void Render(std::shared_ptr<GameObject> gameObject, float frameTime) override;

	//Loads multiple images into memory
	//PLEASE NOTE: THIS DOES NOT OVER_RIDES THE LOAD IMAGE METHOD IN RENDER COMPONENT
	void LoadImages();

private:
	//a vector to store the images
	std::vector<PictureIndex> explosionImages;

	//current explosion number
	float currentImageNunber;

	//max amount of the explosion images
	static const int NUMBER_OF_EXPLOSION_IMAGES = 8;
};