/* Zavala Irvin Matricula:01270771
Programa que calcula el factorial de un numero*/
#include<stdio.h>
#include<math.h>

long int factorial(int n);

int main(void){
	int n;//Declaracion de variables
	
	printf("Programa que calcula el factorial de un numero dado");
	printf("\nIngresa un numero: ");
	scanf("%d", &n);
	factorial(n);//Se llama a la funcion factorial
	return 0;
}

long int factorial(int n){
	long int fact = 1;
	int i;
	for (i = 1; i <= n; i++){//Ciclo for para calcular el factorial
		fact = fact*i;
	}
	printf("\nEl factorial de %d es: %d", n, fact);
	return fact;
}
