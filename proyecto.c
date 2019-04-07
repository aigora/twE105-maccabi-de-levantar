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
	char respuesta[25];
}inicio;

void main ()
{
  //VARIABLES Y FUNCIONES GLOBALES:
  int imprime(char frase[], int s, int e); //funcion imprimir frase con animacion y dar s saltos de linea y e espacios
  int numal(int num1,int num2); //Genera numeros aleatorios 
  void semilla(); //Genera semilla
  
  int salida=0;
  char juego = '0';
  
  //VARIABLES Y FUNCIONES CIFRAS Y LETRAS:
	char eleccion;
	
  //VARIABLES Y FUNCIONES HUNDIR LA FLOTA:
  int imprimematriz(int mat[6][6]);	
  int generarbarco(int n, int mat[6][6], int barco);
  int matrizcons[6][6], i, j; //matriz que representa los barcos del cpu
  int matrizjug[6][6];		  //matriz que representa los barcos del jugador
  
  //VARIABLES Y FUNCIONES TRIVIAL:
   void comprobaSiHaSalidoPregunta(int numpreg[],int i,int iz,int der);
   int comprobarRespuesta(inicio tabla[],int pos,int posicion);	
  while (juego != '1' && juego != '2' && juego != '3' && juego != '4') //preguntar al jugador a que juego quiere jugar
  {
  	 imprime("",1,2);
  	 imprime("\n  BIENVENIDO JUGADOR!",3,3);
  	 imprime("1: Para jugar a Cifras y Letras",2,3);
  	 imprime("2: Para jugar a Hundir La Flota",2,3);
  	 imprime("3: Para jugar al Trivial",2,3);
  	 imprime("4: Para salir del programa",2,3);
     scanf(" %c", &juego);
  switch (juego)
{
	case '1': //JUEGO 1
	{
	do{
    system("cls");
	//Introduccion del juego
	imprime("Bienvenido a Cifras y letras. El juego en el que tendras que combinar ingenio y rapidez",1,0);
	imprime("Instrucciones:",1,0);
	imprime("El juego consiste en elegir Cifras (pulsa c) o Letras (pulsa l).",1,2);
	//Instrucciones juego de cifras
	imprime("El juego de cifras consiste en generar 6 cifras al azar y hallar un numero (o un numero lo mas aproximado posible a ese numero) tambien generado al azar con operaciones. Pero ojo, hay ciertas normas:",1,5);
	imprime("-No puedes repetir ninguna de las 6 cifras",1,5);
	imprime("-Solo puedes usar las operaciones:'+','*','-','/'.",1,5);
	imprime("-Tienes 45 segundos para pensar tu respuesta",1,5);
	imprime("-Tienes que escribir las operaciones correspondientes acompañados del resultado final para ver si no has hecho trampas o has cometido algun error",1,5);
	imprime("-¡Sobre todo disfrutar y pasar un buen rato!",3,2);
	//Instrucciones juego de letras
	imprime("El juego de letras consiste en general 10 letras al azar, aunque el usuario tendra la posibilidad de elegir entre si quiere vocal o consonante, y hallar el nombre de animal mas largo que se puede hacer con esas 10 letras. Pero ojo, hay ciertas normas:",1,5);
	imprime("-No puede repetir ninguna letra, aunque las letras si se pueden repetir a la hora de salir al azar.",1,5);
	imprime("-Todos los nombres de animales que el usuario consiga, tienen que ser reales y conocidos, ya que si el usuario se los inventa no serán considerados como validos",1,5);
	imprime("-Puede escribir en mayusculas o en minusculas indiferentemente",1,5);
	imprime("-El usuario tendra 45 segundos, para escribir el nombre del animal. Si no da una respuesta valida en ese intervalo de tiempo, no conseguira ningun punto y perdera",1,5);
	imprime("-¡Sobre todo disfrutar y pasar un buen rato!",2,0);
	//Elección de cifras o letras
	imprime("Pulse C para jugar cifras o pulse L si quiere jugar letras",1,0);
	scanf(" %c",&eleccion);
	switch (eleccion)
{
	case 'C':
	case 'c':
		{
			system("cls");
			imprime("Bienvenido amante de los numeros. Has elegido cifras.",1,0);
			break;
		}
	case 'L':
	case'l':
		{
			system("cls");
			imprime("Bienvenido fan de la palabra. Has elegido letras.",1,0);
			break;
		}
	default:
		{
			imprime("Tu respuesta no se corresponde con ninguna de las opciones.",2,0);
			break;
		}
}
	imprime("",3,0);
    imprime("Pulsa 0 para volver a jugar o pulsa cualquier otra numero para salir del juego",2,0);
	scanf("%d",&salida);
    system("cls");
} while(salida==0);
    break;
}
    case '2' : //JUEGO HUNDIR LA FLOTA
    {
    do{
	system("cls");
    //Instrucciones
    imprime("",1,3);
    imprime("Bienvenido almirante, la flota espera sus ordenes",2,4);
	imprime("Instrucciones:",2,3);
	imprime("-El objetivo consiste en acabar con los 4 barcos enemigos (portaviones, destructor, bombardero y submarino)",1,3);
    imprime("-Los barcos del enemigo se generan aleatoriamente",1,3);
    imprime("-Al jugador se le pide primero la fila (letra), seguido de la columna (numero)",3,5);
    imprime("Presione cualquier tecla para continuar...",1,0);
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
	generarbarco(5, matrizcons, 5);	//portaviones rellena la matriz de 5
	generarbarco(4, matrizcons, 4);	//destructor rellena la matriz de 4
	generarbarco(3, matrizcons, 3);	//acorazado rellena la matriz de 3
  	generarbarco(2, matrizcons, 2);	//submarino rellena la matriz de 2
  	imprimematriz(matrizcons);
	imprime("",3,0);
	imprimematriz(matrizjug);
	
//Colocacion de barcos por parte del jugador
	imprime("",3,0);
	imprime("Pulsa 0 para volver a jugar o pulse cualquier otra numero para salir del juego",2,0);
	scanf("%d",&salida);
    system("cls");
}while(salida==0);
break;
}
    case '3': //JUEGO 3
    {	
    int i,j,dado[6],numpreg[6],puntuacion=0,salida=0;
	char solucion[20],tirar;
	inicio geografia[]={{"Que pais está entre Peru y Colombia?","ECUADOR"},{"Cual es la capital de Marruecos?","RABAT"},{"Cual es el pais mas visitado del mundo","FRANCIA"},{"En que pais se encuentra el rio Po","ITALIA"},{"En que pais se encuentra la peninsula de Yucatan?","MEXICO"},{"Cual es el oceano que bana las aguas de Sri Lanka?","INDIC"},{"Que nombre recibe un cowboy argentino?","GAUCHO"},{"Cual es la montaña más alta del mundo?","EVEREST"},{"Cual es el idioma mas hablado en Suiza?","ALEMAN"},{"En que hemisferio se encuentra Jamaica?","NORTE"}};
	inicio historia[]={{"De que pais europeo fue colonia Mozambique?","PORTUGAL"},{"Quienes conquistaron Constantinopla (fin del Imperio Bizantino) en 1453?","TURCOS"},{"De que pais se independizo Eslovenia?","YUGOSLAVIA"},{"Que moneda se usaba en España antes de la llegada del euro?","PESETA"},{"En que pais se encuentra la peninsula de Yucatan?","MEXICO"},{"Cual era la ciudad hogar de Marco Polo?","VENECIA"},{"Quien fue el primer presidente de los Estados Unidos?","GEORGE WASHINGTON"},{"Como se llamaba el famoso dictador italiano?","MUSSOLINI"},{"Que pais fue llamado la Galia por los romanos?","FRANCIA"},{"En que ciudad española se realizo el famoso bombardeo de La Legion Condor?","GUERNICA"}};
	inicio deporte[]={{"Que pieza de ajedrez puede hacer un movimiento en forma de L?","CABALLO"},{"Que seleccion de futbol gano el Mundial de Brasil de 2014?","ALEMANIA"},{"Cual es el estilo de natacion mas rapido?","CROL"},{"De donde es el jugador Alexis Sanchez?","CHILE"},{"Cómo se llama el estadio del Betis?","BENITO VILLAMARIN"},{"Como se llama la liga espanola de balonmano?","ASOBAL"},{"Que pais fue el ganador de baloncesto en los Juegos Olimpicos de Londres 2012?","ESTADOS UNIDOS"},{"Cual es la ultima cinta en las artes marciales?","NEGRA"},{"Que le arrojaba antiguamente un caballero a otro para desafiarlo en duelo?","GUANTE"},{"Como se llama el palo utilizado en hockey?","STICK"}};
    inicio ciencia[]={{"Como se llaman las celulas nerviosas?","NEURONAS"},{"Que elemento contienen todos los componentes organicos?","CARBONO"},{"Como se llaman las lineas que unen los puntos de igual temperatura?","ISOBARAS"},{"Cual es el pajaro simbolo de la paz?","PALOMA"},{"En que mes el sol esta mas cerca de la Tierra?","DICIEMBRE"},{"En que parte del cuerpo se encuentra la piel mas gruesa?","ESPALDA"},{"Como se llama la ciencia que estudia la sangre?","HEMATOLOGIA"},{"Cual de los cinco sentidos se desarrolla el primero?","OLFATO"},{"Cual es el dedo mas sensible de la mano?","INDICE"},{"Que fabrico Alessandro Volta, por primera vez, en 1800?","PILA"}};
	inicio arte[]={{"Que escribia un testador?","TESTAMENTOS"},{"Quien escribio Poeta en Nueva York?","FEDERICO GARCIA LORCA"},{"En que ciudad comenzo y termino Phileas Fogg su viaje alrededor del mundo?","LONDRES"},{"Quien era el campanero jorobado de Notre Dame?","QUASIMODO"},{"A que tipo de instrumento pertenece la citara?","CUERDA"},{"En que ciudad espanola se encuentra La casa de las conchas?","SALAMNCA"},{"Quien vivia en el 221B de Backer Street?","SHERLOCK HOLMES"},{"Cual fue el genero mas cultivado por los autores de la generación del 27?","POESIA"},{"Como se llama a la gente que no posee magia en la saga Harry Potter?","MUGGLES"},{"Cual es el genero teatral intermedio entre la comedia y la tragedia ?","DRAMA"}};
	inicio entretenimiento[]={{"Que pelicula creo la palabra magica supercalifragilisticoespialidoso?","MARY POPPINS"},{"Como se llama la ciudad en la que vivia el Mago de Oz?","ESMERALDA"},{"Como se llama el oso mas famoso del parque nacional de Yellowstone?","YOGUI"},{"Cual de los Siete Enanitos no tenia barba?","MUDITO"},{"Que actor espanol protagonizo ?La máscara del Zorro? en 1998?","ANTONIO BANDERAS"},{"Quien fue la primera voz de Mickey Mouse?","WALT DISNEY"},{"Que cancion de Los Beatles ha sido la mas grabada?","YESTERDAY"},{"Quien es la mascota de SEGA?","SONIC"},{"Que actor interpretaba a Hache en la pelicula 3MSC?","MARIO CASAS"},{"Como se llama el protagonista de la saga Indiana Jones?","HARRISON FORD"}};
	int imprime(char frase[],int s, int e); //funcion imprimir frase con animacion
    int numal(int num1,int num2); //Genera numeros aleatorios 
    void semilla(); //Genera semilla
    void ComprobacionPregunta(int numpreg[],int dado[],int i,int iz,int der);
    int Solucion(inicio tabla[],int pos,int posicion);
    system ("cls");
    imprime("Bienvenido concursante, le doy la bienvenida a Trivial, el juego en el que tendras que responder una serie \nde preguntas relacionadas con tematicas como Historia, Geografia, Arte y Literatura, Entretenimiento, \nCiencia y Literatura y Deportes para hacerte con la victoria.",2,0);
    imprime("Para ello, deberas responder un conjunto de de 6 preguntas (+1 plus) y obtener la maxima puntuacion posible.\n\nSeras capaz de conseguir la casi inalcanzable puntuacion de 100 puntos?",2,0);
	imprime("Adelante y buena suerte",2,4);
	imprime("Instrucciones:",2,3);
	imprime("-Antes de cada pregunta lanzaras un dado pulsando enter para elegir aleatoriamente el tema de la pregunta",1,4);
	imprime("+El numero 1 corresponde a la categoria de Geografia",1,4);
	imprime("+El numero 2 corresponde a la categoria de Historia",1,4);
	imprime("+El numero 3 corresponde a la categoria de Deporte",1,4);
	imprime("+El numero 4 corresponde a la categoria de Ciencias y Naturaleza",1,4);
	imprime("+El numero 5 corresponde a la categoria de Arte y Literatura",1,4);
	imprime("+El numero 6 corresponde a la categoria de Entretenimiento",1,3);
	imprime("-Tendras 20 segundos para responder la pregunta",1,3);
	imprime("-No pongas preposiciones y determinantes en las respuestas",1,3);
	imprime("-Es indiferente si la respuesta esta escrita en mayusculas o minusculas",1,3);
	imprime("-No debes poner tildes en las respuestas",2,4);
	imprime("Puntuacion:",2,3);
	imprime("-Cada respuesta acertada sumara un total de 10 puntos",1,3);
	imprime("-Cada respuesta incorrecta restara un total de 5 puntos",1,3);
	imprime("-Cada respuesta no contestada ni sumara ni restara puntos",1,3);
	imprime("BONUS: Por cada racha de preguntas acertadas que consigas se le sumara una pequena cantidad de puntos a tu respuesta",1,4);
	imprime("-La racha de 2 respuestas acertadas le suma un bonus de 2 puntos",1,4);
	imprime("-La racha de 3 respuestas acertadas le suma un bonus de 4 puntos",1,4);
	imprime("-La racha de 4 respuestas acertadas le suma un bonus de 6 puntos",1,4);
	imprime("-La racha de 5 respuestas acertadas le suma un bonus de 8 puntos",1,4);
	imprime("-La racha de 6 respuestas acertadas le suma un bonus de 10 puntos",3,5);
    imprime("Presione cualquier tecla para comenzar el juego...",1,0);
    getch();
    system("cls");
    do{
    imprime("Bienvenido concursante.",2,0);
    for(i=0;i<6;i++)
    {
    	semilla(); // Generamos una semilla para los numeros aleatorios que vamos a utlizar
    	imprime("Pregunta ",0,0);
    	printf("%d:",i+1);
    	imprime("",2,0);
    	imprime("Tire el dado:",1,0);
    	scanf("%c",&tirar);
    	dado[i]=numal(1,6);
    	imprime("El dado ha sacado el numero ",0,0);
    	scanf("%d",dado[i]);
    	imprime("",2,0);
    	switch(dado[i])
    	{
    		case 1:
    			imprime("Pregunta sobre Geografia:",2,0);
    			semilla();
    			numpreg[i]=numal(0,9);
				ComprobacionPregunta(numpreg,dado,i,0,9); //Funcion que nos permite comprobar si la pregunta aleatoria ha salido antes para no voler a repetirla
				puntuacion=Solucion(geografia,numpreg[i],puntuacion); // Funcion que nos permite pedir la solucion del concursante y ver si es correcta o incorrecta y nos devuelve la nueva puntuacion en funcion de ello
    			break;
    		case 2:
    			imprime("Pregunta sobre Historia:",2,0);
    			semilla();
    			numpreg[i]=numal(0,9);
    			ComprobacionPregunta(numpreg,dado,i,0,9);
				puntuacion=Solucion(historia,numpreg[i],puntuacion);
    			break;
    		case 3:
    			imprime("Pregunta sobre Deporte:",2,0);
    			semilla();
    			numpreg[i]=numal(0,9);
    			ComprobacionPregunta(numpreg,dado,i,0,9);
				puntuacion=Solucion(deporte,numpreg[i],puntuacion);
    			break;
    		case 4:
    			imprime("Pregunta sobre Ciencia y Naturaleza:",2,0);
    			semilla();
    			numpreg[i]=numal(0,9);
    			ComprobacionPregunta(numpreg,dado,i,0,9);
				puntuacion=Solucion(ciencia,numpreg[i],puntuacion);
    			break;
    		case 5:
    			imprime("Pregunta sobre Arte y Literatura:",2,0);
    			semilla();
    			numpreg[i]=numal(0,9);
    			ComprobacionPregunta(numpreg,dado,i,0,9);
				puntuacion=Solucion(arte,numpreg[i],puntuacion);
    			break;
    		case 6:
    			imprime("Pregunta sobre Entretenimiento:",2,0);
    			semilla();
    			numpreg[i]=numal(0,9);
    			ComprobacionPregunta(numpreg,dado,i,0,9);
				puntuacion=Solucion(entretenimiento,numpreg[i],puntuacion);
    			break;
		}
		imprime("Presione cualquier tecla para la siguiente pregunta",1,0);
        getch();
        system("cls");
	}
	imprime("Tu puntuacion final es de: ",0,0);
	printf("%d",puntuacion);
	imprime("puntos",3,0);
	if(puntuacion<30)
	{
		imprime("Has perdido, lo siento...",2,0);
		imprime("Pero no te rindas, siempre hay segundas oportunidades",2,0);
		imprime("Pulsa 0 para volver a intentarlo",2,0);
		imprime("Pulsa cualquier otro numero para salir del juego",2,0);
		scanf("%d",&salida);
	}
	else if(puntuacion>=30 && puntuacion<60)
	{
		imprime("Has ganado, enhorabuena concursante!",2,0);
		imprime("Pulsa 0 para volver a jugar",2,0);
		imprime("Pulsa cualquier otra numero para salir del juego",2,0);
		scanf("%d",&salida);
	}
	else
	{
		imprime("Eres una maquina del trivial!",2,0);
		imprime("Enhorabuena por conseguir la maxima puntuacion concursante",2,0);
		imprime("Pulsa 0 para corroborar que eres un genio",2,0);
		imprime("Pulsa cualquier otra numero para salir del juego",2,0);
		scanf("%d",&salida);
	}
	system("cls");
}while(salida==0);
break;
   }
   
   case '4':
   	imprime("",2,3);
	imprime("Has cerrado el programa, hasta la proxima!",1,0);
    break;
    
   default:
   	imprime("",2,6);
    imprime("ERROR: JUEGO NO VALIDO",1,0);
    Sleep(700);
    system("cls");
    break;
   }
}
}
//FUNCIONES GLOBALES

  //Imprime una frase letra por letra con un delay entre ellas
