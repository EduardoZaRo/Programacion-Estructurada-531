/*Zavala Roman Irvin Eduardo 1270771
Practica 10 Ejercicio 2*/

#include<stdio.h>
#include<math.h>
//Estructura
struct racional{
    float num;
    float den;
};

//Prototipos
struct racional captura();
void mostrar(struct racional);
void suma(struct racional, struct racional);
void resta(struct racional, struct racional);
void multiplicacion(struct racional, struct racional);
void division(struct racional, struct racional);

int main(void){
	int opc;
	//Se imprimen las opciones al usuario
	printf("\nMenu de opciones: ");
	printf("\n1. Imprimir un numero racional.");
	printf("\n2. Suma de numeros racionales.");
	printf("\n3. Resta de numeros racionales.");
	printf("\n4. Multiplicacion de numeros racionales.");
	printf("\n5. Division numeros racionales.\n");
	scanf("%d", &opc);

	//Entrada de 2 numeros racionales
	struct racional r1 = captura();
	struct racional r2 = captura();
	
	//Se llaman las opciones respecto a la opcion
	switch(opc){
		case 1: ;
			mostrar(r1);
			mostrar(r2);
			break;	
		case 2: ;	
			suma(r1, r2);		
			break;
		case 3: ;
			resta(r1, r2);				
			break;
		case 4: ;
			multiplicacion(r1, r2);				
			break;
		case 5: ;
			division(r1, r2);			
			break;
	}


    return 0;
}

struct racional captura(){//Captura numeros racionales
    struct racional c;
    printf("Ingrese numero racional (ej 1/2): ");
    scanf("%f/%f", &c.num, &c.den);
    return c;
}

void mostrar(struct racional r){//Muestra numeros racionales
    printf("Numero racional: %.1f / %.1f ", r.num, r.den);
}

void suma(struct racional r, struct racional r1){//Suma numeros racionales
	float a, b, c;
	a = r.den*r1.den;
	b = r.num * r1.den;
	c = r.den * r1.num;
	printf("\nLa suma %.2f/%.2f + %.2f/%.2f = %f", r.num, r.den, r1.num, r1.den, (b+c)/a);
}

void resta(struct racional r, struct racional r1){//Resta numeros racionales
	float a, b, c;
	a = r.den*r1.den;
	b = r.num * r1.den;
	c = r.den * r1.num;
	printf("\nLa resta  %.2f/%.2f - %.2f/%.2f = %f", r.num, r.den, r1.num, r1.den, (b-c)/a);
}

void multiplicacion(struct racional r, struct racional r1){//Multiplica numeros racionales
	float a, b;
	a = r.num*r1.num;
	b = r.den * r1.den;
	printf("\nLa multiplicacion  %.2f/%.2f * %.2f/%.2f = %f", r.num, r.den, r1.num, r1.den, a/b);
}

void division(struct racional r, struct racional r1){//Dvidide numeros racionales
	float a, b;
	a = r.num*r1.den;
	b = r.den * r1.num;
	printf("\nLa division (%.2f/%.2f)/(%.2f/%.2f) = %f", r.num, r.den, r1.num, r1.den, a/b);
}
