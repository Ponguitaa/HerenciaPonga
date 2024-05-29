#include "EnemigoFinal.h"
#include <cstdlib>

EnemigoFinal::EnemigoFinal(std::string nombre, int vida, int ataque, int posicionX, int posicionY, int superAtaque1, int superAtaque2)
    : Personaje(nombre, vida, ataque, posicionX, posicionY), superAtaque1(superAtaque1), superAtaque2(superAtaque2) {}

int EnemigoFinal::realizarSuperAtaque() {
    return (rand() % 2 == 0) ? superAtaque1 : superAtaque2;
}
