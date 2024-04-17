﻿//---------------------------------------------------------------------------

#pragma hdrstop

#include "PolinomioV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

PolinomioV::PolinomioV (){
	Nterminos=0;
}



bool PolinomioV::EsCero(){
	return (Nterminos==0);
}



int PolinomioV::Grado(){ //devuelve Grado del Polinomio
	if (Nterminos>0) {
		int max=exponente[0];
		for (int i=1; i <Nterminos; i++) {
			if (exponente[i]>max) {
				max=exponente[i];
			}
		}
	return max;
	} else  {
				cout << "Error: No existe terminos\n";
			}
}


void PolinomioV::asignar_coeficiente(int coef, int exp){
	int lug=Pos_Exponente(exp);
	if (lug!=-1) {
		coeficiente[lug]=coef;
		if (coeficiente[lug]==0) {
			for (int i = lug; i <= Nterminos; i++) {
				coeficiente[lug]=coeficiente[lug+1];
			}
			Nterminos=Nterminos-1;
		}
	}

}


int PolinomioV::Pos_Exponente(int exp){
		int lug=-1;
		for (int i=0; i <= Nterminos; i++) {
			if (exponente[i]==exp) {
				lug= i;
			}
		}
		return lug;
}


void PolinomioV::Poner_Termino(int coef, int exp){
	int lug=Pos_Exponente(exp);
	if (lug!=-1) {
		coeficiente[lug]=coeficiente[lug]+coef;
		if (coeficiente[lug]==0) {
			for (int i = lug; i <= Nterminos; i++) {
				coeficiente[lug]=coeficiente[lug+1];
			}
			Nterminos=Nterminos-1;
		}
	}else
	{
		coeficiente[Nterminos]=coef;
		exponente[Nterminos]=exp;
		Nterminos=Nterminos+1;
	}
}


int PolinomioV::Numero_Terminos(){
return Nterminos;
}


int PolinomioV::Coeficiente (int exp){
	if ((exp>=0) && (exp<=Grado())) {
		for (int i = 0; i <= Nterminos; i++) {
			if (exponente[i]==exp) {
				return coeficiente[i];
			}
		}
	}
}


int PolinomioV::Exponente (int  nroter){
	if ((nroter>=1) && (nroter <=Nterminos)) {
		return exponente[nroter-1];
	}
}




void PolinomioV::sumar(PolinomioV* p1, PolinomioV* p2, PolinomioV* &pr){
	pr= new PolinomioV();
	for (int i=1; i <= p1->Numero_Terminos(); i++) {
		int ex=p1->Exponente(i);
		int co=p1->Coeficiente(ex);
		pr->Poner_Termino(co,ex);
	}

	for (int i=1; i <= p2->Numero_Terminos(); i++) {
		int ex=p2->Exponente(i);
		int co=p2->Coeficiente(ex);
		pr->Poner_Termino(co,ex);
	}
}



void PolinomioV::restar(PolinomioV* p1, PolinomioV* p2, PolinomioV* &pr){
	pr= new PolinomioV();
	for (int i=1; i <= p1->Numero_Terminos(); i++) {
		int ex=p1->Exponente(i);
		int co=p1->Coeficiente(ex);
		pr->Poner_Termino(co,ex);
	}

	for (int i=1; i <= p2->Numero_Terminos(); i++) {
		int ex=p2->Exponente(i);
		int co=p2->Coeficiente(ex);
		pr->Poner_Termino(-co,ex);
	}
}



string PolinomioV::to_str(){
	string s="";
	for (int i=1; i <=Nterminos; i++) {
		int ex=Exponente(i);
		int co=Coeficiente(ex);
		if (co>0) {
			s+="+";
		}
		s+=to_string(co) + "x^" + to_string(ex);
	}
	return s;
}
