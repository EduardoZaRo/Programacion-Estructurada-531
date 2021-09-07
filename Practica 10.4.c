#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
/*Zavala Roman Irvin Eduardo 1270771
Practica 10 Ejercicio 4*/

//Estructuras
typedef struct{
    int dia;
    int mes;
    int year;
} fecha_t;


typedef struct{
    int matricula;
    char nombre[35];
    char paterno[35];
    char materno[35];
    fecha_t fecha_ingreso;
    fecha_t fecha_nacimiento;
    float promedio;
} alumno_t;


//Prototipo de las funciones
void mostrar_alumno(alumno_t);
fecha_t captura_fecha();
alumno_t captura();
float suma(alumno_t*, int);
void aprobados(alumno_t*, int );
void reprobados(alumno_t*, int );
void matricula(alumno_t*, int );
void bus_nom(alumno_t*, int );


int main(void)
{
	srand(time(NULL));//Para los numeros aleatorios
	
	//Declaracion de variables y entrada de la cantidad de alumnos
	int cant, i, opc;
    printf("\nCuantos alumnos vas a ingresar?: ");
    scanf("%d", &cant);
    
    alumno_t alumnos[cant];

	//Por cada elemento del array alumnos se llamara la funcion captura
	for(i = 0; i < cant; i++){
		alumnos[i] = captura();
	}
	
	//Se imprime el menu de opciones
	printf("\n\tMenu de opciones: \n");
	printf("\n1. Mostrar los alumnos");
	printf("\n2. Calcular el promedio de todos los alumnos");
	printf("\n3. Mostrar los alumnos aprobados");
	printf("\n4. Mostrar los alumnos reprobados");
	printf("\n5. Buscar un alumno por matricula");
	printf("\n6. Buscar alumno por nombre o apellidos\n");
	scanf("%d", &opc);

	//Se llaman las funciones dependiendo de la opcion
	switch(opc){
		case 1: ;
			for(i = 0; i < cant; i++){
				mostrar_alumno(alumnos[i]);
				printf("\n\n");
			}
			;break;
		case 2: ;
			float sum = suma(&alumnos[0], cant);
			float prom = sum/cant;
			printf("\nEl promedio de los %d alumnos es: %.2f", cant, prom);
			;break;
		case 3: ;
			aprobados(&alumnos[0], cant);
			;break;
		case 4: ;
			reprobados(&alumnos[0], cant);
			;break;
		case 5: ;
			matricula(&alumnos[0], cant);
			;break;
		case 6: ;
			bus_nom(&alumnos[0], cant);
			;break;
	}


    return 0;
}


void mostrar_alumno(alumno_t al){//Se imprimen los datos del alumno
    printf("\nMatricula del alumno: %d", al.matricula);
    printf("\nNombre del alumno: %s", al.nombre);
    printf("\nApellido del alumno: %s %s", al.paterno, al.materno);
    printf("\nPromedio del alumno: %.1f", al.promedio);
    printf("\nFecha de ingreso %d/%d/%d", al.fecha_ingreso.dia, al.fecha_ingreso.mes, al.fecha_ingreso.year);
    printf("\nFecha de nacimiento %d/%d/%d", al.fecha_nacimiento.dia, al.fecha_nacimiento.mes, al.fecha_nacimiento.year);           
}

alumno_t captura(){//Se captura un nuevo alumno
    //struct paciente es el tipo de dato
    alumno_t nuevo;

    printf("\nIngrese el nombre: ");
    scanf("%s", nuevo.nombre);
    printf("Ingrese el apellido paterno: ");
    scanf("%s", nuevo.paterno);
    printf("Ingrese el apellido materno: ");
    scanf("%s", nuevo.materno);
    printf("Ingrese la matricula: ");
    scanf(" %d", &nuevo.matricula);
    printf("Ingrese fecha de ingreso: ");
    nuevo.fecha_ingreso = captura_fecha();
    printf("Ingrese fecha de nacimiento: ");
    nuevo.fecha_nacimiento = captura_fecha();
    nuevo.promedio = rand()%100;
    printf("\nEl promedio es de: %f", nuevo.promedio);
    return nuevo;
}

fecha_t captura_fecha(){//Se capturan fechas, se usa para las de ingreso y nacimiento
    fecha_t fecha;

    printf("\nIngrese fecha (formato dd/mm/aaaa): ");
    scanf("%d/%d/%d",&fecha.dia, &fecha.mes, &fecha.year);

    return fecha;
}

float suma(alumno_t* al, int cant){//Se suman promedios para luego calcular promedio
	float suma = 0;
    int i;
    for(i = 0; i < cant; i++){
		suma += (*al).promedio;
		al++;
		printf("\nLa suma es :%f", suma);
	}
	return suma;
}

void aprobados(alumno_t* al, int cant){//Por cada alumno en alumnos se verifica quienes aprobaron para imprimirlo
	int aprobados = 0, i;
	for(i = 0; i < cant; i++){
		if((*al).promedio >= 60){
			printf("\nEl alumno %s esta aprobado", (*al).nombre);
			aprobados++;
		}
		al++;
	}
	if(aprobados == 0){
		printf("\nNingun alumno aprobo :(");
	}	
}

void reprobados(alumno_t* al, int cant){//Por cada alumno en alumnos se verifica quienes reprobaron para imprimirlo
	int reprobados = 0, i;
	for(i = 0; i < cant; i++){
		if((*al).promedio < 60){
			printf("\nEl alumno %s esta reprobado", (*al).nombre);
			reprobados++;
		}
		al++;
	}
	if(reprobados == 0){
		printf("\nNingun alumno reprobo :)");
	}	
}

void matricula(alumno_t* al, int cant){//Se pide una matricula y se compara con las matriculas de cada alumno en alumnos
	int mat, i;
	printf("\nInserta la matricula del alumno a buscar: ");
	scanf("%d", &mat);
	for(i = 0; i < cant; i++){
		if(mat == (*al).matricula){
			printf("\nLa matricula %d corresponde al alumno %s", (*al).matricula, (*al).nombre);
		}
		al++;
	}	
}

void bus_nom(alumno_t* al, int cant){//Se piden nombre y apellidos del alumno a buscar (si los sabe), se comparan estos datos con strcmp en cada elemento alumno en alumnos
	char nom[35], pat[35], mater[35];
	int i;
	printf("\nInserta nombre del alumno a buscar (Si no sabe escriba 1): ");
	scanf("%s", nom);

	printf("\nInserta apellido paterno del  alumno a buscar (Si no sabe escriba 1): ");
	scanf("%s", pat);

	printf("\nInserta apellido materno del  alumno a buscar (Si no sabe escriba 1): ");
	scanf("%s", mater);

	for(i = 0; i < cant; i++){
		if(strcmp(nom, (*al).nombre) == 0 || strcmp(pat, (*al).paterno) == 0 || strcmp(mater, (*al).materno == 0)){
			printf("\nEl nombre completo del alumno es de %s %s %s", (*al).nombre, (*al).paterno, (*al).materno);
		}
		al++;
	}	
}

