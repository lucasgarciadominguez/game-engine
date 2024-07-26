
/**********************************************************************
*Project           : ColdEngine
*
*Author : Lucas García
*
*
*Purpose : 3D Engine compiled as a static library (.lib) that can generate an .exe
*
**********************************************************************/

#include "RenderSystem.h"
#include "Scene.h"
#include <Transform.h>
#include "Entity.h"

namespace coldEngine
{
	RenderSystem::RenderSystem(std::shared_ptr<Scene> _level) 
	{
		level = _level;
	}

	RenderSystem::~RenderSystem()
	{
		for (MeshRenderer* component : components)
		{
			delete component;
		}
	}

	MeshRenderer* RenderSystem::create_component(Node* _model,Entity& entity)
	{
		//create component meshrenderer via renderSystem
		MeshRenderer* gfx = new MeshRenderer(_model, entity);
		//add to components
		components.push_back(gfx);
		return gfx;

	}

	void RenderSystem::Update()
	{

		for (const auto& meshRenderer : components)
		{
			Entity* entity = meshRenderer->GetEntity();
			if (entity)
			{
				// Obtain the transform of the entity
				Transform* transform = entity->GetTransform();

				// Check if transform is correct
				if (transform)
				{
					// Apply the transformations to the meshrenderer
					float xPos;
					float yPos;
					float zPos;
					float xRot;
					float yRot;
					float zRot;
					float xSca;
					float ySca;
					float zSca;

					transform->GetLastTransformation(xPos, yPos, zPos);
					transform->GetScale(xSca,ySca,zSca);

					transform->GetRotation(xRot, yRot, zRot);
					meshRenderer->Update(xPos, yPos, zPos, xRot, yRot, zRot, xSca, ySca, zSca);
				}
			}

		}
	}
}
