//------------------------------Librerias---------------------------------------

	#pragma hdrstop

	#include "Metodos.h"
	#include <iostream>
	#include <stdio.h>
	#include <conio.h>
	#include <string>
	#include <windows.h>
	#include <fstream>
	#include <algorithm>
	#include <functional>
	#include <cctype>
	#include <locale>
	#include <cstring>
	#include <typeinfo>
	#include <sstream>
	#include <lib/rapidjson/document.h>
	#include <lib/rapidjson/prettywriter.h>
	#include <lib/rapidjson/stringbuffer.h>
	using namespace std;
	using namespace rapidjson;

//------------------------------------------------------------------------------

	#pragma package(smart_init)

//------------------------------Variables---------------------------------------

	int Variables::AnchoPantalla = 0;
	int Variables::AltoPantalla = 0;
	int Variables::OpcionMenu = 0;
	string Variables::RutaArchivo = "";

//------------------------------Interfaz----------------------------------------


    //-----------------------------Colores----------------------------------

		void Color(int Background, int Text)
		{
			// Funci�n para cambiar el color del fondo y/o pantalla

			HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE); // Tomamos la consola.
			// Para cambiar el color, se utilizan n�meros desde el 0 hasta el 255.
			// Pero, para convertir los colores a un valor adecuado, se realiza el siguiente c�lculo.
			int    New_Color= Text + (Background * 16);
			SetConsoleTextAttribute(Console, New_Color); // Guardamos los cambios en la Consola.
		}

	//---------------------------Fullscreen---------------------------------

		void Fullscreen()
		{
			keybd_event(VK_MENU,
						   0x38,
							  0,
							  0);
			keybd_event(VK_RETURN,
							 0x1c,
								0,
								0);
			keybd_event(VK_RETURN,
							 0x1c,
				  KEYEVENTF_KEYUP,
								0);
			keybd_event(VK_MENU,
						   0x38,
				KEYEVENTF_KEYUP,
							  0);
			return;
		}

	//---------------------Obtener Resoluci�n Pantalla----------------------

		void Resolucion()
		{
			Variables::AnchoPantalla = (GetSystemMetrics(SM_CXSCREEN) / 8) - 2;
			Variables::AltoPantalla = (GetSystemMetrics(SM_CYSCREEN) / 19) + 1;
		}

	//------------------------------Men�------------------------------------

		void Menu()
		{
			//Informaci�n
			Color(0,4);
			gotoxy ((Variables::AnchoPantalla - 2)/2 - 20, 2);
			cout<< "Universidad De San Carlos De Guatemala" <<endl;
			gotoxy ((Variables::AnchoPantalla - 2)/2 - 12, 4);
			cout<< "Facultad De Ingenieria" <<endl;
			gotoxy ((Variables::AnchoPantalla - 2)/2 - 11, 6);
			cout<< "Estructuras De Datos" <<endl;
			gotoxy ((Variables::AnchoPantalla - 2)/2 - 6, 8);
			cout<< "Proyecto 1" <<endl;
			gotoxy ((Variables::AnchoPantalla - 2)/2 - 17, 10);
			Color(0,1);
			cout<< "Sergio Alexander Echigoyen Gomez" <<endl;
			gotoxy ((Variables::AnchoPantalla - 2)/2 - 6, 12);
			cout<< "201801628" <<endl;

			//Men�
			Color(0,6);
			gotoxy ((Variables::AnchoPantalla - 2)/2 - 4, 20);
			cout<< "Menu" <<endl;
			gotoxy ((Variables::AnchoPantalla - 2)/2 - 11, 22);
			cout<< "1. Lectura De Archivo" <<endl;
			gotoxy ((Variables::AnchoPantalla - 2)/2 - 11, 24);
			cout<< "2. Juego" <<endl;
			gotoxy ((Variables::AnchoPantalla - 2)/2 - 11, 26);
			cout<< "3. Reportes" <<endl;
			gotoxy ((Variables::AnchoPantalla - 2)/2 - 11, 28);
			cout<< "4. Salir" <<endl;
			gotoxy ((Variables::AnchoPantalla - 2)/2 - 11, 30);
			cout<< "Elija Una Opcion: " <<endl;
			gotoxy ((Variables::AnchoPantalla - 2)/2 + 8, 30);

			cin>> Variables::OpcionMenu;
		}

	//-----------------------------Marcos-----------------------------------

		void gotoxy(int x, int y)
		{
			COORD coord;
			coord.X = x;
			coord.Y = y;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		}

		void MarcoMenu(int Col1, int Col2, int Fil1, int Fil2)
		{
			Color(0,9);
			for(int Cols = Col1; Cols <= Col2; Cols++)
			{
				for(int Fils = Fil1; Fils <= Fil2; Fils++)
				{
					gotoxy(Cols,Fils);
					//Linea Vertical Derecha E Izquierda
					if((Cols == Col1 || Cols == Col2) && (Fils != Fil1 && Fils != Fil2))
					{
						cout << (char)186;
					}
					//Linea Horizontal Superior E Inferior
					else if((Fils == Fil1 || Fils == Fil2) && (Cols != Col1 && Cols != Col2))
					{
						cout << (char)205;
					}
				}
			}

			//Esquina Superior Izquierda
			gotoxy(Col1,Fil1);
			cout << (char)201;
			//Esquina Inferior Izquierda
			gotoxy(Col1,Fil2);
			cout << (char)200;
			//Esquina Superior Derecha
			gotoxy(Col2,Fil1);
			cout << (char)187;
			//Esquina Inferior Derecha
			gotoxy(Col2,Fil2);
			cout << (char)188;
		}

		void MarcoArchivo(int Col1, int Col2, int Fil1, int Fil2)
		{
			Color(0,9);
			for(int Cols = Col1; Cols <= Col2; Cols++)
			{
				for(int Fils = Fil1; Fils <= Fil2; Fils++)
				{
					gotoxy(Cols,Fils);
					//Linea Vertical Derecha E Izquierda
					if((Cols == Col1 || Cols == Col2) && (Fils != Fil1 && Fils != Fil2))
					{
						cout << (char)186;
					}
					//Linea Horizontal Superior E Inferior
					else if((Fils == Fil1 || Fils == Fil2) && (Cols != Col1 && Cols != Col2))
					{
						cout << (char)205;
					}

                    //Barra De T�tulo
					else if((Cols != Col1) && (Fils == Fil1 + 2))
					{
						cout << (char)205;
					}

					//Status Bar
					else if((Cols != Col1) && (Fils == Fil2 - 4))
					{
						cout << (char)205;
					}
				}
			}

			//Esquina Superior Izquierda
			gotoxy(Col1,Fil1);
			cout << (char)201;
			//Esquina Inferior Izquierda
			gotoxy(Col1,Fil2);
			cout << (char)200;
			//Esquina Superior Derecha
			gotoxy(Col2,Fil1);
			cout << (char)187;
			//Esquina Inferior Derecha
			gotoxy(Col2,Fil2);
			cout << (char)188;


			//Textos
			Color(0,4);
			gotoxy(Col1 + 75,Fil1 + 1);
			cout << "Scrabble++ SEG";
			Color(0,9);
			gotoxy(Col1 + 50,Fil1 + 5);
			cout << "Ingrese La Ruta Del Archivo: ";
			cin >> Variables::RutaArchivo;
		}

		void MarcoSalir(int Col1, int Col2, int Fil1, int Fil2)
		{
			Color(0,9);
			for(int Cols = Col1; Cols <= Col2; Cols++)
			{
				for(int Fils = Fil1; Fils <= Fil2; Fils++)
				{
					gotoxy(Cols,Fils);
					//Linea Vertical Derecha E Izquierda
					if((Cols == Col1 || Cols == Col2) && (Fils != Fil1 && Fils != Fil2))
					{
						cout << (char)186;
					}
					//Linea Horizontal Superior E Inferior
					else if((Fils == Fil1 || Fils == Fil2) && (Cols != Col1 && Cols != Col2))
					{
						cout << (char)205;
					}

                    //Barra De T�tulo
					else if((Cols != Col1) && (Fils == Fil1 + 2))
					{
						cout << (char)205;
					}

					//Status Bar
					else if((Cols != Col1) && (Fils == Fil2 - 4))
					{
						cout << (char)205;
					}
				}
			}

			//Esquina Superior Izquierda
			gotoxy(Col1,Fil1);
			cout << (char)201;
			//Esquina Inferior Izquierda
			gotoxy(Col1,Fil2);
			cout << (char)200;
			//Esquina Superior Derecha
			gotoxy(Col2,Fil1);
			cout << (char)187;
			//Esquina Inferior Derecha
			gotoxy(Col2,Fil2);
			cout << (char)188;


			//Textos
			Color(0,4);
			gotoxy(Col1 + 75,Fil1 + 1);
			cout << "Scrabble++ SEG";
			Color(0,13);
			gotoxy(Col1 + 66,Fil1 + 5);
			cout << "Gracias Por Jugar Vuelva Pronto..!";
		}

  	//---------------------------Leer Archivos------------------------------

	   void LeerArchivo(string RutaArchivo)
	   {
		  stringstream Cadena;
		  fstream Archivo(RutaArchivo, fstream::in);

		  if(Archivo)
		  {
			  Cadena << Archivo.rdbuf();
			  Archivo.close();
		  }
		  else
		  {
			  cout<< "No Se Encuentra El Archivo Seleccionado" <<endl;
		  }

		  Document JsonDocument;

		  if(JsonDocument.Parse<0>(Cadena.str().c_str()).HasParseError())
		  throw invalid_argument("Error Al Leer El Archivo Json");

		  string Dimension = JsonDocument["dimension"].GetString();

          cout<< Dimension <<endl;
		  getch();
	   }
