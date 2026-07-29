/**
 * \file main.cpp
 * \brief Archivo principal para el memorama
 * \author S&aacute;nchez Montoy, Jes&uacute;s Axel
 * \author Helleon Cardenas, Alba Rosa
 * \author Chenoweth Galaz, Ivana Lin
 * \date 28/07/2026
 */

#include "raylib.h"
#include <iostream>

#include "Menu.hpp"

// ***********************************************
// CONFIGURACION DE LA VENTANA
// ***********************************************

// Mas adelante estos valores saldran del archivo de tema (tema.json), para que el tamano de la ventana se pueda ajustar sin recompilar.

const int PantallaAncho = 1280;
const int PantallaAlto = 720;
const int FPS = 60;

using namespace std;

// ***********************************************

int main()
{
    // InitWindow crea la ventana
    // Nota: nada de raylib funciona antes de esta llamada: dibujar o cargar texturas
    InitWindow(PantallaAncho, PantallaAlto, "Memorama epico papus");

    SetTargetFPS(FPS); // Se establece el juego a 60 fps

    Escena_Estado escenaActual = Escena_menu;

    // Loop principal del juego
    while(!WindowShouldClose()){

        switch(escenaActual)
        {
            case Escena_juego:

            break;

            case Escena_configuracion:

            break;

            case Escena_puntajes:

            break;

            case Escena_creditos:

            break;

            default: break;
        }



        // Todo lo que se dibuja va entre BeginDrawing y EndDrawing
        BeginDrawing();
            ClearBackground(RAYWHITE);

            switch(escenaActual)
            {
                case Escena_menu:
                    DrawText("PANTALLA DE MENU PRINCIPAL", 260, 300, 24, DARKGRAY);
                    DrawText("Presiona ENTER para jugar (Pronto...)", 260, 350, 20, GRAY);
                break;

                case Escena_juego:
                    DrawText("AQUI VA EL TABLERO DEL JUEGO", 260, 300, 24, DARKBLUE);
                break;

                default: break;
            }

        EndDrawing();
    }

    CloseWindow(); // Cierra la ventana

    cout << "\n\nEl programa se acabo!" << endl;
    system("pause");
    return 0;
}
