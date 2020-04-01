
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
	#include <RecorridosLS.h>
    #include <FichasLS.h>
	#include <MatrizDispersa.h>
	using namespace std;

//--------------------------------Variables-------------------------------------



//---------------------------------Métodos--------------------------------------


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
		ArbolABB NodoPadre = NULL;
		ListaLS ListaRecorridos = NULL;
		ListaLDJ CabezaJugador1 = NULL;
		ListaLDJ ColaJugador1 = NULL;
		ListaLDJ CabezaJugador2 = NULL;
		ListaLDJ ColaJugador2 = NULL;
		ListaFichas ListaFichasDT = NULL;
		MatrizDispersa<string> MatrizDispersaMD;

		int Contador = 1;

        while(Variables::OpcionMenu != 4)
		{
			switch(Variables::OpcionMenu)
			{
				case 1:
					system("cls");
					MarcoArchivo(0, Variables::AnchoPantalla - 2, 0, Variables::AltoPantalla + 6);
					if(Variables::RutaArchivo != "Salir")
					{
						LeerArchivo(MatrizDispersaMD, Variables::RutaArchivo, ListaDobleCircularDiccionario, ListaFichasDT);
					}
					system("cls");
					MarcoMenu(0, Variables::AnchoPantalla - 2, 0, Variables::AltoPantalla + 6);
					MenuPrincipal();
				break;

				case 2:
					system("cls");
					MarcoJugar(0, Variables::AnchoPantalla - 2, 0, Variables::AltoPantalla + 6);
					MenuJugar();
					while(Variables::OpcionJugar != 4)
					{
						switch(Variables::OpcionJugar)
						{
							case 1:
								system("cls");
								MarcoJugar(0, Variables::AnchoPantalla - 2, 0, Variables::AltoPantalla + 6);
								ListaRecorridos = NULL;
								RecorridoPreOrden(ArbolJugadores, ListaRecorridos);
								if(ColaFichasCabeza == NULL)
								{
									Color(0, 4);
									gotoxy((Variables::AnchoPantalla/2) - 26, 4);
									cout<< "Aun No Se Han Agregado Fichas Para Comenzar La Partida"<<endl;
									system("pause > 0");
								}
								else if(NumeroNodos(ListaRecorridos) < 2)
								{
									Color(0, 4);
									gotoxy((Variables::AnchoPantalla/2) - 35, 4);
									cout<< "Aun No Se Han Agregado Jugadores Suficientes Para Comenzar La Partida" <<endl;
									system("pause > 0");
								}
								else if(ListaDobleCircularDiccionario == NULL)
								{
                                    Color(0, 4);
									gotoxy((Variables::AnchoPantalla/2) - 38, 4);
									cout<< "Aun No Se Han Agregado Palabras Al Diccionario Para Comenzar La Partida" <<endl;
									system("pause > 0");
								}
								else
								{
									CabezaJugador1 = NULL;
									ColaJugador1 = NULL;
									CabezaJugador2 = NULL;
									ColaJugador2 = NULL;
									Jugar(ArbolJugadores, ListaRecorridos, CabezaJugador1, CabezaJugador2, ColaJugador1, ColaJugador2, ColaFichasCabeza, ColaFichasCola, MatrizDispersaMD, Contador);
									ColaFichasCabeza = NULL;
									ColaFichasCola = NULL;
								}
								system("cls");
								MarcoJugar(0, Variables::AnchoPantalla - 2, 0, Variables::AltoPantalla + 6);
								MenuJugar();
							break;

							case 2:
								system("cls");
								MarcoJugar(0, Variables::AnchoPantalla - 2, 0, Variables::AltoPantalla + 6);
								AgregarJugadores();
								InsertarNombreABB(ArbolJugadores, NodoPadre, Variables::NombreJugador);
								system("pause > 0");
								system("cls");
								MarcoJugar(0, Variables::AnchoPantalla - 2, 0, Variables::AltoPantalla + 6);
								MenuJugar();
							break;

							case 3:
								GenerarFichas(ColaFichasCabeza, ColaFichasCola);
								Color(0, 10);
								gotoxy ((Variables::AnchoPantalla - 2)/2 + 8, 14);
								cout<< "Fichas Agregadas Con Exito" <<endl;
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
					while(Variables::OpcionReporte != 11)
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
								ReporteColaFichas(ColaFichasCabeza);
								system("pause > 0");
								system("cls");
								MarcoReportes(0, Variables::AnchoPantalla - 2, 0, Variables::AltoPantalla + 6);
								MenuReporte();
							break;

							case 3:
								ReporteArbolBinarioBusqueda(ArbolJugadores);
								system("pause > 0");
								system("cls");
								MarcoReportes(0, Variables::AnchoPantalla - 2, 0, Variables::AltoPantalla + 6);
								MenuReporte();
							break;

							case 4:
								ListaRecorridos = NULL;
								RecorridoPreOrden(ArbolJugadores, ListaRecorridos);
								ReporteArbolPreOrden(ListaRecorridos);
								system("pause > 0");
								system("cls");
								MarcoReportes(0, Variables::AnchoPantalla - 2, 0, Variables::AltoPantalla + 6);
								MenuReporte();
							break;

							case 5:
								ListaRecorridos = NULL;
								RecorridoInOrden(ArbolJugadores, ListaRecorridos);
								ReporteArbolInOrden(ListaRecorridos);
								system("pause > 0");
								system("cls");
								MarcoReportes(0, Variables::AnchoPantalla - 2, 0, Variables::AltoPantalla + 6);
								MenuReporte();
							break;

							case 6:
								ListaRecorridos = NULL;
								RecorridoPostOrden(ArbolJugadores, ListaRecorridos);
								ReporteArbolPostOrden(ListaRecorridos);
								system("pause > 0");
								system("cls");
								MarcoReportes(0, Variables::AnchoPantalla - 2, 0, Variables::AltoPantalla + 6);
								MenuReporte();
							break;

							case 7:
								cout<< "Reporte Puntajes";
								system("pause > 0");
								system("cls");
								MarcoReportes(0, Variables::AnchoPantalla - 2, 0, Variables::AltoPantalla + 6);
								MenuReporte();
							break;

							case 8:
							     cout<< "Reporte ScoreBoard";
								system("pause > 0");
								system("cls");
								MarcoReportes(0, Variables::AnchoPantalla - 2, 0, Variables::AltoPantalla + 6);
								MenuReporte();
							break;

							case 9:
								if(MatrizDispersaMD.EstaVacia() == true)
								{
                                    Color(0, 4);
									gotoxy ((Variables::AnchoPantalla - 2)/2 - 2 , 28);
									cout<< "No Se Puede Generar El Reporte La Matriz Se Encuentra Vacia!" <<endl;
								}
								else if(MatrizDispersaMD.EstaVacia() == false)
								{
									MatrizDispersaMD.ReporteMatrizDispersa();
									Color(0, 10);
									gotoxy ((Variables::AnchoPantalla - 2)/2 - 2, 28);
									cout<< "Reporte Generado Con Exito..." <<endl;
								}
								system("pause > 0");
								system("cls");
								MarcoReportes(0, Variables::AnchoPantalla - 2, 0, Variables::AltoPantalla + 6);
								MenuReporte();
							break;

							case 10:
								ReporteJugadoresFichas1Reportes(CabezaJugador1);
								ReporteJugadoresFichas2Reportes(CabezaJugador2);
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


