
/**
 * \author Lucas Garcia
 * \version 1.0
 * \date 2024-06-18
 */

 /**
  * \class Position
  * \brief Class that has the position components like seen in Unity or Unreal Engine
  * Updates the kernel and the sdl2 features in the window
  */

#pragma once

namespace coldEngine
{
    class Position
    {
        float xPos;
        float yPos;
        float zPos;

        float lastXPos;
        float lastYPos;
        float lastZPos;

    public:
        Position();
        void SetPosition(float x, float y, float z);
        void GetPosition(float& x, float& y, float& z);
        void Translate(float x, float y, float z);
        void GetLastTransformation(float& x, float& y, float& z);
        void ResetLastPos();
    };
}