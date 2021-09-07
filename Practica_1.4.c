/* Zavala Irvin Matricula:01270771
Programa para saber cuanto antibiotico darle a tu perro sin que se muera*/
#include <stdio.h>

/*funcion principal*/
int main(void)
{
    float peso, antibiotico;

    printf("\tPrograma para saber cuantos mm de antibiotico darle a tu dog");
    printf("\n\nIntroduzca el peso de su perro en kg: ");

    //funcion de captura
    scanf("%f", &peso);

    // antibiotico 
    antibiotico = peso * 12.5;

    //funcion de salida
    printf("Para %f kilogramos se debe dar %f mm de antibiotico", peso, antibiotico);

    return 0;
}
