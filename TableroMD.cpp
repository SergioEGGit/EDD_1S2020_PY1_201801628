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
	#include "TableroMD.h"
	using namespace std;

//------------------------------------------------------------------------------

	#pragma package(smart_init)

//---------------------------------Métodos--------------------------------------

	MatrizDispersa Nodo(MatrizDispersa Header, string Letra, int X, int Y)
	{
		Header -> Letra = Letra;
		Header -> X = X;
		Header -> Y = Y;
		Header -> RIGHT = NULL;
		Header -> LEFT = NULL;
		Header -> UP = NULL;
		Header -> DOWN = NULL;
	}

	MatrizDispersa BuscarFila(MatrizDispersa Raiz, int Y)
	{
		MatrizDispersa Temp = Raiz;

		while(Temp != NULL)
		{
			if(Temp -> Y == Y)
			{
				return Temp;
			}
			Temp = Temp -> DOWN;
		}
		return NULL;
	}

	MatrizDispersa BuscarColumna(MatrizDispersa Raiz, int X)
	{
		MatrizDispersa Temp = Raiz;

		while(Temp != NULL)
		{
			if(Temp -> X == X)
			{
				return Temp;
			}
			Temp = Temp -> RIGHT;
		}
		return NULL;
    }

	MatrizDispersa InsertarOrdenadoColumna(MatrizDispersa Nuevo, MatrizDispersa Cabeza_Col)
	{
		MatrizDispersa Temp = Cabeza_Col;
		bool Bandera = false;

		while(true)
		{
			if(Temp -> X == Nuevo -> X)
			{
				Temp -> Y = Nuevo -> Y;
				Temp -> Letra = Nuevo -> Letra;
				return Temp;
			}
			else if(Temp -> X > Nuevo -> X)
			{
				Bandera = true;
				break;
			}

			if(Temp -> RIGHT != NULL)
			{
				Temp = Temp -> RIGHT;
			}
			else
			{
				break;
            }
		}

		if(Bandera)
		{
			Nuevo -> RIGHT = Temp;
			Temp -> LEFT -> RIGHT = Nuevo;
			Nuevo -> LEFT = Temp -> LEFT;
			Temp -> LEFT = Nuevo;
		}
		else
		{
			Temp -> RIGHT = Nuevo;
			Nuevo -> LEFT = Temp;
		}
		return Nuevo;







	}

	MatrizDispersa InsertarOrdenadoFila(MatrizDispersa Nuevo, MatrizDispersa Cabeza_Fila)
	{
		MatrizDispersa Temp = Cabeza_Fila;
		bool Bandera = false;

		while(true)
		{
			if(Temp -> Y == Nuevo -> Y)
			{
				Temp -> X = Nuevo -> X;
				Temp -> Letra = Nuevo -> Letra;
				return Temp;
			}
			else if(Temp -> Y > Nuevo -> Y)
			{
				Bandera = true;
				break;
			}

			if(Temp -> DOWN != NULL)
			{
				Temp = Temp -> DOWN;
			}
			else
			{
				break;
            }
		}

		if(Bandera)
		{
			Nuevo -> DOWN = Temp;
			Temp -> UP -> DOWN = Nuevo;
			Nuevo -> UP = Temp -> UP;
			Temp -> UP = Nuevo;
		}
		else
		{
			Temp -> DOWN = Nuevo;
			Nuevo -> UP = Temp;
        }
		return Nuevo;
	}

	MatrizDispersa CrearColumna(MatrizDispersa Raiz, int X)
	{
		MatrizDispersa Cabeza_Columna = Raiz;
		MatrizDispersa Columna = InsertarOrdenadoColumna(Nodo(Raiz, "Col", X, -1), Cabeza_Columna);
		return Columna;
	}

	MatrizDispersa CrearFila(MatrizDispersa Raiz, int Y)
	{
		MatrizDispersa Cabeza_Fila = Raiz;
		MatrizDispersa Fila = InsertarOrdenadoFila(Nodo(Raiz, "Fil", -1, Y), Cabeza_Fila);
		return Fila;
	}

	void InsertarElementoMD(MatrizDispersa Header, int X, int Y, string Letra)
	{
		MatrizDispersa Nuevo =  Nodo(Header, Letra, X, Y);
		MatrizDispersa NodoColumna = BuscarColumna(Header, X);
		MatrizDispersa NodoFila = BuscarFila(Header, Y);

		if(NodoColumna == NULL && NodoFila == NULL)
		{
			cout<< "Caso 1";
			NodoColumna = CrearColumna(Header, X);
			NodoFila = CrearFila(Header, Y);
			Nuevo = InsertarOrdenadoColumna(Nuevo, NodoFila);
			Nuevo = InsertarOrdenadoFila(Nuevo, NodoColumna);
			return;
		}
		else if(NodoColumna == NULL && NodoFila != NULL)
		{
			cout<< "Caso 2";
			NodoColumna = CrearColumna(Header, X);
			Nuevo = InsertarOrdenadoColumna(Nuevo, NodoFila);
			Nuevo = InsertarOrdenadoFila(Nuevo, NodoColumna);
			return;
		}
		else if(NodoColumna != NULL && NodoFila == NULL)
		{
			cout<< "Caso 3";
			NodoFila = CrearFila(Header, Y);
			Nuevo = InsertarOrdenadoColumna(Nuevo, NodoFila);
			Nuevo = InsertarOrdenadoFila(Nuevo, NodoColumna);
			return;
		}
		else if(NodoColumna != NULL && NodoFila != NULL)
		{
			cout<< "Caso 4";
			Nuevo = InsertarOrdenadoColumna(Nuevo, NodoFila);
			Nuevo = InsertarOrdenadoFila(Nuevo, NodoColumna);
        }
	}
