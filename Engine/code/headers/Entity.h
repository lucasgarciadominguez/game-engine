
/**
 * \author Lucas Garcia
 * \version 1.0
 * \date 2024-06-18
 */

 /**
  * \class Entity
  * \brief Representation of an object in the scene
  */

#pragma once
#include <string>
#include <vector>
#include <memory>
#include <map>

namespace coldEngine
{
	class Transform;
	class MeshRenderer;
	class RenderSystem;
	class EntityListenerComponent;
	class Scene;
	class EntitySystem;
	class Component;

	using namespace std;

	class Entity
	{
		Transform* transform;
		Scene* level;
		///
		/// 
		///
		/**
		* \brief Vector that contains all non-essential components
		*/
		vector<std::shared_ptr<Component>> components;

		vector <Entity*> children;
		Entity* parent;

	public:
		~Entity()
		{
			// Liberar los componentes del vector components
			//if (components.size()>0)
			//{
			//	for (Component* comp : components)
			//	{
			//		delete comp;
			//	}
			//}

			components.clear();

			for (Entity* child : children)
			{
				delete child;
			}
			children.clear();

			delete transform;
			transform = nullptr;



			delete parent;
			parent = nullptr;
		
		}
		string name;

		Entity(const std::string& EntityName, Scene& level, RenderSystem& _renderSystem,
			const std::string& obj_file_path, EntitySystem& task);
		Entity(const std::string& EntityName, Scene& level, RenderSystem& _renderSystem,
			const std::string& obj_file_path, EntitySystem& task, EntityListenerComponent& _entityListenerComponent);
		virtual void Update();

		void SetScale(float x, float y, float z);

		void Translate(float x, float y, float z);
		void SetPosition(float x, float y, float z);
		void SetRotation(float x, float y, float z);
		void GetPosition(float& x, float& y, float& z);
		///
		/// 
		/**
		* \brief Add Component to vector of components
		*/
		void AddComponent(std::shared_ptr<Component> comp);

		void AddChild(Entity& child);
		void RemoveChild(Entity& child);
		void SetParent(Entity& _parent);
		/**
		* \brief Set parent as null
		*/
		void UnSetParent();
		Transform* GetTransform();
	};
	
}

