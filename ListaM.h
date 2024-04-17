
        // PROBADO Y FUNCIONA

//---------------------------------------------------------------------------

#ifndef ListaMH
#define ListaMH
//---------------------------------------------------------------------------

#include <iostream>
#include <string>
#include "UMemoria.h"
using namespace std;


 const string datoNL="elemento,sig";
 const string elemNL="->elemento";
 const string sigNL="->sig";

 class ListaM{
   //Atributos
 private:
	int PtrElementos;
	int longit;
	CSMemoria* mem;
 //Métodos
 public:
	ListaM();
	ListaM(	CSMemoria* m);   //CREA LA LISTA EN LA MEMORIA
	int fin();
	int primero();
	int siguiente(int d);
	int anterior( int d);
	bool vacia();
	int recupera(int d);
	int longitud();
	void inserta( int d, int elem);
	void inserta_primero(int elem);
	void inserta_ultimo(int elem);
	void suprime( int d);
	void modifica( int d, int elem) ;
	string to_str();
 };
#endif
