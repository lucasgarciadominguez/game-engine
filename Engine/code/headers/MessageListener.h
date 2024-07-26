
/**
 * \author Lucas Garcia
 * \version 1.0
 * \date 2024-06-18
 */

 /**
  * \class MessageListener
  * \brief Base class for creating objects that will be waiting for messages
  */

#pragma once
#include <memory>
namespace coldEngine
{
	class Message;
	class MessageSystem;

	class MessageListener
	{

		std::shared_ptr<MessageSystem> messageSystem;

	public:
		MessageListener(std::shared_ptr < MessageSystem> bus);
		
		virtual void UseMessage(Message* message);
	};
}