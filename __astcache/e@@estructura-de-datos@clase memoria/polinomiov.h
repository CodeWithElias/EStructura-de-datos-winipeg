﻿
          //APROBADO Y FUNCIONA

#include <iostream>
#include <string>
//---------------------------------------------------------------------------

#ifndef PolinomioVH
#define PolinomioVH
//---------------------------------------------------------------------------
using namespace std;

const int MaxP=100;

class PolinomioV{
	private:

		int coeficiente[MaxP];
		int exponente[MaxP];
		int Nterminos;

	public:

		PolinomioV (); //Crea el polinomio
		bool EsCero(); //Devuelve verdadero si el polinomio no tiene terminos
		int Grado(); //devuelve (Grado del Polinomio)
		void asignar_coeficiente(int coef, int exp);  // modifica el coeficiente de un exponete dado por el usuario
		void Poner_Termino(int coef, int exp); // agrega un termino dado por el usuario al polinomio
		int Numero_Terminos(); // Devuelve el numero de terminos que tiene el polinomio
		int Coeficiente (int exp); //Devuelve el Coeficiente que corresponde al termino con exponente dado por el usuario
		int Exponente (int  nroter); // Devuelve el grado de termino dada una posicion
		void sumar(PolinomioV* p1, PolinomioV* p2, PolinomioV* &pr);
		void restar(PolinomioV* p1, PolinomioV* p2, PolinomioV* &pr);
	   //	void multiplicar (P1, P2: Polinomio);

	   int Pos_Exponente(int exp); // devuelve la posicion del exponente
	   string to_str();
};

#endif
