#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

typedef struct
{
	char pregunta[80];
	char respuesta[20];
}inicio;

int main ()
{
  //VARIABLES Y FUNCIONES GLOBALES:
  int imprime(char frase[]); //funcion imprimir frase con animacion
  int salto(int s); //imprimir \n
  int espacio(int e); // imprimir \t
  int numal(int num1,int num2); //Genera numeros aleatorios 
  void semilla(); //Genera semilla
  
  int juego = 0;
  
  //VARIABLES Y FUNCIONES CIFRAS Y LETRAS:
 
  //VARIABLES Y FUNCIONES HUNDIR LA FLOTA:
  int imprimematriz(int mat[6][6]);	
  int generarbarco(int n, int mat[6][6], int barco);
  
  int matrizcons[6][6], i, j; //matriz que representa los barcos del cpu
  int matrizjug[6][6];		  //matriz que representa los barcos del jugador
  
  //VARIABLES Y FUNCIONES TRIVIAL:
   void comprobaSiHaSalidoPregunta(int numpreg[],int i,int iz,int der);
   int comprobarRespuesta(inicio tabla[],int pos,int posicion);	
   
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
	case 1: //JUEGO 1
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
	imprime("-El objetivo consiste en acabar con los 4 barcos enemigos (portaviones, destructor, acorazado y submarino)");
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
    
//llenar de 0 las matriz
	for (i=0; i<6; i++)
		{
			for (j=0; j<6; j++)
				{
				matrizcons[i][j] = 0; 
				matrizjug[i][j] = 0;
				}
		}
	srand (time(NULL)); 
	
//Generar barcos consola 	
	generarbarco(5, matrizcons, 5);	//portaviones
	generarbarco(4, matrizcons, 4);	//destructor
	generarbarco(3, matrizcons, 3);	//acorazado
  	generarbarco(2, matrizcons, 2);	//submarino
  	
	imprimematriz(matrizcons);
	salto(3);
	imprimematriz(matrizjug);
	
//Colocacion de barcos por parte del jugador
	

break;
}

    case 3: //JUEGO 3
    {	
    int i,j,dado,puntuacion=0;
	int numpreg[6];
	char tirar;
	char solucion[20];
	inicio geografia[]={{"Que pais está entre Peru y Colombia?","ECUADOR"},{"Cual es la capital de Marruecos?","RABAT"},{"Cual es el pais mas visitado del mundo","FRANCIA"},{"En que pais se encuentra el rio Po","ITALIA"},{"En que pais se encuentra la peninsula de Yucatan?","MEXICO"},{"Cual es el oceano que bana las aguas de Sri Lanka?","INDIC"},{"Que nombre recibe un cowboy argentino?","GAUCHO"},{"Cual es la montaña más alta del mundo?","EVEREST"},{"Cual es el idioma mas hablado en Suiza?","ALEMAN"},{"En que hemisferio se encuentra Jamaica?","NORTE"}};
	inicio historia[]={{"De que pais europeo fue colonia Mozambique?","PORTUGAL"},{"Quienes conquistaron Constantinopla (fin delI mperio Bizantino) en 1453?","TURCOS"},{"De que pais se independizo Eslovenia?","YUGOSLAVIA"},{"Que moneda se usaba en España antes de la llegada del euro?","PESETA"},{"En que pais se encuentra la peninsula de Yucatan?","MEXICO"},{"Cual era la ciudad hogar de Marco Polo?","VENECIA"},{"Quien fue el primer presidente de los Estados Unidos??","GEORGE WASHINGTON"},{"Como se llamaba el famoso dictador italiano?","MUSSOLINI"},{"Que pais fue llamado la Galia por los romanos?","FRANCIA"},{"En que ciudad española se realizo el famoso bombardeo de La Legion Condor?","GUERNICA"}};
	inicio deporte[]={{"Que pieza de ajedrez puede hacer un movimiento en forma de L?","CABALLO"},{"Que seleccion de futbol gano el Mundial de Brasil de 2014?","ALEMANIA"},{"Cual es el estilo de natacion mas rapido?","CROL"},{"De donde es el jugador Alexis Sanchez?","CHILE"},{"Cómo se llama el estadio del Betis?","BENITO VILLAMARIN"},{"Como se llama la liga española de balonmano?","ASOBAL"},{"Que pais fue el ganador de baloncesto en los Juegos Olimpicos de Londres 2012?","ESTADOS UNIDOS"},{"Cual es la ultima cinta en las artes marciales?","NEGRA"},{"Que le arrojaba antiguamente un caballero a otro para desafiarlo en duelo?","GUANTE"},{"Como se llama el palo utilizado en hockey?","STICK"}};
    system ("cls");
    imprime("Bienvenido concursante, le doy la bienvenida a Trivial, el juego en el que tendras que responder una serie \nde preguntas relacionadas con tematicas como Historia, Geografia, Arte y Literatura, Entretenimiento, \nCiencia y Literatura y Deportes para hacerte con la victoria.");
    salto(2);
    imprime("Para ello, deberas responder un conjunto de de 6 preguntas (+1 plus) y obtener la maxima puntuacion posible.\n\nSeras capaz de conseguir la casi inalcanzable puntuacion de 100 puntos?");
	salto(2);
	imprime("Adelante y buena suerte");
	salto(2);
    espacio(4);
	printf("Instrucciones:");
	salto(2);
	espacio(3);
	imprime("-Antes de cada pregunta lanzaras un dado pulsando cualquier tecla para elegir aleatoriamente el tema de la pregunta");
	salto(1);
	espacio(4);
	imprime("+El numero 1 corresponde a la categoria de Geografia");
	salto(1);
	espacio(4);
	imprime("+El numero 2 corresponde a la categoria de Historia");
	salto(1);
	espacio(4);
	imprime("+El numero 3 corresponde a la categoria de Deporte");
	salto(1);
	espacio(4);
	imprime("+El numero 4 corresponde a la categoria de Ciencias y Naturaleza");
	salto(1);
	espacio(4);
	imprime("+El numero 5 corresponde a la categoria de Arte y Literatura");
	salto(1);
	espacio(4);
	imprime("+El numero 6 corresponde a la categoria de Entretenimiento");
	salto(1);
	espacio(3);
	imprime("-Tendras 20 segundos para responder la pregunta");
	salto(1);
	espacio(3);
	imprime("-No pongas preposiciones en las respuestas");
	salto(1);
	espacio(3);
	imprime("-Es indiferente si la respuesta esta escrita en mayusculas o minusculas");
	salto(1);
	espacio(3);
	imprime("-No debes poner tildes en las respuestas");
	salto(2);
    espacio(4);
	printf("Puntuacion:");
	salto(2);
	espacio(3);
	imprime("-Cada respuesta acertada sumara un total de 10 puntos");
	salto(1);
	espacio(3);
	imprime("-Cada respuesta incorrecta restara un total de 5 puntos");
	salto(1);
	espacio(3);
	imprime("-Cada respuesta no contestada ni sumara ni restara puntos");
	salto(1);
	espacio(3);
	imprime("BONUS: Por cada racha de preguntas acertadas que consigas se le sumara una pequena cantidad de puntos a tu respuesta");
	salto(1);
	espacio(4);
	imprime("-La racha de 2 respuestas acertadas le suma un bonus de 2 puntos");
	salto(1);
	espacio(4);
	imprime("-La racha de 3 respuestas acertadas le suma un bonus de 4 puntos");
	salto(1);
	espacio(4);
	imprime("-La racha de 4 respuestas acertadas le suma un bonus de 6 puntos");
	salto(1);
	espacio(4);
	imprime("-La racha de 5 respuestas acertadas le suma un bonus de 8 puntos");
	salto(1);
	espacio(4);
	imprime("-La racha de 6 respuestas acertadas le suma un bonus de 10 puntos");
	salto(3);
    espacio(5);
    imprime("Presione cualquier tecla para comenzar el juego...");
    salto(1);
    getch();
    system("cls");
    imprime("Bienvenido concursante.");
    salto(2);
    for(i=0;i<6;i++)
    {
    	imprime("Tire el dado:\n");
    	scanf("%c",&tirar);
    	dado=numal(1,6);
    	printf("El dado ha sacado el numero %d.\n\n",dado);
    	switch(dado)
    	{
    		case 1:
    			imprime("Pregunta sobre Geografia:\n\n");
    			semilla(); // Generamos una semilla para los numeros aleatorios que despues vamos a utlizar
    			numpreg[i]=numal(0,9);
    			/*for(j=1;j<=i+1;j++)
    			{
    				if(numpreg[j-1]==numpreg[i])
    				{
    					numpreg[i]=numal(0,9);
    					j=0;
					}
				}*/
				comprobaSiHaSalidoPregunta(numpreg,i,0,9);
				puntuacion=comprobarRespuesta(geografia,numpreg[i],puntuacion);
			/*	printf("%s\n",geografia[numpreg[i]].pregunta);
				gets(solucion);
				if(strcmp(solucion,geografia[numpreg[i]].respuesta)==0)
				{
					imprime("La respuesta es...\n");
					imprime("CORRECTA\n");
					puntuacion+=10;
					printf("Puntuacion actual: %d puntos\n",puntuacion);
				}
				else
				{
					imprime("La respuesta es...\n");
					imprime("INCORRECTA\n");
					puntuacion-=5;
					printf("Puntuacion actual: %d puntos\n",puntuacion);
				}*/
    			break;
    		case 2:
    			imprime("Pregunta sobre Historia:\n\n");
    			numpreg[i]=numal(10,19);
    			break;
    		case 3:
    			imprime("Pregunta sobre Deporte:\n\n");
    			numpreg[i]=numal(20,29);
    			break;
    		case 4:
    			imprime("Pregunta sobre Ciencia y Naturaleza:\n\n");
    			numpreg[i]=numal(30,39);
    			break;
    		case 5:
    			imprime("Pregunta sobre Arte y Literatura:\n\n");
    			numpreg[i]=numal(40,49);
    			break;
    		case 6:
    			imprime("Pregunta sobre Entretenimiento:\n\n");
    			numpreg[i]=numal(50,59);
    			break;
	     }
     }
   }
}
return 0;
}

