/*
Zavala Roman Irvin Eduardo 1270771
Ejercicio 2 Practica 9
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>


//No pude hacer que funcionara la funcion de captura de coeficientes :(
float evalua_poli(float*, int, float);

int main(void)
{
	//Declaracion variables
    float *poli = NULL, x;
    int tam, i;

	//Entrada del grado del polinomio
    printf("\nIngresa el grado del polinomio: ");
    scanf("%d", &tam);
    
    //Reservacion de memoria para los coeficientes
	poli = (float*) malloc(tam * sizeof(float));
	
	//Entrada de los coeficients
    for(i = 0; i <= tam; i++){
    	printf("\nIngresa el coeficiente de x^%d: ", i);
    	scanf("%f", &poli[i]);
	}

	//Se imprime la ecuacion
	printf("\nEl polinomio es: \n");
    for(i = tam; i >= 0; i--){
    	printf("%.2fx^%d", poli[i], i);
    	if( i !=  0)
    		printf("+");
	}
	//Se pide el valor a evaluar y se lleva a la funcion evalue_poli
    printf("\nIngrese el valor a evaluar en el polinomio: ");
    scanf("%f", &x);
    printf("f(%.2f) = %.3f", x, evalua_poli(poli, tam, x));
}

float evalua_poli(float *poli, int tam, float x)
{
    float resultado = 0;
    //Instrucciones para evaluar el polinomio
	int i;
	for(i = 0; i <= tam; i++){
		resultado += poli[i]*pow(x,i);
	}
    return resultado;
}

