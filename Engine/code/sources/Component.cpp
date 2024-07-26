
/**********************************************************************
*Project           : ColdEngine
*
*Author : Lucas García
*
*
*Purpose : 3D Engine compiled as a static library (.lib) that can generate an .exe
*
**********************************************************************/

#include "..\headers\Component.h"

namespace coldEngine
{

	Component::Component()
	{
		linkedEntity = nullptr;
	}
	void Component::SetEntity(Entity* entity)
	{
		linkedEntity = entity;
	}
	void Component::Update()
	{
	}
}

