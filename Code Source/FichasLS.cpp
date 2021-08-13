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
	#include "FichasLS.h"
	using namespace std;

//------------------------------------------------------------------------------

	#pragma package(smart_init)

//---------------------------------Métodos--------------------------------------

	void InsertarFinalListaFichas(ListaFichas &Lista, int X, int Y, string Tipo)
	{
		ListaFichas auxT, auxQ = new(struct FichasDT);
		auxQ -> X = X;
		auxQ -> Y = Y;
		auxQ -> Tipo = Tipo;
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


	string BuscarFichasLS(ListaFichas &Lista, int x, int y)
	{
		ListaFichas aux = Lista;
		string Tipo = "";

		while(aux != NULL)
		{
			if(x == aux -> X)
			{
				if(y == aux -> Y)
				{
					Tipo = aux -> Tipo;
                }
			}
			aux = aux -> sgte;
		}
		return Tipo;
    }
