/*
Zavala Irvin Matricula:01270771
Ejercicios 3
*/

#include<stdio.h>

#define MAXIMO 20


int tres_a(char [], int);
int tres_b(char [], int);
int tres_c(char [], int);
int tres_d(char [], int);
int tres_e(char [], int);

int main(void)
{
	int MAX = MAXIMO, opc;
	char oracion[MAX];
	
	printf("Introduce una oracion: ");
	gets(oracion);
	

	printf("\n\tMenu de opciones: ");
	printf("\n1. Saber cuantas vocales, consonantes y digitos tiene una cadena");
	printf("\n2. Eliminar espacios en blanco de la cadena");
	printf("\n3. Determinar si la oracion es palindromo.");
	printf("\n4. Convertir las minusculas en mayusculas de tu oracion");
	printf("\n5. Convertir mayusculas en minusculas de tu oracion");
	printf("\n6. Salir\n");

	do{
		printf("\nIntroduce una opcion: ");
		scanf("%d", &opc);
		switch(opc){
			
			case 1: tres_a(oracion, MAX); break;
			case 2: tres_b(oracion, MAX); break;
			case 3: tres_c(oracion, MAX); break;
			case 4: tres_d(oracion, MAX); break;
			case 5: tres_e(oracion, MAX); break;
			case 6: printf("\nNos vemos :)"); break;
			default: printf("Opcion no valida :/");
		}
			
	}while(opc != 6);

    return 0;
}

int tres_a(char oracion[], int MAX){//Funcion para saber vocales, consonantes y digitos de la oracion

	//Mi idea fue tomar toda la oracion como consonante e irle restanto las vocales, espacios y digitos
	int vocales = 0, consonantes = strlen(oracion), digitos = 0;
	int i;

	for(i = 0; oracion[i]!='\x0'; i++){

		if( oracion[i] == 'A' || oracion[i] =='a' ||oracion[i] == 'E' || oracion[i] =='e'||oracion[i] == 'I' || oracion[i] == 'i'||oracion[i] == 'O' || oracion[i] =='o'||oracion[i] == 'U' || oracion[i] =='u' ){
			vocales++;
			consonantes--;

		}
		if(oracion[i] == ' '){
			consonantes--;
		}
		if(oracion[i] == '0' || oracion[i] == '1' || oracion[i] == '2' || oracion[i] == '3'|| oracion[i] == '4' || oracion[i] == '5'|| oracion[i] == '6'|| oracion[i] == '7'|| oracion[i] == '8' || oracion[i] == '9'){
			digitos++;
			consonantes--;
		}

	}

	printf("\nTu oracion tiene %d vocales, %d consonantes y %d digitos", vocales, consonantes, digitos);
	
	return 0;
}

int tres_b(char oracion[], int MAX){//Funcion para quitar espacios
    int i, j = 0;
    char oracion_s_e[MAX];

	for(i = 0; oracion[i] != '\x0'; i++){//Sigue el bucle mientras i no sea el caracter nulo
		if(oracion[i] != ' '){//Mientras i no sea un espacio lo escribo en otro array
			oracion_s_e[j] = oracion[i];
			j++;
		}
	}
	//El metodo de recorrer el array al detectar un espacio no me funciono muy bien :/

	printf("\nTu oracion sin espacios queda %s", oracion_s_e);
	return 0;
}

int tres_c(char oracion[], int MAX){//Funcion para saber si la oracion es palindroma
	int i = 0, j = 0;
	char new_oracion[MAX], oracion_sin_espacios[MAX];


    for(i = 0; i < strlen(oracion); i++){//Primero hago minuscula la oracion
        if(oracion[i] != ' '){
            if(oracion[i] >= 'A' && oracion[i] <= 'Z'){
                oracion[i] += 32;
            }
            else{
                oracion[i];
            }            
        }
    }

	for(i = 0; oracion[i]!='\x0'; i++){//Luego le quito los espacios
		if(oracion[i]!=' '){
			oracion_sin_espacios[j] = oracion[i];
			j++;
		}
	}
	
	int aux, lar = strlen(oracion_sin_espacios);
	j = lar - 1;
	i = 0;
	
	while( (i < j) && (oracion_sin_espacios[i] == oracion_sin_espacios[j])){//Comienzo a comparar el array desde los extremos al centro
		i++;
		j--;
	}
	if(i >= j){
		printf("\nEs palindroma");
	}
	else{
		printf("\nNo es palindroma");
	}
	return 0;
}

int tres_d(char oracion[], int MAX){//Funcion para convertir a mayusculas
    int i;
    
	for(i = 0; i < strlen(oracion); i++){//Recorro el array de inicio al ultimo caracter
        if(oracion[i] != ' '){//Mientras no sea un espacio checo si i es minuscula y si lo es lo hago mayuscula
            if(oracion[i] >= 'a' && oracion[i] <= 'z'){
                oracion[i] -= 32;
            }
            else{
                oracion[i];//Sino queda igual
            }            
        }
    }
	printf("\nLa oracion con minusculas en mayusculas queda: %s", oracion);
	return 0;
}

int tres_e(char oracion[], int MAX){//Funcion para convertir a minusculas
	int i;
	
    for(i = 0; i < strlen(oracion); i++){//Hago lo mismo que el anterior pero comparo i si es mayuscula y si es lo hago minuscula
        if(oracion[i] != ' '){
            if(oracion[i] >= 'A' && oracion[i] <= 'Z'){
                oracion[i] += 32;
            }
            else{
                oracion[i];
            }            
        }
    }
    

	printf("\nLa oracion con mayusculas en minusculas queda: %s", oracion);
	return 0;
}


