/* Zavala Irvin Matricula:01270771
Programa que calcula todos los números de tres cifras tales que la suma de los cubos de las
cifras es igual al valor del número.*/
#include<stdio.h>
#include<math.h>

int main(void){
	int a, b, c, abc,i;//Declaracion enteros
	
	i = 0;//Contador de los numeros que cumplen la condicion
	
	for(abc = 100; abc <= 999; abc++){ //Se exploran todos los numeros de 3 cifras (100-999)
	
		//Esto sirve para separar el numero en los 3 numeros que lo conforman
		//Por ejemplo 855; a=8, b=5, c=5
		a = abc / 100;
    	b = (abc % 100) / 10;
	    c = (abc % 100) % 10 /1;

	    if(abc == pow(a, 3) + pow(b, 3) + pow(c, 3)) {//Se compara si el numero es igual a la suma de los cubos de sus cifras, si es igual entra
	    	i++;//Se incrementa el contador de numero que cumplen la condicion
	    	printf("%d = %d ^ 3 + %d ^ 3 + %d ^ 3.\n",abc, a, b, c);//Se imprime el numero con la condicion al usuario	
		}
	    
	}
	printf("Hay %d numeros de 3 cifras que la suma de los cubos de sus digitos dan el mismo numero",i);//Se imprime cuantos numeros de 3 cifras hay que cumplen la condicion
	return 0;
}
