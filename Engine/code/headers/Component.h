
/**
 * \author Lucas Garcia
 * \version 1.0
 * \date 2024-06-18
 */

 /**
  * \class Component
  * \brief Base class for components used on entities
  */

#pragma once
namespace coldEngine
{

	class Entity;
	
	class Component
	{
	protected:
		Entity* linkedEntity;
	public:
		///
		/// Constructor
		///
		Component();
		~Component() = default;
		/**
		* \brief Set the entity this component is attached to
		*/
		void SetEntity(Entity* entity);
		/**
		* \brief Gets the entity linked
		*/
		Entity* GetEntity()
		{
			return linkedEntity;
		}
		virtual void Update();
	};
}