#include <stdio.h>
#include <string.h>
int main()
{
	FILE *pf;
	int puntos,cont=1;
	char premio[40],basura;
	pf = fopen("tienda.txt", "w");
	if (pf == NULL) 
	{
	// Si el resultado es NULL mensaje de error 
	printf("Error al abrir el fichero.\n"); 
	return -1; 
	} 
	printf("Inserte el premio %d: ", cont);
	gets(premio);
	while(strcmp(premio, "fin")!=0)
	{
	printf("Indique los puntos necesarios para conseguir %s: ",premio);
	scanf("%d",&puntos);
	scanf("%c",&basura);
	_strupr(premio);
	fprintf(pf, "%s;%d",premio, puntos); 
	cont++;
	printf("Inserte el premio %d: ", cont);
	gets(premio);
	}
	fclose(pf);
	return 0;
}
