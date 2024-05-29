#include "Juego.h"
#include <iostream>

void mostrarMenu() {
    std::cout << "Opciones de movimiento:\n";
    std::cout << "w - Mover arriba\n";
    std::cout << "s - Mover abajo\n";
    std::cout << "a - Mover izquierda\n";
    std::cout << "d - Mover derecha\n";
    std::cout << "q - Salir de la mazmorra\n";
}

int main() {

    Juego juego(10, 10);
    char opcion;
    bool continuar = true;

    while (continuar) {
        system("pause");
        system("cls");
        juego.mostrarMapa();
        mostrarMenu();
        std::cin >> opcion;

        switch (opcion) {
        case 'w':
            juego.moverHeroe(-1, 0);
            break;
        case 's':
            juego.moverHeroe(1, 0); 
            break;
        case 'a':
            juego.moverHeroe(0, -1);
            break;
        case 'd':
            juego.moverHeroe(0, 1);
            break;
        case 'q':
            continuar = false;
            break;
        default:
            std::cout << "Opción no válida. Inténtalo de nuevo.\n";
            break;
        }
    }

    return 0;
}
