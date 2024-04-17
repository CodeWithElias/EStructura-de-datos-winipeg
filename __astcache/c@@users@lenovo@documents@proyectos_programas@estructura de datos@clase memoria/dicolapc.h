//---------------------------------------------------------------------------

#ifndef DiColaPCH
#define DiColaPCH
//---------------------------------------------------------------------------

#include <iostream>
#include <string>

#include "ColaP.h"

using namespace std;


class DicolaP {
private:
	NodoC* ini;
	NodoC* fin;

public:
	DicolaP();
	bool vacia();
	void poner(int e);
	void sacar(int &e);
	int primero();
	int ultimo();
	void poner_frente(int e);
	void sacar_final(int &e);
	string tostr();
};



#endif
