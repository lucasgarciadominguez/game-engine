
/**********************************************************************
*Project           : ColdEngine
*
*Author : Lucas García
*
*
*Purpose : 3D Engine compiled as a static library (.lib) that can generate an .exe
*
**********************************************************************/

#include "Entity.h"
#include "Transform.h"
#include "MeshRenderer.h"
#include "Scene.h"
#include "EntitySystem.h"
#include "EntityListenerComponent.h"
#include "Component.h"
#include <string>
#include "RenderSystem.h"
#include <Model.hpp>
#include <Model_Obj.hpp>
#include "Node.hpp"

namespace coldEngine
{
	Entity::Entity(const std::string& EntityName, Scene& _level,RenderSystem& _renderSystem, 
		const std::string& obj_file_path, EntitySystem& task)
	{
		name = EntityName;
		task.AddEntity(this);
		level = &_level;
		transform = new Transform();
		shared_ptr<Model> _model(new Model_Obj(obj_file_path));
		_level.Add(EntityName, _model);
		glt::Node* _node = _level.GetEntity(EntityName);

		MeshRenderer* gfx = _renderSystem.create_component(_node, *this);
		_level.levelEntities.push_back(this); //Save entity in a vector for final shrink animation

		parent = nullptr;
	}
	Entity::Entity(const std::string& EntityName, Scene& _level, RenderSystem& _renderSystem,
		const std::string& obj_file_path, EntitySystem& task, EntityListenerComponent& _entityListenerComponent)
	{
		name = EntityName;
		task.AddEntity(this);
		_entityListenerComponent.SetEntity(this);
		level = &_level;
		transform = new Transform();
		shared_ptr<glt::Model> _model(new glt::Model_Obj(obj_file_path));
		_level.Add(EntityName, _model);

		glt::Node* _node = _level.GetEntity(EntityName);
		MeshRenderer* gfx = _renderSystem.create_component(_node, *this);
		_level.levelEntities.push_back(this); //Save entity in a vector for final shrink animation

		parent = nullptr;
	}
	void Entity::Update()
	{
		float x;
		float y;
		float z;

		float xSize;
		float ySize;
		float zSize;

		transform->GetLastTransformation(x, y, z);
		transform->GetScale(xSize, ySize, zSize);



		for (int i = 0; i < children.size(); i++)
		{
			children[i]->Translate(x, y, z);
			children[i]->Update();
		}

		for (int i = 0; i < components.size(); i++)
		{
			components[i]->Update();
		}
	}

	void Entity::SetScale(float x, float y, float z)
	{
		transform->SetScale(x, y, z);
	}

	void Entity::Translate(float x, float y, float z)
	{
		transform->Translate(x, y, z);
	}

	void Entity::SetPosition(float x, float y, float z)
	{
		transform->SetPosition(x, y, z);
	}
	void Entity::SetRotation(float x, float y, float z)
	{
		transform->SetRotation(x, y, z);
	}

	void Entity::GetPosition(float& x, float& y, float& z)
	{
		transform->GetPosition(x, y, z);
	}

	void Entity::AddComponent(std::shared_ptr<Component> comp)
	{
		comp->SetEntity(this);
		components.push_back(comp);
	}

	void Entity::AddChild(Entity& child)
	{
		children.push_back(&child);
		child.parent = this;
	}

	void Entity::RemoveChild(Entity& child)
	{
		for (int i = 0; i < children.size(); i++)
		{
			if (children[i] == &child)
			{
				children[i] = nullptr;
				break;
			}
		}

		children.erase(remove(children.begin(), children.end(), nullptr), children.end());
	}

	void Entity::SetParent(Entity& _parent)
	{
		if (parent != nullptr)
		{
			parent->RemoveChild(*this);
		}

		parent->AddChild(*this);
	}
	void Entity::UnSetParent()
	{
		if (parent != nullptr)
		{
			parent->RemoveChild(*this);
		}
	}
	Transform* Entity::GetTransform()
	{
		return transform;
	}
}