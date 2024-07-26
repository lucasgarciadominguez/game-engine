/**********************************************************************
*Project           : ColdEngine
*
*Author : Lucas García
*
*
*Purpose : 3D Engine compiled as a static library (.lib) that can generate an .exe
*
**********************************************************************/

#include "Scale.h"

namespace coldEngine
{
    // Constructor
    Scale::Scale()
    {
        xSize = 1;
        ySize = 1;
        zSize = 1;
        lastXSize = 1;
        lastYSize = 1;
        lastZSize = 1;
    }

    // Métodos específicos para la escala
    void Scale::SetScale(float x, float y, float z)
    {
        //ResetLastScale();
        xSize = x;
        ySize = y;
        zSize = z;
    }

    void Scale::GetScale(float& x, float& y, float& z)
    {
        x = xSize;
        y = ySize;
        z = zSize;
        ResetLastScale();

    }

    //void Scale::GetLastTransformation(float& x, float& y, float& z)
    //{
    //    x = xSize - lastXSize;
    //    y = ySize - lastYSize;
    //    z = zSize - lastZSize;
    //    ResetLastScale();
    //}

    void Scale::ResetLastScale()
    {
        xSize = lastXSize;
        ySize = lastYSize;
        zSize = lastZSize;
    }
}
