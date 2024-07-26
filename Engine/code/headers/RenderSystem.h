
/**
 * \author Lucas Garcia
 * \version 1.0
 * \date 2024-06-18
 */

 /**
  * \class RenderSystem
  * \brief Task in charge of rendering everything in the scene
  */

#pragma once
#include <memory>
#include <list>
#include "MeshRenderer.h"
#include "System.h"
namespace coldEngine
{
	class Scene;

	class RenderSystem : public System
	{
		list<MeshRenderer*> components;

	public:
		RenderSystem(std::shared_ptr<Scene> _level);
		~RenderSystem();
		MeshRenderer* create_component(
			Node* _model, Entity& entity); 
		 void Update() override;
		
	};
}