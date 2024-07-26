
/**
 * \author Lucas Garcia
 * \version 1.0
 * \date 2024-06-18
 */

 /**
  * \class EntityListenerComponent
  * \brief Component attached to entities for enabling them changes
  *
  */

#pragma once
#include <MessageListener.h>
#include <Component.h>
#include <string>
#include <memory>
using namespace std;

namespace coldEngine
{
	class Entity;

	class EntityListenerComponent : public MessageListener, public Component
	{

	public:
		EntityListenerComponent(std::shared_ptr < MessageSystem> bus);
		/**
		* \brief Decodes the message and uses them for other tasks
		* Substrings the message and uses them for changing the behaviour in the entities
		*/
		void UseMessage(Message* message) override;

	};
}