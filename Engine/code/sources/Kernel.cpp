
/**********************************************************************
*Project           : ColdEngine
*
*Author : Lucas García
*
*
*Purpose : 3D Engine compiled as a static library (.lib) that can generate an .exe
*
**********************************************************************/

#include "Kernel.h"
#include "EntitySystem.h"
#include "RenderSystem.h"
#include "InputSystem.h"
#include "MessageSystem.h"
#include <memory>
namespace coldEngine
{

	Kernel::Kernel(std::shared_ptr<EntitySystem> _entitySystem, std::shared_ptr<RenderSystem> _renderSystem, std::shared_ptr<InputSystem> _inputSystem, std::shared_ptr<MessageSystem> _messageSystem)
		: entitySystem(_entitySystem), renderSystem(_renderSystem), inputSystem(_inputSystem), messageSystem(_messageSystem) {}

	Kernel::~Kernel()
	{
		//delete inputSystem;
		//delete entitySystem;
		//delete messageSystem;
		//delete renderSystem;
	}

	void Kernel::Update()
	{
		inputSystem->Update();
		entitySystem->Update();

		messageSystem->SendToListeners();

		renderSystem->Update();
	}
}

