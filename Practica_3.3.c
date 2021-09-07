/* Zavala Irvin Matricula:01270771
Programa que determina el tipo de triangulo con la longitud de los lados, con eso calcular perimetro y area*/
#include<stdio.h>
#include<math.h>

int main(void){
	float s,area,perimetro,s_1, s_2, s_3,a,b,c; //Declaracion variables
	
	printf("Programa que te dice el tipo de triangulo,area y perimetro con solo sus lados");//Descripcion de programa al usuario
	
	//Entrada de datos
	printf("\nIntroduzca el primer lado\n");
	scanf("%f",&s_1);
	printf("\nIntroduzca el segundo lado\n");
	scanf("%f",&s_2);
	printf("\nIntroduzca el tercer lado\n");
	scanf("%f",&s_3);
	if (s_1 > 0 && s_2 > 0 && s_3 > 0){//Los lados deben ser positivos pa que arranque
	
		//Primero ordenamos encontramos el numero mayor, los otros 2 da igual su orden
		if (s_1 >= s_2 && s_1 >= s_3){
			a = s_1;
			b = s_2;
			c = s_3;

		}
		else{
			if(s_3 < s_2){
				a = s_2;
				b = s_1;
				c = s_3;

			}
			else{
				a = s_3;
				b = s_1;
				c = s_2;

			}
			
		}
		if (a >= b + c){//Empieza la formacion de triangulos y su procedimiento
			printf("No se forma ningun triangulo ://\n");
		}
		else{
			if(a*a == b*b + c*c){
				printf("Se forma un triagulo rectangulo :o\n");
				s = (a + b + c)/2;
				area = sqrt(s*(s - a)*(s - b)*(s - c));
				perimetro = a + b + c;
				printf("El area es de %f y el perimetro de %f",area,perimetro);
			}
			else{
				if( a*a > b*b + c*c){
					printf("Se forma un triagulo obtuso :o\n");
					s = (a + b + c)/2;
					area = sqrt(s*(s - a)*(s - b)*(s - c));
					perimetro = a + b + c;
					printf("El area es de %f y el perimetro de %f",area,perimetro);
				}
				else{
					if(a == b && b == c){
						printf("Se forma un triagulo equilatero :o\n");
						s = (a + b + c)/2;
						area = sqrt(s*(s - a)*(s - b)*(s - c));
						perimetro = a + b + c;
						printf("El area es de %f y el perimetro de %f",area,perimetro);
					}
					else{
						if( a*a < (b*b + c*c)){
							printf("Se forma un triagulo agudo :o\n");
							s = (a + b + c)/2;
							area = sqrt(s*(s - a)*(s - b)*(s - c));
							perimetro = a + b + c;
							printf("El area es de %f y el perimetro de %f",area,perimetro);
						}
					}
				}
			}
		}
	}
	
	else{
		printf("No puedes meter lados negativos ://");
	}

	

	return 0;
}
