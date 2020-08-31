//Render component is the base class for all render components used throughout the game
//Componenet can extends this class to use their own render method or use the one provided
//w16005124

#pragma once
#include "mydrawengine.h"
#include <memory>

//forwards decleration of game object
//Full implemenation takes place further down 
class GameObject;

//Render component class renders an image to the screen. It provides a method to render an image
//although this oculd be overriden.
class RenderComponent
{
public:
	//Constructor for Render Component
	RenderComponent();

	//A default render method, may be over-ridden but upto the programmer
	//gameObject -> The game object to be rendered
	//frameTime => time between the last 2 frames. 
	virtual void Render(std::shared_ptr<GameObject> gameObject, float frameTime);

	//Load 1 image to memory, maybe over-ridden in a sub class
	//gameObject -> The game object where the image will be applied to in the render function
	//fileName -> The name of the sprite to be loaded. 
	virtual void LoadImage(std::shared_ptr<GameObject> gameObject, wchar_t *fileName);

	//Deconstructor
	virtual ~RenderComponent() {}
};