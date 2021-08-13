
//------------------------------------------------------------------------------

	#ifndef DiccionarioLDCH
	#define DiccionarioLDCH

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

	struct Diccionario
	{
		string Palabra;
		struct Diccionario *sgte;
		struct Diccionario *ante;
	};

	typedef struct Diccionario *ListaDLDC;


//-----------------------------Métodos------------------------------------------

	void InsertarPrimeroPalabraDLDC(ListaDLDC &Lista, string Palabra);

	void InsertarUltimoPalabraDLDC(ListaDLDC &Lista, string Palabra);

	bool EstaVaciaDLDC(ListaDLDC &Lista);

	void ImprimirDLDC(ListaDLDC &Lista);

	int CantidadDLDC(ListaDLDC &Lista);

	void EliminarPalabraDLDC(ListaDLDC &Lista, int Posicion);

    bool BuscarPalabraDLDC(ListaDLDC &Lista, string Palabra);

//------------------------------------------------------------------------------

	#endif
