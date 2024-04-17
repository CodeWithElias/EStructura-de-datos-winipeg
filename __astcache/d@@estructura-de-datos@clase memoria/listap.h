//---------------------------------------------------------------------------

#ifndef ListaPH
#define ListaPH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;

struct NodoL{
	int elemento;
	NodoL* sig;
};

typedef NodoL* direccionP;

class ListaP{
	// Atributos
	private:
		direccionP PtrElemento;
		int longi;

	public:
		ListaP();
		direccionP fin();
		direccionP primero();
		direccionP siguiente(direccionP d);
		direccionP anterior(direccionP d);
		bool vacio();
		int recupera(direccionP d);
		int Longitud();
		void insertar(direccionP d, int elem);
		void insertar_primero(int elem);
		void insertar_ultimo(int elem);
		void suprime(direccionP d);
		void modifica(direccionP d, int elem);
        string tostr();

};

#endif
