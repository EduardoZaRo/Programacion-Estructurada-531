/*Zavala Roman Irvin Eduardo 01270771
Practica 11  Mayusculas a minusculas y viceversa*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//Prototipos
void minus(char* c);
void mayus(char* c);


int main(int argc, char** argv){
    int c, i = 1;
	FILE* oracion;
	FILE* min;
	FILE* may;
	oracion = fopen(argv[2], "r" );	//Abro el archivo que tenga nombre como el tercer argumento ingresado
	
	if(argc <= 1 || argc >= 5){//Este if sirve para checar la cantidad de parametros
		printf("\nError en los parametros");
		return 0;
	}
	//Si tiene 4 parametros es porque quiere guardar el resultado en el archivo con nombre del ultimo parametro
	if((argc == 4) &&  (strcmp(argv[1], "minus" ) == 0)){
		min = fopen(argv[3], "w");
	}
	if((argc == 4) &&  (strcmp(argv[1], "mayus" ) == 0)){
		may = fopen(argv[3], "w");
	}
	
	
	//Comparo el segundo argumento con minus o mayus para saber como convertir
	if(strcmp(argv[1], "minus" ) == 0){
		printf("\nEl texto en el archivo %s en minusculas queda:\n", argv[2]);
		if (oracion){
		    while ((c = getc(oracion)) != EOF){//Paso letra por letra y hago la conversion con funcion
		    	minus(&c);
				putchar(c);
				if(argc == 4){
					fputc(c, min);
				}
				
			}
		    fclose(oracion);
		}		
	}
	else{
		if(strcmp(argv[1], "mayus" ) == 0){
			printf("\nEl texto en el archivo %s en mayusculas queda:\n", argv[2]);
			if (oracion){
			    while ((c = getc(oracion)) != EOF){//Paso letra por letra y hago la conversion con funcion
			    	mayus(&c);
					putchar(c);
					if(argc == 4){
						fputc(c, may);
					}
				
				}
			    fclose(oracion);
			}		
		}	
		else{
			printf("\n\tError");

		}	
		
	}


    return 0;
}


void minus(char* c){//Funcion para convertir a minusculas
    *c = *c>='A'&&*c<='Z'? *c+32:*c;

}

void mayus(char* c){//Funcion para convertir a mayusculas
    *c = *c>='a'&&*c<='z'? *c-32:*c;

}

