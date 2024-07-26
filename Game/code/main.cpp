
/**********************************************************************
*Project           : ColdEngine
*
*Author : Lucas García
*
*
*Purpose : 3D Engine compiled as a static library (.lib) that can generate an .exe
*
**********************************************************************/

#include <Window.h>
#include <Scene.h>
#include <Entity.h>
#include <Component.h>
#include <Transform.h>
#include <EntitySystem.h>
#include <RenderSystem.h>
#include <EntityListenerComponent.h>
#include <Kernel.h>
#include <InputSystem.h>
#include <Message.h>
#include <MessageSystem.h>
#include <PlayerMovementComponent.h>

using namespace coldEngine;


void configure_scene(Scene& scene) {
    scene.TranslateCamera(0, 12, 4);
    scene.RotateCamerta(-1, 0, 0);
}

void set_walls(vector<shared_ptr<Entity>>& walls, Scene& level, RenderSystem& _renderSystem,
    EntitySystem& entityTask, vector<shared_ptr<EntityListenerComponent>> entityListenerComponents, MessageSystem& messageSystem)
{
    shared_ptr<Entity> wall1 = make_shared <Entity>("wall1", level, _renderSystem, "../../assets/Cube.obj",
        entityTask, *entityListenerComponents[0]);
    messageSystem.AddMessage(new Message("UpdatePosition|wall1|35,0,0"));
    messageSystem.AddMessage(new Message("UpdateScale|wall1| 0.2, 0.5, 14"));

    walls.push_back(wall1);

    shared_ptr<Entity> wall2 = make_shared <Entity>("wall2", level, _renderSystem, "../../assets/Cube.obj",
        entityTask, *entityListenerComponents[1]);
    messageSystem.AddMessage(new Message("UpdatePosition|wall2|-35,0,0"));
    messageSystem.AddMessage(new Message("UpdateScale|wall2|0.2,0.5,14."));
    walls.push_back(wall2);


    shared_ptr<Entity> wall3 = make_shared <Entity>("wall3", level, _renderSystem, "../../assets/Cube.obj",
        entityTask, *entityListenerComponents[2]);
    messageSystem.AddMessage(new Message("UpdatePosition|wall3|0,0,35"));
    messageSystem.AddMessage(new Message("UpdateScale|wall3| 14, 0.5, 0.2"));
    walls.push_back(wall3);

    shared_ptr<Entity> wall4 = make_shared <Entity>("wall4", level, _renderSystem, "../../assets/Cube.obj",
        entityTask,  *entityListenerComponents[3]);
    //wall4->GetTransform()->Translate(0,0,-35);
    messageSystem.AddMessage(new Message("UpdatePosition|wall4|0,0,-35"));
    messageSystem.AddMessage(new Message("UpdateScale|wall4|14.,0.5,0.2"));
    walls.push_back(wall4);

}

void set_numbers(vector<shared_ptr<Entity>>& numbers, Scene& level,
    RenderSystem& _renderSystem, EntitySystem& entityTask, vector<shared_ptr<EntityListenerComponent>> entityListenerComponents, MessageSystem& messageSystem)
{

    shared_ptr<Entity> number1 = make_shared<Entity>("number1", level, _renderSystem, "../../assets/001.obj", entityTask, *entityListenerComponents[0]);
    messageSystem.AddMessage(new Message("UpdatePosition|number1|6,0,6"));
    messageSystem.AddMessage(new Message("UpdateRotation|number1|0,0,0"));

    messageSystem.AddMessage(new Message("UpdateScale|number1|1,1,1"));
    numbers.push_back(number1);



    shared_ptr<Entity> number2 = make_shared<Entity>("number2", level, _renderSystem, "../../assets/002.obj", entityTask, *entityListenerComponents[1]);
    messageSystem.AddMessage(new Message("UpdatePosition|number2|-6,0,-6"));
    messageSystem.AddMessage(new Message("UpdateRotation|number2|0,0,0"));
    messageSystem.AddMessage(new Message("UpdateScale|number2|1,1,1"));
    numbers.push_back(number2);


    shared_ptr<Entity> number3 = make_shared<Entity>("number3", level, _renderSystem, "../../assets/003.obj", entityTask, *entityListenerComponents[2]);
    messageSystem.AddMessage(new Message("UpdatePosition|number3|-6,0,6"));
    messageSystem.AddMessage(new Message("UpdateRotation|number3|0,0,0"));
    messageSystem.AddMessage(new Message("UpdateScale|number3|1,1,1"));
    numbers.push_back(number3);


    shared_ptr<Entity> number4 = make_shared<Entity>("number4", level, _renderSystem, "../../assets/004.obj", entityTask, *entityListenerComponents[3]);
    messageSystem.AddMessage(new Message("UpdatePosition|number4|6,0,-6"));
    messageSystem.AddMessage(new Message("UpdateRotation|number4|0,0,0"));
    messageSystem.AddMessage(new Message("UpdateScale|number4|1,1,1"));

    numbers.push_back(number4);


    shared_ptr<Entity> number5 = make_shared<Entity>("number5", level, _renderSystem, "../../assets/005.obj", entityTask, *entityListenerComponents[4]);
    messageSystem.AddMessage(new Message("UpdatePosition|number5|0,0,-3"));
    messageSystem.AddMessage(new Message("UpdateRotation|number5|0,0,0"));
    messageSystem.AddMessage(new Message("UpdateScale|number5|1,1,1"));

    numbers.push_back(number5);
}

