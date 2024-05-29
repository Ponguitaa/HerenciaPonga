#pragma once
#include "Personaje.h"

class Heroe : public Personaje {
public:
    Heroe(std::string nombre, int vida, int ataque, int posicionX, int posicionY);
};

