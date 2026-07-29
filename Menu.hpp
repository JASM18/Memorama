#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED

enum Escena_Estado {
    Escena_menu,
    Escena_configuracion,
    Escena_puntajes,
    Escena_creditos,
    Escena_juego,
    Escena_pausa,
    Escena_resultados
};

void ActualizarEscena(int opcion);

#endif // MENU_HPP_INCLUDED
