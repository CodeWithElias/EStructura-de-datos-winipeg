//---------------------------------------------------------------------------

#ifndef DiColaPH
#define DiColaPH
//---------------------------------------------------------------------------


#include <iostream>
#include <string>

using namespace std;

struct NodoD {
	NodoD* ant;
	int elemento;
	NodoD* sig;
};

class Dicola {
private:
	NodoD* ini;
	NodoD* fin;

public:
	Dicola();
	bool vacia();
	void poner(int e);
	void sacar(int &e);
	int primero();
	int ultimo();
	void poner_frente(int e);
	void sacar_final(int &e);
	void mostrar();
	string to_str();
};
#endif
