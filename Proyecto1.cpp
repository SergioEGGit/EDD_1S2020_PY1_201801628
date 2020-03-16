
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
	#include <DiccionarioLDC.h>
	#include <FichasCola.h>
	#include <JugadoresABB.h>
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
		MenuPrincipal();

		ListaDLDC ListaDobleCircularDiccionario = NULL;
		ColaFichas ColaFichasCabeza = NULL;
		ColaFichas ColaFichasCola = NULL;
		ArbolABB ArbolJugadores = NULL;

		int Contador = 0;

		while(Variables::OpcionMenu != 4)
		{
			switch(Variables::OpcionMenu)
			{
				case 1:
					system("cls");
					MarcoArchivo(0, Variables::AnchoPantalla - 2, 0, Variables::AltoPantalla + 6);
					if(Variables::RutaArchivo != "Salir")
					{
						LeerArchivo(Variables::RutaArchivo, ListaDobleCircularDiccionario);
					}
					system("cls");
					MarcoMenu(0, Variables::AnchoPantalla - 2, 0, Variables::AltoPantalla + 6);
					MenuPrincipal();
				break;

				case 2:
					system("cls");
					MarcoJugar(0, Variables::AnchoPantalla - 2, 0, Variables::AltoPantalla + 6);
					MenuJugar();
					while(Variables::OpcionJugar != 3)
					{
						switch(Variables::OpcionJugar)
						{
							case 1:
                                system("cls");
                                MarcoJugar(0, Variables::AnchoPantalla - 2, 0, Variables::AltoPantalla + 6);
								MenuJugar();
								for(Contador = 0; Contador <= 5; Contador++)
								{
									cout<< RecorridoPreOrden(ArbolJugadores);
								}
								system("pause > 0");
							break;

							case 2:
								system("cls");
								MarcoJugar(0, Variables::AnchoPantalla - 2, 0, Variables::AltoPantalla + 6);
								AgregarJugadores();
								InsertarNombreABB(ArbolJugadores, Variables::NombreJugador);
								system("pause > 0");
								system("cls");
                                MarcoJugar(0, Variables::AnchoPantalla - 2, 0, Variables::AltoPantalla + 6);
								MenuJugar();
							break;

							default:
								system("cls");
								MarcoJugar(0, Variables::AnchoPantalla - 2, 0, Variables::AltoPantalla + 6);
								MenuJugar();
							break;
						}
					}
                    system("cls");
					MarcoMenu(0, Variables::AnchoPantalla - 2, 0, Variables::AltoPantalla + 6);
					MenuPrincipal();
				break;

				case 3:
					system("cls");
					MarcoReportes(0, Variables::AnchoPantalla - 2, 0, Variables::AltoPantalla + 6);
					MenuReporte();
					while(Variables::OpcionReporte != 3)
					{
						switch(Variables::OpcionReporte)
						{
							case 1:
								ReporteDiccionario(ListaDobleCircularDiccionario);
								system("pause > 0");
								system("cls");
								MarcoReportes(0, Variables::AnchoPantalla - 2, 0, Variables::AltoPantalla + 6);
								MenuReporte();
							break;

							case 2:
								GenerarFichas(ColaFichasCabeza, ColaFichasCola);
								ReporteColaFichas(ColaFichasCabeza);
                                system("pause > 0");
								system("cls");
								MarcoReportes(0, Variables::AnchoPantalla - 2, 0, Variables::AltoPantalla + 6);
								MenuReporte();
							break;

							default:
								system("cls");
                                MarcoReportes(0, Variables::AnchoPantalla - 2, 0, Variables::AltoPantalla + 6);
								MenuReporte();
							break;
						}
					}
                    system("cls");
					MarcoMenu(0, Variables::AnchoPantalla - 2, 0, Variables::AltoPantalla + 6);
					MenuPrincipal();
				break;

				default:
					system("cls");
					MarcoMenu(0, Variables::AnchoPantalla - 2, 0, Variables::AltoPantalla + 6);
					MenuPrincipal();
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


