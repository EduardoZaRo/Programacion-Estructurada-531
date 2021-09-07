/*
Zavala Roman Irvin Eduardo 1270771
Ejercicio 3 Practica 9
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>



float** suma(float**, float**, int, int);
void componentes(float**, int, int);
float** reserva_memoria(int, int);
void muestra_matriz(float**, int, int);

int main(void)
{
    //Un apuntador doble permite realizar dos operaciones de indirección
    float **matriz1, **matriz2, **resultado;
    int filas, cols;

	//Entrada del tamano de las matrices
    printf("Ingrese dimensiones de la matriz (ej. 2,2): ");
    scanf("%d,%d", &filas, &cols);

	//Se ingresan los componentes y se muestran 
    printf("Matriz 1:\n");
    matriz1 = reserva_memoria(filas,cols);
    componentes(matriz1, filas,cols);
    muestra_matriz(matriz1, filas,cols);

    printf("Matriz 2:\n");
    matriz2 = reserva_memoria(filas,cols);
    componentes(matriz2, filas,cols);
    muestra_matriz(matriz2, filas,cols);

	//Se mandan las 2 matrices para multiplocarlas
    printf("Multiplicacion de matrices:\n");
    resultado = suma(matriz1, matriz2, filas,cols);
    muestra_matriz(resultado, filas,cols);

	//Se libera memoria
    free(matriz1);
    free(matriz2);
    free(resultado);

}

float** suma(float **A, float **B, int filas, int cols){
    int i,j,k, suma;
    float** matriz = reserva_memoria(filas, cols);
    for(i=0; i<filas; i++){
        for(j=0; j<cols; j++){
        	for(k = 0; k < cols; k++){
        		matriz[i][j] += A[i][k] * B[k][j];
			}

		} 	
	}
        
    return matriz;
}

void componentes(float **A, int filas, int cols){
    int i,j, componente;
    for(i=0; i<filas; i++){
        for(j=0; j<cols; j++){
        	printf("\nIngresa el elemento [%d][%d] :", i, j);
        	scanf("%d", &componente);
        	A[i][j] = componente;
		}    	
	}         
}

void muestra_matriz(float **A, int filas, int cols){
    int i,j;
    for(i=0; i<filas; i++){
        for(j=0; j<cols; j++)
            printf("%.2f ", A[i][j]);
        printf("\n");
    }
    printf("\n");
}

float** reserva_memoria(int filas, int cols)
{
    int i=0;
    float **matriz = (float**) calloc(filas, sizeof(float*) );

    while(i<filas){
        matriz[i] = (float*) calloc(cols, sizeof(float) );
        i++;
    }

    return matriz;
}
