/*
Zavala Irvin Matricula:01270771
Angramas EXTRA
*/
#include <stdio.h>
#define MAX 50

int anagrama(char [], char [], int);

int main(void){
    int tam = MAX, ana;
    char cadena_1[tam], cadena_2[tam];

    printf("\nIngresa una oracion: ");
    gets(cadena_1);
    printf("\nIngresa otra oracion: ");
    gets(cadena_2);
	

	ana = anagrama(cadena_1, cadena_2, tam);//Llamo la funcion para saber si los arrays son anagramas
	if(ana){
		printf("\nNo son anagramas");
	}
	else{
		printf("\nSon anagramas");
	}



    return 0;
}

int anagrama(char cadena_1[], char cadena_2[], int tam){ 
	int  coincidencias = 0;
	int i, j;

	

	//Convierto las 2 oraciones a minusculas
    for(i = 0; i < strlen(cadena_1); i++){
        if(cadena_1[i] != ' '){
            if(cadena_1[i] >= 'A' && cadena_1[i] <= 'Z'){
                cadena_1[i] += 32;
            }
            else{
                cadena_1[i];
            }            
        }
    }
    for(i = 0; i < strlen(cadena_2); i++){
        if(cadena_2[i] != ' '){
            if(cadena_2[i] >= 'A' && cadena_2[i] <= 'Z'){
                cadena_2[i] += 32;
            }
            else{
                cadena_2[i];
            }            
        }
    }
    
    //Le quito los espacios a las oraciones
	char cadena_1_s[tam], cadena_2_s[tam];
	for(i = 0; cadena_1[i]!='\0'; i++){
		if(cadena_1[i]!=' '){
			cadena_1_s[j] = cadena_1[i];j++;
		}
	}
    j = 0;
	for(i = 0; cadena_2[i]!='\0'; i++){
		if(cadena_2[i]!=' '){
			cadena_2_s[j] = cadena_2[i];j++;
		}
	}


	//A este punto tengo las 2 oraciones en minusculas y sin espacios

	if (strlen(cadena_1_s) != strlen (cadena_2_s))//Si no son del mismo tamano no puede ser anagrama
		return 1;	  

	//Si las oraciones son del mismo tamano busco las letras que coincidan en las 2 oraciones  
	for (i = 0; i < strlen(cadena_1_s); i++){
		for(j = 0; j < strlen(cadena_2_s); j++){
			if (cadena_1_s[i] == cadena_2_s[j]){
				cadena_2_s[j] = '*';//Con esto marco letras que coinciden
				coincidencias++; 
				printf("\n%s", cadena_2_s);
				break;//Si una letra de la primera coincide con una de la segunda me salgo porque si hay mas se eliminarias todas
			}	
		}
	}
	//Si las coincidiencias es del tamano de las oraciones entonces todas las letras coinciden y por lo tanto es anagrama
	if (coincidencias == strlen(cadena_2_s))
	    return 0;
	else
	    return 1;		
}
