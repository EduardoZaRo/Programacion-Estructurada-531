/*Zavala Roman Irvin Eduardo 01270771
Practica 11  Ejercicio 2*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char** argv){
    int c, i;
	FILE* oracion;
	oracion = fopen(argv[2] , "r" );
		
	if(argc <= 1 || argc > 3){
		printf("\nError en la cantidad de parametros :/");
		return 0;
	}
	
	//Comparo el 2do parametro con las opciones
	if(strcmp(argv[1], "-l") == 0){
		i = 1;
		if (oracion) {
		    while ((c = getc(oracion)) != EOF){//Voy caracter por caracter y si hay un '\n' cuanto una linea
		    	if(c == '\n')
					i++;
			}
			
		    printf("\nEl archivo tiene %d lineas", i);   
		    fclose(oracion);
		}		
	}
	else{
		if(strcmp(argv[1], "-c") == 0){
			i = 0;
			if (oracion) {
			    while ((c = getc(oracion)) != EOF){//Voy caracter por caracter y los cuento
						i++;
				}
			    printf("\nEl archivo tiene %d caracteres", i);   
			    fclose(oracion);
			}		
		}
		else{
			char palabras[20];
			if(strcmp(argv[1], "-w") == 0){
				i = 0;
				if (oracion) {
					while ((fscanf(oracion, "%19s", palabras)) != EOF){//Abro cada numero real del archivo
					printf("[%s]", palabras);
						i++;
					}
				    printf("\nEl archivo tiene %d palabras", i);   
				    fclose(oracion);
				}		
			}	
			else{//Sino es ninguna de las opciones imprimo error
				printf("\n\tError :(");
				return 0;
			}		
		}			
	}

    return 0;
}
