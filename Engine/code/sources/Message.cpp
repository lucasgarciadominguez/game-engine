
/**********************************************************************
*Project           : ColdEngine
*
*Author : Lucas García
*
*
*Purpose : 3D Engine compiled as a static library (.lib) that can generate an .exe
*
**********************************************************************/

#include "Message.h"

namespace coldEngine
{
	Message::Message(string message)
	{
		messageEvent = message;
	}
	Message::~Message()
	{
	}
	string Message::getEvent()
	{
		return messageEvent;
	}
}

