#pragma once
#include "Heroe.h"
#include "Enemigo.h"
#include "EnemigoFinal.h"
#include <vector>

class Juego {
    std::vector<std::vector<char>> mapa;
    Heroe* heroe;
    std::vector<Enemigo*> enemigos;
    EnemigoFinal* enemigoFinal;

public:
    Juego(int filas, int columnas);

    void mostrarMapa();
    void moverHeroe(int dx, int dy);

private:
    Enemigo* encontrarEnemigo(int x, int y);
    void luchar(Personaje* a, Personaje* b);
};
