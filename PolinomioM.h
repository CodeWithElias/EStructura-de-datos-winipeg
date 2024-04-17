
      // PROBADO Y FUNCIONA

#include <iostream>
#include <string>
#include "UMemoria.h"
using namespace std;
//---------------------------------------------------------------------------

#ifndef PolinomioMH
#define PolinomioMH
//---------------------------------------------------------------------------

const string Dato="Coeficiente,Exponente,Sig";
const string Coef="->Coeficiente";
const string Exp="->Exponente";
const string Sig="->Sig";

 class PolinomioM{
	 private:
		CSMemoria* mem;
		int Ptr_Poli;
		int Nterminos;

		int Buscar_Exponente(int exp);
		int Buscar_Termino(int n);
		int anterior(int dir);


	 public:
		PolinomioM(); // crea el polinomio
		PolinomioM(CSMemoria* m);// crea el polinomio en la memoria
		bool Es_Cero();// devuelve verdadero si el polinomio esta vacio
		int Grado();
		int Coeficiente(int exp); // devuelve el coeficiente dado un exponente
		void Asignar_Coeficiente(int coef, int exp); // asigna un valor a un coeficiente dado un exponente
		void Poner_Termino(int coef, int exp);// introdice un termino al polinomio
		int Numero_Terminos();//devuleve la cantidad de terminos
		int Exponente(int ter); // devuleve el grado de termino dado un termino

		void sumar(PolinomioM* p1, PolinomioM* p2, PolinomioM* &pr);
		void restar(PolinomioM* p1, PolinomioM* p2, PolinomioM* &pr);
		void derivar();
		string to_str();
 };


#endif
