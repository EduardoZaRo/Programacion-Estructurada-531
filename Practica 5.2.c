/* Zavala Irvin Matricula:01270771
Programa que calcula diferencia entre horas*/
#include<stdio.h>
#include<math.h>

float dif_horas(float horas_1, float minutos_1, float segundos_1, float horas_2, float minutos_2, float segundos_2 );
float dif_minutos(float horas_1, float minutos_1, float segundos_1, float horas_2, float minutos_2, float segundos_2 );
float dif_segundos(float horas_1, float minutos_1, float segundos_1, float horas_2, float minutos_2, float segundos_2 );

int main(void){
	//Declaracion variables
	float horas_1, minutos_1, segundos_1, horas_2, minutos_2, segundos_2;
	char opc;
	
	//Introduccion de datos
	printf("Programa que calcula los segundos entre 2 horas dadas.");	
	printf("\nIngrese la primera hora (HH,MM,SS) :  ");
	scanf("%f, %f, %f", &horas_1, &minutos_1, &segundos_1);
	printf("\nIngrese la segunda hora (HH,MM,SS) : ");
	scanf("%f, %f, %f", &horas_2, &minutos_2, &segundos_2);
	
	printf("\nSelecciona el formato de salida: ");
	printf("\n\tH : Horas       M : Minutos      S : Segundos\n");
	scanf("\n%c", &opc);
	
	//Se verifica que las horas sean validas
	if ( horas_1 >= 0 && horas_1 < 24 && horas_2 >= 0 && horas_2 < 24 && minutos_1 >= 0 && minutos_1 <60 && minutos_2 >= 0 && minutos_2 < 60 && segundos_1 >= 0 && segundos_1 < 60 && segundos_2 >= 0 && segundos_2 < 60 ){
		if (opc == 'H'){
			dif_horas(horas_1, minutos_1, segundos_1, horas_2, minutos_2, segundos_2);	//Se llama a la funcion para saber la diferencia en horas
		}
		else{
			if(opc == 'M'){
				dif_minutos(horas_1, minutos_1, segundos_1, horas_2, minutos_2, segundos_2);//Se llama a la funcion para saber la diferencia en minutos
			}
			else{
				if(opc == 'S'){
					dif_segundos(horas_1, minutos_1, segundos_1, horas_2, minutos_2, segundos_2);//Se llama a la funcion para saber la diferencia en segundos
				}
			}
		}
	}
	else{ 
		printf("\nLa hora no es valida :/");
	}

	
	
	return 0;
}

float dif_horas(float horas_1, float minutos_1, float segundos_1, float horas_2, float minutos_2, float segundos_2 ){
	float dif_h;
	dif_h = fabs((horas_1 + minutos_1/60 + segundos_1/3600) - (horas_2 + minutos_2/60 + segundos_2/3600));//Diferencia en horas
	printf("\nLa diferencia entre las 2 horas es de %.3f horas.", dif_h);
	return dif_h;
}

float dif_minutos(float horas_1, float minutos_1, float segundos_1, float horas_2, float minutos_2, float segundos_2 ){
	float dif_m;
	dif_m = fabs((horas_1*60 + minutos_1 + segundos_1/60) - (horas_2*60 + minutos_2 + segundos_2/60));//Diferencia en minutos
	printf("\nLa diferencia entre las 2 horas es de %.3f minutos.", dif_m);
	return dif_m;
}

float dif_segundos(float horas_1, float minutos_1, float segundos_1, float horas_2, float minutos_2, float segundos_2 ){
	float dif_s;
	dif_s = fabs((horas_1*3600 + minutos_1*60 + segundos_1) - (horas_2*3600 + minutos_2*60 + segundos_2));//Diferencia en segundos
	printf("\nLa diferencia entre las 2 horas es de %.3f segundos.", dif_s);
	return dif_s;
}




