/* Zavala Irvin Matricula:01270771
Programa que calcula raices de una funcion cuadratica*/
#include<stdio.h>
#include<math.h>
void raices(float, float, float, float*, float* );
int main(void){
	float a, b, c, x_1, x_2, *raiz_1, *raiz_2; //Declaracion variables y punteros
	
	printf("Programa que calcula las raices de una funcion cuadratica de la forma ax^2 + bx +c");//Descripcion de programa al usuario
	
	//Entrada de datos
	printf("\nIntroduzca a: ");
	scanf("\n%f",&a);
	printf("\nIntroduzca b: ");
	scanf("\n%f",&b);
	printf("\nIntroduzca c: ");
	scanf("\n%f",&c);
	
	//Les asigno la memoria a la que van a apuntar los punteros
	raiz_1 = &x_1;
	raiz_2 = &x_2;
	
	//Llamo la funcion

	raices(a, b, c , raiz_1, raiz_2);

	
	
	//Imprimo las raices devueltas desde la memoria apuntada

	return 0;
}

void raices(float a, float b, float c, float* raiz_1, float* raiz_2){
	float e, discriminante, x_1_i, x_2_i;
	discriminante = b*b - (4*a*c);
	e = 2 * a;
	if(discriminante == 0){//Si el discriminante es 0 solo queda -b/2a
		*raiz_1 = -b/e;
		*raiz_2 = -b/e;
	}
	else{//A este punto sabemos que el discriminante no es 0, por lo que solo queda que sea positivo o negativo
		if (discriminante > 0){//Si el discriminante es mayor las raices son reales
			*raiz_1 = (-b + sqrt(discriminante)) / e;
			*raiz_2 = (-b - sqrt(discriminante)) / e;
		}
		else{//Si el discriminante es negativo las raices son imaginarias

			*raiz_1 = (-b) / e;
			*raiz_2 = (-b) / e;
			x_1_i = (sqrt(-discriminante)) / e;
			x_2_i =  (sqrt(-discriminante)) / e;
			printf("La primera raiz es: %.5f + %.5f i\n",*raiz_1,x_1_i);
			printf("La segunda raiz es: %.5f - %.5f i\n",*raiz_2,x_2_i);					
		}
	}

}

