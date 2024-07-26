
/**
 * \author Lucas Garcia
 * \version 1.0
 * \date 2024-06-18
 */

 /**
  * \class System
  * \brief Base class for tasks
  */


#pragma once
#include <Component.h>
#include <memory>
#include <Scene.h>
namespace coldEngine
{
	class System
	{
	protected:
		std::shared_ptr<Scene> level;

	public:

		virtual Component* create_component(Entity& entity)
		{
			return 0;
		}
        virtual void Update() { }
	};
}