void set_entities(Entity& character, shared_ptr<PlayerMovementComponent>& movComponent)
{
    character.AddComponent(movComponent);
    movComponent->SetMovementLimits(-6.5, 6.5, 6.5, -6.5);
}

void set_systems(shared_ptr <Scene> scene,shared_ptr<MessageSystem>& messageBus, shared_ptr<EntitySystem>& entityTask,
    shared_ptr<RenderSystem>& renderTask, shared_ptr<InputSystem>& inputTask)
{
    messageBus = make_shared<MessageSystem>();
    entityTask = make_shared<EntitySystem>();
    renderTask = make_shared<RenderSystem>(scene);
    inputTask = make_shared<InputSystem>(messageBus);
}

int main()
{
    // Creates a window:

    Window window("Game", 1280, 720,true);

    window.enable_vsync();


    //It is better using make_shared instead of new Class, the allocations get reduced from 2 dynamic memory to 1 single allocation

    shared_ptr<Scene> level = make_shared<Scene>(window);
    configure_scene(*level);

    //Set systems
    shared_ptr<MessageSystem> messageBus;
    shared_ptr<EntitySystem> entityTask;
    shared_ptr<RenderSystem> renderTask;
    shared_ptr<InputSystem> inputTask;

    set_systems(level, messageBus, entityTask, renderTask, inputTask);

    shared_ptr<EntityListenerComponent> entityListenerComponent1 = make_shared<EntityListenerComponent>(messageBus);
    shared_ptr<EntityListenerComponent> entityListenerComponent2 = make_shared<EntityListenerComponent>(messageBus);
    shared_ptr<EntityListenerComponent> entityListenerComponent3 = make_shared<EntityListenerComponent>(messageBus);
    shared_ptr<EntityListenerComponent> entityListenerComponent4 = make_shared<EntityListenerComponent>(messageBus);
    shared_ptr<EntityListenerComponent> entityListenerComponent5 = make_shared<EntityListenerComponent>(messageBus);

    // Añadir las instancias al vector de EntityListenerComponent
    vector<shared_ptr<EntityListenerComponent>> entityListenerComponents;
    entityListenerComponents.push_back(entityListenerComponent1);
    entityListenerComponents.push_back(entityListenerComponent2);
    entityListenerComponents.push_back(entityListenerComponent3);
    entityListenerComponents.push_back(entityListenerComponent4);
    entityListenerComponents.push_back(entityListenerComponent5);

    for (shared_ptr<EntityListenerComponent> listener: entityListenerComponents)
    {
        messageBus->AddListener(listener);
    }

    shared_ptr<EntityListenerComponent> entityListenerComponentWall1 = make_shared<EntityListenerComponent>(messageBus);
    shared_ptr<EntityListenerComponent> entityListenerComponentWall2 = make_shared<EntityListenerComponent>(messageBus);
    shared_ptr<EntityListenerComponent> entityListenerComponentWall3 = make_shared<EntityListenerComponent>(messageBus);
    shared_ptr<EntityListenerComponent> entityListenerComponentWall4 = make_shared<EntityListenerComponent>(messageBus);

    // Añadir las instancias al vector de EntityListenerComponent
    vector<shared_ptr<EntityListenerComponent>> entityListenerComponentsWalls;
    entityListenerComponentsWalls.push_back(entityListenerComponentWall1);
    entityListenerComponentsWalls.push_back(entityListenerComponentWall2);
    entityListenerComponentsWalls.push_back(entityListenerComponentWall3);
    entityListenerComponentsWalls.push_back(entityListenerComponentWall4);


    for (shared_ptr<EntityListenerComponent> listener : entityListenerComponentsWalls)
    {
        messageBus->AddListener(listener);
    }

    shared_ptr<Kernel> kernel = make_shared<Kernel>(entityTask, renderTask, inputTask, messageBus);

    //Set Entities
    shared_ptr<Entity> character = make_shared <Entity>("character", *level,*renderTask, "../../assets/FinalBaseMesh.obj", *entityTask);
    messageBus->AddMessage(new Message("UpdateRotation|character|0,0,0"));
    shared_ptr<PlayerMovementComponent> movComponent = make_shared<PlayerMovementComponent>(messageBus, 5, "../../assets/wallHit.wav");
    messageBus->AddListener(movComponent);

    vector<shared_ptr<Entity>> numbers;
    vector<shared_ptr<Entity>> walls;

    set_entities(*character, movComponent);
    set_walls(walls, *level, *renderTask, *entityTask,entityListenerComponentsWalls,*messageBus);
    set_numbers(numbers, *level, *renderTask, *entityTask, entityListenerComponents,*messageBus);

    //sets all the values of the level
    level->initialize(kernel, messageBus, character, numbers, walls, movComponent);
    // Executes the main loop
    level->Update();

    return 0;
}
