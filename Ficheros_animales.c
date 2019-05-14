#include <stdio.h>
#include <string.h>
int main()
{
	FILE *sac;
	int puntos,cont=1;
	char animal[40];
	sac = fopen("animales.txt", "w");
	if (sac == NULL) 
	{
	// Si el resultado es NULL mensaje de error 
	printf("Error al abrir el fichero.\n"); 
	return -1; 
	} 
	//Empiezo a meter nombres de animales
	printf("Inserte el animal %d: ", cont);
	gets(animal);
	//Creo bucle para repetir la operacion, cuando quiera acabar escribo fin
	while(strcmp(animal, "fin")!=0)
	{
	_strupr(animal);
	fprintf(sac, "%s;",animal); 
	cont++;
	printf("Inserte el animal %d: ", cont);
	gets(animal);
	}
	fclose(sac);
	return 0;
}
