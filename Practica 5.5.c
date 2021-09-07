/*
Zavala Irvin Matricula:01270771

Realizar un programa que solicite al usuario ingresar
un numero entero, posteriormente el programa le
solicitará que seleccione la tarea que se desea ejecutar.

Las tareas a elegir corresponden con:
1) Reversa de un numero
2) Cantidad de digitos de un número
3) Suma de sus cifras
4) �Es primo?
*/

#include<stdio.h>

int reversa(int);
int digitos(int);
int suma_cifras(int);
int primo(int);


int main(void)
{
    int opc, num, cifras, i;//Declaracion variables

    printf("Ingrese un numero entero: ");
    scanf("%d", &num);

    do
    {

        printf("\n\nMENU: ");
        printf("\n1) Reversa de un numero ");
        printf("\n2) Cantidad de digitos ");
        printf("\n3) Suma de sus cifras ");
        printf("\n4) Es primo? ");
        printf("\n5) Salir ");

        printf("\n\nSeleccione una opcion: ");
        scanf("%d", &opc);
        switch(opc) //Switch para ir a la opcion seleccionada
        {
            case 1:
                printf("El numero %d, al reves es %d", num, reversa(num));//Llamado a la funcion reversa
                break;
            case 2:
                printf("El numero %d, tiene %d digitos", num, digitos(num));//Llamada a la funcion numero de digitos del numero
                break;
            case 3:
                printf("La suma de las cifras de %d es %d", num, suma_cifras(num));//Llamada a la funcion la suma de las cifras del numero
                break;
            case 4:
                if(primo(num))//Llamado la funcion para saber si es primo
                    printf("El numero %d es primo", num);
                else
                    printf("El numero %d no es primo", num);
                break;
            case 5: break;//En esta opcion se sale
            default: printf("\nSeleccione una opc valida\n");//Si no se selecciona ninguno se le avisa al usuario
        }
    }while(opc!=5);//Se sale hasta que el usuario seleccione la opcion correspondiente


    return 0;
}

int reversa(int num)
{
	int volteado;
	while(num > 0){
		volteado = (num % 10) + volteado * 10;//Ciclo para voltear el numero
		num = num/10;
	}
  return volteado;
}

int digitos(int num)
{
	int cifras, i;
	while ( num > 0){
		cifras = num%10;//Ciclo para saber el numero de digitos
		num = num/10;
		i++;
	}
    return i;
}

int suma_cifras(int num)
{
    int suma = 0;
    while(num)
    {
        suma += num%10;//Ciclo para saber la suma de las cifras del numero
        num = num / 10;
    }

    return suma;
}

int primo(int num)
{
	int i, primo, divisores;//Declaracion contador
	divisores = 0;

	
	for (i=1; i <= num; i++){
		if( num % i == 0){
			divisores++;//Si hay un divisor que cumpla la condicion se suma en divisores
		}
	}
	if (divisores == 2){
		primo = 1;
	}
	else{
		primo = 0;
	}

    return primo;
}
