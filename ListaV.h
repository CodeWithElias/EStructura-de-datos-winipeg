
         // FUNCIONA Y PROBADO

//---------------------------------------------------------------------------

#ifndef ListaVH
#define ListaVH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

typedef int direccionI;

	const int MaxV=100;
	const int NuloV=0;


class ListaV{
	private:

		int* elementos;
		int longi;

	public:
		ListaV();
		direccionI fin();
		direccionI primero();
		direccionI siguiente(direccionI dir);
		direccionI anterior(direccionI dir);
		bool vacia();
		int recupera(direccionI dir);
		int longitud();
		void inserta(direccionI dir, int e);
		void inserta_primero(int e);
		void inserta_ultimo(int e);
		void suprime(direccionI dir);
		void modifica(direccionI dir, int e);

		string to_str();
};
#endif
