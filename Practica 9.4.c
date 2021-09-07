/*
Zavala Roman Irvin Eduardo 1270771
Ejercicio 4 Practica 9
*/

#include<stdio.h>
#include<stdlib.h>

int primo(int* arreglo);
//No pude hacer funcionar la funcion agregar :(


int main(void)
{
	//Declaracion variables
    int tam, i, j, n = 1;
    char opc;
	int *arreglo = NULL, *unicos = NULL, tam_unicos = 0;
	
	//Se pide la cantidad de elementos a ingresar
	printf("\n\tVoy a crear un arreglo con los valores sin repetir");
	printf("\nCuantos elementos vas a ingresar?: ");
	scanf("%d", &n);
	
	//Se reserva memoria a arreglo
	arreglo = (int*)malloc(sizeof(int)*n);
	
	//Se ingresan elementos a arreglo
	for(i = 0; i < n; i++){
		printf("\nIngresa el elemento %d: ", i);
		scanf("%d", &arreglo[i]);
	}
	
	//Se imprime el arreglo
	printf("\nEl arreglo que ingresaste fue: \n ");
	for(i = 0; i < n; i++){
		printf("[%d] ", arreglo[i]);
	}
	int repetido = 0;
	//Se reserva memoria de para 1 elemento int a unicos
	unicos = (int*)malloc(sizeof(int));
	
	//Todos los elementos repetidos de arreglo se marca con -1
	for(i = 0; i < n; i++){
		if(arreglo[i] != -1){
			for(j = 0; j < n; j++){
				if(i != j){
					if(arreglo[i] == arreglo[j]){
						arreglo[j] = -1;
					}				
				}	
			}
		}			
	}
	
	//Todos los numeros diferentes de -1 se escriben a unicos
	for(i = 0; i < n; i++){
		if(arreglo[i] != -1){
			tam_unicos++;
			unicos = (int*)realloc(unicos, tam_unicos*sizeof(int));//Se va incrementando el tamano de unicos conforme se agregan numeros unicos
			unicos[tam_unicos-1] = arreglo[i];
		}
	}

	//Se imprime el arreglo unicos
	printf("\nEl arreglo sin valores repetidos queda: \n");
	for(i = 0; i < tam_unicos; i++){
		printf("[%d] ", unicos[i]);
	}
	
	//Se libera la memoria
    free(arreglo);
	free(unicos);
    return 0;
}


