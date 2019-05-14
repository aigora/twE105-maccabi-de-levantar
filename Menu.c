#include <stdio.h>
#include <stdlib.h>
void main()
{
//VARIABLES Y FUNCIONES GLOBALES:
  int imprime(char frase[]); //funcion imprimir frase con animacion
  int salto(int s); //imprimir \n
  int espacio(int e); // imprimir \t
  int numal(int num1,int num2); //Genera numeros aleatorios 
  void semilla(); //Genera semilla
  int juego,eleccion,salida=0,i,dado[6],numpreg[6];
  while(juego!=4)
  {
    salto(1);
    espacio(2);
    imprime("BIENVENIDO JUGADOR!");
  	salto(3);
  	espacio(3);
  	imprime("1: Para jugar a Cifras y Letras");
  	salto(2);
  	espacio(3);
  	imprime("2: Para jugar a Hundir La Flota");
  	salto(2);
  	espacio(3);
  	imprime("3: Para jugar al Trivial");
  	salto(2);
  	espacio(3);
  	imprime("4: Para salir del programa");
  	salto(2);
  	espacio(3);
  	scanf("%d", &juego);
  	switch(juego)
  	{
  		case 1: //JUEGO 1
	{
		do
		{
    system("cls");
	//Introduccion del juego
	imprime("Bienvenido a Cifras y letras. El juego en el que tendras que combinar ingenio y rapdidez");
	salto(1);
	imprime("Instrucciones:");
	salto(1);
	imprime("El juego consiste en elegir Cifras (pulsa c) o Letras (pulsa l).");
	salto(1);
	//Instrucciones juego de cifras
	//Elección de cifras o letras
	imprime("Pulse C para jugar cifras o pulse L si quiere jugar letras: ");
	salto(1);
	scanf(" %c",&eleccion);
	switch (eleccion)
   {
	case 'C':
	case 'c':
		{
			system("cls");
			imprime("Bienvenido amante de los numeros. Has elegido cifras.\n");
			//Juego de cifras
			break;
		}
	case 'L':
	case'l':
		{
			system("cls");
			imprime("Bienvenido fan de la palabra. Has elegido letras.\n");
			//Juego de letras
			break;
		}
	default:
		{
			imprime("Tu respuesta no se corresponde a ninguna de las opciones.\n");
			salto(1);
			break;
		}
	}
	imprime("Pulsa 0 para volver a jugar o pulsa cualquier otra numero para salir del juego");
	salto(2);
	scanf("%d",&salida);
    system("cls");
}while(salida==0);
break;
}
    case 2 : //JUEGO HUNDIR LA FLOTA
    {
    	do
    	{
		
	system("cls");
//Instrucciones
    salto(1);
    espacio(3);
    imprime("Bienvenido almirante, la flota espera sus ordenes");
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
    espacio(3);
    //llenar de 0 las matriz
    //Generar barcos consola 
    //Colocacion de barcos por parte del jugador
    //Mientras que alguno de los dos tenga barcos vivos, la consola dispara aleatoriamente y consecutivamente el ordenador
    //Si el jugador gana devuelve un 0 y si pierde otro numero aleatorio
    imprime("Pulsa 0 para volver a jugar o pulse cualquier otra numero para salir del juego");
	salto(2);
	scanf("%d",&salida);
    system("cls");
}while(salida==0);
	break;
    }
    case 3:
    {
    	do
    	{
    system ("cls");
    imprime("Bienvenido concursante, le doy la bienvenida a Trivial, el juego en el que tendras que responder una serie \nde preguntas relacionadas con tematicas como Historia, Geografia, Arte y Literatura, Entretenimiento, \nCiencia y Literatura y Deportes para hacerte con la victoria.");
    salto(2);
    imprime("Para ello, deberas responder un conjunto de de 6 preguntas (+1 plus) y obtener la maxima puntuacion posible.\n\nSeras capaz de conseguir la casi inalcanzable puntuacion de 100 puntos?");
	salto(2);
	imprime("Adelante y buena suerte");
	salto(2);
    espacio(4);
	//Instrucciones del juego.
    //Generamos 6 preguntas al azar una pregunta aleatoria mediante un dado (de 6 caras)
    getch();
    semilla();
    dado[i]=numal(1,6);
    printf("El dado ha sacado el numero %d.\n\n",dado[i]);
    	switch(dado[i])
    	{
    		case 1:
    			imprime("Pregunta sobre Geografia:\n\n");
    			semilla();
    			numpreg[i]=numal(0,9);
				//Funcion que nos permite comprobar si la pregunta aleatoria ha salido antes para no voler a repetirla
				// Funcion que nos permite pedir la solucion del concursante y ver si es correcta o incorrecta y nos devuelve la nueva puntuacion en funcion de ello
    			break;
    		case 2:
    			imprime("Pregunta sobre Historia:\n\n");
    			semilla();
    			numpreg[i]=numal(0,9);
    			//Funcion que nos permite comprobar si la pregunta aleatoria ha salido antes para no voler a repetirla
				// Funcion que nos permite pedir la solucion del concursante y ver si es correcta o incorrecta y nos devuelve la nueva puntuacion en funcion de ello
    			break;
    		case 3:
    			imprime("Pregunta sobre Deporte:\n\n");
    			semilla();
    			numpreg[i]=numal(0,9);
    			//Funcion que nos permite comprobar si la pregunta aleatoria ha salido antes para no voler a repetirla
				// Funcion que nos permite pedir la solucion del concursante y ver si es correcta o incorrecta y nos devuelve la nueva puntuacion en funcion de ello
    			break;
    		case 4:
    			imprime("Pregunta sobre Ciencia y Naturaleza:\n\n");
    			semilla();
    			numpreg[i]=numal(0,9);
    			//Funcion que nos permite comprobar si la pregunta aleatoria ha salido antes para no voler a repetirla
				// Funcion que nos permite pedir la solucion del concursante y ver si es correcta o incorrecta y nos devuelve la nueva puntuacion en funcion de ello
    			break;
    		case 5:
    			imprime("Pregunta sobre Arte y Literatura:\n\n");
    			semilla();
    			numpreg[i]=numal(0,9);
    			//Funcion que nos permite comprobar si la pregunta aleatoria ha salido antes para no voler a repetirla
				// Funcion que nos permite pedir la solucion del concursante y ver si es correcta o incorrecta y nos devuelve la nueva puntuacion en funcion de ello
    			break;
    		case 6:
    			imprime("Pregunta sobre Entretenimiento:\n\n");
    			semilla();
    			numpreg[i]=numal(0,9);
    			//Funcion que nos permite comprobar si la pregunta aleatoria ha salido antes para no voler a repetirla
				// Funcion que nos permite pedir la solucion del concursante y ver si es correcta o incorrecta y nos devuelve la nueva puntuacion en funcion de ello
    			break;
		}
    //Cuando se terminen las 6 preguntas el programa sumara la puntuacion total y en funcion de ella te dira si has ganado o perdido
    imprime("Pulsa 0 para volver a jugar o pulse cualquier otra numero para salir del juego");
	salto(2);
	scanf("%d",&salida);
	system("cls");
}while(salida==0);
	break;
	}
	case 4:
	salto(2);
  	espacio(3);
	imprime("Has cerrado el programa, hasta la proxima!\n");
    break;
	default:
		salto(2);
  	    espacio(6);
     	printf("ERROR: JUEGO NO VALIDO\n");
     	Sleep(700);
     	system("cls");
     	break;
}
}
}
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
