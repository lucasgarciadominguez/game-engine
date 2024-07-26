
/**
 * \author Lucas Garcia
 * \version 1.0
 * \date 2024-06-18
 */

 /**
  * \class Rotation
  * \brief Class that has the rotation components like seen in Unity or Unreal Engine
  */

#pragma once

namespace coldEngine
{
    // Clase Rotation que hereda de Transform
    class Rotation
    {
        float xRot;
        float yRot;
        float zRot;

    public:
        // Constructor
        Rotation();
        void GetRotation(float& x, float& y, float& z);

        // Método para establecer la rotación
        void SetRotation(float x, float y, float z);
    };
}
