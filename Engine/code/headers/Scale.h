
/**
 * \author Lucas Garcia
 * \version 1.0
 * \date 2024-06-18
 */

 /**
  * \class Scale
  * \brief Class that has the scale components like seen in Unity or Unreal Engine
  */

#pragma once

namespace coldEngine
{
    class Scale
    {
    private:
        float xSize;
        float ySize;
        float zSize;

        float lastXSize;
        float lastYSize;
        float lastZSize;

    public:
        // Constructor
        Scale();

        // Métodos específicos para la escala
        void SetScale(float x, float y, float z);
        void GetScale(float& x, float& y, float& z);
        //void GetLastTransformation(float& x, float& y, float& z);

    private:
        void ResetLastScale();
    };
}