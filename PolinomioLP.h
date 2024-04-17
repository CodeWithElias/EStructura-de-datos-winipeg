//---------------------------------------------------------------------------

#ifndef PolinomioLPH
#define PolinomioLPH
//---------------------------------------------------------------------------

#include <iostream>
#include <string>
#include "ListaP.h"
using namespace std;


class PolinomioLP{

	private:
		ListaP* Pol;

		direccionP buscar_exponente(int exp);
		direccionP buscar_termino(int i);

	public:

		PolinomioLP (); //Crea el polinomio
		bool EsCero(); //Devuelve verdadero si el polinomio no tiene terminos
		int Grado(); //devuelve (Grado del Polinomio)
		int Coeficiente (int exp); //Devuelve el Coeficiente que corresponde al termino con exponente dado por el usuario
		void asignar_coeficiente(int coef, int exp);  // modifica el coeficiente de un exponete dado por el usuario
		void Poner_Termino(int coef, int exp); // agrega un termino dado por el usuario al polinomio
		int Numero_Terminos(); // Devuelve el numero de terminos que tiene el polinomio
		int Exponente (int  nroter); // Devuelve el grado de termino dada una posicion
		void sumar(PolinomioLP* p1, PolinomioLP* p2, PolinomioLP* &pr);
		void restar(PolinomioLP* p1, PolinomioLP* p2, PolinomioLP* &pr);
		void multiplicar (PolinomioLP* p1, PolinomioLP* p2, PolinomioLP* &pr);

		void poner_terminoEx(int coef, int exp);

	   string to_str();

};

#endif
