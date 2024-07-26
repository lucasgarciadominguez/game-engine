
/**
 * \author Lucas Garcia
 * \version 1.0
 * \date 2024-06-18
 */

 /**
  * \class PlayerMovementComponent
  * \brief Component made as a simple in game object control by keyboard inputs, it is attached to EntityTask classes
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

	class PlayerMovementComponent : public MessageListener, public Component
	{
		float speed;

		int actualNumber;
		///
		/// Forward limit
		///
		float fLimit;
		///
		/// Backwards limit
		///
		float bLimit;
		///
		/// Right limit
		///
		float rLimit;
		///
		/// Left limit
		///
		float lLimit;
		///
		/// Path to the audio clip that will be played
		///
		string soundFile;

		enum class Direction
		{
			Right,
			Left,
			Backwards,
			Forward
		};

	public:
		bool enableLimits;

		PlayerMovementComponent(std::shared_ptr<MessageSystem> bus, float _speed, string _soundFile);
		int GetActualNumber();
		void IncreaseNumber();
		/**
		* \brief Decodes the messages and applies them to the entities
		*/
		void UseMessage(Message* message) override;
		/**
		* \brief Set the limits coordinates for the entity movement
		*/
		void SetMovementLimits(float forward, float backwards, float right, float left);

	private:
		///
		/// Move forward
		///
		void Forward();
		///
		/// Move backwards
		///
		void BackWards();
		///
		/// Move right
		///
		void Right();
		///
		/// Move left
		///
		void Left();
		/**
		* \brief Check if the entity is trying to move out of the given limits
		*/
		bool OutOfLimits(Direction dir, float movement);
		/**
		* \brief Play an audio clip, this part is commented because i havent been able to use SFML audio lib when building for the demo project,
		a lot of LNK2019 errors popped up, and I havent been able to solve them
		*/
		void PlayAudio();
		
	};
}