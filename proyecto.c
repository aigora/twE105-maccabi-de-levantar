#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <windows.h>

int main ()
{
  //VARIABLES Y FUNCIONES GLOBALES:
  int imprime(char frase[]); //funcion imprimir frase con animacion
  int salto(int s); //imprimir \n
  int espacio(int e);
  
  int juego = 0;
  
  //VARIABLES Y FUNCIONES CIFRAS Y LETRAS:
 
  //VARIABLES Y FUNCIONES HUNDIR LA FLOTA:
  int tableroconsola[6][6],filacons, columcons,i,j;
  //VARIABLES Y FUNCIONES TRIVIAL:	
  
  while (juego == 0) //preguntar al jugador a que juego quiere jugar
  {
  	 salto(1);
  	 espacio(2);
  	 imprime("BIENVENIDO JUGADOR!");
  	 salto(3);
  	 espacio(3);
  	 imprime("Escriba 1 para jugar a Cifras y Letras");
  	 salto(2);
  	 espacio(3);
  	 imprime("Escriba 2 para jugar a Hundir La Flota");
  	 salto(2);
  	 espacio(3);
  	 imprime("Escriba 3 para jugar al Trivial");
  	 salto(2);
  	 espacio(3);
  	 
     scanf("%d", &juego);
     
     if (juego != 1 && juego != 2 && juego != 3)
     {
     	salto(2);
  	    espacio(6);
     	printf("ERROR: JUEGO NO VALIDO\n");
     	Sleep(700);
     	system("cls");
     	juego = 0;
	 }
  }
  
  switch (juego)
{
	case 1: //JUEGO 2
	{
	
printf("¡BIENVENIDO AL JUEGO 1!"); 

    break;
}

    case 2 : //JUEGO HUNDIR LA FLOTA
    {
	
    system("cls");
//Instrucciones
    salto(1);
    espacio(3);
    imprime("Bienvenido camarada, le deseo mucha suerte en su mision");
    salto(2);
    espacio(4);
	printf("Instrucciones:");
	salto(2);
	espacio(3);
	imprime("-El objetivo consiste en acabar con los 4 barcos enemigos (portaviones, destructor, bombardero y submarino)");
    salto(1);
    espacio(3);
    imprime("-Los barcos del enemigo se generan aleatoriamente");
    salto(1);
    espacio(3);
    imprime("-Al jugador se le pide primero la fila (letra), seguido de la columna (numero)");
    salto(3);
    espacio(5);
    imprime("Presione cualquier tecla para continuar...");
    salto(1);
    getch();
    system("cls");
//Generar barcos consola    
	//portaviones
	

break;
}

    case 3: //JUEGO 3
    {
	
printf("¡BIENVENIDO AL JUEGO 3!");

break;
}

}
  
   return 0;
}



//FUNCIONES GLOBALES

  //Imprime una frase letra por letra con un delay entre ellas
int imprime(char frase[]){
	int i= 0;
 while (frase[i] != '\0') 
{
   printf("%c", frase[i]);
   Sleep(30);
   i++;
}
}

  //Imprime los saltos de linea deseados
int salto(int s){
	int i= 0;
	for (i=0;i<s;i++) 
     printf("\n");
}

  //Imprime los espacios deseados
int espacio(int e){
	
	int i= 0;
	for (i=0;i<e;i++) 
     printf(" ");
}

//FUNCIONES CIFRAS Y LETRAS:
 
//FUNCIONES HUNDIR LA FLOTA:
  
//FUNCIONES TRIVIAL:
