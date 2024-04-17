
			  // FUNCIONA Y ESTA PROBADO

//---------------------------------------------------------------------------

#ifndef ConjuntoLH
#define ConjuntoLH
#include "ListaP.h"
//---------------------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;


class ConjuntoL{
	private:

		ListaP* elem;

	public:

		ConjuntoL();
		bool vacio();
		bool pertenece(int e);
		void inserta(int e);
		int cardinal();
		int ordinal(int e);
		void suprime(int e);
		int muestrea();
		string to_str();
		void unir(ConjuntoL* b, ConjuntoL* c);
		void intercectar(ConjuntoL* b, ConjuntoL* c);
		void reiniciar();
};

#endif
