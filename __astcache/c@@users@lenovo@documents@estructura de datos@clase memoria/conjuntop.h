
       // FUNCIONA Y ESTA PROBADO

//---------------------------------------------------------------------------

#ifndef ConjuntoPH
#define ConjuntoPH
//---------------------------------------------------------------------------

#include <iostream>
#include <string>

using namespace std;

struct NodoConj {
	int dato;
	NodoConj* sig;
};

class ConjuntoPtr {
private:
	NodoConj* ptrConj;
	int cant;

	NodoConj* localiza(int e);
	NodoConj* anterior(NodoConj *p);

public:
	ConjuntoPtr();
	bool vacio();
	int cardinal();
	int ordinal(int e);
	void inserta(int e);
	void suprime(int e);
	bool pertenece(int e);
	int muestrea();
	int elemento(int pos);
	void reiniciar();
	string toStr();
	void unir(ConjuntoPtr *b, ConjuntoPtr *c);
	// ConjuntoPtr* unir(ConjuntoPtr* B);
	void intersectar(ConjuntoPtr *b, ConjuntoPtr *c);
	ConjuntoPtr* diferenciaSimetrica(ConjuntoPtr* b);

	void unionC(ConjuntoPtr *a, ConjuntoPtr *b, ConjuntoPtr *c);
	void interseccion(ConjuntoPtr *a, ConjuntoPtr *b, ConjuntoPtr *c);
};


#endif
