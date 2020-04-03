//------------------------------------------------------------------------------

	#ifndef JugadoresFichasLDH
	#define JugadoresFichasLDH

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

	struct FichasJugadores
	{
		string Letra;
		int Punteo;
		struct FichasJugadores *sgte;
		struct FichasJugadores *ante;
	};

	typedef struct FichasJugadores *ListaLDJ;

//-----------------------------Métodos------------------------------------------

	void InsertarInicioLDJ(ListaLDJ &Cabeza, ListaLDJ &Cola, string Letra , int Punteo);

	void InsertarFinalLDJ(ListaLDJ &Cabeza, ListaLDJ &Cola, string Letra, int Punteo);

	void InsertarEnMedioLDJ(ListaLDJ &Cabeza, ListaLDJ &Cola, string Letra, int Punteo, int Posicion);

    int SizeLDJ(ListaLDJ &Cabeza);

	void EliminarLDJ(ListaLDJ &Cabeza, ListaLDJ &Cola, int Posicion);

//------------------------------------------------------------------------------

	#endif
