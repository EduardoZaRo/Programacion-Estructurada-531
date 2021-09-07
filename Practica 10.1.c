/*Zavala Roman Irvin Eduardo 1270771
Practica 10 Ejercicio 1*/

#include<stdio.h>
#include<math.h>
//Estructuras
struct complejo{
    float real;
    float img;
};

//Prototipos
struct complejo captura();
void rectangular(struct complejo);
void polar(struct complejo);
void suma(struct complejo, struct complejo);
void resta(struct complejo, struct complejo);
void multiplicacion(struct complejo, struct complejo);
void division(struct complejo, struct complejo);

int main(void){
	
	//Se imprimen las opciones al usuario
	int opc;
	printf("\nMenu de opciones: ");
	printf("\n1. Imprimir numero complejo en forma rectangular.");
	printf("\n2. Imprimir numero complejo en forma polar.");
	printf("\n3. Sumar numeros complejos.");
	printf("\n4. Restar numeros complejos.");
	printf("\n5. Multiplicacion numeros complejos.");
	printf("\n6. Division numeros complejos.\n");
	scanf("%d", &opc);

	//Se ingresan 2 numeros complejos
	struct complejo c1 = captura();
	struct complejo c2 = captura();
	
	//Se llaman las funciones dependiendo de la opcion
	switch(opc){
		case 1: ;
			rectangular(c1);
			rectangular(c2);
			break;	
		case 2: ;
			polar(c1);
			polar(c2);				
			break;
		case 3: ;
			suma(c1, c2);				
			break;
		case 4: ;
			resta(c1, c2);				
			break;
		case 5: ;
			multiplicacion(c1, c2);				
			break;
		case 6: ;
			division(c1, c2);				
			break;
	}


    return 0;
}

struct complejo captura(){//Funcion para capturar los numeros complejos
    struct complejo c;
    printf("Ingrese numero complejo (ej 1+2i): ");
    scanf("%f+%fi", &c.real, &c.img);
    return c;
}

void rectangular(struct complejo c){//Imprime numeros complejos en forma rectangular
    printf("\nNumero complejo: %.1f + %.1fi ", c.real, c.img);
}

void polar(struct complejo c){//Imprime numeros complejos en forma polar
	float r, theta, a, b;
	r = sqrt(pow(c.real, 2) + pow(c.img, 2));

	if(c.real > 0){//Si la parte real es positiva theta = atan(b/a)
		theta = atan(c.img/c.real);
	}
	if(c.real < 0){//Si la parte real es positiva theta = atan(b/a)+2pi
		theta = atan(c.img/c.real) + acos(-1.0);
	}
	a = cos(theta);
	b = sin(theta);
	printf("\nEl numero en forma polar es %f(%f + %f i)", r, a, b);
}

void suma(struct complejo c, struct complejo c1){//Imprime la suma de numeros complejos
	float a, b;
	a = c.real + c1.real;
	b = c.img + c1.img;
	printf("\nLa suma de (%.2f+%.2f i)+(%.2f+%.2f i) = %.2f+%.2f i", c.real, c.img, c1.real, c1.img, a, b);
}

void resta(struct complejo c, struct complejo c1){//Imprime la resta de numeros complejos
	float a, b;
	a = c.real - c1.real;
	b = c.img - c1.img;
	printf("\nLa suma de (%.2f+%.2f i)-(%.2f+%.2f i) = %.2f+%.2f i", c.real, c.img, c1.real, c1.img, a, b);
}

void multiplicacion(struct complejo c, struct complejo c1){//Imprime la multiplicacion de numeros complejos
	float a, b, d;
	//Se simula la multiplicacion de numeros complejos
	a = c.real * c1.real;
	b = c.img * c1.real + c.real * c1.img;
	d = c.img * c1.img;
	printf("\nLa multiplicacion de (%.2f+%.2f i)*(%.2f+%.2f i) = %.2f+%.2f i", c.real, c.img, c1.real, c1.img, a-d, b);
}

void division(struct complejo c, struct complejo c1){//Imprime la division de numeros complejos
	float a, b, d, e, f, g;
	//Se simula racionalizacion y multiplicacion necesarios para la division
	a = c.real * c1.real;
	b = c.img * c1.real + c.real * (-1*c1.img);
	d = c.img * (-1*c1.img);

	
	e = c1.real * c1.real;
	f = c1.img * c1.real + c.real * (-1*c1.img);
	g = c1.img * (-1*c1.img);
	printf("\nLa division de (%.2f+%.2f i)/(%.2f+%.2f i) = %.2f+%.2f i", c.real, c.img, c1.real, c1.img, (a-d)/(e-f+g), (b)/(e-f+g));
}

