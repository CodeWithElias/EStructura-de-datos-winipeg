
    // FUNCIONA Y ESTA PROBADO

//---------------------------------------------------------------------------

#ifndef ColaLH
#define ColaLH
//---------------------------------------------------------------------------

#include <iostream>
#include <string>
#include "ListaV.h"

using namespace std;

class ColaL {
private:
	ListaV* L;

public:
	ColaL();
	bool vacia();
	void poner(int e);
	void sacar(int &e);
	int primero();
	string to_str();
};

#endif
