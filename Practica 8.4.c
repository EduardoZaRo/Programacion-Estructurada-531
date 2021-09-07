#include<stdio.h>
#define MAX 50

void minus(char[]);
void eliminar_espacios(char[], char[]);
void opc_1(char[], int*, int*, int*);
int main(void)
{
	//Declaracion de variables
	char oracion[MAX] = {0}, oracion_sin_espacios[MAX] = {0};
	int opc;
	
	
	printf("\nIngresa una oracion: ");
	gets(oracion);

	printf("\n---------MENU DE OPCIONES-----------");
	printf("\n1. Saber la cantidad de vocales, consonantes y digitos de la oracion");
	printf("\n2. Eliminar los espacios\n");
	scanf("\n%d",&opc);
	if(opc == 1){
		minus(&oracion);//Se convierte la oracion en minusculas
		eliminar_espacios(&oracion, &oracion_sin_espacios);//Se eliminan los espacios
		
		//Declaracion variables
		int vocales = 0, consonantes = strlen(oracion_sin_espacios), digitos = 0;//Se considera toda la oracion como consonantes y se le van a restar las vocales y los digitos
		opc_1(&oracion_sin_espacios, &vocales, &consonantes, &digitos);//Llamada de la funcion para calcular lo buscado
		printf("\nLa oracion tiene %d consonantes, %d vocales y %d digitos :)", consonantes, vocales, digitos);//Salida de resultados
	}else{
		if(opc == 2){
		    eliminar_espacios(&oracion, &oracion_sin_espacios);//Se eliminan espacios
		    puts(oracion_sin_espacios);	//Se imprime el resultado	
		}	
		else{
			printf("\nOpcion no valida");//Si es una opcion diferente de 1 o 2 no es valido
		}	
	}
	return 0;
}

void eliminar_espacios(char* oracion, char* oracion_sin_espacios){
	while(*oracion){
		if(*oracion != ' '){//Si el puntero es dirente de espacio se copia en otro array
			*oracion_sin_espacios = *oracion;
			*oracion_sin_espacios++;
		}
		oracion++;
	}
}

void minus(char* oracion){
    while(*oracion){
        *oracion = *oracion>='A'&&*oracion<='Z'? *oracion+32:*oracion;//Si el puntaro es mayuscula se convierte a minuscula
        oracion++; 
    }
}

void opc_1(char* oracion,  int* vocales, int* consonantes, int* digitos){
	
	while(*oracion){
	
		if(*oracion == 'a' || *oracion == 'e' ||*oracion == 'i'|| *oracion == 'o'|| *oracion == 'u'){//Si el puntero es igual a una vocal se le suma 1 al puntero vocal y se resta uno al puntero consonantes
			++*vocales;
			--*consonantes;				
		}else{
			if(*oracion == '1' || *oracion == '2' || *oracion == '3'|| *oracion == '4' || *oracion == '5' || *oracion == '6'|| *oracion == '7'|| *oracion == '8'|| *oracion == '9'){//Si el puntero es un numero se le suma 1 al puntero digitos y se resta 1 a consonantes
				++*digitos;
				--*consonantes;				
			}
		}
		oracion++;
	}
}
