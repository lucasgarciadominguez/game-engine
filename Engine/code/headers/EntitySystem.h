
/**
 * \author Lucas Garcia
 * \version 1.0
 * \date 2024-06-18
 */

 /**
  * \class EntitySystem
  * \brief Task in charge of updating all the entities created
  */


#pragma once
#include <vector>
#include "System.h"
namespace coldEngine
{
	class Entity;

	class EntitySystem : public System
	{
		std::vector<Entity*> entities;

	public:
		EntitySystem();
		~EntitySystem();
		void Update() override;
		void AddEntity(Entity* entity);
	};
}
