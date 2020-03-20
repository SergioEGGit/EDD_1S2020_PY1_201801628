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
	#include "RecorridosLS.h"
	using namespace std;

//------------------------------------------------------------------------------

	#pragma package(smart_init)

//---------------------------------Métodos--------------------------------------

	void InsertarFinal(ListaLS &Lista, string Nombre)
	{
		ListaLS auxT, auxQ = new(struct Recorridos);
		auxQ -> Nombre = Nombre;
		auxQ -> sgte = NULL;

		if(Lista == NULL)
		{
			Lista = auxQ;
		}
		else
		{
			auxT = Lista;

			while(auxT -> sgte != NULL)
			{
				auxT = auxT -> sgte;
			}
			auxT -> sgte = auxQ;
		}
	}
