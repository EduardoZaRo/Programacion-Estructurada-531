/* Zavala Irvin Matricula:01270771
Programa para registrar pacientes en un hospital*/
#include <stdio.h>

/*funcion principal*/
int main(void)
{	
	//Declaracion de variables en las que se introduciran cadenas
	char nombre[20], apellido_materno[20], apellido_paterno[20], tipo_sangre[5],genero[2]; 
	
	//Declaracion de variables en la que se introduciran numeros enteros
    int peso, dia_nacimiento, mes_nacimiento, year_nacimiento;
    
    //Declaracion de variables numeros flotantes
    float estatura;

    printf("\tBienvenido al registro de pacientes del Hospital");


    //funcion de captura nombre
    printf("\nIntroduzca el primer nombre: ");
    scanf("%s",nombre);

    //funcion de captura apellido paterno
    printf("\nIntroduzca el apellido paterno: ");
    scanf("%s",apellido_paterno);
    
    //funcion de captura apellido materno
    printf("\nIntroduzca el apellido materno: ");
    scanf("%s", apellido_materno);

    //funcion de captura peso
    printf("\nIntroduzca el peso en kg: ");
    scanf("%d", &peso);
    
    //funcion de captura estatura
    printf("\nIntroduzca la estatura en m: ");
    scanf("%f", &estatura);

    //funcion de captura tipo de sangre
    printf("\nIntroduzca el tipo de sangre: ");
    scanf("%s",tipo_sangre);
	    
    //funcion de captura genero
    printf("\nIntroduzca el genero ('M' o 'F'): ");
    scanf("%s",genero);
    
    //funcion de captura dia de nacimiento
    printf("\nIntroduzca el dia de nacimiento: ");
    scanf("%d", &dia_nacimiento);    
    
     //funcion de captura mes de nacimiento
    printf("\nIntroduzca el mes de nacimiento: ");
    scanf("%d", &mes_nacimiento);  
	
    //funcion de captura año de nacimiento
    printf("\nIntroduzca el anio de nacimiento: ");
    scanf("%d", &year_nacimiento);  	   
    
    //funcion de salida
    printf("\n *****DATOS DEL PACIENTE*****");
    printf("\n*Nombre completo: %s %s %s ",nombre, apellido_paterno, apellido_materno);
    printf("\n*Peso: %d kg", peso);
    printf("\n*Estatura: %f metros", estatura);
    printf("\n*Tipo de sangre: %s",tipo_sangre);
	printf("\n*Genero: %s", genero);
	printf("\n*Fecha de nacimiento: %d/%d/%d", dia_nacimiento, mes_nacimiento, year_nacimiento);
  	printf("\n*****************************");
    return 0;
}
