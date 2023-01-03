#include "funciones3Raya.hpp"

int main(int argc, char const *argv[])
{
    int opt;

    while (true) {

        printf("1) Jugar\n2) Salir\nIngrese una opción: ");

        scanf("%d", &opt);

        switch (opt)
        {
            case 1:
                printf("1) La máquina comienza\n2) El jugador comienza\nIngrese una opción: ");
                scanf("%d", &opt);

                if (opt < 1 || opt > 2) {
                    printf("Opción no valida\n");
                    break;
                }

                playTresEnRaya(opt);
                break;

            case 2:
                printf("Gracias por jugar\n");
                return 0;

            default:
                printf("Opción no valida\n");
                break;
        }

    }
}
