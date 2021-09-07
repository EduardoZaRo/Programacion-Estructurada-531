/* Zavala Irvin Matricula:01270771
Programa que solicite un numero y diga si es primo o no*/
#include<stdio.h>

int main(void){
	int n, divisores;//Declaracion enteros
	float primo;//Declaracion flotante
	
	printf("Inserte un numero y dire si es primo o no: ");
	scanf("%d", &n);
	
	int i;//Declaracion contador
	
	divisores = 0;//Se inicia la variable responsable de almacenar los divisores del numero
	
	for (i=1; i <= n; i++){
		if( n % i == 0){
			divisores++;//Si hay un divisor que cumpla la condicion se suma en divisores
		}
	}
	if (divisores == 2){
		printf("El numero es primo :)");
	}
	else{
		printf("El numero no es primo :(");
	}

	return 0;
}
