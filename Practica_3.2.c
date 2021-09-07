/* Zavala Irvin Matricula:01270771
Programa que calcula raices de una funcion cuadratica*/
#include<stdio.h>
#include<math.h>

int main(void){
	float a, b, c,discriminante,e,x_1,x_2,x_1_i,x_2_i; //Declaracion variables
	
	printf("Programa que calcula las raices de una funcion cuadratica de la forma ax^2 + bx +c");//Descripcion de programa al usuario
	
	//Entrada de datos
	printf("\nIntroduzca a: ");
	scanf("\n%f",&a);
	printf("\nIntroduzca b: ");
	scanf("\n%f",&b);
	printf("\nIntroduzca c: ");
	scanf("\n%f",&c);
	
	discriminante = b*b - (4*a*c);
	e = 2 * a;
	if(discriminante == 0){//Si el discriminante es 0 solo queda -b/2a
		x_1 = -b/e;
		x_2 = -b/e;
		printf("\nLas 2 raices valen: %f", x_1);
	}
	else{//A este punto sabemos que el discriminante no es 0, por lo que solo queda que sea positivo o negativo
		if (discriminante > 0){//Si el discriminante es mayor las raices son reales
			x_1 = (-b + sqrt(discriminante)) / e;
			x_2 = (-b - sqrt(discriminante)) / e;
			printf("La primera raiz es: %.5f\n",x_1);
			printf("La segunda raiz es: %.5f\n",x_2);
		}
		else{//Si el discriminante es negativo las raices son imaginarias
			x_1 = (-b) / e;
			x_2 = (-b) / e;
			x_1_i = (sqrt(-discriminante)) / e;
			x_2_i =  (sqrt(-discriminante)) / e;
			printf("La primera raiz es: %.5f + %.5f i\n",x_1,x_1_i);
			printf("La segunda raiz es: %.5f - %.5f i\n",x_2,x_2_i);			
		}
	}
	return 0;
}
