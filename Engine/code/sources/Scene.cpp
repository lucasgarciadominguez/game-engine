
/**********************************************************************
*Project           : ColdEngine
*
*Author : Lucas García
*
*
*Purpose : 3D Engine compiled as a static library (.lib) that can generate an .exe
*
**********************************************************************/

#include <Light.hpp>
#include <Model.hpp>
#include <OpenGL.hpp>
#include <Model_Obj.hpp>
#include <Render_Node.hpp>
#include <Node.hpp>
#include <Window.h>
#include "Scene.h"
#include <Box2D/Box2D.h>

#include "EntitySystem.h"
#include "Kernel.h"
#include "MessageSystem.h"
#include "Message.h"
#include "Entity.h"
#include "PlayerMovementComponent.h"

namespace coldEngine
{
	Scene::Scene(Window& given_window)
	{
		window = &given_window;
		CreateScene();		
	}

	Scene::~Scene()
	{
	}


	void Scene::CreateScene()
	{

		shared_ptr< Render_Node > _level(new Render_Node);
		shared_ptr< Camera      > camera(new Camera(20.f, 1.f, 500.f, 1.f));
		shared_ptr< Light       > light(new Light);


		_level->add("camera", camera);
		_level->add("light", light);

		scene = _level;

		(*scene)["light"]->translate(glt::Vector3(10.f, 10.f, 10.f));
		(*scene)["camera"]->translate(Vector3(0.f, 0.f, 5.f));

	}

	void Scene::ResetViewport()
	{
		GLsizei width = GLsizei(window->get_width());
		GLsizei height = GLsizei(window->get_height());

		scene->get_active_camera()->set_aspect_ratio(float(width) / height);

		glViewport(0, 0, width, height);
	}

	void Scene::initialize(std::shared_ptr<Kernel> kernel, std::shared_ptr<MessageSystem> messageBus,
		std::shared_ptr<Entity> character, vector<shared_ptr<Entity>> numbers, vector<shared_ptr<Entity>> walls, std::shared_ptr<PlayerMovementComponent> movComponent)
	{
		this->kernel = kernel;
		this->messageSystem = messageBus;
		this->character = character;
		this->numbers = numbers;
		this->walls = walls;
		this->movComponent = movComponent;
	}

	void Scene::Add(const std::string& name, std::shared_ptr<Node> node)
	{
		scene->add(name, node);
	}

	Node* Scene::GetEntity(const std::string& name)
	{
		return scene->get(name);
	}

	void Scene::Update()
	{
		bool firstTime = true;
		bool exit = false;
		while (!exit) {
			Window::Event event;
			while (window->poll(event)) {
				switch (event.type) {
				case Window::Event::CLOSE:
					exit = true;
					break;
				case Window::Event::KEY_PRESSED:
					if (event.data.keyboard.key_code == Keyboard::KEY_ESCAPE) {
						exit = true;
					}
					break;
				}
			}
			float playerX;
			float playerY;
			float playerZ;

			float enemyX{};
			float enemyY{};
			float enemyZ{};

			character->GetPosition(playerX, playerY, playerZ);
			rotate_numbers();
			if (firstTime)
				firstTime = false;
			else
				distance_to_numbers(enemyX, enemyY, enemyZ, playerX, playerY, playerZ);

			kernel->Update();

			ResetViewport();

			window->clear();

			scene->render();

			window->swap_buffers();
		}

	}
	void Scene::distance_to_numbers(float enemyX, float enemyY, float enemyZ, float playerX, float playerY, float playerZ)
	{
		////distances to numbers
		for (int i = 0; i < numbers.size(); i++)
		{
			//Get normalized Vector
			numbers[i]->GetPosition(enemyX, enemyY, enemyZ);
			float newX = enemyX - playerX;
			float newY = enemyY - playerY;
			float newZ = enemyZ - playerZ;
			float module = -sqrtf((newX * newX) + (newY * newY) + (newZ * newZ)); //using floats for efficiency
			if (module > -0.8f)
			{
				if (movComponent->GetActualNumber() == i)
				{
					if (movComponent->GetActualNumber() == numbers.size() - 1)
					{
						messageSystem->AddMessage(new Message("UpdateScale|number" + to_string(movComponent->GetActualNumber() + 1) + "|" + "0,0,0"));

						for (int i = 1; i <= walls.size(); i++)
						{
							messageSystem->AddMessage(new Message("UpdateScale|wall" + to_string(i)
								+ "|" + "0,0,0"));
						}
						movComponent->enableLimits = false;

					}
					else
					{
						movComponent->IncreaseNumber();
						messageSystem->AddMessage(new Message("UpdateScale|number" + to_string(movComponent->GetActualNumber()) + "|" + "0,0,0"));
					}

				}
				break;
			}

		}
	}
	void Scene::rotate_numbers()
	{
		for (int i = 1; i <= numbers.size(); i++)
		{
			messageSystem->AddMessage(new Message("UpdateRotation|number" + to_string(i) + "|" + " 0, 0.01, 0"));

		}
	}
	void Scene::TranslateCamera(float x, float y, float z)
	{
		(*scene)["camera"]->translate(Vector3(x, y, z));
	}
	void Scene::RotateEntities(const std::string& name,float x, float y, float z)
	{
		(*scene)[name]->rotate_around_x(x);
		(*scene)[name]->rotate_around_y(y);
		(*scene)[name]->rotate_around_z(z);
	}
	void Scene::RotateCamerta(float x, float y, float z)
	{
		(*scene)["camera"]->rotate_around_x(x);
		(*scene)["camera"]->rotate_around_y(y);
		(*scene)["camera"]->rotate_around_z(z);
	}

	void Scene::DebugMethod()
	{
		return; //Method use for checking if things work adding a breakpoint, if the project enters here, it means the test works
	}
}



