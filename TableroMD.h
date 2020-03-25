//------------------------------------------------------------------------------

	#ifndef TableroMDH
	#define TableroMDH

//------------------------------Librerias---------------------------------------

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

//-----------------------------Estructura---------------------------------------

	struct Matriz
	{
		string Letra;
		int X;
		int Y;
		struct Matriz *UP;
		struct Matriz *DOWN;
		struct Matriz *RIGHT;
		struct Matriz *LEFT;
	};

	typedef struct Matriz *MatrizDispersa;


//-----------------------------Métodos------------------------------------------

	MatrizDispersa Nodo(MatrizDispersa Header, string Letra, int x, int y);

	MatrizDispersa BuscarFila(MatrizDispersa Raiz, int Y);

	MatrizDispersa BuscarColumna(MatrizDispersa Raiz, int X);

	MatrizDispersa InsertarOrdenadoColumna(MatrizDispersa Nuevo, MatrizDispersa Cabeza_Col);

	MatrizDispersa InsertarOrdenadoFila(MatrizDispersa Nuevo, MatrizDispersa Cabeza_Fila);

	MatrizDispersa CrearColumna(MatrizDispersa Raiz, int X);

	MatrizDispersa CrearFila(MatrizDispersa Raiz, int Y);

	void InsertarElementoMD(MatrizDispersa Header, int X, int Y, string Letra);

//------------------------------------------------------------------------------

	#endif
