
/**
 * \author Lucas Garcia
 * \version 1.0
 * \date 2024-06-18
 */

 /**
  * \class Kernel
  * \brief Updates all the systems / tasks in runtime.
  *
  * First gets the input,updates the transforms of the entities and then send messages and finally renders the scene
  */

#pragma once
#include <memory>
namespace coldEngine
{
	class EntitySystem;
	class RenderSystem;
	class InputSystem;
	class MessageSystem;

	class Kernel
	{
	private:

		std::shared_ptr<EntitySystem> entitySystem;
		std::shared_ptr < RenderSystem> renderSystem;
		std::shared_ptr < InputSystem> inputSystem;
		std::shared_ptr < MessageSystem> messageSystem;

	public:

		Kernel(std::shared_ptr < EntitySystem> _entitySystem, std::shared_ptr < RenderSystem> _renderSystem, std::shared_ptr < InputSystem> _inputSystem, std::shared_ptr < MessageSystem> _messageSystem);
		~Kernel();
		void Update();

	};
}
