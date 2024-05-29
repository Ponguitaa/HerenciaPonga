#include "Juego.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

Juego::Juego(int filas, int columnas) {
    mapa.resize(filas, std::vector<char>(columnas, '*'));
    srand(static_cast<unsigned int>(time(0)));

    // Crear héroe
    heroe = new Heroe("Antonio", 100, 20, 0, 0);
    mapa[0][0] = 'A';

    // Crear enemigos
    for (int i = 0; i < 5; ++i) {
        int x = rand() % filas;
        int y = rand() % columnas;
        while (mapa[x][y] != '*') {
            x = rand() % filas;
            y = rand() % columnas;
        }
        Enemigo* enemigo = new Enemigo("Empoleon" + std::to_string(i + 1), 50, 10, x, y);
        enemigos.push_back(enemigo);
        mapa[x][y] = 'E';
    }

    // Crear enemigo final 
    int salidaY = rand() % columnas;
    enemigoFinal = new EnemigoFinal("Pedro Sanchez", 200, 30, filas - 1, salidaY, 40, 50);
    mapa[filas - 1][salidaY] = 'P';
}

void Juego::mostrarMapa() {
    for (const auto& fila : mapa) {
        for (char celda : fila) {
            std::cout << celda << ' ';
        }
        std::cout << '\n';
    }
}

void Juego::moverHeroe(int dx, int dy) {
    int nuevaX = heroe->getPosX() + dx;
    int nuevaY = heroe->getPosY() + dy;

    if (nuevaX < 0 || nuevaX >= mapa.size() || nuevaY < 0 || nuevaY >= mapa[0].size()) {
        std::cout << "Movimiento fuera de los límites.\n";
        return;
    }

    char celdaDestino = mapa[nuevaX][nuevaY];
    if (celdaDestino == 'E') {
        // Luchar con enemigo
        Enemigo* enemigo = encontrarEnemigo(nuevaX, nuevaY);
        if (enemigo) {
            luchar(heroe, enemigo);
            if (!enemigo->estaVivo()) {
                mapa[nuevaX][nuevaY] = ' ';
            }
        }
    }
    else if (celdaDestino == 'P') {
        // Luchar con enemigo final
        luchar(heroe, enemigoFinal);
        if (heroe->estaVivo()) {
            std::cout << "¡Antonio ha salido de la mazmorra!\n";
        }
        else {
            std::cout << "¡Has perdido contra Pedro Sanchez!\n";
        }
        return;
    }

    // Mover héroe
    mapa[heroe->getPosX()][heroe->getPosY()] = ' ';
    heroe->mover(dx, dy);
    mapa[nuevaX][nuevaY] = 'A';

    if (!heroe->estaVivo()) {
        std::cout << "¡Has sido derrotado!\n";
    }
}

Enemigo* Juego::encontrarEnemigo(int x, int y) {
    for (Enemigo* enemigo : enemigos) {
        if (enemigo->getPosX() == x && enemigo->getPosY() == y) {
            return enemigo;
        }
    }
    return nullptr;
}

void Juego::luchar(Personaje* a, Personaje* b) {
    std::cout << "Comienza la lucha entre " << a->getNombre() << " y " << b->getNombre() << "!\n";
    while (a->estaVivo() && b->estaVivo()) {
        b->recibirDano(a->getAtaque());
        if (b->estaVivo()) {
            a->recibirDano(b->getAtaque());
        }
    }
    if (a->estaVivo()) {
        std::cout << a->getNombre() << " ha ganado la lucha!\n";
    }
    else {
        std::cout << b->getNombre() << " ha ganado la lucha!\n";
    }
}
