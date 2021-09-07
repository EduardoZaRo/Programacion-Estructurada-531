/* Zavala Irvin Matricula:01270771
Programa para convertir grados centigrados a farenheit*/
#include <stdio.h>

/*funcion principal*/
int main(void)
{
    float centigrados, farenheit;

    printf("\tPrograma para convertir grados Centigrados a Farenheit");
    printf("\n\nIntroduzca los grados centigrados: ");

    //funcion de captura
    scanf("%f", &centigrados);

    // F=5/9 * C + 32
    farenheit = 1.8*centigrados + 32;

    //funcion de salida
    printf(" %f grados centigrados equivale a %f farenheit", centigrados, farenheit);

    return 0;
}
