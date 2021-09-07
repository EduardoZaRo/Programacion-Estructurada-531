/*Zavala Roman Irvin Eduardo 01270771
Practica 11  Ejercicio 4*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

//Prototipos
float suma(float*, int);
float max(float*, int);
float min(float*, int);
float media(float*, int);
float mediana(float*, int);
float moda(float*, int);
float desva(float*, int );
int comparar(const void *, const void *);

int main(int argc, char* argv[]){
	
	FILE* lista;
	lista = fopen(argv[1], "r");//Se abre el archivo con el nombre del 2do parametro ingresado
	if(argc != 2){//Si hay menos de 2 parametros o mas ERROR
		printf("\nError");
		return 0;
	}
	
	//Inicio el arreglo dinamico
	float *arreglo = NULL;
	arreglo = (float*)malloc(sizeof(float));
	int i = 0, tam = 0;
	char c[20];
	
	if(lista){
		while ((fscanf(lista, "%19s", c)) != EOF){//Abro cada numero real del archivo
			i++;
			tam++;
			arreglo = (float*)realloc(arreglo, sizeof(float)*i);//Aumento el tamano del vector dinamico
			arreglo[tam - 1] = atof(c);//Como el numero lo extraigo como cadeno lo convierto a float con atof y lo guardo en el vector
			printf("[%.3f]", arreglo[i-1]);
		}
		fclose(lista);
	}
	

	//Copy paste de la practica 8.2 para llamar las funciones, solo cambio el int del tipo de arreglo a float
    float (*funciones[])(float*, int) = {suma, max, min, media, mediana, moda, desva};
    char* nombres[] = {"suma", "maximo", "minimo", "media", "mediana", "moda", "desviacion"};
    int   size = sizeof(funciones)/sizeof(funciones[0]);
    printf("\n");
    for(i = 0; i < size; i++)//Se llaman las funciones
        printf("%s: %.3f\n", nombres[i], funciones[i](arreglo,tam));
    free(arreglo);
    return 0;
}

float suma(float* array, int size)//Se suman los elementos del array
{
    float sum = 0;

    while(size--)
        sum += *(array++);
    
    return sum;
}

float max(float* array, int size)//Se le da el valor maximo al primer elemento y se compara a lo largo del array para buscar el maximo
{
    float maximo = *array;
    while(size--)
    {
        if(maximo < *array)
            maximo =*array;
        array++;
    }

    return maximo;
}

float min(float* array, int size)//Se la da el valor minimo al primero elemento y se compara a lo largo del array para buscar el minimo
{
	float minimo = *array;
    while(size--)
    {
        if(minimo > *array)
            minimo =*array;
        array++;
    }
    return minimo;
}

float media(float* array, int size)//Se llama la funcion suma y se divide entre el size para calcular la media
{
	float sum = suma(array, size), media;
	
	media = sum/size;
	
    return media;
}

//Se requiere datos ordenados
float mediana(float* array, int size)//Se ordenan los elementos, si el numero de elementos es impar la mediana es el del medio, si es par la mediana es el promedio del los 2 valores centrales
{	
    //usar funcion qsort se stdlib.h para ordenamiento de datos
    qsort(array, size, sizeof(float), comparar);
    float mediana;
    if(size%2 != 0){
    	mediana = array[size/2];
	}
	else{
		int a, b;

		a = array[(size/2)];
		b = array[(size/2)-1];
		mediana = (a+b)/2;
	}

    return mediana;
}

float moda(float* array, int size)//Se compara un elemento con todos los demas, si se repite se suma uno a contador, si contador es mayor a otra moda entonces el contador es la nueva moda
{
	int arreglo[size], i, j, contador, moda = contador, a = 0, modas = 0;

	for(i = 0; i < size; i++){
		arreglo[i] = *array;
		array++;

	}
	qsort(arreglo, size, sizeof(int), comparar);

	for(i = 0; i < size; i++){
		contador = 0;
		for(j = 0; j < size; j++){
			if(arreglo[i] == arreglo[j] && i != j){
				contador++;
			}
		}
		if(contador > moda){
			moda = contador;
			a = i;
		}
	}	



	moda = arreglo[a];

 	return moda;

}

float desva(float* array, int size)//Se llama la funcion promedio y aplicamos la formula de desviacion estandar
{
	float promedio = media(array, size), sumatoria = 0, desva, a;
	int cont = size;
	while(cont--){
		a = *(array++)-promedio;
		sumatoria += pow(a, 2);

	}

	desva = sqrt(sumatoria/size);
	return desva;
}

int comparar(const void *a, const void *b)//Ordena elementos
{
    return *(int*)a - *(int*)b;
}
