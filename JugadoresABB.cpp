//------------------------------------------------------------------------------

	#pragma hdrstop

//---------------------------------Librerias------------------------------------

	#include <iostream>
	#include <stdio.h>
	#include <conio.h>
	#include <string>
	#include <cstdlib>
	#include <fstream>
	#include <windows.h>
	#include "JugadoresABB.h"
	#include "Metodos.h"
	#include "RecorridosLS.h"
	using namespace std;

//------------------------------------------------------------------------------

	#pragma package(smart_init)

//---------------------------------Métodos--------------------------------------

	ArbolABB CrearNombreABB(ArbolABB &Padre, string Nombre)
	{
		ArbolABB aux = new(struct Jugadores);

		aux -> Nombre = Nombre;
		aux -> RIGHT = NULL;
		aux -> LEFT  = NULL;
		aux -> Padre = Padre;

		return aux;
   }

	void InsertarNombreABB(ArbolABB &Arbol, ArbolABB &Padre, string Nombre)
	{
		if(Arbol == NULL)
		{
			ArbolABB aux = CrearNombreABB(Padre, Nombre);
			Arbol = aux;
			Color(0, 2);
			gotoxy((Variables::AnchoPantalla/2) + 1, 5);
			cout<< "Nombre Agregado Con Exito" <<endl;
		}
		else
		{
			string Raiz = Arbol -> Nombre;

			if(BusquedaABB(Arbol, Nombre) == true)
			{
                Color(0, 4);
				gotoxy((Variables::AnchoPantalla/2) + 1, 5);
				cout<< "El Usuario Ya Existe En El Sistema." <<endl;
			}
			else
			{
				if(Nombre.compare(Raiz) < 0)
				{
					InsertarNombreABB(Arbol -> LEFT, Padre, Nombre);
					Color(0, 2);
					gotoxy((Variables::AnchoPantalla/2) + 1, 5);
					cout<< "Nombre Agregado Con Exito" <<endl;
				}
				else if(Nombre.compare(Raiz) > 0)
				{
					InsertarNombreABB(Arbol -> RIGHT, Padre, Nombre);
					Color(0, 2);
					gotoxy((Variables::AnchoPantalla/2) + 1, 5);
					cout<< "Nombre Agregado Con Exito" <<endl;
				}
			}
		}
	}

	void ImprimirABB(ArbolABB &Arbol, int Contador)
	{
		if(Arbol == NULL)
		{
			return;
		}
		else
		{
			ImprimirABB(Arbol -> RIGHT, Contador + 1);
            Color(0, 9);
			gotoxy((Variables::AnchoPantalla/2) - 5, Contador + 5);
			cout<< Contador << "." << Arbol -> Nombre <<endl;
			ImprimirABB(Arbol -> LEFT, Contador + 1);
		}
	}

	bool BusquedaABB(ArbolABB &Arbol, string Nombre)
	{
		if(Arbol == NULL)
		{
			return false;
		}
		else if(Arbol -> Nombre == Nombre)
		{
			return true;
		}
		else if(Nombre.compare(Arbol -> Nombre) < 0)
		{
			return BusquedaABB(Arbol -> LEFT, Nombre);
		}
		else
		{
			return BusquedaABB(Arbol -> RIGHT, Nombre);
        }

	}

	void RecorridoPreOrden(ArbolABB &Arbol, ListaLS &Lista)
	{
		if(Arbol == NULL)
		{
			return;
		}
		else
		{
			InsertarFinal(Lista, Arbol -> Nombre);
			RecorridoPreOrden(Arbol -> LEFT , Lista);
			RecorridoPreOrden(Arbol -> RIGHT, Lista);
		}
	}

	void RecorridoInOrden(ArbolABB &Arbol, ListaLS &Lista)
	{
		if(Arbol == NULL)
		{
			return;
		}
		else
		{
			RecorridoInOrden(Arbol -> LEFT, Lista);
			InsertarFinal(Lista, Arbol -> Nombre);
			RecorridoInOrden(Arbol -> RIGHT, Lista);
		}
	}

	void RecorridoPostOrden(ArbolABB &Arbol, ListaLS &Lista)
	{
		if(Arbol == NULL)
        {
			return;
		}
		else
		{
			RecorridoPostOrden(Arbol -> LEFT, Lista);
			RecorridoPostOrden(Arbol -> RIGHT, Lista);
			InsertarFinal(Lista, Arbol -> Nombre);
		}


	}

	string ReporteABB(ArbolABB &Arbol)
	{
		if(Arbol == NULL)
		{
			Variables::CadenaArbol = "";
		}
		else
		{
			int Num = Variables::ContadorArbol;
			Variables::CadenaArbol = Variables::CadenaArbol + "N" + to_string(Num) + "[label = \"" + Arbol -> Nombre + "\"]\n";

			if(Arbol -> LEFT != NULL)
			{
				Variables::ContadorArbol++;
				Variables::CadenaArbol = Variables::CadenaArbol + "N" + to_string(Num) + "->" + "N" + to_string(Variables::ContadorArbol) + "\n";
				ReporteABB(Arbol -> LEFT);
			}
			if(Arbol -> RIGHT != NULL)
			{
				Variables::ContadorArbol++;
				Variables::CadenaArbol = Variables::CadenaArbol + "N" + to_string(Num) + "->" + "N" + to_string(Variables::ContadorArbol) + "\n";
				ReporteABB(Arbol -> RIGHT);
			}
		}
		return Variables::CadenaArbol;


	}





