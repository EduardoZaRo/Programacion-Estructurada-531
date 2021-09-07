/*Zavala Roman Irvin Eduardo 1270771
Practica 10 Ejercicio 3*/

#include<stdio.h>
#include<math.h>
//Estructura
struct vector{
    float i;
    float j;
    float k;
};

//Prototipo de funciones
struct vector captura();
void mostrar(struct vector);
float modulo(struct vector);
void suma(struct vector , struct vector);
void resta(struct vector , struct vector);
void producto_escalar(struct vector , struct vector);
void producto_vectorial(struct vector , struct vector);


int main(void){
	//Se imprime menu de opciones
	int opc;
	printf("\nMenu de opciones: ");
	printf("\n1. Imprimir 2 vectores.");
	printf("\n2. Modulo de vector.");
	printf("\n3. Suma de vectores.");
	printf("\n4. Resta de vectores.");
	printf("\n5. Producto escalar.");
	printf("\n6. Producto vectorial.\n");
	scanf("%d", &opc);

	//Entrada de 2 vectores
	struct vector v1 = captura();
	struct vector v2 = captura();
	
	//Se llaman las funciones dependiendo de la opcion
	switch(opc){
		case 1: ;
			mostrar(v1);
			mostrar(v2);
			break;	
		case 2: ;	
			printf("\nEl modulo del vector 1 es: %f", modulo(v1));
			printf("\nEl modulo del vector 2 es: %f", modulo(v2));
			break;
		case 3: ;
			suma(v1, v2);
			break;
		case 4: ;
			resta(v1, v2);			
			break;
		case 5: ;
			producto_escalar(v1, v2);
			break;
		case 6: ;
			producto_vectorial(v1, v2);
			break;
	}


    return 0;
}

struct vector captura(){//Captura vectores de la forma ai+bj+ck
    struct vector v;
    printf("Ingrese un vector (ej 5i+8j+2k -> (5,8,2)): ");
    scanf("%f,%f,%f", &v.i, &v.j, &v.k);
    return v;
}

void mostrar(struct vector v){//Imprime vector
    printf("\nVector: %.1f + %.1f +%.1f ", v.i, v.j, v.k);
}

float modulo(struct vector v){//Calcula el modulo del vector con la formula ||v||=sqrt(a^2+b^2+c^2)
	float a, b, modulo = sqrt(pow(v.i, 2)+pow(v.j, 2)+pow(v.k, 2));
	return modulo;
}

void suma(struct vector v, struct vector v1){//Suma 2 vectores
	float a, b, c;
	a = v.i + v1.i;
	b = v.j + v1.j;
	c = v.k + v1.k;
	printf("\nLa suma de los vectores (%.2f %.2f %.2f) + (%.2f %.2f %.2f) = (%.2f %.2f %.2f)", v.i, v.j, v.k, v1.i, v1.j, v1.k, a, b, c);
}

void resta(struct vector v, struct vector v1){//Resta 2 vectores
	float a, b, c;
	a = v.i - v1.i;
	b = v.j - v1.j;
	c = v.k - v1.k;
	printf("\nLa resta de los vectores (%.2f %.2f %.2f) - (%.2f %.2f %.2f) = (%.2f %.2f %.2f)", v.i, v.j, v.k, v1.i, v1.j, v1.k, a, b, c);
}

void producto_escalar(struct vector v, struct vector v1){//Calcula el producto escalar (multiplicacion) de vectores
	float a, b, c;
	a = v.i*v1.i;
	b = v.j*v1.j;
	c = v.k*v1.k;
	printf("\nEl producto escalar de los vectores (%.2f %.2f %.2f) * (%.2f %.2f %.2f) = %.2f", v.i, v.j, v.k, v1.i, v1.j, v1.k, a+b+c);
}

void producto_vectorial(struct vector v, struct vector v1){//Calcula el producto vectorial (producto cruz) de vectores
	float a, b, c;
	a = v.j*v1.k - v.k*v1.j;
	b = v.k*v1.i - v.i*v1.k;
	c = v.i*v1.j - v.j*v1.i;
	printf("\nEl producto escalar de los vectores (%.2f %.2f %.2f) x (%.2f %.2f %.2f) =(%.2f %.2f %.2f)", v.i, v.j, v.k, v1.i, v1.j, v1.k, a, b, c);
}
