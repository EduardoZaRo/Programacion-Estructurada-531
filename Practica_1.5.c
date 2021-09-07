/* Zavala Irvin Matricula:01270771
Programa para calcular perimetro y area de un terreno*/
#include <stdio.h>

/*funcion principal*/
int main(void)
{
    float ancho, largo, perimetro, area;

    printf("\tPrograma para calcular perimetro y area de un terreno cuyo ancho es 3 veces mayor que el largo");
    printf("\n\nIntroduzca ancho del terreno en metros: ");

    //funcion de captura
    scanf("%f", &ancho);

    // perimetro
    perimetro = 2*(ancho/3) + 2*(ancho);
    
    //area
    area = (ancho/3)*(ancho);

    //funcion de salida
    printf("Para una ancho de %f se tiene un area de %.3f y un perimetro de %.3f", ancho, area, perimetro);
	

    return 0;
}
