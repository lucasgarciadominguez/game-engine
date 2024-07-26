
/**********************************************************************
*Project           : ColdEngine
*
*Author : Lucas García
*
*
*Purpose : 3D Engine compiled as a static library (.lib) that can generate an .exe
*
**********************************************************************/

#include "PlayerMovementComponent.h"
#include <MessageSystem.h>
#include <Message.h>
#include <Entity.h>
#include <memory>

namespace coldEngine
{

	PlayerMovementComponent::PlayerMovementComponent(std::shared_ptr<MessageSystem> bus, float _speed, string _soundFile):MessageListener(bus), Component()
	{
		speed = _speed;
		enableLimits = true;
		actualNumber = 0;
		fLimit = 0;
		bLimit = 0;
		rLimit = 0;
		lLimit = 0;
		soundFile = _soundFile;
	}
	int PlayerMovementComponent::GetActualNumber()
	{
		return actualNumber;
	}
	void PlayerMovementComponent::IncreaseNumber()
	{
		++actualNumber;
	}
	void PlayerMovementComponent::UseMessage(Message* message)
	{
		if(linkedEntity !=nullptr)
			if (message->getEvent() == "w")
			{
				Forward();
			}
			else if(message->getEvent() == "d")
			{
				Right();
			}
			else if (message->getEvent() == "s")
			{
				BackWards();
			}
			else if (message->getEvent() == "a")
			{
				Left();
			}
			else if (message->getEvent() == "UpdateRotation|character|0,0,0")
			{
				linkedEntity->SetRotation(0,0,0);

			}
	}

	void PlayerMovementComponent::SetMovementLimits(float forward, float backwards, float right, float left)
	{
		fLimit = forward;
		bLimit = backwards;
		rLimit = right;
		lLimit = left;
	}

	void PlayerMovementComponent::Forward()
	{
		float movement = -0.01f * speed;
		if(OutOfLimits(Direction::Forward, movement))
			linkedEntity->Translate(0.f, 0.f, movement);
	}

	void PlayerMovementComponent::BackWards()
	{
		float movement = 0.01f * speed;
		if (OutOfLimits(Direction::Backwards, movement))
			linkedEntity->Translate(0.f, 0.f, movement);
	}

	void PlayerMovementComponent::Right()
	{
		float movement = 0.01f * speed;
		if (OutOfLimits(Direction::Right, movement))
			linkedEntity->Translate(movement, 0.f, 0.f);
	}

	void PlayerMovementComponent::Left()
	{
		float movement = -0.01f * speed;
		if (OutOfLimits(Direction::Left, movement))
			linkedEntity->Translate(movement, 0.f, 0.f);
	}

	bool PlayerMovementComponent::OutOfLimits(Direction dir, float movement)
	{
		if (enableLimits)
		{

			float x;
			float y;
			float z;
			linkedEntity->GetPosition(x, y, z);

			if (dir == Direction::Forward)
			{
				if (fLimit > z + movement)
				{
					return false;
					PlayAudio();
				}
			}
			else if (dir == Direction::Backwards)
			{
				if (bLimit < z + movement)
				{
					return false;
					PlayAudio();
				}
			}
			else if (dir == Direction::Right)
			{
				if (rLimit < x + movement)
				{
					return false;
					PlayAudio();
				}
			}
			else if (dir == Direction::Left)
			{
				if (lLimit > x + movement)
				{
					return false;
					PlayAudio();
				}
			}
		}
		return true;
	}

	void PlayerMovementComponent::PlayAudio()
	{
	}

}
