
/**********************************************************************
*Project           : ColdEngine
*
*Author : Lucas García
*
*
*Purpose : 3D Engine compiled as a static library (.lib) that can generate an .exe
*
**********************************************************************/

#include "InputSystem.h"
#include <Keyboard.h>
#include <MessageSystem.h>
#include <Message.h>
#include <SDL.h>
#include <memory>
namespace coldEngine
{
	InputSystem::InputSystem(std::shared_ptr<MessageSystem> bus) : messageSystem(bus)
	{
	}

	void InputSystem::Update()
	{
		const Uint8* state = SDL_GetKeyboardState(NULL);

        if (state[SDL_SCANCODE_W]) messageSystem->AddMessage(new Message("w"));
        if (state[SDL_SCANCODE_A]) messageSystem->AddMessage(new Message("a"));
        if (state[SDL_SCANCODE_S]) messageSystem->AddMessage(new Message("s"));
		if (state[SDL_SCANCODE_D]) messageSystem->AddMessage(new Message("d"));

	}

}

