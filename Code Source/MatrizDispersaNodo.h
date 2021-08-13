
//------------------------------------------------------------------------------

	#ifndef MatrizDispersaNodoH
	#define MatrizDispersaNodoH

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

	template <class T>


	class MatrizDispersaNodo
	{
		private:
		   T object;
		   int x;
		   int y;
		   MatrizDispersaNodo *nextNode;
		   MatrizDispersaNodo *previousNode;
		   MatrizDispersaNodo *upNode;
		   MatrizDispersaNodo *downNode;
	   public:
		  MatrizDispersaNodo(int x, int y);
		  MatrizDispersaNodo(int x, int y, T object);
		  ~MatrizDispersaNodo();

	   int getX();
	   void setX(int x);

	   int getY();
	   void setY(int y);

	   T getObject();
	   void setObject(T object);

	   MatrizDispersaNodo *getNextNode() const;
	   void setNextNode(MatrizDispersaNodo *nextNode);

	   MatrizDispersaNodo *getPreviousNode() const;
	   void setPreviousNode(MatrizDispersaNodo *previousNode);

	   MatrizDispersaNodo *getUpNode() const;
	   void setUpNode(MatrizDispersaNodo *upNode);

	   MatrizDispersaNodo *getDownNode() const;
	   void setDownNode(MatrizDispersaNodo *downNode);
	};


	template<class T>

	MatrizDispersaNodo<T>::MatrizDispersaNodo(int x, int y)
	{
		this -> x = x;
		this -> y = y;
		nextNode = nullptr;
		previousNode = nullptr;
		upNode = nullptr;
		downNode = nullptr;
	}

	template<class T>

	MatrizDispersaNodo<T>::MatrizDispersaNodo(int x, int y, T object)
	{
		this -> x = x;
		this -> y = y;
		this -> object = object;
		nextNode = nullptr;
		previousNode = nullptr;
		upNode = nullptr;
		downNode = nullptr;
	}

	template<class T>

	MatrizDispersaNodo<T>::~MatrizDispersaNodo()
	{

	}

	template<class T>

	int MatrizDispersaNodo<T>::getX()
	{
		return x;
	}

	template<class T>

	void MatrizDispersaNodo<T>::setX(int x)
	{
		this -> x = x;
	}

	template<class T>

	int MatrizDispersaNodo<T>::getY()
	{
		return y;
	}

	template<class T>

	void MatrizDispersaNodo<T>::setY(int y)
	{
		this -> y = y;
	}

	template<class T>

	T MatrizDispersaNodo<T>::getObject()
	{
		return object;
	}

	template<class T>

	void MatrizDispersaNodo<T>::setObject(T object)
	{
		this -> object = object;
	}

	template<class T>

	typename MatrizDispersaNodo<T>::MatrizDispersaNodo *MatrizDispersaNodo<T>::getNextNode() const
	{
		return nextNode;
	}

	template<class T>

	void MatrizDispersaNodo<T>::setNextNode(MatrizDispersaNodo *nextNode)
	{
		this -> nextNode = nextNode;
	}

	template<class T>

	typename MatrizDispersaNodo<T>::MatrizDispersaNodo *MatrizDispersaNodo<T>::getPreviousNode() const
	{
		return previousNode;
	}

	template<class T>

	void MatrizDispersaNodo<T>::setPreviousNode(MatrizDispersaNodo *previousNode)
	{
		this -> previousNode = previousNode;
	}

	template<class T>

	typename MatrizDispersaNodo<T>::MatrizDispersaNodo *MatrizDispersaNodo<T>::getUpNode() const
	{
		return upNode;
	}

	template<class T>

	void MatrizDispersaNodo<T>::setUpNode(MatrizDispersaNodo *upNode)
	{
		this -> upNode = upNode;
	}

	template<class T>

	typename MatrizDispersaNodo<T>::MatrizDispersaNodo *MatrizDispersaNodo<T>::getDownNode() const
	{
		return downNode;
	}

	template<class T>

	void MatrizDispersaNodo<T>::setDownNode(MatrizDispersaNodo *downNode)
	{
		this -> downNode = downNode;
	}

//------------------------------------------------------------------------------
#endif
