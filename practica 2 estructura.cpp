#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
// Definicion de las estructura.
struct nombre
{
	char pNombre[15];
	char sNombre[15];
	char pApellido[15];
	char sApellido[15];
};
struct cedula
{
	char tomo[2];
	int  folio, asiento;
};
struct direccion
{
	char provincia[20];
	char distrito[20];
	char correg[20];
	char urban[20];
	char calle[20];
	char avenida[20];
};
struct fechaNac
{
	int dd, mm, aa;
};
struct registro
{
	struct nombre name;
	struct cedula pID;
	struct direccion addr;
	struct fechaNac birth;
	int edad;
}student[1];
//principal program
int main()
{
	int i, contStudent=0;
	char letra;
	// Lectura de los datos y carga del vector estructurado.
	
	for(i=0;i<1;i++)
	{
		printf("\n\t\tESTUDIANTE %i\n",i+1);
		printf("\nNombre completo: ");
		scanf(" %s %s %s %s",&student[i].name.pNombre, &student[i].name.sNombre, &student[i].name.pApellido, &student[i].name.sApellido);
		printf("\nIngrese su N.o de cedula: ");
		scanf(" %s %d %d", &student[i].pID.tomo, &student[i].pID.folio, &student[i].pID.asiento);
		printf("\nIngrese su direccion: \n");
		printf("Provincia: ");
		scanf(" %[^\n]",&student[i].addr.provincia);
		printf("Distrito: ");
		scanf(" %[^\n]",&student[i].addr.distrito);
		printf("Corregimiento: ");
		scanf(" %[^\n]",&student[i].addr.correg);
		printf("Urbanizacion: ");
		scanf(" %[^\n]",&student[i].addr.urban);
		printf("Calle: ");
		scanf(" %[^\n]",&student[i].addr.calle);
		printf("Avenida: ");
		scanf(" %[^\n]",&student[i].addr.avenida);
		printf("\n Ingrese su edad: ");
		scanf(" %d",&student[i].edad);
		printf("\nIngrese su fecha de nacimiento (dd-mm-aa): ");
		scanf("%d %d %d",&student[i].birth.dd, &student[i].birth.mm, &student[i].birth.aa);
	}
	
	printf("\n\n\tESTUDIANTES QUE VIVEN: CALLE A SUR, AVENIDA 2DA OESTE, DAVID. 1ER LETRA DE 1ER APELLIDO F");
	int cont1=0;
	for(i=0;i<1;i++)
	{
		letra=student[i].name.pApellido[0];
		if ((strcmp(student[i].addr.calle,"A Sur")==0)&&(strcmp(student[i].addr.avenida,"2da oeste")==0))
			if(letra=='F'||'f')
				printf("\n\n Nombre: %s\nApellido: %s",student[i].name.pNombre, student[i].name.pApellido); cont1+=1;
		if(cont1==0)
			printf("\nNo hay estudiantes econ estas caracteristicas");
	}
	
	printf("\n\n\tESTUDIANTES NACIDOS EN COCLE EN JUNIO DE 1990"); 
	for (i=0;i<1;i++)
		if((strcmp(student[i].pID.tomo,"2")==0)&&(student[i].birth.mm==6||06 )&&(student[i].birth.aa==1990))
			contStudent+=1;
	if(contStudent>0)
		printf("\n %d estudiantes",contStudent); 
	else
		printf("\nNo hay estudiantes con estas caracteristicas");
	 
	printf("\n\n\tESTUDIANTES CON EDAD ENTRE 18 Y 25");cont1=0;
	for (i=0;i<1;i++)
	{
		if((student[i].edad>=18)&&(student[i].edad<=25))
			printf("\n\n1er Nombre: %s\n2do Nombre: %s\n1er Apellido: %s\n2do Apellido: %s\nEdad: %d",student[i].name.pNombre,student[i].name.sNombre, student[i].name.pApellido,student[i].name.sApellido, student[i].edad);cont1+=1;
		if(cont1==0)
			printf("\nNo hay estudiantes con esta caracteristica");
	}
}
