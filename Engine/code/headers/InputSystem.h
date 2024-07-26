
/**
 * \author Lucas Garcia
 * \version 1.0
 * \date 2024-06-18
 */

 /**
  * \class InputSystem
  * \brief Task in charge of detecting keyboard inputs and sending these inputs as messages to the message bus
  */

#pragma once
#include <memory>
#include "System.h"

namespace coldEngine
{
	class MessageSystem;

	class InputSystem : public System
	{
		std::shared_ptr<MessageSystem> messageSystem;

	public:
		InputSystem(std::shared_ptr<MessageSystem> bus);
		~InputSystem()
		{
		}
		void Update() override;
	};
}