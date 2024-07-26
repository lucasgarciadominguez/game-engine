
/**********************************************************************
*Project           : ColdEngine
*
*Author : Lucas García
*
*
*Purpose : 3D Engine compiled as a static library (.lib) that can generate an .exe
*
**********************************************************************/

#include "MessageSystem.h"
#include "Message.h"
#include "MessageListener.h"

namespace coldEngine
{
	MessageSystem::MessageSystem() = default;

	void MessageSystem::AddMessage(Message* message)
	{
		messages.push(std::shared_ptr<Message> (message));
	}

	void MessageSystem::AddListener(std::shared_ptr<MessageListener> listener)
	{
		listeners.push_back(listener);
	}

	void MessageSystem::SendToListeners()
	{
		while (!messages.empty())
		{
			for (std::shared_ptr<MessageListener> listener : listeners)
			{
				listener->UseMessage(messages.front().get());
			}
			messages.pop(); //deletes from the qeue and calls the automatic destructor of shared_ptr
		}
	}

}