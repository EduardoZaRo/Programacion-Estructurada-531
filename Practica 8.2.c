/* Zavala Irvin Matricula:01270771
Programa que calcula moda, mediana, max, min, media, suma con punteros y funciones*/
#include<stdio.h>
#include<stdlib.h> //funcion qsort
#include<time.h>
#define TAM 50

void aleatorios(int*, int);

float suma(int*, int);
float max(int*, int);
float min(int*, int);
float media(int*, int);
float mediana(int*, int);
float moda(int*, int);
float desva(int*, int );
int comparar(const void *, const void *);



//EXTRA 10pts
//float desviacion(int*, int);

int main(void)
{
	//Declaracion variables
    int size, i, tam;
    float (*funciones[])(int*, int) = {suma, max, min, media, mediana, moda, desva};
    char* nombres[] = {"suma", "maximo", "minimo", "media", "mediana", "moda", "desviacion"};
    
    
    //Entrada de la cantidad de datos y los datos
	printf("\nCuanto numeros vas a ingresar?: ");
	scanf("%d", &tam);
	int arreglo[tam];
	for (i = 0; i < tam; i++){
		printf("\nIngresa el numero %d: ", i+1);
		scanf("%d", &arreglo[i]);
	}
	
    size = sizeof(funciones)/sizeof(funciones[0]);
    for(i=0; i<size; i++)//Se llaman las funciones
        printf("%s: %.3f\n", nombres[i], funciones[i](arreglo,tam));


    return 0;
}


float suma(int* array, int size)//Se suman los elementos del array
{
	
    float sum = 0;

    while(size--)
        sum += *(array++);
    
    return sum;
}

float max(int* array, int size)//Se le da el valor maximo al primer elemento y se compara a lo largo del array para buscar el maximo
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

float min(int* array, int size)//Se la da el valor minimo al primero elemento y se compara a lo largo del array para buscar el minimo
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

float media(int* array, int size)//Se llama la funcion suma y se divide entre el size para calcular la media
{
	float sum = suma(array, size), media;
	
	media = sum/size;
	
    return media;
}

//Se requiere datos ordenados
float mediana(int* array, int size)//Se ordenan los elementos, si el numero de elementos es impar la mediana es el del medio, si es par la mediana es el promedio del los 2 valores centrales
{	
    //usar funcion qsort se stdlib.h para ordenamiento de datos
    qsort(array, size, sizeof(int), comparar);
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

float moda(int* array, int size)//Se compara un elemento con todos los demas, si se repite se suma uno a contador, si contador es mayor a otra moda entonces el contador es la nueva moda
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

float desva(int* array, int size)//Se llama la funcion promedio y aplicamos la formula de desviacion estandar
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
