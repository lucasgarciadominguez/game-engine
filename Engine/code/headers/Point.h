//Copyright (c) 2023+ Lucas
//this code is released under public domain
#pragma once
namespace coldEngine
{
    template <unsigned DIMENSION,typename TYPE>
    struct Point
    {
        TYPE coordinates[DIMENSION];
    };
    using Point2 = Point<2, float>;
    using Point3 = Point<3, float>;
    using Point4 = Point<4, float>;
}