/**********************************************************************
*Project           : ColdEngine
*
*Author : Lucas García
*
*
*Purpose : 3D Engine compiled as a static library (.lib) that can generate an .exe
*
**********************************************************************/

#include "Rotation.h"

namespace coldEngine
{
    Rotation::Rotation()
    {
        xRot = 0;
        yRot = 0;
        zRot = 0;
    } 

    void Rotation::GetRotation(float& x, float& y, float& z) {
        x = xRot;
        y = yRot;
        z = zRot;
    }

    void Rotation::SetRotation(float x, float y, float z)
    {
        xRot = x;
        yRot = y;
        zRot = z;
    }
}