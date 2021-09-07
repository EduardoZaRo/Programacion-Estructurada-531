/* Zavala Irvin Matricula:01270771
Programa para convertir unidades de pulgadas a mm*/
#include <stdio.h>

/*funcion principal*/
int main(void)
{
    float pulgadas, milimetros;

    printf("\tPrograma para convertir cantidad de lluvia de pulgadas a milimetros");
    printf("\n\nIntroduzca la cantidad de lluvia de este anio en pulgadas: ");

    //funcion de captura
    scanf("%f", &pulgadas);

    // 1m = 1.09361
    milimetros=pulgadas * 25.4;

    //funcion de salida
    printf("La cantidad de %f pulgadas equivale a %f milimetros", pulgadas, milimetros);

    return 0;
}
