/* Zavala Irvin Matricula:01270771
Programa que incremente un segundo a un horario dado*/
#include<stdio.h>

int main(void){
	int horas, minutos, segundos; //Declaracion variables
	
	printf("Programa que le suma un segundo a la hora del dia que introduzcas");//Descripcion de programa al usuario
	
	//Entrada de datos
	printf("\nIntroduzca las horas: ");
	scanf("%d",&horas);
	printf("\nIntroduzca minutos: ");
	scanf("%d",&minutos);
	printf("\nIntroduzca segundos: ");
	scanf("%d",&segundos);
	
	if (horas >= 0 && horas <= 23 && minutos >= 0 && minutos <= 59 && segundos >= 0 && segundos <= 59){//Si no se cumples todas las condiciones la hora no es valida
		
		segundos += 1;//Le sumo un segundo a la hora
		
		if (segundos == 60){//Si llega a 60 segundos se reinicia y se incrementa un minuto
			segundos = 0;
			
			minutos += 1;
			if (minutos == 60){//Si llega a 60 minutos se reinicia y se incrementa una hora
				minutos = 0;
				
				horas +=1;
				if (horas == 24){//Si llega a 24 horas se reinicia a 0
					horas = 0;
				}
			}
		}
		printf("\nUn segundos despues de la hora que introduciste es: %d:%d:%d",horas, minutos, segundos);//Salida de la hora con el segundo incrementado
	}
	else {
		printf("Esa hora no es valida ://");//Si una condicion no se cumplio del primer if aparecera este mensaje
	}
	return 0;
}
