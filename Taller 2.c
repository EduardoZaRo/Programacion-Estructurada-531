/* Zavala Irvin Matricula:01270771
Programa que dice el cuadro de covid de un paciente*/

#include <stdio.h>

int main(void)
{
    //Mensajes de cuadros de covid
    const char recomendaciones_caso_leve[] = "\n\nBienvenid%c %s %s, segun la informacion \
ingresada se considera como un posible caso leve, por lo que se puede recuperar en el hogar. \
Se recomienda llamar a un proveedor de atencion medica. \
\n\nSe recomienda que realice las siguientes medidas de prevencion :\
\n\n\t-Quedese en su casa y llame al medico para asesoramiento medico y antes de ir al consultorio.\
\n\t-Separese de las demas personas en su hogar. \
\n\t-Use un tapaboca de tela cuando esta con otras personas\
\n\n\t *********************************************\
\n\t*%s %s\
\n\t*Genero:%c   Edad:%d\
\n\t*Peso:%.2f  Temperatura:%.2f\
\n\t*No es vulnerable\
\n\t*Tiene sintomas leves\
\n\t************************************************";

    const char recomendaciones_caso_grave[] = "\n\nBienvenid%c %s %s, segun la informacion \
ingresada se considera como un posible caso grave, por lo que se recomienda asistir \
al medico de manera inmediata. Se recomienda primero llamar a un proveedor de atencion \
medica.\n\nSe recomienda que realice las siguientes medidas de prevencion :\
\n\n\t-Use un tapaboca de tela cuando esta con otras personas. \
\n\t-Evite el contacto innecesario con las demas personas.\
\n\n\t *********************************************\
\n\t*%s %s\
\n\t*Genero:%c   Edad:%d\
\n\t*Peso:%.2f  Temperatura:%.2f\
\n\t*Tiene sintomas graves\
\n\t**********************************************";

    const char recomendaciones_caso_vul[] = "\n\nBienvenid%c %s %s, segunn la informacion \
ingresada se considera que pertenece al grupo vulnerable con sintomas leves, por lo que se recomienda asistir al \
medico, favor de llamar previamente a un proveedor de atencion medica.\
\n\nSe recomienda que realice las siguientes medidas de prevencion :\
\n\n\t-Use un tapaboca de tela cuando esta con otras personas. \
\n\t-Evite el contacto innecesario con las demas personas.\
\n\n\t *********************************************\
\n\t*%s %s\
\n\t*Genero:%c   Edad:%d\
\n\t*Peso:%.2f  Temperatura:%.2f\
\n\t*Es vulnerable\
\n\t*Tiene sintomas leves\
\n\t************************************************";

    const char recomendaciones_no_covid[] = "\n\nBienvenid%c %s %s, segun la informacion \
ingresada se considera que no presenta un cuadro compatible con covid19.\
\n\nSe recomienda que realice las siguientes medidas de prevencion :\
\n\n\t-Use un tapaboca de tela cuando esta con otras personas. \
\n\t-Evite el contacto innecesario con las demas personas.\
\n\n\t *********************************************\
\n\t*%s %s\
\n\t*Genero:%c   Edad:%d\
\n\t*Peso:%.2f  Temperatura:%.2f\
\n\t*No tiene sintomas\
\n\t**********************************************";

/*Variables referentes a la informacion del paciente*/

char nombre[50], apellido[50], genero, saludo_terminacion, hip_diabetes, embarazo, dificultad_resp, dolor_pecho, confusion, inc_despertarse, cara_azul, sintomas_varios, vulnerable;
int edad;
float peso, temperatura, imc, estatura;

printf("Programa que le da un posible cuadro de covid19 al paciente");

//Entrada de datos del paciente
printf("\nIngrese su nombre: ");
scanf("%s", nombre);

printf("\nIngrese su apellido: ");
scanf("%s", apellido);

printf("\nIngrese su genero(M/F): ");
scanf(" %c", &genero);
    
//Preguntar si esta embazarada si es mujer 
if (genero == 'F'){
    printf("\nEsta embarazada?(S/N): ");
    scanf(" %c", &embarazo);
}
	
printf("\nIngrese su edad: ");
scanf("%d", &edad);
    
printf("\nIngrese su temperatura en C: ");
scanf("%f", &temperatura);
    
printf("\nIngrese su peso en kg: ");
scanf("%f", &peso);
    
printf("\nIngrese su estatura en metros: ");
scanf("%f", &estatura);
    
printf("\nTiene hipertension y/o diabetes?:(S/N) ");
scanf(" %c", &hip_diabetes);

printf("\nTiene dificultad para respirar?:(S/N) ");
scanf(" %c", &dificultad_resp);
    
printf("\nTiene dolor o presion persistente en el pecho?:(S/N) ");
scanf(" %c", &dolor_pecho);

printf("\nTiene confusion repentina?:(S/N) ");
scanf(" %c", &confusion);

printf("\nTiene incapacidad de despertar o estar despierto?:(S/N) ");
scanf(" %c", &inc_despertarse);
    
printf("\nTiene cara o labios azulados?:(S/N) ");
scanf(" %c", &cara_azul);
    
printf("\nTiene fiebre, escalofrios, tos, fatiga, dolores musculares/corporales, dolor de cabeza, perdida del gusto/olfato, dolor de garganta, congestion, moqueo, nauseas, vomito o diarrea?:(S/N) ");
scanf(" %c", &sintomas_varios);
    

	
//Si el IMC del paciente es mayor a 30 tiene obesidad y por lo tanto es vulnerable
imc = peso / (estatura*estatura);
printf("\n\tEl IMC del paciente es: %.2f", imc);
//Para saber con que terminacion referirse al paciente
if (genero == 'F')
    saludo_terminacion = 'a';
else
    saludo_terminacion = 'o';
        
//Saber si el paciente es vulnerable
if ( edad > 60 || embarazo == 'S' || imc > 30 || hip_diabetes == 'S'){
	printf("\n\tEl paciente se encuentra en un sector vulnerable");
	vulnerable = 'S';
}
//Saber el cuadro de covid19
if ( temperatura < 37.5 && sintomas_varios == 'N' && dificultad_resp == 'N' && dolor_pecho == 'N' && confusion == 'N' && inc_despertarse == 'N' && cara_azul == 'N'){//Sino tiene sintomas graves, leves ni temperatura no tiene covid
	printf("\n\n***CASO NO COVID***\n\n");
   	printf(recomendaciones_no_covid, saludo_terminacion, nombre, apellido, nombre, apellido,genero, edad, peso, temperatura);
	if(vulnerable =='S'){
		printf("\nAunque no tiene cuadro de covid-19, es alguien vulnerable, tenga cuidao");//A pesar de no tener cuadro de covid, puede ser alguien vulnerable, ya sea por edad, embarazo, obesidad, etc.
	}	
}
if(dificultad_resp == 'S' || dolor_pecho == 'S' || confusion == 'S' || inc_despertarse == 'S'|| cara_azul == 'S'){//Si tiene uno de los sintomas graves se le dira que tiene cuadro de covid grave
	printf("\n\n***CASO COVID GRAVE ***\n\n");
    printf(recomendaciones_caso_grave, saludo_terminacion, nombre, apellido, nombre, apellido,genero, edad, peso, temperatura);		
}
else{
	if(vulnerable == 'S'){
		if(sintomas_varios == 'S' || temperatura > 37.5){//Si no tiene sintomas graves y es vulnerable con sintomas varios o temperatura tiene cuadro de covid leve vulnerable
			printf("\n\n***CASO COVID LEVE VULNERABLE***\n\n");
   			printf(recomendaciones_caso_vul, saludo_terminacion, nombre, apellido, nombre, apellido,genero, edad, peso, temperatura);
		}
	}
	else{
		if(sintomas_varios == 'S' || temperatura > 37.5){//Si no tiene sintomas graves y no es vulnerable con sintomas varios o temperatura tiene cuadro de covid leve
			printf("\n\n***CASO COVID LEVE ***\n\n");
   			printf(recomendaciones_caso_leve, saludo_terminacion, nombre, apellido, nombre, apellido,genero, edad, peso, temperatura);
		}
	}
}
	

    return 0;
}

