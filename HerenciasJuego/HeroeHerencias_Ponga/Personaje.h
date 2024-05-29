#pragma once
#include <string>

class Personaje {
private:
    std::string nombre;
    int vida;
    int ataque;
    int posicionX;
    int posicionY;

public:
    Personaje(std::string nombre, int vida, int ataque, int posicionX, int posicionY);

    virtual void mover(int dx, int dy);

    bool estaVivo() const;
    int getPosX() const;
    int getPosY() const;
    std::string getNombre() const;
    int getVida() const;
    int getAtaque() const;

    void recibirDano(int dano);
};
