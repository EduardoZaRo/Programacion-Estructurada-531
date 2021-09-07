/*
Zavala Irvin Matricula:01270771
Cafeteria
*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define MAX 50
#define CALIF 10

void crea_calificaciones(int[], int);
void muestra_calificaciones(int[], int);
void muestra_frecuencias(int[], int);
void calcula_frecuencias(int[], int[], int);
void tabla(int[]);
int main(void)
{
    int calificaciones[MAX], frecuencias[CALIF] = {0};
    srand(time(NULL));

    crea_calificaciones(calificaciones, MAX);
    printf("\n\nArreglo de calificaciones:\n\n");
    muestra_calificaciones(calificaciones, MAX);

    calcula_frecuencias(calificaciones, frecuencias, MAX);
    printf("\n\nArreglo de frecuencias:\n\n");
    muestra_frecuencias(frecuencias, CALIF);
    printf("\n|Calif|\tFrecuencia|\tHistograma\n");

    tabla(frecuencias);

    return 0;
}


void crea_calificaciones(int calificaciones[], int tam)
{
    while(tam>0)
    {

        calificaciones[tam-1] = rand()%CALIF;
        tam--;
    }
}

void muestra_calificaciones (int calificaciones[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
        printf("Elemento %d: %d\n",i+1, calificaciones[i] + 1);


}
void muestra_frecuencias (int frecuencias[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
        printf("Calificacion %d: %d veces\n",i+1, frecuencias[i]);


}
void calcula_frecuencias(int calificaciones[], int frecuencias[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
        frecuencias[ calificaciones[i] ]++;
}

void tabla(int frecuencias[]){
	int i = 0;
	printf("_____________________________________");
	while(i < CALIF){
		printf("\n|%-5d|\t%-10d|\t", i+1, frecuencias[i]);
		int j; 
		for(j = 0; j < frecuencias[i]; j++){
			printf("*");
		}
		i++;
		printf("\n-------------------------------------");
	}	
}

