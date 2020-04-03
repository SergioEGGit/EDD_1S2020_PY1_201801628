//------------------------------------------------------------------------------

	#ifndef FichasLSH
	#define FichasLSH

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

	struct FichasDT
	{
		int X;
		int Y;;
		string Tipo;
		struct FichasDT *sgte;
	};

	typedef struct FichasDT *ListaFichas;


//-----------------------------Métodos------------------------------------------

	void InsertarFinalListaFichas(ListaFichas &Lista, int X, int Y, string Tipo);

	string BuscarFichasLS(ListaFichas &Lista, int x, int y);

//------------------------------------------------------------------------------

	#endif
