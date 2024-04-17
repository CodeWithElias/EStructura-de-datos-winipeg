
             // FUNCIONA Y ESTA PROBADO

//---------------------------------------------------------------------------

#ifndef MatrizVH
#define MatrizVH
//---------------------------------------------------------------------------

#include <iostream>
#include <string>

using namespace std;

//int MAX_MV = 0;

class MatrizV {
private:
	int* vf;
	int* vc;
	int* vd;
	int df, dc;
	int repe;
	int nt;

	int posicion(int f, int c);

public:
	MatrizV();    // CREA LA MATRIZ
	void dimensionar(int f, int c);  // DETERMINA LA DIMENCION DE LA MATRIZ
	int dimension_fila(); // DEVUELVE EL NUMERO MAXIMO DE FILAS
	int dimension_columna(); // DEVUELVE EL NUMERO MAXIMO DE COLUMNAS
	void poner(int f, int c, int valor); // ADICIONA UN ELEMENTO EN LA MATRIZ
	int elemento(int f, int c);  // BUSCA EL ELEMENTO QUE ESTA EN F,C
	void definir_valor_repetido(int valor); // ESTABLECE QUE VALOR ES EL QUE MAS SE REPITE EN LA MATRIZ
	string to_str();
};


#endif