//FUNCIONES GLOBALES

  //Imprime una frase letra por letra con un delay entre ellas
int imprime(char frase[])
{
	int i= 0;
	while (frase[i] != '\0') 
		{
   		printf("%c", frase[i]);
   		Sleep(30);
   		i++;
		}
}

  //Imprime los saltos de linea deseados
int salto(int s)
{
	int i= 0;
	for (i=0;i<s;i++) 
     printf("\n");
}

  //Imprime los espacios deseados
int espacio(int e)
{
	int i= 0;
	for (i=0;i<e;i++) 
    printf(" ");
}
 // Genera una semilla para generar un numero aleatorio
 void semilla()
 {
 	srand(time(NULL));
 }
 // Genera numeros aleatorios en el intervalo deseado
 int numal(int num1,int num2)
 {
 	int numero;
 	numero= rand() % (num2-num1+1) + num1;
 	return numero;
 }

//FUNCIONES CIFRAS Y LETRAS:
 
//FUNCIONES HUNDIR LA FLOTA:
int generarbarco(int n, int mat[6][6], int barco)
{
	int fila, colum, dir, exito = 0, okupa, i;
	
while(exito==0)
{
	fila = rand() % (5+1);
	colum = rand() % (5+1);
	dir = rand () % (4-1+1) + 1;
	okupa=0;
 
if(dir==1)							//direccion arriba
{
  if(fila >= (n-1))
  	{ 
	  for(i=fila;i>=(fila-n+1);i--)  
	      	{
	      	if(mat[i][colum]!=0)
	    		{
	    		okupa++;
				}
	      	}
	    if(okupa == 0)
	   {
  	  		for(i=fila;i>=(fila-n+1);i--)  
	      		{
	    		mat[i][colum]=barco;
	      		}
	   		exito++;
	   }
	}
}

if(dir==2)							//direccion derecha
{
  if(colum + n <= 6)
  	{ 
	  for(i=colum;i<=(colum+n-1);i++)  
	      	{
	      	if(mat[fila][i]!=0)
	    		{
	    		okupa++;
				}
	      	}
	    if(okupa == 0)
	   {
  	  		for(i=colum;i<=(colum+n-1);i++)  
	      		{
	    		mat[fila][i]=barco;
	      		}
	   		exito++;
	   }
	}
}
	  
if(dir==3)							//direccion abajo
{
  if(fila + n <= 6)
  	{ 
	  for(i=fila;i<=fila+n-1;i++)  
			{
	    	if(mat[i][colum]!=0)
	    		{
	    		okupa++;
				}
	   	    }
	    if(okupa == 0)
	   		{
  	  		for(i=fila;i<=fila+n-1;i++)  
	      		{
	    		mat[i][colum]=barco;
	      		}
	   		exito++;
	   		}
	}
}

if(dir==4)							//direccion izquierda
{
  if(colum + 1 >= n)
  	{ 
	  for(i=colum;i>=(colum-n+1);i--)  
	      	{
	      		if(mat[fila][i]!=0)
	    			{
	    				okupa++;
					}
	      	}
	    if(okupa == 0)
	   		{
			   for(i=colum;i>=(colum-n+1);i--)  
	      			{
	    			mat[fila][i]=barco;
	      			}
	   			exito++;
	   		}
	}
}
}

}
int imprimematriz(int mat[6][6])
{
    int i,j;
	for(i=0;i<6;i++)  
	      {
	      	for(j=0;j<6;j++)
	      	{
	      		printf("%i ",mat[i][j]);
			  }
			    printf("\n",i);
	      }	
}
  
//FUNCIONES TRIVIAL:
int comprobarRespuesta(inicio tabla[],int pos,int puntuacion)
{
	char solucion[20];
	printf("%s\n",tabla[pos].pregunta);
				gets(solucion);
				if(strcmp(solucion,tabla[pos].respuesta)==0)
				{
					imprime("La respuesta es...\n");
					imprime("CORRECTA\n");
					puntuacion+=10;
					printf("Puntuacion actual: %d puntos\n",puntuacion);
				}
				else
				{
					imprime("La respuesta es...\n");
					imprime("INCORRECTA\n");
					puntuacion-=5;
					printf("Puntuacion actual: %d puntos\n",puntuacion);
				}
				return puntuacion;
}
void comprobaSiHaSalidoPregunta(int numpreg[],int i,int iz,int der)
{
	int j;
	numpreg[i]=numal(iz,der);
    		for(j=0;j<i;j++)
    		{
    			
    			if(numpreg[j]==numpreg[i])
    			{
    				numpreg[i]=numal(iz,der);
    				j=-1;
				}
			}
}
