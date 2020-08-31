//Handles rock rendering although the default render method is used.
//this class is mainly used for loading a different, random, rock image
//w16005124

#pragma once
#include "RenderComponent.h"

//Class for loading a rock image.
//Rendering will use the default method in RenderComponent class 
class RockRenderComponent : public RenderComponent
{
public:
	//constructor
	RockRenderComponent();

	//Load image selects a random number to load an image 
	//gameObject -> the pointer to the rock game object
	void LoadRockImage(std::shared_ptr<GameObject> gameObject);
};