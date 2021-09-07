/* Zavala Irvin Matricula:01270771
Programa que calcula angulo de recta*/
#include<stdio.h>
#include<math.h>
float pendiente(float x_1, float x_2, float y_1, float y_2);
float angulo(float m );
float radagrad(float rad);
float ec_recta(float m, float x_1, float y_1);

int main(void){
	
	float x_1, x_2, y_1, y_2, m, rad, grad ,mx1_y1; //Declaracion variables
	
	printf("Programa que calcula el angulo de la pendiente de una linea recta dado 2 puntos");
	printf("\nInserte el primer punto (x,y): ");
	scanf("%f, %f", &x_1, &y_1);
	printf("\nInserte el primer punto (x,y): ");
	scanf("%f, %f", &x_2, &y_2);
	
	m =  pendiente(x_1, x_2, y_1, y_2);//Se llama la funcion pendiente con los puntos dados en m
	rad = angulo(m);//Se llama a la funcion angulo con pendiente y se guarda en rad
	grad = radagrad(rad); //Se llama la funcion radagrad en grad
	mx1_y1 = ec_recta(m, x_1, y_1);//Se llama la funcion ecuacion de la recta con parametros pendiente y un punto
	
	printf("\nLa pendiente es de %.3f", m);
	printf("\nEl angulo es de %.3f radianes o %.3f grados", rad, grad);
	printf("\nLa ecuacion de la recta es y = %.3f x + %.3f", m, mx1_y1);
	return 0;
}

float pendiente(float x_1, float x_2, float y_1, float y_2){
	float m;
	m = (y_2 - y_1)	/ (x_2 - x_1);//Calculo de pendiente
	return m;
}

float angulo(float m ){
	float angulo;
	angulo = atan(m);//Calculo del angulo en rad
	return angulo;
}

float radagrad(float rad){
	float grad;
	grad = rad * (180 / acos(-1));//Conversion de radianes a grados
	
	return grad;
}

float ec_recta(float m, float x_1, float y_1){
	float mx1_y1;
	mx1_y1 = -(m * x_1) + y_1; //Ecuacion de la recta
	
	return mx1_y1;
}
