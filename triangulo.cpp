#include <stdio.h>
#include <conio.h>
#include <windows.h>

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void dibujarTriangulo(int x, int y) {
    gotoxy(x, y);
    printf("  /\\");
    gotoxy(x, y + 1);
    printf(" /  \\");
    gotoxy(x, y + 2);
    printf("/____\\");
}

int main() {
    int x = 40; // Posición inicial del triángulo en el eje X
    int y = 10; // Posición inicial del triángulo en el eje Y

    char tecla;
    do {
        system("cls"); // Limpia la pantalla

        dibujarTriangulo(x, y);

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