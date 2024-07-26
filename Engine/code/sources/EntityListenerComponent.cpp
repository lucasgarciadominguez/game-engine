
/**********************************************************************
*Project           : ColdEngine
*
*Author : Lucas García
*
*
*Purpose : 3D Engine compiled as a static library (.lib) that can generate an .exe
*
**********************************************************************/

#include "EntityListenerComponent.h"
#include <MessageSystem.h>
#include <Message.h>
#include <Entity.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include<memory>
//#include <SFML/Audio.h>

namespace coldEngine
{

	EntityListenerComponent::EntityListenerComponent(std::shared_ptr < MessageSystem> bus)
		: MessageListener(bus), Component()
	{
	}
	void EntityListenerComponent::UseMessage(Message* message)
	{
		if (message->getEvent() == "w"|| message->getEvent() == "a"|| message->getEvent() == "s"|| message->getEvent() == "d")
		{
			//linkedEntity->Translate(0.1f, 0.f, 0.f);

		}
		else
		{
			std::string messageFound = message->getEvent();
			std::vector<std::string> parameters;
			std::stringstream ss(messageFound);
			std::string token;

			// Iterates above the string using getline with '|' as delimeter
			while (std::getline(ss, token, '|')) {
				parameters.push_back(token);
			}
			if (linkedEntity != nullptr && !parameters.empty()) 
			{
				std::string firstParameter = parameters[0];

				if (parameters[1] == linkedEntity->name)
				{
					std::string messageVector = parameters[2];
					std::vector<std::string> parametersVector;
					std::stringstream ssVec(messageVector);
					std::string tokenVector;

					while (std::getline(ssVec, tokenVector, ',')) {
						parametersVector.push_back(tokenVector);
					}

					if (firstParameter == "UpdatePosition") {
						linkedEntity->Translate(std::stof(parametersVector[0]), std::stof(parametersVector[1]), std::stof(parametersVector[2]));
					}
					else if (firstParameter == "UpdateRotation") {
						linkedEntity->SetRotation(std::stof(parametersVector[0]), std::stof(parametersVector[1]), std::stof(parametersVector[2]));

					}
					else if (firstParameter == "UpdateScale") {
						linkedEntity->SetScale(std::stof(parametersVector[0]), std::stof(parametersVector[1]), std::stof(parametersVector[2]));
					}
					else {

					}

				}

			}
		}




	}

}