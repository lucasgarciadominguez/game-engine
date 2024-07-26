
/**********************************************************************
*Project           : ColdEngine
*
*Author : Lucas García
*
*
*Purpose : 3D Engine compiled as a static library (.lib) that can generate an .exe
*
**********************************************************************/

#include "MessageListener.h"
#include "MessageSystem.h"
#include <memory>
namespace coldEngine
{
	MessageListener::MessageListener(std::shared_ptr < MessageSystem> bus)
	{
		messageSystem = bus;
	}
	void MessageListener::UseMessage(Message* message)
	{

	}
}

