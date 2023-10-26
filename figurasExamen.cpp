#include <stdio.h>
#include <conio.h>
#include <windows.h>

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void dibujarFigura(int figura){
	if(figura==1){
		int x = 40;
	    int y = 10;
	
	    char tecla;
	    do {
	        system("cls");
	
	        gotoxy(x, y);
		    printf(" ____ ");
		    gotoxy(x, y + 1);
		    printf("|    |");
		    gotoxy(x, y + 2);
		    printf("|____|");
	
	        tecla = getch();
	
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
	    } while (tecla != 27);
	} else if(figura==2){
		int x = 40;
	    int y = 10;
	
	    char tecla;
	    do {
	        system("cls");
	
	        gotoxy(x, y);
		    printf("  /\\");
		    gotoxy(x, y + 1);
		    printf(" /  \\");
		    gotoxy(x, y + 2);
		    printf("/____\\");
	
	        tecla = getch();
	
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
	    } while (tecla != 27);
	} else if(figura==3){
		int x = 40; // Posición inicial del círculo en el eje X
	    int y = 10; // Posición inicial del círculo en el eje Y
	    int radio = 5; // Radio del círculo
	
	    char tecla;
	    do {
	        system("cls"); // Limpia la pantalla
	
	        for (int i = -radio; i <= radio; i++) {
		        for (int j = -radio; j <= radio; j++) {
		            if (i * i + j * j <= radio * radio) {
		                gotoxy(x + j, y + i);
		                printf("*");
		            }
		        }
		    }
	
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
	    } while (tecla != 27);
	}
	
}

int main() {
	int figura;
	printf("Cual figura desea seleccionar:\n1-Cuadrado\n2-Triangulo\n3-Circulo\n");
	scanf("%d", &figura);
    dibujarFigura(figura);

    return 0;
}
