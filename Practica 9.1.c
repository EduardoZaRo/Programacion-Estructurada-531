/*
Zavala Roman Irvin Eduardo 1270771
Ejercicio 1 Practica 9
*/

#include<stdio.h>
#include<stdlib.h>

int primo(int* arreglo);
//No pude hacer funcionar la funcion agregar elemento


int main(void)
{
	//Declaracion variables
    int tam, lim_i, lim_s, i, *arreglo = NULL, *prim = NULL;

	//Entrada del rango
	printf("\n\tVoy a regresar los numeros primos de un rango que ingreses :o");
	printf("\nInserte el limite inferior del arreglo: ");
	scanf("%d", &lim_i);
	printf("\nInserte el limite superior del arreglo: ");
	scanf("%d", &lim_s);
	if(lim_i >= lim_s){
		printf("\nEl rango no es valido :/");
		return 0;
	}
	tam = lim_s - lim_i + 1;

	//Asignacion de memoria para los arreglos
	arreglo = (int*) malloc(sizeof(int) * tam);
	prim = (int*) malloc(sizeof(int));
    
	//Se llema arreglo con numeros consecutivos
    for( i = 0; i < tam; i++){
		arreglo[i] = lim_i;
		lim_i++;
    }
    
    //Se recorre el arreglo
    int tam_prim = 0;
	for(i = 0; i < tam; i++){
		if(primo(&arreglo[i])){//Si la funcion regresa que es primo entra al if
			tam_prim++;
			prim = (int*) realloc(prim, sizeof(int)*tam_prim);//Se aumenta en 1 la memoria asignada al arreglo de numeros primos
			prim[tam_prim-1] = arreglo[i];//Se guarda el numero primo
		}

	}
	
	//Se imprimen los numeros primos
	printf("\nEl arreglo con los numeros primos contiene:\n ");
	for(i = 0; i < tam_prim; i++){
		printf("[%d] ", prim[i]);
	}

	//Se libera la memoria
    free(arreglo);
	free(prim);
    return 0;
}


//Funcion para saber si el numero del arreglo es primo
int primo(int* arreglo){
	int i, primo, divisores = 0;

	for (i=1; i <= *arreglo; i++){
		if( *arreglo % i == 0){
			divisores++;
		}
	}
	if (divisores == 2){
		primo = 1;
	}
	else{
		primo = 0;
	}

    return primo;
}




