
/**
 * \author Lucas Garcia
 * \version 1.0
 * \date 2024-06-18
 */

 /**
  * \class MessageSystem
  * \brief Manages all the messages, sends them to the listeners and adds listeners.
  */

#pragma once

#include <queue>
#include <memory>
#include "System.h"

namespace coldEngine
{	
	class Message;
	class MessageListener;

	class MessageSystem : public System
	{
		std::vector< std::shared_ptr<MessageListener>> listeners;
		std::queue<std::shared_ptr<Message>> messages;

	public:
		MessageSystem();
		~MessageSystem()
		{
			// The messages are being managed by messages.pop
			//for (MessageListener* listener : listeners)
			//{
			//	delete listener;
			//}
			//listeners.clear();
		}
		void AddMessage(Message* message);
		void AddListener(std::shared_ptr<MessageListener> listener);
		void SendToListeners();
	};
}