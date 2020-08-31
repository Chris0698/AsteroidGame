//cpp file for collision component although contains very little code
//w16005124

#include "CollisionComponent.h"

CollisionComponent::CollisionComponent()
{
}

bool CollisionComponent::GetIfCollidable()
{
	return CollisionComponent::isCollidable;
}

CollisionComponent::~CollisionComponent()
{
}
