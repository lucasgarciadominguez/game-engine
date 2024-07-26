/**********************************************************************
*Project           : ColdEngine
*
*Author : Lucas García
*
*
*Purpose : 3D Engine compiled as a static library (.lib) that can generate an .exe
*
**********************************************************************/

#include "..\headers\transform\Position.h"

namespace coldEngine
{
    Position::Position()
    {
        xPos = 0;
        yPos = 0;
        zPos = 0;
        lastXPos = 0;
        lastYPos = 0;
        lastZPos = 0;

    }

    void Position::SetPosition(float x, float y, float z) {
        ResetLastPos();
        xPos = x;
        yPos = y;
        zPos = z;
    }

    void Position::GetPosition(float& x, float& y, float& z) {
        x = xPos;
        y = yPos;
        z = zPos;
    }

    void Position::Translate(float x, float y, float z) {
        xPos += x;
        yPos += y;
        zPos += z;
    }

    void Position::GetLastTransformation(float& x, float& y, float& z)
    {
        x = xPos - lastXPos;
        y = yPos - lastYPos;
        z = zPos - lastZPos;
        ResetLastPos();

    }

    void Position::ResetLastPos()
    {
        lastXPos = xPos;
        lastYPos = yPos;
        lastZPos = zPos;
    }
}