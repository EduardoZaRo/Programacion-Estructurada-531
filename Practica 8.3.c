#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define h 1e-4


float biseccion( float (*f)(float), float tolerancia, float max_iter);
float falsa_posicion( float (*f)(float), float tolerancia, float max_iter);
float newton( float (*f)(float), float tolerancia, float max_iter);
float f(float);
float derivada(float (*f)(float), float);


float f(float x){
    return pow(x,x)-100;//Aqui se inserta la funcion que queremos resolver, en este caso es x^x = 100
}

int main (void){

	//Declaracion de variables
	int opt, size, i, max_iter;
	float (*metodos[])(float (*f)(float), float, float) = {biseccion, falsa_posicion, newton};
	char* nombres[] = {"Biseccion", "Falsa posicion", "Newton"};
	
	size=sizeof(nombres)/sizeof(char*);
	
	//Se imprimen los metodos a escoger
	printf("Seleccione un metodo:\n");
	i = 1;
	do
	{
		printf("%d) %s\n", i, nombres[i-1]);
	}while(i++<size);
	
	//Se ingresa la opcion
	printf("Ingrese opcion: ");
	scanf("%d", &opt);
	
	//Se llama la funcion  si la opcion es correcta	
	if(opt<=size && opt>=1)
	    printf("\nSolucion: %f", metodos[opt-1](f, 1e-5, 100));
	else
	    printf("Seleccione opcion correcta");
  return 0;
}


float biseccion( float (*f)(float), float tolerancia, float max_iter)
{
    //Declaracion variables
    float x_i, x_d, x_a, x_new, tol = 1e10;
    
    //Entrada de limites
    printf("\nIngrese el limite izquierdo: ");
    scanf("%f", &x_i);
    printf("\nIngrese el limite derecho: ");
    scanf("%f", &x_d);
    int iteraciones = 0;
    
    //Si el rango menor es mayor al superior o la raiz no esta en el rango entonces no es valido
	if(x_i >= x_d ||f(x_d)*f(x_i) > 0){
		printf("\nRango no valido :/\n");
		biseccion(f, 1e-5, 100);
	}
	//Si es valido se aplica el metodo correspondiente
    do{	
    	x_new = (x_i + x_d)/2.0;
    	if(f(x_new) * f(x_i) < 0){
    		x_d = x_new;
		}
		else{
			x_i = x_new;
		}
		iteraciones++;
		tol = fabs(f(x_new));
		printf("\nEn la iteracion %d la raiz aproximada de: %f", iteraciones, x_new);

	}while(tol > tolerancia && iteraciones < max_iter);//Se repite mientras la tolerancias sea mayor a lo que queremos o que las iteraciones no pasen de 100

	return x_new;
}

float falsa_posicion( float (*f)(float), float tolerancia, float max_iter)
{
    //Declaracion variables
    float x_i, x_d, x_a, x_new = 0, tol = 1e10;
    
    //Entrada de limites
    printf("\nIngrese el limite izquierdo: ");
    scanf("%f", &x_i);
    printf("\nIngrese el limite derecho: ");
    scanf("%f", &x_d);
    int iteraciones = 0;
    //Si el rango menor es mayor al superior o la raiz no esta en el rango entonces no es valido
	if(x_i >= x_d ||f(x_d)*f(x_i) > 0){
		printf("\nRango no valido :/\n");
		return 0;
	}
	//Si es valido se aplica el metodo correspondiente
    do{
    	
    	x_new = x_i - (f(x_i)*(x_d-x_i))/(f(x_d) - f(x_i));
    	

    	if(f(x_new) * f(x_i) < 0){
    		x_d = x_new;
		}
		else{
			x_i = x_new;
		}	
		iteraciones++;
    	tol = fabs(f(x_new));
    	printf("\nEn la iteracion %d la raiz aproximada de: %f", iteraciones, x_new);
	}while(tol > tolerancia && iteraciones < max_iter);//Se repite mientras la tolerancias sea mayor a lo que queremos o que las iteraciones no pasen de 100

	return x_new;
}

float newton( float (*f)(float), float tolerancia, float max_iter)
{
    //Declaracion variables
    float x_i, x_new, tol = 1e10;
    
    //Entrada del punto de partida del metodo
    printf("\nIngrese el punto de inicio: ");
    scanf("%f", &x_i);

    int iteraciones = 0;
	
	//Se aplica el metodo correspondiente, no hay restriccion de numero no valido
    do{
    	iteraciones++;
    	x_new = x_i - f(x_i)/derivada(f, x_i);
    	

    	tol = fabs(f(x_new));
		
    	printf("\nEn la iteracion %d la raiz aproximada de: %f", iteraciones, x_new);
		x_i = x_new;
		
	}while(tol > tolerancia && iteraciones < max_iter);//Se repite mientras la tolerancias sea mayor a lo que queremos o que las iteraciones no pasen de 100

	return x_new;
}
float derivada(float (*f)(float), float x){//Calculo de la derivada para el metodo de Newton- Raphson
    return (f(x+h)-f(x-h))/(2*h);
}




