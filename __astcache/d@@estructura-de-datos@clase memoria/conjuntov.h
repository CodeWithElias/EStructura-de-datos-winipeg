//---------------------------------------------------------------------------

#ifndef ConjuntoVH
#define ConjuntoVH
//---------------------------------------------------------------------------

#include <iostream>
#include <string>

using namespace std;

const int Maxc =10;

class ConjuntoV{
	private:
		int *vec;
		int cant;

	public:

		ConjuntoV();
		bool vacio();
		int cardinal();
		int ordinal(int e);
		void inserta(int e);
		void suprime(int e);
		bool pertenece(int e);
		int muestrea();
		int elemento(int pos);
		string tostr();
		void unir(ConjuntoV * b, ConjuntoV* c);
		void intercectar(ConjuntoV * b, ConjuntoV* c);
};

#endif
