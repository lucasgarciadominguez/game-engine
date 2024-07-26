#pragma once
struct Event
{
    enum Type
    {
        CLOSE,
        KEY_PRESSED,
        KEY_RELEASED
    }
    type;

    union Data
    {
        struct { int key_code; } keyboard;

        struct
        {
            float x, y;
            int   buttons;
        }
        mouse;
    }
    data;
};