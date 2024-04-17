//---------------------------------------------------------------------------

#ifndef MatrizLMH
#define MatrizLMH
//---------------------------------------------------------------------------


#include <iostream>
#include <string>
#include "ListaM.h"

using namespace std;

class MatrizL {
private:
	ListaM* k;
	int repe, df, dc;
	int nt;

	int buscar(int f, int c);

public:
	MatrizL();
	MatrizL(CSMemoria* m);
	void dimensionar(int f, int c);
	int dimension_fila();
	int dimension_columna();
	void poner(int f, int c, int valor);
	int elemento(int f, int c);
	void definir_valor_repetido(int valor);
	void mostrar();
	string to_str();


};


#endif
