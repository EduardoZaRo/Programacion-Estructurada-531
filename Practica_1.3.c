/* Zavala Irvin Matricula:01270771
Programa para convertir dias,horas,minutos y segundos a solo segundos*/
#include <stdio.h>

/*funcion principal*/
int main(void)
{
    int dias, dias_seg, horas, horas_seg, minutos, minutos_seg, segundos, segundos_totales;

    printf("\tPrograma para convertir dias,horas,minutos y segundos a solo segundos");
    printf("\n\nIntroduzca los dias: ");
    //funcion de captura dias
    scanf("%d", &dias);
    printf("\n\nIntroduzca las horas: ");
    //funcion de captura horas
    scanf("%d", &horas);
    printf("\n\nIntroduzca los minutos: ");
    //funcion de captura minutos 
    scanf("%d", &minutos);
    printf("\n\nIntroduzca los segundos: ");
    //funcion de captura segundos
    scanf("%d", &segundos);
    
    //Dias a segundos
	dias_seg = dias * 86400;
	
    // Horas a segundos
    horas_seg = horas * 3600;
    
    //Minutos a segundos
    minutos_seg = minutos * 60;
    
    //Segundos quedan igual, se suman todos
    segundos_totales = dias_seg + horas_seg + minutos_seg + segundos;
    

    //funcion de salida
    printf(" %d dias, %d horas, %d minutos y %d segundos equivale a %d segundos", dias, horas, minutos, segundos, segundos_totales);

    return 0;
}
