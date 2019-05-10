#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

//ESTRUCTURA TRIVIAL
typedef struct
{
	char pregunta[80];
	char respuesta[25];
}inicio;

//VARIABLES Y FUNCIONES GLOBALES:
int imprime(char frase[], int s, int e); //funcion imprimir frase con animacion y dar s saltos de linea y e espacios
int numal(int num1,int num2); //Genera numeros aleatorios 
void semilla(); //Genera semilla
int cifrasyletras();
int hundirlaflota();
int trivial();
void tienda();
int instrucciones();
void listanimales();
void listatienda();
  
void main ()
{
FILE *us,*aux;
int salida=0,juego=0,administrador=0,puntuacion,punt,bandera;
char basura,admin[14],usuario[25],nombre[25],kudu[3];

imprime("",1,2);
imprime("Por favor, indica si eres jugador o administrador:",1,2);
scanf("%s",admin);
_strupr(admin);
system("cls");
while(strcmp(admin,"ADMINISTRADOR")!=0 && strcmp(admin,"JUGADOR")!=0)
{
	imprime("",1,2);
	imprime("Recuerda que tienes que escribir administrador o jugador",1,2);
	scanf("%s",admin);
	_strupr(admin);
	system("cls");
}
if(strcmp(admin,"ADMINISTRADOR")==0)
{
	while(administrador!=3)
	{
	imprime("",1,2);
  	imprime("BIENVENIDO ADMINISTRADOR",3,3);
  	imprime("Pulsa:",2,3);
  	imprime("1: Para aceder a la tienda",2,3);
  	imprime("2: Para acceder a la lista de animales",2,3);
  	imprime("3: Para salir del programa",2,3);
  	scanf(" %d", &administrador);
    scanf("%c",&basura);
    
    switch(administrador)
    {
    	case 1:
    		system("cls");
    		imprime("Al meterte en esta opcion, se borrara la informacion almacenada previamente, estas seguro?",1,0);
			scanf("%s",kudu);
			_strupr(kudu);
			while(strcmp(kudu,"SI")!=0 && strcmp(kudu,"NO")!=0)
			{	
				imprime("No me has contestado a la pregunta",2,0);
				imprime("Al meterte en esta opcion, se borrara la informacion almacenada previamente, estas seguro?",1,0);
				scanf("%s",kudu);
			}
			if(strcmp(kudu,"SI")==0){
    	    	listatienda();
    			}	
    	    break;
    	case 2:
    		system("cls");
    		imprime("Al meterte en esta opcion, se borrara la informacion almacenada previamente, estas seguro?",1,0);
			scanf("%s",kudu);
			_strupr(kudu);
			while(strcmp(kudu,"SI")!=0 && strcmp(kudu,"NO")!=0)
			{	
			imprime("No me has contestado a la pregunta",2,0);
			imprime("Al meterte en esta opcion, se borrara la informacion almacenada previamente, estas seguro?",1,0);
			scanf("%s",kudu);
			}
			if(strcmp(kudu,"SI")==0){
    	    	listanimales();
    		}
    	    break;
    	case 3:
    		imprime("",2,3);
	        imprime("Has cerrado el programa, hasta la proxima!",1,0);
            break;
        default:
   	        imprime("",2,6);
            imprime("ERROR: OPCION NO VALIDA",1,0);
            Sleep(700);
            system("cls");
            break;
	}
    }
}
else if(strcmp(admin,"JUGADOR")==0)
{
	imprime("Como te llamas?",2,0);
	scanf("%c",&basura);
	gets(usuario);
	_strupr(usuario);
	us = fopen("usuarios.txt", "r"); 
	if (us == NULL) { 
	us = fopen("usuarios.txt", "w");
	fclose(us); 
	 } 
	 else
	 {
	 	bandera=1;
	 	while(bandera==1&&fscanf(us,"%[^;];%d",nombre,&puntuacion)!=EOF)
	 	{
	 		if(strcmp(nombre,usuario)==0)
	 		{
	 			bandera=0;	
			}
		 }
		 fclose(us);
		 if(bandera==1)
		 {
		 	imprime("Es un nuevo usuario, bienvenido",2,0);
		 	imprime("Tu nueva puntuacion es 0",2,0);
		 	puntuacion=0;
		 }
		 else
		 {
		 	imprime("Bienvenido de nuevo ",0,0);
		 	printf("%s",usuario);
		 	imprime(",su puntuacion es",0,0);
		 	printf("%d\n\n",puntuacion);
		 }
	 }

    while (juego!=5) //preguntar al jugador a que juego quiere jugar
{
	system("cls");
  	imprime("",1,2);
  	imprime("BIENVENIDO JUGADOR!",3,3);
  	imprime("Pulsa:",2,3);
  	imprime("1: Para jugar a Cifras y Letras",2,3);
  	imprime("2: Para jugar a Hundir La Flota",2,3);
  	imprime("3: Para jugar al Trivial",2,3);
  	imprime("4: Para abrir la tienda",2,3);
  	imprime("5: Para salir del programa",2,3);
    scanf(" %d", &juego);
    scanf("%c",&basura);
     
  switch (juego)
{
	
	case 1: //JUEGO 1
	do
	{
        salida=cifrasyletras();
        
	}while(salida==0);
    break;

    case 2: //JUEGO HUNDIR LA FLOTA
    do
	{
        salida=hundirlaflota();
   	}while(salida==0);
	break;

    case 3: //JUEGO TRIVIAL
    do
	{
        salida=trivial();
	}while(salida==0);
    break;
    
    case 4: //TIENDA
{	
    tienda();
    break;
}
   
    case 5:
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
us = fopen("usuarios.txt", "r"); 
aux= fopen("auxiliar.txt", "w");
puntuacion=60;
bandera=0;
while(fscanf(us,"%[^;];%d",nombre,&punt)!=EOF)
	 	{
	 		if(strcmp(nombre,usuario)==0)
	 		{
	 			bandera=1;
	 			punt=puntuacion;
			}
			fprintf(aux,"%s;%d",nombre,punt);
		 }
		 printf("%d %s",puntuacion,usuario);
		 if(bandera==0)
		fprintf(aux,"%s;%d",usuario,puntuacion);
		fclose(us);
	    fclose(aux);
		if(remove("usuarios.txt")==0) // Eliminamos el archivo
        printf("El archivo fue eliminado satisfactoriamente\n");
        else
        printf("No se pudo eliminar el archivo\n");
        
        if(rename("auxiliar.txt","usuarios.txt")==0)// Renombramos el archivo
        printf("El archivo se renombro satisfactoriamente\n");
        else
        printf("No se pudo renombrar el archivo\n");
}
}
int cifrasyletras()
{
	//Variables cifras y letras
int compraleat(int v[],int num);//Comprueba si los numeros pertenecen a los numeros aleatorios.
int comprganador(int obj,int candid);//Comprueba si el numero es el numero ganador
int comprop( char oper);//Comprueba si el operador es correcto
int calculadora(int num1,char cop,int num2);
char eleccion,instr,op;
int i,j,numaleatorio,numobj,cos1,cos2,cos3,cos4,cos5,cos6,cos7,cos8,cos9,cos10,compr1,compr2,compr3,res1,res2,res3,res4,res5,resdef,ganad,resop,punts,contador=0,salida=0;
int numaleat[6],auxnumaleat[5],auxnumaleat2[4],auxnumaleat3[3],auxnumaleat4[2],auxnumaleat5[1];
int flag=0,turra;
	//JUEGO:
	//Introduccion del juego
	system("cls");
	imprime("Bienvenido a Cifras y letras. El juego en el que tendras que combinar ingenio y rapidez",2,0);
	turra=instrucciones();
	imprime("",1,0);
	//Eleccion de querer o no las instrucciones
	if (turra==0){
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
		imprime("Presione cualquier tecla para continuar...",1,0);
        getch();
		system("cls");
	}
	//Elección de cifras o letras
	imprime("Pulse C para jugar cifras o pulse L si quiere jugar letras",1,0);
	scanf(" %c",&eleccion);
	switch (eleccion){
	//Codigo de cifras
	case 'C':
	case 'c':
		{
			system("cls");
			imprime("Bienvenido amante de los numeros. Has elegido cifras.",1,0);
			imprime("Los numeros con los que tienes que jugar son: ",1,0);
			//genero 6 numeros aleatorios para hallar el objetivo
			semilla();
			for(i=0;i<6;i++){
				numaleat[i]=rand()%20 +1;
				printf("%i\n",numaleat[i]);
			}
			//Hallo el numero objetivo
			numobj= numal(120,500);
			imprime("El numero que tienes que hallar con las operaciones es: ",1,0);
			printf("%i\n",numobj);
			imprime("Al terminar este mensaje comienzan los 45 segundos. Escribe a continuacion todas las operaciones. Suerte",1,0);
			//Durante los 45 segundos escribimos las operaciones que realice el usuario
			//Primera operacion
				//Compruebo si el primer numero esta en el vector de numeros aleatorios
			do{
				scanf(" %i",&cos1);
			}while(compraleat(numaleat,cos1)==0);
				//Compruebo si el operador es de los 4 validos
			do{
				scanf(" %c",&op);
				resop= comprop(op);
			}while(resop==0);
				//Compruebo si el segundo numero esta en el vector de numeros aleatorios
			do{
				scanf("%i",&cos2);
			}while(compraleat(numaleat,cos2)==0);
			//Hallo resultado de la operacion que hace el usuario y
			//Compruebo si el numero es el que buscamos
			res1=calculadora(cos1,op,cos2);
			ganad = comprganador(numobj,res1);
			if(ganad==1){
				imprime("Enhorabuena, has conseguido obtener el numero",1,0);
				res1=resdef;
			}else{
				//Si no gana actualizamos el vector de numeros aleatorios y se sigue pidiendo numeros y operaciones.
				for(i=0,j=0;i<6;i++){
					if(numaleat[i]!=cos1&&numaleat[i]!=cos2){
					auxnumaleat[j]=numaleat[i];
					j++;
					}	
					}
				auxnumaleat[j]=res1;
				//Informacion al final del turno y pasamos al siguiente
				imprime("Los numeros con los que puedes seguir jugando son:",1,0);
				for(i=0;i<5;i++){
					printf(" %i\n",auxnumaleat[i]);
				}	
				//Vuelvo a pedir el primer numero
				do{
					scanf(" %i",&cos3);
				}while(compraleat(auxnumaleat,cos3)==0);
				//Vuelvo a pedir el operador
				do{
					scanf(" %c",&op);
					resop= comprop(op);
				}while(resop==0);
				//Vuelvo a pedir el segundo numero
				do{
					scanf("%i",&cos4);
				}while(compraleat(auxnumaleat,cos4)==0);
				//Compruebo si es el numero que buscamos
				res2=calculadora(cos3,op,cos4);
				ganad = comprganador(numobj,res2);
				if(ganad==1){
					imprime("Enhorabuena, has conseguido obtener el numero",1,0);
					res2=resdef;
				}else{
					//Si no es el numero volvemos a actualizar el vector de numeros aleatorios.
					for(i=0,j=0;i<5;i++){
					if(auxnumaleat[i]!=cos3&&auxnumaleat[i]!=cos4){
					auxnumaleat2[j]=auxnumaleat[i];
					j++;
					}	
					}
					auxnumaleat2[j]=res2;
					//Informacion de final de turno y pasamos al siguiente
					imprime("Los numeros con los que puedes seguir jugando son:",1,0);
					for(i=0;i<4;i++){
						printf(" %i\n",auxnumaleat2[i]);
				}
					//Vuelvo a pedir el primer numero
					do{
						scanf(" %i",&cos5);
					}while(compraleat(auxnumaleat2,cos5)==0);
					//Vuelvo a pedir el operador
					do{
						scanf(" %c",&op);
						resop= comprop(op);
					}while(resop==0);
					//Vuelvo a pedir el segundo numero
					do{
						scanf(" %i",&cos6);
					}while(compraleat(auxnumaleat2,cos6)==0);
					//Compruebo si el numero es el que buscamos
					res3=calculadora(cos5,op,cos6);
					ganad = comprganador(numobj,res3);
					if(ganad==1){
						imprime("Enhorabuena, has conseguido obtener el numero",1,0);
						res3=resdef;
					}else{
							//Si no es el numero volvemos a actualizar el vector de numeros aleatorios.
							for(i=0,j=0;i<4;i++){
								if(auxnumaleat2[i]!=cos5&&auxnumaleat2[i]!=cos6){
								auxnumaleat3[j]=auxnumaleat2[i];
								j++;
							}	
							}
								auxnumaleat3[j]=res3;
							//Informacion de final de turno y pasamos al siguiente
							imprime("Los numeros con los que puedes seguir jugando son:",1,0);
							for(i=0;i<3;i++){
								printf(" %i\n",auxnumaleat3[i]);
							}
							//Vuelvo a pedir el primer numero
							do{
								scanf(" %i",&cos7);
							}while(compraleat(auxnumaleat3,cos7)==0);
							//Vuelvo a pedir el operador
							do{
								scanf(" %c",&op);
								resop= comprop(op);
							}while(resop==0);
							//Vuelvo a pedir el segundo numero
							do{
								scanf("%i",&cos8);
							}while(compraleat(auxnumaleat3,cos8)==0);
							//Compruebo si es el numero que buscamos
							res4=calculadora(cos7,op,cos8);
							ganad = comprganador(numobj,res4);
							if(ganad==1){
							imprime("Enhorabuena, has conseguido obtener el numero",1,0);
							res4=resdef;
							}else{	
									//Si no es el numero volvemos a actualizar el vector de numeros aleatorios.
									for(i=0,j=0;i<3;i++){
										if(auxnumaleat3[i]!=cos7&&auxnumaleat3[i]!=cos8){
										auxnumaleat4[j]=auxnumaleat3[i];
										j++;
										}	
									}
									auxnumaleat4[j]=res4;
									//Informacion de final de turno y pasamos al siguiente
									imprime("Los numeros con los que puedes seguir jugando son:",1,0);
									for(i=0;i<2;i++){
									printf(" %i\n",auxnumaleat4[i]);
									}
									//Vuelvo a pedir el primer numero
									do{
										scanf(" %i",&cos9);
									}while(compraleat(auxnumaleat4,cos9)==0);
									//Vuelvo a pedir el operador
									do{
										scanf(" %c",&op);
										resop= comprop(op);
									}while(resop==0);
									//Vuelvo a pedir el segundo numero
									do{
										scanf("%i",&cos10);
									}while(compraleat(auxnumaleat4,cos10)==0);
									//Compruebo si es el numero que buscamos
									res5=calculadora(cos9,op,cos10);
									ganad = comprganador(numobj,res5);
									res5=resdef;
									if(ganad==1){
									imprime("Enhorabuena, has conseguido obtener el numero",1,0);
									}else{
										//Si no es el numero volvemos a actualizar el vector de numeros aleatorios.
										for(i=0,j=0;i<3;i++){
											if(auxnumaleat4[i]!=cos9&&auxnumaleat4[i]!=cos10){
											auxnumaleat5[j]=auxnumaleat4[i];
											j++;
											}	
										}
										auxnumaleat5[j]=res5;
										//Como ya es el ultimo turno, nos quedamos con ese numero.
										imprime("Se han acabado las operaciones posibles, el numero final obtenido es:",1,0);
										printf(" %i\n",res5);
										}
								}
						}
				}
		}
			punts=puntuacion(numobj,resdef);
			imprime("La puntuación que has obtenido es:",1,0);
			printf("%i",punts);
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
    imprime("Pulsa 0 para volver a jugar o pulsa cualquier otro numero para salir del juego",2,0);
	scanf("%d",&salida);
    system("cls");
    return salida;
}

    int fila,columna;
    int fila1, fila2, columna1, columna2;
    int barcojug=1;
int hundirlaflota()
{
	//VARIABLES Y FUNCIONES HUNDIR LA FLOTA:
	int i,j,salida=0;
	int colocacionjug=0;
	int ganador=0, barcoscons=4, barcosjug=4;
	int formatocoord=1,formatocoord2=1;
	char coordport[2];
	char coordport2[2];
	int generarbarcojug(int f1, int f2, int c1,int c2, int mat[6][6], int n);
	int imprimematriz(int mat[6][6]);	
	int generarbarco(int n, int mat[6][6], int barco);
	int matrizcons[6][6];//matriz que representa los barcos del cpu
	int matrizjug[6][6];//matriz que representa los barcos del jugador
	
	//JUEGO:
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
//llenar de 0 las matrices
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
	generarbarco(5, matrizcons, 5);	//portaviones rellena la matriz de 5 portaviones
	generarbarco(4, matrizcons, 4);	//destructor rellena la matriz de 4
	generarbarco(3, matrizcons, 3);	//acorazado rellena la matriz de 3
  	generarbarco(2, matrizcons, 2);	//submarino rellena la matriz de 2
//Colocacion de barcos por parte del jugador
	do{
	
	if (barcojug==1)
	{
		system("cls");
		if (formatocoord==0)
			imprime("Error: Formato no valido, por favor, introduzca un formato de coordenada valido, como por ejemplo A5 o B4",2,0);
		if (formatocoord2==0)
			imprime("Error: Formato no valido, por favor, introduzca un formato de coordenada valido, como por ejemplo A5 o B4",2,0);
		formatocoord=1;
		formatocoord2=1;
		imprimematriz(matrizjug);
		imprime("\n\n  Introduzca el primer punto del portaviones (5 casillas)",2,2);
		scanf(" %s", coordport);
		formatocoord = comprobarformatocoord(coordport);
		fila1=fila;
		columna1=columna;
		if (formatocoord==1)
		{
			imprime("\n  Introduzca el segundo punto del portaviones:",2,2);
			scanf(" %s", coordport2);
			formatocoord2 = comprobarformatocoord(coordport2);
			fila2=fila;
			columna2=columna;
			if (formatocoord2== 1)
			{
				generarbarcojug(fila1, fila2, columna1, columna2, matrizjug, 5);
			}
		}
	}
	if (barcojug==2)
	{
		system("cls");
		if (formatocoord==0)
			imprime("Error: Formato no valido, por favor, introduzca un formato de coordenada valido, como por ejemplo A5 o B4",2,0);
		if (formatocoord2==0)
			imprime("Error: Formato no valido, por favor, introduzca un formato de coordenada valido, como por ejemplo A5 o B4",2,0);
		formatocoord=1;
		formatocoord2=1;
		imprimematriz(matrizjug);
		imprime("\n\n  Introduzca el primer punto del destructor (4 casillas)",2,2);
		scanf(" %s", coordport);
		formatocoord = comprobarformatocoord(coordport);
		fila1=fila;
		columna1=columna;
		if (formatocoord==1)
		{
			imprime("\n  Introduzca el segundo punto del destructor:",2,2);
			scanf(" %s", coordport2);
			formatocoord2 = comprobarformatocoord(coordport2);
			fila2=fila;
			columna2=columna;
			if (formatocoord2== 1)
			{
				generarbarcojug(fila1, fila2, columna1, columna2, matrizjug, 4);
			}
		}
	}
	if (barcojug==3)
	{
		system("cls");
		if (formatocoord==0)
			imprime("Error: Formato no valido, por favor, introduzca un formato de coordenada valido, como por ejemplo A5 o B4",2,0);
		if (formatocoord2==0)
			imprime("Error: Formato no valido, por favor, introduzca un formato de coordenada valido, como por ejemplo A5 o B4",2,0);
		formatocoord=1;
		formatocoord2=1;
		imprimematriz(matrizjug);
		imprime("\n\n  Introduzca el primer punto del acorazado (3 casillas)",2,2);
		scanf(" %s", coordport);
		formatocoord = comprobarformatocoord(coordport);
		fila1=fila;
		columna1=columna;
		if (formatocoord==1)
		{
			imprime("\n  Introduzca el segundo punto del acorazado:",2,2);
			scanf(" %s", coordport2);
			formatocoord2 = comprobarformatocoord(coordport2);
			fila2=fila;
			columna2=columna;
			if (formatocoord2== 1)
			{
				generarbarcojug(fila1, fila2, columna1, columna2, matrizjug, 3);
			}
		}
	}
	if (barcojug==4)
	{
		system("cls");
		if (formatocoord==0)
			imprime("Error: Formato no valido, por favor, introduzca un formato de coordenada valido, como por ejemplo A5 o B4",2,0);
		if (formatocoord2==0)
			imprime("Error: Formato no valido, por favor, introduzca un formato de coordenada valido, como por ejemplo A5 o B4",2,0);
		formatocoord=1;
		formatocoord2=1;
		imprimematriz(matrizjug);
		imprime("\n\n  Introduzca el primer punto del submarino (2 casillas)",2,2);
		scanf(" %s", coordport);
		formatocoord = comprobarformatocoord(coordport);
		fila1=fila;
		columna1=columna;
		if (formatocoord==1)
		{
			imprime("\n  Introduzca el segundo punto del submarino:",2,2);
			scanf(" %s", coordport2);
			formatocoord2 = comprobarformatocoord(coordport2);
			fila2=fila;
			columna2=columna;
			if (formatocoord2== 1)
			{
				generarbarcojug(fila1, fila2, columna1, columna2, matrizjug, 2);
			}
		}
	}
	
	if (barcojug==5)
	{
		colocacionjug++;
		break;
	}
	
    }while(colocacionjug==0);
    
    system("cls");
	imprime("",2,3);	
	imprime("Magnifica estrategia almirante, pero ahora empieza lo divertido.",2,3);
	imprime("Tomaremos ventaja sobre nuestro adversario, le sorprenderemos atacando primero",2,3);
/*	while(ganador==0)
	{
		disparojug();  //Disparo de jugador
		if (disparojug==0)
			agua();
		if (disparojug==1)
		{
			tocado();
			if(barcoscons==0)
			{
				ganador=1;
				break;
			}
		}
		
		disparocons(); //Disparo de consola
		if (disparocons==0)
			aguacons();
		if(disparocons==1)
		{
			tocadocons();
			if(barcoscons==0)
			{
				ganador=2;
				break;
			}
		}
	}
*/
	
	
//Salir del juego
 	imprime("",3,0);
	imprime("Pulsa 0 para volver a jugar o pulse cualquier otro numero para salir del juego",2,0);
	scanf(" %d",&salida);
    system("cls");
    return salida;
}

int trivial()
{
	//VARIABLES Y FUNCIONES:
	void comprobaSiHaSalidoPregunta(int numpreg[],int i,int iz,int der);
	int comprobarRespuesta(inicio tabla[],int pos,int posicion);	
	int i,j,dado[6],numpreg[6],puntuacion=0,salida=0,vuelta=0,turra;
	char solucion[20],tirar,basura,decision[3];
	inicio geografia[]={{"Que pais está entre Peru y Colombia?","ECUADOR"},{"Cual es la capital de Marruecos?","RABAT"},{"Cual es el pais mas visitado del mundo","FRANCIA"},{"En que pais se encuentra el rio Po","ITALIA"},{"En que pais se encuentra la peninsula de Yucatan?","MEXICO"},{"Cual es el oceano que bana las aguas de Sri Lanka?","INDIC"},{"Que nombre recibe un cowboy argentino?","GAUCHO"},{"Cual es la montaña más alta del mundo?","EVEREST"},{"Cual es el idioma mas hablado en Suiza?","ALEMAN"},{"En que hemisferio se encuentra Jamaica?","NORTE"}};
	inicio historia[]={{"De que pais europeo fue colonia Mozambique?","PORTUGAL"},{"Quienes conquistaron Constantinopla (fin del Imperio Bizantino) en 1453?","TURCOS"},{"De que pais se independizo Eslovenia?","YUGOSLAVIA"},{"Que moneda se usaba en España antes de la llegada del euro?","PESETA"},{"En que pais se encuentra la peninsula de Yucatan?","MEXICO"},{"Cual era la ciudad hogar de Marco Polo?","VENECIA"},{"Quien fue el primer presidente de los Estados Unidos?","GEORGE WASHINGTON"},{"Como se llamaba el famoso dictador italiano?","MUSSOLINI"},{"Que pais fue llamado la Galia por los romanos?","FRANCIA"},{"En que ciudad española se realizo el famoso bombardeo de La Legion Condor?","GUERNICA"}};
	inicio deporte[]={{"Que pieza de ajedrez puede hacer un movimiento en forma de L?","CABALLO"},{"Que seleccion de futbol gano el Mundial de Brasil de 2014?","ALEMANIA"},{"Cual es el estilo de natacion mas rapido?","CROL"},{"De donde es el jugador Alexis Sanchez?","CHILE"},{"Cómo se llama el estadio del Betis?","BENITO VILLAMARIN"},{"Como se llama la liga espanola de balonmano?","ASOBAL"},{"Que pais fue el ganador de baloncesto en los Juegos Olimpicos de Londres 2012?","ESTADOS UNIDOS"},{"Cual es la ultima cinta en las artes marciales?","NEGRA"},{"Que le arrojaba antiguamente un caballero a otro para desafiarlo en duelo?","GUANTE"},{"Como se llama el palo utilizado en hockey?","STICK"}};
    inicio ciencia[]={{"Como se llaman las celulas nerviosas?","NEURONAS"},{"Que elemento contienen todos los componentes organicos?","CARBONO"},{"Como se llaman las lineas que unen los puntos de igual temperatura?","ISOBARAS"},{"Cual es el pajaro simbolo de la paz?","PALOMA"},{"En que mes el sol esta mas cerca de la Tierra?","DICIEMBRE"},{"En que parte del cuerpo se encuentra la piel mas gruesa?","ESPALDA"},{"Como se llama la ciencia que estudia la sangre?","HEMATOLOGIA"},{"Cual de los cinco sentidos se desarrolla el primero?","OLFATO"},{"Cual es el dedo mas sensible de la mano?","INDICE"},{"Que fabrico Alessandro Volta, por primera vez, en 1800?","PILA"}};
	inicio arte[]={{"Que escribia un testador?","TESTAMENTOS"},{"Quien escribio Poeta en Nueva York?","FEDERICO GARCIA LORCA"},{"En que ciudad comenzo y termino Phileas Fogg su viaje alrededor del mundo?","LONDRES"},{"Quien era el campanero jorobado de Notre Dame?","QUASIMODO"},{"A que tipo de instrumento pertenece la citara?","CUERDA"},{"En que ciudad espanola se encuentra La casa de las conchas?","SALAMNCA"},{"Quien vivia en el 221B de Backer Street?","SHERLOCK HOLMES"},{"Cual fue el genero mas cultivado por los autores de la generación del 27?","POESIA"},{"Como se llama a la gente que no posee magia en la saga Harry Potter?","MUGGLES"},{"Cual es el genero teatral intermedio entre la comedia y la tragedia ?","DRAMA"}};
	inicio entretenimiento[]={{"Que pelicula creo la palabra magica supercalifragilisticoespialidoso?","MARY POPPINS"},{"Como se llama la ciudad en la que vivia el Mago de Oz?","ESMERALDA"},{"Como se llama el oso mas famoso del parque nacional de Yellowstone?","YOGUI"},{"Cual de los Siete Enanitos no tenia barba?","MUDITO"},{"Que actor espanol protagonizo ?La máscara del Zorro? en 1998?","ANTONIO BANDERAS"},{"Quien fue la primera voz de Mickey Mouse?","WALT DISNEY"},{"Que cancion de Los Beatles ha sido la mas grabada?","YESTERDAY"},{"Quien es la mascota de SEGA?","SONIC"},{"Que actor interpretaba a Hache en la pelicula 3MSC?","MARIO CASAS"},{"Como se llama el protagonista de la saga Indiana Jones?","HARRISON FORD"}};
	inicio final[]={{"De que arbol son las hojas de las cuales los koalas se alimentan?","EUCALIPTO"},{"Cual fue la primera pelicula de Walt Disney?","BLANCANIEVES"},{"Cual es la ciudad mas poblada del mundo?","TOKIO"},{"Quien pinto la ultima cena?","LEONARDO DA VINCI"},{"Que deporte practicaba Carl Lewis?","ATLETISMO"},{"Cual era la capital del Imperio Inca?","CUSCO"}};
	int imprime(char frase[],int s, int e); //funcion imprimir frase con animacion
    int numal(int num1,int num2); //Genera numeros aleatorios 
    void semilla(); //Genera semilla
    void ComprobacionPregunta(int numpreg[],int dado[],int i,int iz,int der);
    int Solucion(inicio tabla[],int pos,int posicion);
    
    //JUEGO:
    system ("cls");
    imprime("Bienvenido concursante, le doy la bienvenida a Trivial, el juego en el que tendras que responder una serie \nde preguntas relacionadas con tematicas como Historia, Geografia, Arte y Literatura, Entretenimiento, \nCiencia y Literatura y Deportes para hacerte con la victoria.",2,0);
    imprime("Para ello, deberas responder un conjunto de de 6 preguntas (+1 plus) y obtener la maxima puntuacion posible.\n\nSeras capaz de conseguir la casi inalcanzable puntuacion de 100 puntos?",2,0);
	imprime("Adelante y buena suerte",2,0);
	turra=instrucciones();
	imprime("",1,0);
	if(turra==0)
	{
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
    }
    imprime("Presione cualquier tecla para comenzar el juego...",1,0);
    getch();
    system("cls");
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
    	printf("%d",dado[i]);
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
		imprime("",5,0);
		imprime("Presione cualquier tecla para la siguiente pregunta",1,0);
        getch();
        system("cls");
	}
	imprime("Tu puntuacion final es de: ",0,0);
	printf("%d",puntuacion);
	imprime(" puntos",3,0);
	puntuacion=60;
	if(puntuacion==60)
	{
		imprime("Has conseguido la extraordinaria puntuacion de 60 puntos, increible jugador!",2,0);
		imprime("Por ello, tienes la gran oportunidad de conseguir entrar en el top mundial de trivial, sino simplemente conseguiras\nganar el juego. Aunque cuidado, esta pregunta sera un poco mas dificil que las anteriores",2,0);
		imprime("Te atreves con ello?",2,0);
		while(vuelta==0)
		{
		    imprime("Escribe si o no",2,0);
		    scanf("%s",decision);
		    _strupr(decision); //Pasamos la respuesta a mayusuculas para que de igual si el concursante a puesto la respuesta en mayusuculas o minusculas
		    if(strcmp(decision,"SI")==0)
		    {
			    scanf("%c",&basura);
			    vuelta=1;
			    system("cls");
			    imprime("Concursante atrevido, asi me gusta!",2,0);
			    imprime("Ahi va la pregunta final:",2,0);
			    semilla();
			    puntuacion=Solucion(final,numal(0,5),puntuacion);
			    imprime("",5,0);
		        imprime("Presione cualquier tecla para continuar...",1,0);
				getch();
                system("cls");
		    }
		    else if(strcmp(decision,"NO")==0)
		    {
			    vuelta=1;
		        imprime("",2,0);
		        imprime("No pasa nada concursante, todos a veces hemos tenido un poco de miedo, aun asi has conseguido\nla gran puntuacion de 60 puntos, enhorabuena",2,0);
		    }
		    else
		    {
			    imprime("Recuerda que tienes que escribir si o no",2,0);
		    }
	    }
	}
	system("cls");
	
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
	return salida;
}
void tienda()
{
	void AbrirTienda();
	FILE *pf;
	int puntos,salida=0;
	int puntuacion=1200,encontrado;
	char premio[20],eleccion[20],seguro[2],basura;
	system("cls");
	AbrirTienda();
	imprime("",2,0);
	imprime("Usted tiene ",0,0); 
	printf("%d ",puntuacion);
	imprime("puntos",2,0);
	imprime("Indique el nombre del premio (ponga \"FIN\" cuando no quiera mas premios): ",0,0);
	gets(eleccion);
	_strupr(eleccion);
	if(strcmp(eleccion,"FIN")==0)
	system("cls");
	while(strcmp(eleccion,"FIN")!=0 && puntuacion>0)
	{
	encontrado=0;
	pf = fopen("tienda.txt", "r");
	while(fscanf(pf,"%[^;];%d",premio,&puntos )!=EOF&&encontrado==0)
	{
		if(strcmp(premio,eleccion)==0)
		{
			encontrado=1;
	        imprime("El premio ",0,0); 
	        printf("%s ",premio);
	        imprime("son ",0,0);
	        printf("%d ",puntos);
	        imprime("puntos",2,0);
			imprime("Esta seguro de que quiere comprar el premio?",1,0);
			scanf("%s",seguro);
			_strupr(seguro); 
			while(strcmp(seguro,"SI")!=0 && strcmp(seguro,"NO")!=0)
			{	
			imprime("No me has contestado a la pregunta",2,0);
			imprime("El premio ",0,0); 
	        printf("%s ",premio);
	        imprime("son ",0,0);
	        printf("%d ",puntos);
	        imprime("puntos",2,0);
			imprime("Esta seguro de que quiere comprar el premio?",2,0);
			scanf("%s",seguro);
			_strupr(seguro); 
			}
			
			if(strcmp(seguro,"SI")==0)
			{
				if(puntuacion>=puntos)
			    {
				puntuacion=puntuacion-puntos;
	            imprime("Ya tiene su ",0,0); 
	            printf("%s",premio);
	            imprime(",enhorabuena!",2,0);
			    }
			    else
			    {
	            imprime("Lo siento, no tiene suficientes puntos. Tienes ",0,0); 
	            printf("%d ",puntuacion);
	            imprime("puntos",2,0);	
	            }
			}
		}                              
	}
	fclose(pf);
	if(encontrado==0)
	imprime("Lo siento, no tenemos ",0,0); 
	printf("%s ",eleccion);
	imprime("como premio posible",2,0);
	imprime("Le queda ",0,0); 
	printf("%d ",puntuacion);
	imprime("puntos",2,0);
	Sleep(3000);
	system("cls");
	AbrirTienda();
	imprime("",2,0);
	imprime("Indique el nombre del premio (ponga \"FIN\" cuando no quiera mas premios): ",0,0);
	if(encontrado!=0)
	scanf("%c",&basura);
	gets(eleccion);
	_strupr(eleccion);
	if(strcmp(eleccion,"FIN")==0)
	system("cls");
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
// Abre el catalogo de la tienda
void AbrirTienda()
{
	FILE *pf;
	char premio[20];
	int puntos;
	pf = fopen("tienda.txt", "r");
	if (pf == NULL) 
	{
	// Si el resultado es NULL mensaje de error 
	printf("Error al abrir el fichero.\n");  
	} 
	printf("Vamos a visualizar la tienda de premios: ");
	while(fscanf(pf, "%[^;];%d",premio,&puntos )!=EOF)
	{
		printf("\n\tPREMIO %s, PUNTOS: %d",premio,puntos);
	}
	fclose(pf);
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
 // Pregunta al jugador si quiere leer las instrucciones
 int instrucciones()
 {
 	char turra[3];
 	int fallo=0;
 	while(fallo==0)
 	{
 	imprime("Desea leer las instrucciones?. Escriba si o no",1,0);
 	gets(turra);
 	_strupr(turra); //Pasamos la respuesta a mayusuculas para que de igual si el concursante a puesto la respuesta en mayusuculas o minusculas
 	if(strcmp(turra,"SI")==0)
 	{
 		fallo=1;
 		return 0;
	}
	else if(strcmp(turra,"NO")==0)
	{
		fallo=1;
		return 1;
	}
	else
	    imprime("Recuerda que tienes que escribir si o no",2,0);
    }     	
 }
void listanimales()
{
	FILE *sac;
	int puntos,cont=1;
	char animal[40];
	sac = fopen("animales.txt", "w");
	if (sac == NULL) 
	{
	// Si el resultado es NULL mensaje de error 
	printf("Error al abrir el fichero.\n");  
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
}
void listatienda()
{
	FILE *pf;
	int puntos,cont=1;
	char premio[40],basura;
	pf = fopen("tienda.txt", "w");
	if (pf == NULL) 
	{
	// Si el resultado es NULL mensaje de error 
	printf("Error al abrir el fichero.\n"); 
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
}

//FUNCIONES CIFRAS Y LETRAS:	
	//Funcion para introducir un operador correcto	
	int comprop( char oper){
		int boolop=1;
		if(oper!='+'&&oper!='-'&&oper!='*'&&oper!='/'){
				imprime("El operador introducido no es valido",1,0);
				boolop=0;
				}
		return boolop;
		}
	//Funcion que comprueba si los numeros introducidos con el scanf coinciden con los numeros aleatorios.
	int compraleat(int v[],int num){
	int flag=0;
	int i;
	for(i=0;i<6;i++){
		if (v[i]==num){
			flag=1;
		}
	}
	if(flag==0){
		imprime("El numero introducido no es valido",1,0);
	}
	return flag;
}
	//Funcion calculadora
	int calculadora(int num1,char cop,int num2){
		int res1;
		switch (cop){
				case'+':
					res1=num1+num2;
					break;
				case'-':
					res1=num1-num2;
					break;
				case'*':
					res1=num1*num2;
					break;
				default:
					res1=num1/num2;
					break;	
			}
		printf("%i\n", res1);
		return res1;
	}		
	//Funcion que comprueba si el numero obtenido es el ganador
	int comprganador(int obj,int candid){
		 int flaganar=0;
		 if(candid==obj){
		 	flaganar=1;
		 }
		 return flaganar;
	}
	//Funcion que otorga la puntuacion
	int puntuacion(int obj,int candidato){
		int puntos,dif;
		dif=fabs(obj-candidato);
		if(dif==0){
			puntos=100;
			}else if(dif>0&&dif<=20){
				puntos=50;
				}else if(dif>20&&dif<=50){
					puntos=20;
					}else{
						puntos=0;
						}
			return puntos;
	}
 
//FUNCIONES HUNDIR LA FLOTA:
int generarbarcojug(int f1, int f2, int c1,int c2, int mat[6][6], int n)
{
	int okupa=0, i;
	okupa=0;
	if(f1==f2)
				{
					if((c1<c2)&&((c2+1)-c1==n)) //direccion derecha
					{
						if(c1 + n <= 6)
  						{ 
	  					for(i=c1;i<=(c1+n-1);i++)  
	      				{
	      					if(mat[f1][i]!=0)
	    						okupa++;
	      				}
	   					 if(okupa == 0)
	  						{
  	  						for(i=c1;i<=(c1+n-1);i++)  
	    						mat[f1][i]= n;
	      					barcojug++;
	  		 				}
						}	
					}
				
					if(c1>2&&((c1+1-c2)==n)) //direccion izquierda
					{
						if(c1 + 1 >= n)
  						{ 
	 					 for(i=c1;i>=(c1-n+1);i--)  
	      				{
	      					if(mat[f1][i]!=0)
	    						okupa++;
	      				}
	   					 if(okupa == 0)
	   						{
			 			    for(i=c1;i>=(c1-n+1);i--)  
	    						mat[f1][i]=n;
	      					barcojug++;
							}
						}
					}						
				}
				
				if(c1==c2)
				{
					if((f1>f2)&&((f1+1-f2)==n))  //direccion arriba
					{
					  if(f1 >= (n-1))
  						{ 
	  					for(i=f1;i>=(f1-n+1);i--)  
	      					{
	      				if(mat[i][c1]!=0)
	    					okupa++;
	      					}
	    			if(okupa == 0)
	  				 {
  	  				for(i=f1;i>=(f1-n+1);i--)  
	    				mat[i][c1]=n;
	   				barcojug++;
					 }
						}
					}
					if((f1<f2)&&((f2-f1+1)==n)) //direccion abajo
					{
					if(f1+n<=6)
  						{ 
				    for(i=f1;i<=f1+n-1;i++)
						{
	    			if(mat[i][c1]!=0)
	    				okupa++;
	   	 	   			}
	  				  if(okupa == 0)
	   					{
  	  				for(i=f1;i<=f1+n-1;i++)  
	    				mat[i][c1]=n;
	      			barcojug++;
	   				}
						}
					}
				
}
}
int comprobarformatocoord(char coord[2])
{
	if (coord[0]=='a'||coord[0]=='A')
			fila=0;
		else{
			if (coord[0]=='b'||coord[0]=='B')
			fila=1;
			else{
				if (coord[0]=='c'||coord[0]=='C')
				fila=2;
				else{
					if (coord[0]=='d'||coord[0]=='D')
					fila=3;
					else{
						if (coord[0]=='e'||coord[0]=='E')
						fila=4;
						else{
							if (coord[0]=='f'||coord[0]=='F')
							fila=5;	
							else{
									return 0;
								}
							}
						}	
					}
				}
			}

		if ((coord[1]-1)>='0' && (coord[1]-1)<='5')
		{
			columna=coord[1]-'1';
			return 1;
		}
		else
		{
			return 0;
		}
	
}
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
    int i;
    printf("   ");
    for(i=1;i<=6;i++)
		printf("   %i ",i);
	printf("\n\n");
	printf(" A ");
	for(i=0;i<6;i++)  
	      {
	      	printf("   %i ",mat[0][i]);
	      }
	printf("\n\n B ");
	for(i=0;i<6;i++)  
	      {
	      	printf("   %i ",mat[1][i]);
	      }
	printf("\n\n C ");
	for(i=0;i<6;i++)  
	      {
	      	printf("   %i ",mat[2][i]);
	      }
	printf("\n\n D ");
	for(i=0;i<6;i++)  
	      {
	      	printf("   %i ",mat[3][i]);
	      }
	printf("\n\n E ");
	for(i=0;i<6;i++)  
	      {
	      	printf("   %i ",mat[4][i]);
	      }
	printf("\n\n F ");
	for(i=0;i<6;i++)  
	      {
	      	printf("   %i ",mat[5][i]);
	      }
	      	
}

//FUNCIONES TRIVIAL:
int Solucion(inicio tabla[],int pos,int puntuacion)
{
	char solucion[20];
	const int SEGUNDOS = 30; //Tiempo inicial
	int horaActual;
	int horaInicio=	time(NULL);
	printf("%s\n\n",tabla[pos].pregunta);
	gets(solucion);
	_strupr(solucion);
	horaActual=	time(NULL);	
    if((horaActual-horaInicio)>SEGUNDOS)
    {
    	imprime("",2,0);
		imprime("Oh lo siento, tu tiempo se ha acabado",10,0);
		printf("Puntuacion actual: %d puntos\n\n",puntuacion);
	}
	else
	{
	    if(strcmp(solucion,tabla[pos].respuesta)==0)
	    {
		    imprime("",1,0);
		    imprime("La respuesta es...",2,0);
		    imprime("CORRECTA",2,0);
		    if(puntuacion<60)
		    puntuacion+=10;
		    else
			puntuacion+=40;
		    imprime("Puntuacion actual: ",0,0);
		    printf("%d",puntuacion);
		    imprime(" puntos",2,0);
	    }
		else
		{
			imprime("",1,0);
			imprime("La respuesta es...",2,0);
			imprime("INCORRECTA",2,0);
			printf("La respuesta correcta es:  %s",tabla[pos].respuesta); //Le mostramos al usuario la respuesta correcta
			puntuacion-=5;
			if(puntuacion<0) // Como en los trivials no suele haber puntuacion negativo hacemos este if
			puntuacion=0;
			imprime("",2,0);
			imprime("Puntuacion actual: ",0,0);
			printf("%d",puntuacion);
			imprime(" puntos",2,0);
	}
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
