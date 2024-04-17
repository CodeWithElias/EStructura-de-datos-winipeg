
  // FUNDIONA Y ESTA PROBADO

//---------------------------------------------------------------------------

#ifndef MatrizMH
#define MatrizMH
//---------------------------------------------------------------------------


#include <string>
#include <iostream>
#include "UMemoria.h"

using namespace std;


const string p_data = "fila,columna,dato,sig";
const string at_fila = "->fila";
const string at_columna = "->columna";
const string at_dato =  "->dato";
const string at_sig = "->sig";


class MatrizM{
private:
	CSMemoria *mem;
	int ptrmatd;
	int rep,dimf,dimc,nt;

	//metodos privados
	int anterior(int p);
	void suprime(int p);
	int buscar(int f, int c);


public:
	MatrizM();
	MatrizM(CSMemoria *m);
	void dimensionar(int f,int c);
	int dimension_Fila();
	int dimension_Columna();
	void poner(int f, int c, int valor);
	int elemento(int f, int c);
	void definir_valor_repetido(int valor);
	void to_str();



};


#endif
