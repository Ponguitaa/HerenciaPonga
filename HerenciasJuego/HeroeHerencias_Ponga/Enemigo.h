#pragma once
#include "Personaje.h"

class Enemigo : public Personaje {
public:
    Enemigo(std::string nombre, int vida, int ataque, int x, int y);
};

