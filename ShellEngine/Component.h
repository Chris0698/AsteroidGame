#ifndef _COMPONENT_
#define _COMPONENT_

#include <memory>

class GameObject;

class Component
{
public:
	Component() {}

	virtual void Update(std::shared_ptr<GameObject> gameObject, float frameTime) = 0;

	~Component() {}
};

#endif // !_COMPONENT_
