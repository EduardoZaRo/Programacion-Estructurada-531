/*Zavala Roman Irvin Eduardo 01270771
Practica 11  Ejercicio 1*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int c, i = 1;
	FILE* oracion;
	oracion = fopen("more.txt" , "r" );	
	if (oracion) {
	    while ((c = getc(oracion)) != EOF){
			if(c == '\n'){//Por cada salto de linea cuento una linea
				i++;
		    	if(i == 15){//Si son 15 saltos de linea me detengo
		    		char opc;
		    		printf("\nDesea continuar?: ");
		    		scanf(" %c", &opc);
					if(opc == 'N' || opc == 'n'){
						break;
					}	
				}
				if(i == 25){//Imprimo las siguientes 10
					break;
				}
			}

			putchar(c);
		}
		
  
	    fclose(oracion);
	}
    return 0;
}


