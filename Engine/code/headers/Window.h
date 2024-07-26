
// This is free code released into the public domain.
// Drafted by Ángel in January 2019.
// Use it at your own risk. It might have bugs.
// angel.rodriguez@esne.edu

 /**
  * \class Window
  * \brief Manages all the features that are in SDL2 for rendering a window
  */

#pragma once

#include <string>
#include <Keyboard.h>
#include <declarations.h>
namespace coldEngine
{
    class Window
    {

    private:

        SDL_Window* window;
        SDL_GLContext gl_context;



    public:
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
        Window(const char* title, const int width, const int height,const  bool fullscreen);
       ~Window();

    public:

        /** Retorna el ancho actual de la ventana (el usuario puede cambiarlo).
          */
        unsigned get_width () const;

        /** Retorna el alto actual de la ventana (el usuario puede cambiarlo).
          */
        unsigned get_height () const;

        /** Permite extraer un evento de la cola de eventos asociada a la ventana.
          */
        bool poll (Event & event) const;

        void enable_vsync ();

        void disable_vsync ();

        /** Borra el buffer de la pantalla usando OpenGL.
          */
        void clear () const;

        /** Intercambia el buffer visible con el buffer oculto.
          */
        void swap_buffers () const;

    };

}
