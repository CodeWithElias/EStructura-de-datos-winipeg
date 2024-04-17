//---------------------------------------------------------------------------

#ifndef PolinomioV2H
#define PolinomioV2H
//---------------------------------------------------------------------------

#include <iostream>
#include <string>

using namespace std;

const int MAXP = 20;

class PoliV {
private:
	int* vEPC; // int v[MAXP];
	int ntEPC;

public:
	PoliV();
	bool es_cero();
	int grado();
	int coeficiente(int exp);
	void poner_termino(int coef, int exp);
	int numero_terminos();
	int exponente(int nro);
	void sumar(PoliV* p1, PoliV* p2, PoliV* &pr);
	void restar(PoliV* p1, PoliV* p2, PoliV* &pr);
	void multiplicar(PoliV* p1, PoliV* p2, PoliV* &pr);
	void derivar();
	void derivar2();
    float evaluar(float x);
	string to_str();
    string vectorToString();
};



#endif
