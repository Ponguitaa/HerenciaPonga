#pragma once
#include "Personaje.h"

class EnemigoFinal : public Personaje {
    int superAtaque1;
    int superAtaque2;

public:
    EnemigoFinal(std::string nombre, int vida, int ataque, int posicionX, int posicionY, int superAtaque1, int superAtaque2);
    int realizarSuperAtaque();
};

