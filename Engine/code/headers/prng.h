
#pragma once
#include "types.h"
#include <cstdint>

namespace coldEngine
{
    template <unsigned SIZE>
    class Xorshift;

    template <>
    class Xorshift<32>
    {
    public:
        Xorshift(int seed)
        {

        }
        uint32_t next()
        {
            return 0;
        }
    };

}