int imprime(char frase[], int s, int e){
	int i= 0;
 while (frase[i] != '\0') 
{
   printf("%c", frase[i]);
   Sleep(30);
   i++;
}
i= 0;
	for (i=0;i<s;i++) 
     printf("\n");
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
int Solucion(inicio tabla[],int pos,int puntuacion)
{
	char solucion[20];
	printf("%s\n\n",tabla[pos].pregunta);
				gets(solucion);
				_strupr(solucion);
				if(strcmp(solucion,tabla[pos].respuesta)==0)
				{
					imprime("",1,0);
					imprime("La respuesta es...",2,0);
					imprime("CORRECTA",2,0);
					puntuacion+=10;
					imprime("Puntuacion actual: ",0,0);
					printf("%d",puntuacion);
					imprime(" puntos",2,0);
				}
				else
				{
					imprime("",1,0);
					imprime("La respuesta es...",2,0);
					imprime("INCORRECTA",2,0);
					puntuacion-=5;
					imprime("Puntuacion actual: ",0,0);
					printf("%d",puntuacion);
					imprime(" puntos",2,0);
				}
				return puntuacion;
}

void ComprobacionPregunta(int numpreg[],int dado[],int i,int iz,int der)
{
	int j;
	numpreg[i]=numal(iz,der);
    		for(j=0;j<i;j++)
    		{
    			if(numpreg[j]==numpreg[i] && dado[i]==dado[j])
    			{
    				numpreg[i]=numal(iz,der);
    				j=-1;
				}
			}
}
