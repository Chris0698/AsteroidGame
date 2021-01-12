//cpp file to object manager
//w16005124

#include "ObjectManager.h"
#include <thread>

void RunThreads(float frameTime)
{
	//create 2 new threads to handle collision and update
	//std::thread updateThread(&ObjectManager::UpdateAll, frameTime);
	//auto updateThread = std::thread(&ObjectManager::UpdateAll, frameTime);
	//std::thread collisionThread (&ObjectManager::CheckAllCollisions, this);

	//Join each thread back to the main thread
	//updateThread.join();
	//collisionThread.join(); 
}

ObjectManager::ObjectManager()
{
}

void ObjectManager::AddObject(std::shared_ptr<GameObject> pNewObject)
{
	//Move the pointer onto the list
	pGameObjectList.push_back(pNewObject);
}

void ObjectManager::UpdateAll(float frameTime)
{
	//check that the list is not empty
	if (pGameObjectList.size() > 0)
	{
		for (std::shared_ptr<GameObject> &pGameObjectListElement : pGameObjectList)
		{
			if (pGameObjectListElement != nullptr)
			{
				pGameObjectListElement->Update(frameTime);
			}
		}
	}
}

/*
void ObjectManager::RenderAll()
{
	if (pGameObjectList.size() > 0)
	{
		for (std::shared_ptr<GameObject> &pGameObjectListElement : pGameObjectList)
		{
			pGameObjectListElement->Render();
		}
	}
}
*/

void ObjectManager::DeleteInactive()
{
	for (std::shared_ptr<GameObject> &pGameObjectListElement : pGameObjectList)
	{
		if (pGameObjectListElement != nullptr)
		{
			if (!pGameObjectListElement->IsActive())
			{
				pGameObjectListElement.reset();
			}
		}
	}

	//iterator to delete the game object from memory
	auto iterator = std::remove(pGameObjectList.begin(), pGameObjectList.end(), nullptr);
	pGameObjectList.erase(iterator, pGameObjectList.end());
}

void ObjectManager::DeleteAll()
{
	if (!pGameObjectList.empty())
	{
		pGameObjectList.clear();		//clear the list
	}
}

void ObjectManager::CheckAllCollisions()
{
	std::list<std::shared_ptr<GameObject>>::iterator iterator1;
	std::list<std::shared_ptr<GameObject>>::iterator iterator2;
	
	for (iterator1 = pGameObjectList.begin(); iterator1 != pGameObjectList.end(); iterator1++)
	{
		for (iterator2 = std::next(iterator1); iterator2 != pGameObjectList.end(); iterator2++)
		{
			//check that the 2 game objects have a collision component first
			if (((*iterator1)->GetCollisionComponent() != nullptr) && (*iterator2)->GetCollisionComponent() != nullptr)
			{
				if ((*iterator2)->GetIfCollidable() &&
					(*iterator1)->GetHitBoxShape()->Intersects(*(*iterator2)->GetHitBoxShape()))
				{
					(*iterator1)->ProcessCollision(*iterator2);
					(*iterator2)->ProcessCollision(*iterator1);

				}
			}			
		}
	}
}