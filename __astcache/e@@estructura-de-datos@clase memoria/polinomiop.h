﻿#include <iostream>
#include <string>
//---------------------------------------------------------------------------

#ifndef PolinomioPH
#define PolinomioPH
//---------------------------------------------------------------------------

using namespace std;


struct NodoPoli {  //crea la estructura con 3 elementos
	int Expo; // crea la variable como el expoente
	int Coef; // crea la variable como el coeficiente
	NodoPoli *sig; // crea el puntero al siguiente nodo
};

class PolinomioP{
	private:
		NodoPoli* Ptr_Poli;  // ptr_poli como puntero
		int Nterminos;

		NodoPoli* Buscar_Exponente(int Exp);
		NodoPoli* Buscar_Termino(int n);
		void suprime(NodoPoli* dir);// elimina el nodo dado un direccion

	public:
		PolinomioP();
		bool Es_Cero();
		int Grado();
		int coeficiente(int exp);
		void Asignar_coeficiente(int coefi, int exp);
		void Poner_termino(int coef, int exp);
		int numero_terminos();
		int Exponente(int nroter);
		float Evaluar(float x);
		PolinomioP Sumar(PolinomioP* p1, PolinomioP* p2);
		PolinomioP Restar(PolinomioP* p1, PolinomioP* p2);
		PolinomioP Multiplicar(PolinomioP* p1, PolinomioP* p2);
		string Mostrar();

		void derivada(PolinomioP* p);
};
#endif
