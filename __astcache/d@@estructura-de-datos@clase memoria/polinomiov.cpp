﻿//---------------------------------------------------------------------------

#pragma hdrstop

#include "PolinomioV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

PolinomioV::PolinomioV (){
	Nterminos=1;
	coeficiente[1]=3;
    exponente[1]=2;
	//exponente[1]=3;
}



bool PolinomioV::EsCero(){
	return (Nterminos==0);
}



int PolinomioV::Grado(){ //devuelve Grado del Polinomio
	if (Nterminos>0) {
		int max=exponente[1];
		for (int i=1; i <=Nterminos; i++) {
			if (exponente[i]>max) {
				max=exponente[i];
			}
		}
	return max;
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
	for (int i=1; i <= Nterminos; i++) {
		if (exponente[i]==exp) {
			return i;
		}
	}
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
		Nterminos=Nterminos+1;
		coeficiente[Nterminos]=coef;
		exponente[Nterminos]=exp;
	}
}


int PolinomioV::Numero_Terminos(){
return Nterminos;
}


int PolinomioV::Coeficiente (int exp){
	if ((exp>=0) && (exp<=Grado())) {
		for (int i = 1; i <= Nterminos; i++) {
			if (exponente[i]==exp) {
				return coeficiente[i];
			}
		}
	}
}


int PolinomioV::Exponente (int  nroter){
	return exponente[nroter];
}


int PolinomioV::Get_Coef (int pos){
	return coeficiente[pos];
}



