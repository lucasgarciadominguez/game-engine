
/**
 * \author Lucas Garcia
 * \version 1.0
 * \date 2024-06-18
 */

 /**
  * \class Scene
  * \brief Class that has all the entities, cameras, lights...
  * Updates the kernel and the sdl2 features in the window
  */

#pragma once

#include <memory>
#include <string>
#include <vector>
#include <declarations.h>


namespace coldEngine
{
	class Window;
	class Entity;
	class b2World;
	class Kernel;
	class MessageSystem;
	class PlayerMovementComponent;

	using namespace glt;
	using namespace std;
	

	class Scene
	{
	private:

		shared_ptr< Render_Node > scene;
		Window* window;
		b2World* physics_world; // Variable miembro para el mundo de Box2D

		shared_ptr<Kernel> kernel;
		shared_ptr<MessageSystem> messageSystem;
		shared_ptr<Entity> character;
		vector<shared_ptr<Entity>> numbers;
		vector<shared_ptr<Entity>> walls;
		shared_ptr<PlayerMovementComponent> movComponent;
	public:
		vector<Entity*> levelEntities;

	public:

		Scene(Window& given_window);
		~Scene();

		void CreateScene();
		void ResetViewport();
		/**
		* \brief Define the initialize function
		*/
		void initialize(std::shared_ptr<Kernel> kernel,
			std::shared_ptr<MessageSystem> messageBus,
			std::shared_ptr<Entity> character,
			vector<shared_ptr<Entity>> numbers,
			vector<shared_ptr<Entity>> walls,
			std::shared_ptr<PlayerMovementComponent> movComponent);
		/**
		* \brief Add a new object to the scene
		*/
		void Add(const std::string& name, std::shared_ptr< Node > node);
		/**
		* \brief Get an object that has been previously added to the scene
		* Search the entity in the map of nodes
		*/
		Node* GetEntity(const std::string& name);
		/**
		* \brief Updates the kernel,catches the keyboard input and manages the sdl2
		*/
		void Update();
		/**
		* \brief Checks the distance the player has to the rotating numbers
		*/
		void distance_to_numbers(float enemyX, float enemyY, float enemyZ, float playerX, float playerY, float playerZ);

		void rotate_numbers();

		void TranslateCamera(float x, float y, float z);
		void RotateCamerta(float x, float y, float z);
		void RotateEntities(const std::string& name,float x, float y, float z);

		///
		/// Method use for debugging with a breakpoint
		///
		void DebugMethod();

	};
}



