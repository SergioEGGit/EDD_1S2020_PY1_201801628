
//--------------------------------Librerias-------------------------------------

	#pragma hdrstop
	#pragma argsused

	#ifdef _WIN32
		#include <tchar.h>
		#else
			typedef char _TCHAR;
			#define _tmain main
	#endif

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
	using namespace std;

//--------------------------------Variables-------------------------------------



//---------------------------------M�todos--------------------------------------


//--------------------------------Principal-------------------------------------

	int _tmain(int argc, _TCHAR* argv[])
	{
		Fullscreen();
		Resolucion();
        system("color 0b");
		system("cls");
		MarcoMenu(0, Variables::AnchoPantalla - 2, 0, Variables::AltoPantalla + 6);
		Menu();

		while(Variables::OpcionMenu != 4)
		{
			switch(Variables::OpcionMenu)
			{
				case 1:
					system("cls");
					MarcoArchivo(0, Variables::AnchoPantalla - 2, 0, Variables::AltoPantalla + 6);
					LeerArchivo(Variables::RutaArchivo);
					system("cls");
					MarcoMenu(0, Variables::AnchoPantalla - 2, 0, Variables::AltoPantalla + 6);
					Menu();
				break;

				case 2:

				break;

			   default:
					system("cls");
					MarcoMenu(0, Variables::AnchoPantalla - 2, 0, Variables::AltoPantalla + 6);
					Variables::OpcionMenu = 0;
				break;
			}
			cout<<endl<<endl;
			system("cls");
		}

        system("cls");
		MarcoSalir(0, Variables::AnchoPantalla - 2, 0, Variables::AltoPantalla + 6);
		system("pause > 0");
		return 0;
	}


