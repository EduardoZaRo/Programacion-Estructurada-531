/*
Zavala Irvin Matricula:01270771
Polinomios
*/
#include<stdio.h>
#include<math.h>

int coef_grado(int coef[], int grado);
int modificar(int coef[], int grado);
int imprimir(int[], int);
int evaluar(int coef[], int grado);





int main(void)
{
	int grado, i, opc, coef[grado];





	do{
		printf("\nInserte el grado del polinomio (de 1 a 5): ");
		scanf("%d", &grado);
		if(grado >= 1 && grado <= 5){
			coef_grado(coef, grado);
			break;
		}
		else{
			printf("\nEse grado no es valido :/");
		}
	}while(grado >= 1 || grado <= 5);
	

	
	
	printf("\nMenu de opciones: ");
	printf("\n\t 1. Modificar polinomio.");
	printf("\n\t 2. Imprimir el polinomio");
	printf("\n\t 3. Evaluar el polinomio con el numero que quieras.");
	printf("\n\t 4. Salir.\n");



	do{//Meto el switch en un do while para que se repita varias veces hasta que quiera salir el usuario
		printf("\nIntroduce una opcion: ");
		scanf("%d", &opc);
		switch(opc){
			
			case 1: main(); break;//Si quiere meter otros grados o coeficientes lo manda al main(), no se que tan correcto sea esto
			case 2: imprimir(coef,grado) ; break;
			case 3: evaluar(coef, grado); break;
			case 4: printf("\nHasta pronto :D"); break;
			default: printf("\nEsa opcion no es valida");
			
		}		
	}while(opc != 4);

    return 0;
}

int coef_grado(int coef[], int grado){//Sabiendo el grado podemos pedir la cantidad de coeficientes necesaria (grado+1)
	int i;	
	grado += 1;	
	for(i = 0; i < grado; i++){
		printf("\nIngrese el valor del coeficiente %d: ", i);
		scanf("%d", &coef[i]);		
	}		
	return 0;
}

int imprimir(int coef[], int grado){//Sabiendo los coeficientes y el grado podemos imprimir el polinomio que quiere el usuario
	int i;
	for(i = grado ; i >= 0; i--){
		printf("%d*x^(%d)", coef[i], i);
		if( i > 0){
			printf("+");
		}
	} 	


	return 0;
}

int evaluar(int coef[], int grado){//Se pide un numero y con un for y los coeficientes puedo simular la evaluacion en el polinomio
	int f, i, aux, suma;
	suma = 0;
	printf("\nInserta el numero que quieres evaluar en la ecuacion: ");
	scanf("%d", &f);
	printf("\n");
	for(i = 0; i < (grado + 1); i++){
		aux = (coef[i])*(pow(f, i));
		printf("%d*(%d)^(%d)", coef[i], f, i);
		suma += aux;
		if(i < grado){
			printf("+");
		}
		else{
			break;
		}
	}
	printf("\nEl resultado es: %d", suma);
	return suma;
}






