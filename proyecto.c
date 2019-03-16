#include <stdio.h>
#include <string.h>
#include <math.h>

int main ()
{
  //VARIABLES GLOBALES:
  int juego = 0;
  
  //VARIABLES JUEGO 1:
  
  //VARIABLES JUEGO 2:
  
  //VARIABLES JUEGO 3:	
  
  while (juego == 0) //preguntar al jugador a que juego quiere jugar
  {
  	 printf("BIENVENIDO JUGADOR!\nEscriba 1 para jugar al\nEscriba 2 para jugar al\nEscriba 3 para jugar al\n");
     scanf("%d", &juego);
     
     if (juego != 1 && juego != 2 && juego != 3)
     {
     	printf("Juego no valido\n");
     	juego = 0;
	 }
  }
  
  switch (juego)
{
case 1: //JUEGO 1
printf("¡BIENVENIDO AL JUEGO 1!");

break;

case 2: //JUEGO 2
printf("¡BIENVENIDO AL JUEGO 2!");

break;

case 3: //JUEGO 3
printf("¡BIENVENIDO AL JUEGO 3!");

break;

}
  
   return 0;
}
