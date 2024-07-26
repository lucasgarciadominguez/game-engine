
/**
 * \author Lucas Garcia
 * \version 1.0
 * \date 2024-06-18
 */

 /**
  * \class Message
  * \brief Base class for the messages used in the MessageSystem
  */

#pragma once

#include <string>

namespace coldEngine
{
	using namespace std;

	///
	/// Base class for creating messages
	///
	class Message
	{
		string messageEvent;

	public:
		Message(string event);
		~Message();
		string getEvent();
	};
}