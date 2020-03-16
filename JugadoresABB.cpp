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
	using namespace std;

//------------------------------------------------------------------------------

	#pragma package(smart_init)

//---------------------------------M�todos--------------------------------------

	ArbolABB CrearNombreABB(string Nombre)
	{
		ArbolABB aux = new(struct Jugadores);

		aux -> Nombre = Nombre;
		aux -> RIGHT = NULL;
		aux -> LEFT  = NULL;

		return aux;
   }

	void InsertarNombreABB(ArbolABB &Arbol, string Nombre)
	{
		if(Arbol == NULL)
		{
			ArbolABB aux = CrearNombreABB(Nombre);
			Arbol = aux;
			Color(0, 2);
			gotoxy((Variables::AnchoPantalla/2) + 1, 5);
			cout<< "Nombre Agregado Con Exito" <<endl;
		}
		else
		{
			string Raiz = Arbol -> Nombre;

			if(Nombre.compare(Raiz) == 0)
			{
				Color(0, 4);
				gotoxy((Variables::AnchoPantalla/2) + 1, 5);
				cout<< "El Usuario Ya Existe En El Sistema." <<endl;
			}
			else if(Nombre.compare(Raiz) < 0)
			{
                InsertarNombreABB(Arbol -> LEFT, Nombre);
				Color(0, 2);
				gotoxy((Variables::AnchoPantalla/2) + 1, 5);
				cout<< "Nombre Agregado Con Exito" <<endl;
			}
			else if(Nombre.compare(Raiz) > 0)
			{
				InsertarNombreABB(Arbol -> RIGHT, Nombre);
				Color(0, 2);
				gotoxy((Variables::AnchoPantalla/2) + 1, 5);
				cout<< "Nombre Agregado Con Exito" <<endl;
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
			for(int i = 0; i < Contador; i++)
			{
				cout<< "    ";
			}
			cout<< Arbol -> Nombre <<endl;
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

	string RecorridoPreOrden(ArbolABB &Arbol)
	{
		if(Arbol == NULL)
		{
			return "Vacio";
		}
		else
		{
			return Arbol -> Nombre;
			RecorridoPreOrden(Arbol -> LEFT);
			RecorridoPreOrden(Arbol -> RIGHT);
		}
	}