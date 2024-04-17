﻿
      // PROBADO Y FUNCIONA

//---------------------------------------------------------------------------

#ifndef UMemoriaH
#define UMemoriaH
//---------------------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

typedef int direccion_mem;
/*
constantes Max =20
Nulo =-1
*/
const int Max=20;
const int Nulo=-1;

/*
NodoM
dato tipodato (entero)
id cadena(12)
link direccion de Memoria(entero)
fin tipo
*/
struct NodoMem{
	int dato;
	string id;
	int link;
};


// CREAR CLASE
class CSMemoria{
//	atributos
	private:
	//mem arreglo (max) de tipo nodomem
	NodoMem *mem;
	//libre, direccion de memoria (entero)
	direccion_mem libre;

	public:
	CSMemoria();  // crear
	direccion_mem new_espacio(string cadena);
	void Delete_espacio(int dir);
	void poner_dato(int dir, string cadena_id, int valor);
	int obtener_dato(int dir, string lugar);
	int Espacio_disponible();
	int Espacio_ocupado();
	bool dir_libre(int dir);
	void mostrar_memoria();

};
#endif
