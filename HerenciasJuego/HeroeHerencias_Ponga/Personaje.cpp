#include "Personaje.h"

Personaje::Personaje(std::string nombre, int vida, int ataque, int posicionX, int posicionY)
    : nombre(nombre), vida(vida), ataque(ataque), posicionX(posicionX), posicionY(posicionY) {}

void Personaje::mover(int dx, int dy) {
    posicionX += dx;
    posicionY += dy;
}

bool Personaje::estaVivo() const {
    return vida > 0;
}

int Personaje::getPosX() const {
    return posicionX;
}

int Personaje::getPosY() const {
    return posicionY;
}

std::string Personaje::getNombre() const {
    return nombre;
}

int Personaje::getVida() const {
    return vida;
}

int Personaje::getAtaque() const {
    return ataque;
}

void Personaje::recibirDano(int dano) {
    vida -= dano;
}
