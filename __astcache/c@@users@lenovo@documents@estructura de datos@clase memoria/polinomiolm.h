﻿
           // PROBADO Y FUNCIONA

//---------------------------------------------------------------------------

#ifndef PolinomioLMH
#define PolinomioLMH
//---------------------------------------------------------------------------

#include <iostream>
#include <string>
#include "ListaM.h"
using namespace std;


class PolinomioLM{

	private:
		ListaM* Pol;

		int buscar_exponente(int exp);
		int buscar_termino(int i);

	public:

		PolinomioLM (); //Crea el polinomio
		bool EsCero(); //Devuelve verdadero si el polinomio no tiene terminos
		int Grado(); //devuelve (Grado del Polinomio)
		int Coeficiente (int exp); //Devuelve el Coeficiente que corresponde al termino con exponente dado por el usuario
		void asignar_coeficiente(int coef, int exp);  // modifica el coeficiente de un exponete dado por el usuario
		void Poner_Termino(int coef, int exp); // agrega un termino dado por el usuario al polinomio
		int Numero_Terminos(); // Devuelve el numero de terminos que tiene el polinomio
		int Exponente (int  nroter); // Devuelve el grado de termino dada una posicion
		void sumar(PolinomioLM* p1, PolinomioLM* p2, PolinomioLM* &pr);
		void restar(PolinomioLM* p1, PolinomioLM* p2, PolinomioLM* &pr);
		void multiplicar (PolinomioLM* p1, PolinomioLM* p2, PolinomioLM* &pr);

	   string to_str();

};

#endif


