/*Practica 12 Zavala Roman Irvin Eduardo 
Periodico local*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define CLEAR() system("CLS")
//Estructuras
typedef struct{
    int dia;
    int mes;
    int year;
} fecha;
struct anuncio{
  char clasificacion[50];
  char responsable[50];
  long int telefono;
  long int numero;
  char contenido[50];
  fecha publicacion;
  
};
char* MONTH[] = {
	"Enero","Febrero",
    "Marzo", "Abril",
    "Mayo", "Junio",
    "Julio", "Agosto",
    "Septiembre", "Octubre",
    "Noviembre", "Diciembre" };

//Prototipos de las funciones
void registrar(struct anuncio * );
void mostrar();
void grabar(struct anuncio );
fecha captura_fecha();
int busqueda_numeros(char[] );
int busqueda_char(char[] );
void cancelar();
void consultar_clasificacion();
void consultar_responsable();
void editar();
void ordenar();
void fec();
void respaldo(char[]);

int main(){
    struct anuncio registro;
    char opc;
    do
    {
        CLEAR();
        //Menu de opciones
        puts("\n1) Registrar anuncio");
        puts("2) Cancelar anuncio");
        puts("3) Editar anuncio");
        puts("4) Consultar por clasificacion");
        puts("5) Consultar por responsable");
        puts("6) Ordenar por responsable");
        puts("7) Mostrar los anuncion que se publicaran ahora");
        puts("8) Generar respaldo de datos");
        puts("9) Salir");
        printf("Opcion:");

        setbuf(stdin, 0);
        opc = getchar();

        switch(opc){//Llamo funciones dependiendo de la opcion ingresada
            case '1': 
			  	registrar(&registro);
			  	grabar(registro);
                break;
            case '2': 
            	printf("\nNumero del anuncio a eliminar: ");
            	cancelar();
            	break;
            case '3': 
				editar();
            	break;
            case '4': 
				consultar_clasificacion();
            	break;
            case '5': 
				consultar_responsable();
            	break;
            case '6':
            	ordenar();
            	mostrar();
            	break;
            case '7':
            	fec();
            	break;
            case '8':
            	printf("\nIngrese el nombre del archivo de respaldo con extension .dat: \n");
            	char nombre[50];
            	setbuf(stdin, 0);
            	gets(nombre);
            	respaldo(nombre);
            	break;
            default: 
            	printf("\n\tHasta luego!");
            	exit(-1);
				break;
        }
    }while (opc!=48);

    return 0;
}
void registrar(struct anuncio * registro){//Sirve para meter nuevos anuncios por teclado   
    CLEAR();
    //Ingreso de datos
    printf("Numero de anuncio: "); scanf("%d",&registro->numero);
    FILE * flujo;
    struct anuncio file;
	flujo = fopen("Resultado_12.dat","rb");

    if (flujo){//If para comparar el numero de anuncio ingresado con los ya registrados y evitar repetidos
        while( fread(&file,sizeof(struct anuncio),1,flujo)>0){
        	if((file.numero) ==  (registro->numero)){
        		printf("\n\tYa esta registrado :/");
        		exit(-1);//Si ese numero de anuncio ya existe damos error
			}
		} 
    }
    fclose(flujo);
    
    setbuf(stdin,0);
    printf("Clasificacion: "); gets(registro->clasificacion);
    setbuf(stdin,0);
    printf("Responsable de la publicacion: "); gets(registro->responsable);
    printf("Telefono del responsable:"); scanf("%d",&registro->telefono);
    setbuf(stdin,0);
    printf("Contenido del anuncio:"); gets(registro->contenido);
    printf("Fecha de la publicacion:"); 
    fecha aux = captura_fecha();
    registro->publicacion=aux;

}
void grabar(struct anuncio registro){//Guarda en un archivo lo ingresado en registrar
	//Abro el archivo donde van los registros y guardo lo ingresado en registro
    FILE * flujo;
    getchar();
    flujo= fopen("Resultado_12.dat","ab");
    if (flujo!=NULL)
    {
        fwrite(&registro,sizeof(struct anuncio),1,flujo);
        fclose(flujo);
    }
    else
        printf("No se pudo abrir");

}
fecha captura_fecha(){//Sirve para ingresar la fecha de publicacion del anuncio
    fecha fecha_1;

    printf("\nIngrese fecha (formato dd/mm/aaaa): ");
    scanf("%d/%d/%d",&fecha_1.dia, &fecha_1.mes, &fecha_1.year);
	if((fecha_1.dia < 0 || fecha_1.dia > 31)||(fecha_1.mes < 0 || fecha_1.mes > 12)||(fecha_1.year < 1950 || fecha_1.year > 2050)){
		printf("\n\tERROR :(");
		printf("\n\tFecha no valida\n");
		exit(-1);//Si la fecha no es valida damos error
	}
    return fecha_1;
}
void mostrar(){//Imprime los anuncios registrados
	//Abro el archivo y paso por cada anuncio para imprimirlo
    FILE * flujo;
    struct anuncio registro;
    int cont=1;
    flujo= fopen("Resultado_12.dat","rb");
    if (flujo)
    {
        while( fread(&registro,sizeof(struct anuncio),1,flujo)>0)
        {
            printf("\n\n  Numero No. %d\n", cont);
            printf("Numero del anuncio: %d\n", registro.numero);
            printf("Clasificacion: %s \n", registro.clasificacion);
            printf("Responsable: %s \n", registro.responsable);
            printf("Telefono: %d \n", registro.telefono);
            printf("Contenido:"); puts(registro.contenido);
            printf("Fecha de publicacion: %d/%d/%d \n", registro.publicacion.dia, registro.publicacion.mes, registro.publicacion.year);
            setbuf(stdin,0);
            getchar();
            cont++;
        }
    }

	
    fclose(flujo);
}
void cancelar(){//Borra un anuncio por su numero
	//Abre el archivo con anuncios y otro donde se cortara el anuncio a cancelar
   FILE *original, *copia;
   char llave[50];
   int ban;
   struct anuncio aux;
   original=fopen("Resultado_12.dat","rb");
   copia=fopen("temporal.dat","wb");
   if (!original || !copia)
      printf("No se puede realizar la operacion");
   else
   {
       setbuf(stdin, 0);
       gets(llave);
       ban=busqueda_numeros(llave);//Busco si esta el numero de anuncio ingresado por el usuario
       if (ban!=-1)
       {
           while(fread(&aux,sizeof(struct anuncio),1,original)>0)
           {    if(aux.numero != atoi(llave))
                   fwrite(&aux,sizeof(struct anuncio),1,copia);
           }
           fclose(original);
           fclose(copia);
           remove("Resultado_12.dat");
           rename("temporal.dat", "Resultado_12.dat");
           printf("\nAnuncio cancelado!");getchar();
       }
       else
            printf("\nNo se encontro :/");
   }
    
}
int busqueda_numeros(char llave[] ){//Sirve para buscar por numero de anuncio
    //Compara el parametro ingresado con los anuncios registrados
	FILE * flujo;
    struct anuncio registro;
    int cont=0;
    flujo= fopen("Resultado_12.dat","rb");
    if (flujo)
    {
        while( fread(&registro,sizeof(struct anuncio),1,flujo)>0)
        {
            cont++;
            if (registro.numero==atoi(llave))
            {
                getchar();
                fclose(flujo);
                return cont;
            }
        }
        fclose(flujo);
    }
    return -1;
}
int busqueda_char(char llave[] ){//Sirve para buscar por clasificacion
    //Compara la clasificacion ingresada con las ya registradas
	FILE * flujo;
    struct anuncio registro;
    int cont=0;
    flujo= fopen("Resultado_12.dat","rb");
    if (flujo)
    {
        while( fread(&registro,sizeof(struct anuncio),1,flujo)>0)
        {
            cont++;
            if (strcmp(registro.clasificacion, llave) == 0)
            {
            	//Si lo encuentra lo imprime
	            printf("\nNumero del anuncio: %d\n", registro.numero);
	            printf("Clasificacion: %s \n", registro.clasificacion);
	            printf("Responsable: %s \n", registro.responsable);
	            printf("Telefono: %d \n", registro.telefono);
	            printf("Contenido:"); puts(registro.contenido);
	            printf("Fecha de publicacion: %d/%d/%d \n", registro.publicacion.dia, registro.publicacion.mes, registro.publicacion.year);
                getchar();
                fclose(flujo);
                return cont;
            }
        }
        fclose(flujo);

    }
    return -1;
}
void consultar_clasificacion(){//Sirve para buscar por clasificacion
    char llave[50];
    puts("Ingresa clasificacion del anuncio a buscar: ");
    setbuf(stdin, 0);
    gets(llave);
	int ban=busqueda_char(llave);
	if(ban!=-1){
		printf("\n\tNo se encontro :(");
	}
	//No pude poner todo en una funcion como en consultar_responsable(), desconozco el porque
}
void consultar_responsable(){//Sirve para buscar por responsable
    char llave[50];
    puts("Ingresa el responsable del anuncio a buscar: ");
    setbuf(stdin, 0);
    gets(llave);
    FILE * flujo;
    struct anuncio registro;
    int cont=0;
    flujo= fopen("Resultado_12.dat","rb");
    if (flujo)
    {
        while( fread(&registro,sizeof(struct anuncio),1,flujo)>0)
        {
            cont++;
            if (strcmp(registro.responsable, llave) == 0)
            {
	            printf("\nNumero del anuncio: %d\n", registro.numero);
	            printf("Clasificacion: %s \n", registro.clasificacion);
	            printf("Responsable: %s \n", registro.responsable);
	            printf("Telefono: %d \n", registro.telefono);
	            printf("Contenido:"); puts(registro.contenido);
	            printf("Fecha de publicacion: %d/%d/%d \n", registro.publicacion.dia, registro.publicacion.mes, registro.publicacion.year);
                getchar();
                fclose(flujo);
            }
        }
        fclose(flujo);

    }

}
void editar(){//Sirve para editar un anuncio ya registrado

    char llave[50];
    struct anuncio registro;

    FILE * flujo;
    setbuf(stdin,0);
    printf("Numero del anuncio: "); gets(llave);
    int ban=busqueda_numeros(llave);//Veo si el numero de anuncio ingresado en valido

    if (ban!=-1)//Si lo es, dejo modificar todo de ese anuncio menos el numero de anuncio
    {
        flujo= fopen("Resultado_12.dat","rb+");
        if (flujo!=NULL)
        {   
			fseek(flujo,(ban-1)*sizeof(struct anuncio),SEEK_SET);
            fread(&registro,sizeof(struct anuncio),1,flujo);
            printf("\n Encontrado en el Registro No. %d \n", ban);
            printf("Numero del anuncio: %d\n", registro.numero);
            
            printf("Clasificacion: %s \n", registro.clasificacion);
            setbuf(stdin,0);
            
            printf("Escriba la nueva clasificacion: "); gets(registro.clasificacion);
  
            printf("Responsable: %s \n", registro.responsable);
            setbuf(stdin,0);
            printf("Escriba el nuevo responsable: "); gets(registro.responsable);
            printf("Telefono: %d \n", registro.telefono);
            printf("Escriba el nuevo telefono: "); scanf("%d",&registro.telefono);
            printf("Contenido:"); puts(registro.contenido);
            setbuf(stdin,0);
            printf("Escriba el nuevo contenidp: "); gets(registro.contenido);
            printf("Fecha de publicacion: %d/%d/%d \n", registro.publicacion.dia, registro.publicacion.mes, registro.publicacion.year);
            printf("Escriba la nueva fecha: "); 
            fecha aux = captura_fecha();
   			registro.publicacion=aux;
            fseek(flujo,(ban-1)*sizeof(struct anuncio),SEEK_SET);
            fwrite(&registro,sizeof(struct anuncio),1,flujo);
            fclose(flujo);
        }
        else
            printf("No se pudo abrir el archivo");
    }
    else
            printf("No se encontro");
}
void ordenar(){//Ordena los anuncios por responsable
   
   FILE *flujo;
   int i, j;
   int n;
   struct anuncio a,b;
   flujo=fopen("Resultado_12.dat","rb+");
   if (flujo==NULL)
      printf("No se puede realizar la operacion");
   else
   {       i=0;
           fseek(flujo,0,SEEK_END);
           n=ftell(flujo)/sizeof(struct anuncio);
 
           printf("Ordenando %d registros ", n);
           getchar();
           for(i=0;i<n-1;i++)
           {
              for(j=i+1;j<n;j++)
              {
                fseek(flujo,i*sizeof(struct anuncio),SEEK_SET);
                fread(&a,sizeof(struct anuncio),1,flujo);
                fseek(flujo,j*sizeof(struct anuncio),SEEK_SET);
                fread(&b,sizeof(struct anuncio),1,flujo);
                printf("%d, %d, %s con %s \n", i,j,a.responsable, b.responsable);
                getchar();
                if( strcmp(a.responsable,b.responsable)>0)
                {
                    fseek(flujo,i*sizeof(struct anuncio),SEEK_SET);
                    fwrite(&b,sizeof(struct anuncio),1,flujo);
                    fseek(flujo,j*sizeof(struct anuncio),SEEK_SET);
                    fwrite(&a,sizeof(struct anuncio),1,flujo);
                }
              }
           }
           fclose(flujo);
       }
}
void fec(){//Compara la fecha del sistema con la de los anuncios para saber cuales se publicaran ahora
	setbuf(stdin, 0);
    time_t t;
    struct tm tm;

    t = time(NULL);
    tm = *localtime(&t);

    printf("La fecha actual es: %d-%d-%d \n\n\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
    FILE *file;
    int i = 0;
    struct anuncio aux;
    file = fopen("Resultado_12.dat", "rb");
    if (file){
        while( fread(&aux,sizeof(struct anuncio),1,file)>0){
        	if((aux.publicacion.dia == tm.tm_mday)&&(aux.publicacion.mes == tm.tm_mon+1)&&(aux.publicacion.year == (tm.tm_year+1900))){//Comparo las fechas de los anuncios con la de hoy
        		i++;
        		printf("\n%d coincidencia\n\n", i);
	            printf("Numero del anuncio: %d\n", aux.numero);
	            printf("Clasificacion: %s \n", aux.clasificacion);
	            printf("Responsable: %s \n", aux.responsable);
	            printf("Telefono: %d \n", aux.telefono);
	            printf("Contenido:"); puts(aux.contenido);
	            printf("Fecha de publicacion: %d/%d/%d \n", aux.publicacion.dia, aux.publicacion.mes, aux.publicacion.year);
	            setbuf(stdin,0);
	            getchar();
			}
		} 
    }
    if(i == 0){//Si no se conto ninguna coincidencia le decimos al usuario
    	printf("\nNo hay anuncios que se publiquen ahora");
	}
    
    fclose(file);
}
void respaldo(char nombre[]){//Copia los elementos registrados en un archivo nuevo llamado por el usuario
   FILE *original, *respaldo;
   struct anuncio aux;
   original=fopen("Resultado_12.dat","rb");
   respaldo=fopen(nombre,"wb");
   //Copio los anuncios registrados en el archivo de respaldo
   if (!original || !respaldo)
      printf("No se puede realizar la operacion");
   else
   {
		if(original){
	        while(fread(&aux,sizeof(struct anuncio),1,original)>0)
	        {    
	                fwrite(&aux,sizeof(struct anuncio),1,respaldo);
	        }
	        fclose(original);
	        fclose(respaldo);
	        rename(nombre, "Resultado_12.dat");
	        printf("\nRespaldo completado!");
			getchar();			
		}

   } 
    //Se imprime lo que hay en el respaldo
	printf("\nEl respaldo quedaria asi: \n\n\n");
    respaldo=fopen(nombre,"rb");
    if (respaldo)
    {
        while( fread(&aux,sizeof(struct anuncio),1,respaldo)>0)
        {
            printf("Numero del anuncio: %d\n", aux.numero);
            printf("Clasificacion: %s \n", aux.clasificacion);
            printf("Responsable: %s \n", aux.responsable);
            printf("Telefono: %d \n", aux.telefono);
            printf("Contenido:"); puts(aux.contenido);
            printf("Fecha de publicacion: %d/%d/%d \n", aux.publicacion.dia, aux.publicacion.mes, aux.publicacion.year);
            printf("\n");
            getchar();
        }
    }

	
    fclose(respaldo);	
}

