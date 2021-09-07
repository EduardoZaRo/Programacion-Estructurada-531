/* Zavala Irvin Matricula:01270771
Programa que encuentra y muestra todos los números de 4 cifras que cumplen la condición de
que la suma de las cifras de orden impar es igual a la suma de las cifras de orden par.
*/
#include<stdio.h>
#include<math.h>

int main(void){
	int a, b, c, d, abcd,i, suma_par, suma_impar, sum_total;//Declaracion enteros
	i = 0;//Con i voy a contar cuantos numeros cumplen la condicion
	for(abcd = 1000; abcd <= 9999; abcd++){//Con este for se exploran todos los numeros de 4 cifras (1000-9999)

		//Esto sirve para separar el numero en los 4 numeros que lo conforman
		//Por ejemplo si es 8550; a=8, b=5, c=5, d=0
		a = abcd / 1000;
    	b = (abcd % 1000) / 100;
	    c = (abcd % 1000) % 100 /10;
		d = (abcd % 1000) % 100 % 10 ;
		
		suma_par = 0;//Inicio las sumas en 0
		suma_impar = 0;
		
		
		//Con estos if voy viendo cifra por cifra si es par o impar y lo voy acumulando en la suma de su categoria
		if(a%2==0){
			suma_par = a;
		}else{ suma_impar = a;}
		
		if(b%2==0){
			suma_par = suma_par + b;
		}else{ suma_impar = suma_impar + b;}
		
		if(c%2==0){
			suma_par = suma_par +c;
		}else{ suma_impar = suma_impar + c;}
		
		if(d%2==0){
			suma_par = suma_par + d;
		}else{ suma_impar = suma_impar + d;}	
			
		if(suma_par == suma_impar){//Si la suma de los pares e impares es igual si imprime el numero dentro de una oracion
			printf("\nEn el numero %d las sumas de los numeros pares es igual a la suma de los numeros impares",abcd);
			i++;//Se acumulan los numeros que cumplen la condicion
			
		}
		
	}
	printf("\nHay %d numeros que cumplen la condicion", i);
	
	return 0;
}
