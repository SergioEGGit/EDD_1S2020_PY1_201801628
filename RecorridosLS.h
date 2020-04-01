
//------------------------------------------------------------------------------

	#ifndef RecorridoLSH
	#define RecorridoLSH

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

	struct Recorridos
	{
		string Nombre;
		struct Recorridos *sgte;
	};

	typedef struct Recorridos *ListaLS;


//-----------------------------Métodos------------------------------------------

	void InsertarFinal(ListaLS &Lista, string Nombre);
	
	void ImprimirRecorridosLS(ListaLS &Lista, int Contador);
	
	int NumeroNodos(ListaLS &Lista);

//------------------------------------------------------------------------------

	#endif
