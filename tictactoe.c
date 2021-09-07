/*Zavala Roman Irvin Eduardo 01270771
TIC TAC TOU XD*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define CRUZ 'X'
#define CERO 'O'
#define VACIO 0

#define FIL 3
#define COL 3

#define CAMBIOT(X) (X==CRUZ? CERO : CRUZ)


void limpiar_tablero(char[FIL][COL], int, int);
char turno_inicial();
int movimiento(char[FIL][COL], int, int, char);
char turno_n(char);
char ganador(char[FIL][COL], int, int);
int vacios(char[FIL][COL], int, int);
void mostrar_tablero(char[FIL][COL], int, int);

int main(void)
{
	//Declaracion de variables
    char tablero[FIL][COL];
    char turno = turno_inicial(), winner;
	int x, y, i = 1;//El i me servira para contar turnos
	
	
	limpiar_tablero(tablero, FIL, COL);//Creo un tablero 3x3 limpio
	
	do{
		winner = ganador(tablero, FIL, COL);//Funcion que comprueba el ganador
	    
	    mostrar_tablero(tablero, FIL, COL);
		
	    movimiento(tablero, x, y, turno);i++;
	    mostrar_tablero(tablero, FIL, COL);
	    turno = turno_n(turno);//Cambio la ficha
	    
	    //4 es la cantidad minima de movimientos en las que puede ganar alguien
		if(i >= 4){//Compruebo si el movimiento es ganador
			winner = ganador(tablero, FIL, COL);
			if(winner == 'X' ||winner == 'O'){
				mostrar_tablero(tablero, FIL, COL);
				break;
			}		
		}

	    movimiento(tablero, x, y, turno);i++;
	    turno = turno_n(turno);//Cambio la ficha


		if(i >= 4){//Compruebo si el movimiento es ganador
			winner = ganador(tablero, FIL, COL);
			if(winner == 'X' ||winner == 'O'){
				mostrar_tablero(tablero, FIL, COL);
				break;
			}		
		}
		
		if(i == 9){//Si llegamos a este movimiento y nadie a ganado es empate
			if(winner != 'X'||winner != 'O'){
				printf("\nEmpate!");
				mostrar_tablero(tablero, FIL, COL);
				winner == 'E';
				break;	
			}
		}

		
			
	}while(winner == 'X' ||winner == 'O'||winner == 'E');

    return 0;
}

void limpiar_tablero(char tablero[FIL][COL], int fila, int col){//Crea tablero vacio
    int i,j;
    for(i = 0; i < fila; i++)
        for(j = 0; j < col; j++)
            tablero[i][j] = VACIO;	
}

char turno_inicial(){
    return rand()%2 ? CRUZ : CERO;
}

char turno_n(char turno){//Funcion que cambia el turno
	if(turno == CRUZ){
		turno = CERO;
	}
	else{
		turno = CRUZ;
	}
	return turno;
}

int movimiento(char tablero[FIL][COL], int x, int y, char turno){//Funcion que registra la posicion de las fichas
	printf("\nIntroduce la coordenada de tu movimiento(x,y): ");
	scanf("%d, %d", &x, &y);
	if(x >= 0 && x < FIL && y >= 0 && y < COL)
    {
        if(tablero[x][y] == VACIO)
        {
        	if(turno == CRUZ){
        		tablero[x][y] = turno;
        		return 1;
			}
            else{
	            tablero[x][y] = turno;
	            return 0;	

			}
        }
        else{
			printf("\nEse lugar ya esta ocupado!!");
			movimiento(tablero, x, y,turno);
		}
    }
    else
    {
    	printf("\nMovimiento no valido");
    	movimiento(tablero, x, y,turno);
	}
    return 0;
}


void mostrar_tablero(char tablero[FIL][COL], int fila, int col){//Imprime el tablero al usuario
    int i,j;
    char ficha;
    printf("\n **** Tablero **** \n");
    for(i=0; i<fila; i++)
    {
        for(j=0; j<col; j++)
        {
            ficha = !tablero[i][j]?' ':tablero[i][j];
            printf(" %c ", ficha);
            if(j<col-1) printf(" | ");
        }
        if(i<fila-1)
            printf("\n---------------");
        printf("\n");
    }
}

char ganador(char tablero[FIL][COL], int fila, int columna){//Funcion que comprueba quien gana

	if((tablero[0][0] == CRUZ && tablero[0][1]== CRUZ && tablero[0][2]== CRUZ) || (tablero[1][0]== CRUZ && tablero[1][1]== CRUZ && tablero[1][2]== CRUZ) || (tablero[2][0]== CRUZ && tablero[2][1]== CRUZ && tablero[2][2]== CRUZ)||(tablero[0][0] == CRUZ && tablero[1][1]== CRUZ && tablero[2][2]== CRUZ) || (tablero[0][2]== CRUZ && tablero[1][1]== CRUZ && tablero[2][0]== CRUZ)||(tablero[0][0] == CRUZ && tablero[1][0]== CRUZ && tablero[2][0]== CRUZ) || (tablero[0][1]== CRUZ && tablero[1][1]== CRUZ && tablero[2][1]== CRUZ) || (tablero[0][2]== CRUZ && tablero[1][2]== CRUZ && tablero[2][2]== CRUZ) ){
		printf("\nFelicidades! X a ganado");
		return 'X';
	}
	else{
			if((tablero[0][0] == CERO && tablero[0][1]== CERO && tablero[0][2]== CERO) || (tablero[1][0]== CERO && tablero[1][1]== CERO && tablero[1][2]== CERO) || (tablero[2][0]== CERO && tablero[2][1]== CERO && tablero[2][2]== CERO)||(tablero[0][0] == CERO && tablero[1][1]== CERO && tablero[2][2]== CERO) || (tablero[0][2]== CERO && tablero[1][1]== CERO && tablero[2][0]== CERO)||(tablero[0][0] == CERO && tablero[1][0]== CERO && tablero[2][0]== CERO) || (tablero[0][1]== CERO && tablero[1][1]== CERO && tablero[2][1]== CERO) || (tablero[0][2]== CERO && tablero[1][2]== CERO && tablero[2][2]== CERO) ){
			printf("\nFelicidades! O a ganado");
			return 'O';
		}
		else{
			return 'E';
		}	
	}


}


