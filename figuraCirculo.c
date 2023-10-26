#include <stdio.h>
#include <conio.h>
#include <windows.h>

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void dibujarCirculo(int x, int y, int radio) {
    for (int i = -radio; i <= radio; i++) {
        for (int j = -radio; j <= radio; j++) {
            if (i * i + j * j <= radio * radio) {
                gotoxy(x + j, y + i);
                printf("*");
            }
        }
    }
}

int main() {
    int x = 40; // Posición inicial del círculo en el eje X
    int y = 10; // Posición inicial del círculo en el eje Y
    int radio = 5; // Radio del círculo

    char tecla;
    do {
        system("cls"); // Limpia la pantalla

        dibujarCirculo(x, y, radio);

        tecla = getch(); // Espera a que el usuario presione una tecla

        switch (tecla) {
            case 72: // Flecha arriba
                y--;
                break;
            case 80: // Flecha abajo
                y++;
                break;
            case 75: // Flecha izquierda
                x--;
                break;
            case 77: // Flecha derecha
                x++;
                break;
        }
    } while (tecla != 27); // Salir del bucle cuando se presione la tecla Esc (código ASCII 27)

    return 0;
}

