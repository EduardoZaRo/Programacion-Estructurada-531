/* Zavala Irvin Matricula:01270771
Jueguito adivina el numero*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void){
	int num, num_intentos, num_usuario;//Declaracion enteros
	char repetir;//Declaracion caracteres
	time_t inicio, fin;//Declaracion intervalos de tiempo
	float tiempo_total;//Declaracion flotante
	
	repetir = 's';//Inicio repetir en SI para que while inicie al menos una vez
	

	while(repetir == 's'){//Mientras el usuario quiera repetir correra est while
	
		srand(time(NULL));   //Generar numeros aleatorios en cada juego diferente
		num = rand()%1000+1;
		
		
		num_intentos = 0;//Se inicia el numero de intentos en 0 
		
  		printf("\nTengo un numero entre el 1 y el 1000.");
		printf("\nPuedes adivinar cual es?:");
		
		time( &inicio);//Empieza a correr el tiempo desde aqui, el tiempo corre desde que introduce un numero
		
		do{		
		
		scanf("%d", &num_usuario);//Se deja introducir un dato mientras el juego dure
		
		if(num_usuario < 0 || num_usuario > 1000){//Esto es para recordar al usuario que no puede ingresar numero afuera del intervalo dado
			printf("\nNo es valido :/\n");
		}


		num_intentos += 1; //El numero de intentos que empezaba en 0 afuera del do while empieza a incrementar
		
		if(num_usuario == num){//Si el usuario le atina
			printf("\n\tExcelente! has adivinado el numero!");//Mensaje felicitacion
			if(num_intentos < 10){
				printf("\n\tFelicidades! Haz adivinado en pocos intentos(%d)", num_intentos);//Si gana en menos de 10 intentos
			}
			else{
				if(num_intentos == 10){
					printf("\nYa conoces el numero secreto");//Si gana en 10 intentos
				}
				else{
					printf("\nBien hecho, lo puedes hacer mejor!");//Si gana en mas de 10 intentos
				}
			}
			
			time(&fin);//Aqui se acaba el tiempo
			tiempo_total = difftime(fin, inicio);//Se calcula el tiempo entre donde empieza y termina los intervalos de tiempo
			printf("\n\n\tDescubriste el numero en %f segundos", tiempo_total);
			printf("\n\n\tQuieres jugar una vez mas? (s/n): ");//Preguntar si quiere jugar otra vez
			scanf(" %c", &repetir);
			

		}
		else{//Si el usuario no le atina
			if( num_usuario < num){
		 		printf("\nMuy bajo, intentalo nuevamente:  ");
			}
			else{
				printf("\nMuy alto, intentalo nuevamente:  ");
			}
		}
		
		}while( num_usuario < 0 || num_usuario > 1000 || num_usuario < num ||num_usuario > num);//Se repite el do while mientras no le atine al numero o el numero no sea valido
	}

	return 0;
}

