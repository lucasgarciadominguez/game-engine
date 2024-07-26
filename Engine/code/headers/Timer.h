#pragma once
#include <chrono>
#include <SDL.h>

namespace coldEngine
{
    class Timer
    {
        std::chrono::steady_clock::time_point start_timestamp;
    public:
        Timer()
        {
            reset();
        }

        void reset()
        {
            start_timestamp = std::chrono::high_resolution_clock::now();
        }
        float elapsed_seconds()
        {
            auto current_timestamp = std::chrono::high_resolution_clock::now();
            auto difference = current_timestamp - start_timestamp;

            //return ? ? ;
        }
    };
}