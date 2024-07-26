
/**********************************************************************
*Project           : ColdEngine
*
*Author : Lucas García
*
*
*Purpose : 3D Engine compiled as a static library (.lib) that can generate an .exe
*
**********************************************************************/

#include "EntitySystem.h"
#include "Entity.h"
#include "RenderSystem.h"
namespace coldEngine
{
	EntitySystem::EntitySystem() = default;

	EntitySystem::~EntitySystem()
	{
	}

	void EntitySystem::Update()
	{
		for (Entity* entity : entities)
		{
			entity->Update();
		}
	}

	void EntitySystem::AddEntity(Entity* entity)
	{
		entities.push_back(entity);
	}
}

