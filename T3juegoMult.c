/*Taller 3
Juego de multiplicar.

Completar los siguientes requerimientos:
1. Solicitar al usuario el número de preguntas
2. Al finalizar el juego, se debe mostrar:
    2.1 Número de aciertos y porcentaje (50% 2/4)
    2.2 Total de tiempo que tardó en contestar
    2.3 Mostrar puntos
Ejemplo:

    ***** Resultado *****
    Aciertos: 2/4 (50%)
    Tiempo total: 4s
    Puntos: 4000
*/

/*Zavala Roman Irvin Eduardo
1270771 Jueguito*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//Prototipos de funciones
float points( int, float);
int facil(int*, int* );
int medio(int*, int* );
int alto(int*, int* );
double tiempo_maximo(double , double , double*, double*);

int main(void)
{
	//Declaracion variables
	float porcentaje, aciertos = 0, total;
    time_t inicio, fin;
    int a, b, respuesta = 0,preguntas, puntos = 0, dificultad, *a1, *b1;
    double tiempo_transcurrido = 0, old_tiempo = 0, tiempo_final = 0, tiempo_max = 0, tiempo_min = 100;

    srand(time(NULL));//Para los numeros aleatorios
	
	//Entrada de datos
	printf("\nCuantas operaciones quieres realizar?: ");
	scanf("\n%d", &preguntas);
	printf("\nCual dificultad quieres escoger?: ");
	printf("\n\t1. Facil");
	printf("\n\t2. Medio");
	printf("\n\t3. Alto\n");
	scanf("%d", &dificultad);
	total = preguntas;

    do
    {
    	//Cambio entre dificultades
		switch(dificultad){
			case 1: facil(&a, &b); break;
			case 2: medio(&a, &b); break;
			case 3: alto(&a, &b); break;
			default: printf("\nOpcion no valida :/"); break;
		}

        printf("\n%d X %d = ", a, b);//Se imprime la multiplicacion

        time(&inicio);//Inicio del tiempo de respuesta
        scanf("%d", &respuesta);//Entrada de la respuesta
        time(&fin);//Fin del tiempo
		
        if (respuesta == a * b){//Si es correcto imprimimos correcto, sumamos 1 a aciertos
            printf("\tCorrecto! (");
            aciertos++;  
			respuesta = 1; //Devuelve 1 si es correcto  	
		}

        else{
            printf("\tIncorrecto (");   //Imprime si es incorrecto y devuelve 0  
			respuesta = 0; 	
		}
		
		
		old_tiempo = tiempo_transcurrido;//Le voy el valor del tiempo de la iteracion pasada
        tiempo_transcurrido = difftime(fin, inicio);//Se calcula la diferencia de tiempo en una respuesta
        
        printf("%.1f s)\n", tiempo_transcurrido);//Se imprime el tiempo
        
		tiempo_final += tiempo_transcurrido;//Se acumula el tiempo en otra variable para mostrarlo al final

		tiempo_maximo(old_tiempo, tiempo_transcurrido, &tiempo_max, &tiempo_min);//LLamada a la funcion que cambia los tiempos maximos y minimos para responder
		


		puntos = puntos + points(respuesta, tiempo_transcurrido);//Funcion para el calculo de puntos
		printf("\nScore: %d", puntos);
		
    } while (--preguntas > 0);
    
	porcentaje = (aciertos/total)*100;//Se calcula el porcentaje de acierto
	
	//Salida de resultados
	printf("\n\t*******Resultado*******");
	printf("\n\tAcertaste %.0f , sacaste %.2f /100", aciertos, porcentaje);
	printf("\n\tTardaste %.2f segundos", tiempo_final);
	printf("\n\tPuntos: %d", puntos);
	printf("\n\tEl tiempo maximo en contestar una pregunta fue: %.0f", tiempo_max);
	printf("\n\tEl tiempo minimo en contestar una pregunta fue: %.0f", tiempo_min);
    return 0;
}

float points( int respuesta, float tiempo_transcurrido){
	int puntos;
	if(respuesta == 1){
		if(tiempo_transcurrido >= 8){//Si le atina pero tardo mas de 8 segundos no cambia
			puntos = puntos;
		}
		else{
			puntos = 1000;//Si le atina en menos de 2 segundos se le dan 1000 puntos
			if(tiempo_transcurrido >= 2 && tiempo_transcurrido <= 3){
				tiempo_transcurrido -= 2;
				puntos = puntos - tiempo_transcurrido*50;//Si le atina entre 2 y 3 segundos le quitamos 50 puntos por cada seg
			}
			if(tiempo_transcurrido >= 4 && tiempo_transcurrido <= 8){
				tiempo_transcurrido -= 4;//Si le atina entre 4 y 8 seg le quitamos 100 puntos por cada seg
				puntos = puntos - tiempo_transcurrido*100;
			}
		}
		
	}


	if(respuesta == 0){
		puntos = puntos - 100;//Si no le atina se restan 100 puntos y se penalizan por los segundos tambien
		if(tiempo_transcurrido >= 2 && tiempo_transcurrido <= 3){
			tiempo_transcurrido -= 2;
			puntos = puntos - tiempo_transcurrido*50;
		}
		if(tiempo_transcurrido >= 4 && tiempo_transcurrido <= 8){
			tiempo_transcurrido -= 4;
			puntos = puntos - tiempo_transcurrido*100;
		}
	}
	return puntos;
}
//Niveles
int facil(int* a1, int* b1){
	*a1 = 1+rand()%10;
	*b1 = 1+rand()%10;
}
int medio(int* a1, int* b1){
	*a1 = 2+rand()%13;
	*b1 = 2+rand()%13;
}
int alto(int* a1, int* b1){
	*a1 = 6+rand()%20;
	*b1 = 6+rand()%20;
}

//Calculo del tiempo maximo y minimo
double tiempo_maximo(double time_old, double time_transcurrido, double* tiempo_maximo, double* tiempo_minimo){
	*tiempo_maximo = time_transcurrido > *tiempo_maximo ? time_transcurrido : *tiempo_maximo;
	*tiempo_minimo = *tiempo_minimo < time_transcurrido ? *tiempo_minimo : time_transcurrido;
}


