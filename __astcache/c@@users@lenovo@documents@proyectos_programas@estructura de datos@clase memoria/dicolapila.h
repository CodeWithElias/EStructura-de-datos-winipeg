//---------------------------------------------------------------------------

#ifndef DiColaPilaH
#define DiColaPilaH
//---------------------------------------------------------------------------


#include <iostream>
#include <string>
#include "PilaP.h"



class DicolaPila {
private:
	PilaP* k;

public:
	DicolaPila();
	bool vacia();
	void poner(int e);
	void sacar(int &e);
	int primero();
	int ultimo();
	void poner_frente(int e);
	void sacar_final(int &e);
	string to_str();
};


#endif
