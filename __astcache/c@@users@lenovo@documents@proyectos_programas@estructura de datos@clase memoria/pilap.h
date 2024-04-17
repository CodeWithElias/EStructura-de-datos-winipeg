﻿
         // FUNCIONA Y ESTA PROBADO

//---------------------------------------------------------------------------

#ifndef PilaPH
#define PilaPH
//---------------------------------------------------------------------------

#include <iostream>
#include <string>


using namespace std;

struct NodoP{
	int elemento;
	NodoP* sig;
};

class PilaP{
	private:
		NodoP* tope;
	public:
		PilaP();
		bool vacia();
		void meter(int e);
		void sacar(int& e);
		int cima();
		string to_str();
};

#endif
