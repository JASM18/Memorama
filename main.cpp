/**
 * \file main.cpp
 * \brief Archivo principal para el memorama
 * \author S&aacute;nchez Montoy, Jes&uacute;s Axel
 * \author Helleon Cardenas, Alba Rosa
 * \author Chenoweth Galaz, Ivana Lin
 * \date 29/07/2026
 */

#include "raylib.h"
#include <iostream>

#include "Menu.hpp"
#include "Dibujo.hpp"
#include "Tema.hpp"

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
    InitWindow(PantallaAncho, PantallaAlto, "Memorama epico papus");
    SetTargetFPS(FPS); // Se establece el juego a 60 fps

    // Por defecto WindowShouldClose() tambien es verdadero al presionar ESC, no
    // solo al cerrar la ventana. Como nosotros queremos usar ESC para regresar al
    // menu, hay que quitarle ese trabajo. Sin esta linea, ESC cierra el juego.
    SetExitKey(KEY_NULL);

    Escena_Estado escenaActual = Escena_menu;

    // Loop principal del juego
    // Se sale por la X de la ventana o cuando el menu pide Escena_salir.
    while(!WindowShouldClose() && escenaActual != Escena_salir){

        // -------------------------------------------
        // ACTUALIZAR: leer entrada y cambiar el estado
        // -------------------------------------------
        switch(escenaActual)
        {
            case Escena_menu:
                // El menu se encarga de su propia navegacion y nos devuelve a
                // donde hay que ir. Si nadie eligio nada, devuelve Escena_menu
                // y aqui no cambia nada.
                escenaActual = ActualizarMenu();
            break;

            // Estas pantallas todavia no existen, asi que por ahora se comportan
            // igual: ESC regresa al menu. Conforme cada una se implemente, saldra
            // de esta lista y tendra su propio case.
            case Escena_configuracion:
            case Escena_puntajes:
            case Escena_creditos:
            case Escena_juego:

                if(IsKeyPressed(KEY_ESCAPE)){
                    escenaActual = Escena_menu;
                }

            break;

            default: break;
        }

        // -------------------------------------------
        // DIBUJAR: pintar el estado, sin modificarlo
        // -------------------------------------------
        // Todo lo que se dibuja va entre BeginDrawing y EndDrawing
        BeginDrawing();
            ClearBackground(COLOR_FONDO);

            switch(escenaActual)
            {
                case Escena_menu:
                    DibujarMenu();
                break;

                case Escena_configuracion:
                    dibujarPantallaPendiente("CONFIGURAR PARTIDA");
                break;

                case Escena_puntajes:
                    dibujarPantallaPendiente("MEJORES PUNTAJES");
                break;

                case Escena_creditos:
                    dibujarPantallaPendiente("CREDITOS");
                break;

                case Escena_juego:
                    dibujarPantallaPendiente("TABLERO DEL JUEGO");
                break;

                default: break;
            }

        EndDrawing();
    }

    CloseWindow(); // Cierra la ventana

    //cout << "\n\nEl programa se acabo!" << endl;
    //system("pause");
    return 0;
}
