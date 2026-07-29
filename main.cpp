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

// ***********************************************
// CONFIGURACION DE LA VENTANA
// ***********************************************

// Mas adelante estos valores saldran del archivo de tema (tema.json), para que el tamano de la ventana se pueda ajustar sin recompilar.

int PantallaAncho = 1280;
int PantallaAlto = 720;

const int FPS = 60;

using namespace std;

// ***********************************************

int main()
{
    // InitWindow crea la ventana
    // Nota: nada de raylib funciona antes de esta llamada: dibujar o cargar texturas
    InitWindow(PantallaAncho, PantallaAlto, "Memorama epico papus");

    // Limita el bucle a 60 fps. Sin esto el bucle corre tan rapido como pueda el CPU: consume el procesador al 100% sin necesidad
    // Si no se hace, entonces la velocidad del juego dependeria de que tan potente sea cada PC (Como en Geometry Dash xd)
    SetTargetFPS(FPS);

    // WindowShouldClose() devuelve true cuando el usuario cierra la ventana o
    // presiona ESC. Este es el "bucle de juego": se repite una vez por cuadro.
    while(!WindowShouldClose()){

        // Todo lo que se dibuja va entre BeginDrawing y EndDrawing.
        // raylib dibuja sobre un buffer oculto y lo muestra completo al final
        // (doble buffer); por eso no se ve parpadeo mientras se pinta.
        BeginDrawing();

            ClearBackground(RAYWHITE);  // Se limpia el cuadro anterior
            DrawText("raylib esta funcionando", 260, 300, 24, DARKGRAY);

        EndDrawing();
    }

    // Libera la ventana y el contexto de OpenGL. Es la contraparte de InitWindow.
    CloseWindow();

    cout << "\n\nEl programa se acabo!" << endl;
    system("pause");
    return 0;
}
