/* Zavala Irvin Matricula:01270771
Programa que imprima numeros hasta que meta -1*/
#include<stdio.h>
#include<math.h>

float promedio(int i, float sum );

int main(void){
	//Declaracion variables
	int n, aux, i,  mayor, menor;
	float  sum;
	
	
	printf("Pedire numeros hasta que me des -1");
	
	//Se inician las variables pa que no fallen
	n = 0;
	sum = 0;
	i = -1;
	menor = 1e10;//Talvez esto no es lo mas optimizado XDDDD
	
	
	
	do{
		
		aux = n;//Guardo n en una varibale auxiliar
		sum += aux;//Sumo la variable auxiliar
		printf("\nIntroduce un numero: ");//Pido otro numero
		scanf("%d", &n);
		
		i++;
		
		//Se van actualizando las variables mayor y menor cada que se introduce un numero
		if(n > aux){
			mayor = n;
		}
		if(n < menor && n != -1 ){
			menor = n;
		}
		
	}while( n != -1 );//Si es -1 se sale
	
	printf("\nEl numero mayor es el %d.", mayor);
	printf("\nEl numero menor es el %d.", menor);
	printf("\nEl promedio es de %.2f", promedio(i, sum));

	return 0;
}

float promedio(int i, float sum ){
	float promedio;
	
	promedio = (sum/i);//Calculo del promedio
	
	return promedio;
}


