//Copyright (c) 2023+ Lucas
//this code is released under public domain
#pragma once
#include "math.h"
#include "Point.h"
namespace coldEngine
{
    class Sphere
    {
        Point3 center;
        float radius;
    public:
        bool intersects(const Sphere& other)
        {
            return distance(this->center, other.center) < this->radius + other.radius;
        }

    };
}

