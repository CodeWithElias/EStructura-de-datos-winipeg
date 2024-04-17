﻿//---------------------------------------------------------------------------

#pragma hdrstop

#include "PolinomioM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

PolinomioM::PolinomioM(){
	Nterminos=0;
	Ptr_Poli=Nulo;
	mem=new CSMemoria();
}



PolinomioM::PolinomioM(CSMemoria* m){
	Ptr_Poli=Nulo;
	mem=m;
}



bool PolinomioM::Es_Cero(){
return Nterminos==0;
}



int PolinomioM::Grado(){
	int Dir=Ptr_Poli;
	if (!Es_Cero) {
		int MaxG=mem->obtener_dato(Dir,Exp);
		while (Dir!=Nulo){
			if (mem->obtener_dato(Dir,Exp)>MaxG) {
				MaxG=mem->obtener_dato(Dir,Exp);
			}
			Dir=mem->obtener_dato(Dir, Sig);
		}
		return MaxG;
	} else{
		cout<<"No Existe termino\n";
    }
}



int PolinomioM::Coeficiente(int exp){
	int dir=Buscar_Exponente(exp);
	if (!Es_Cero) {
		return mem->obtener_dato(dir,Coef);
	} else{
		cout<<"No Existe termino\n";
	}
}



void PolinomioM::Asignar_Coeficiente(int coef, int exp){
	int dir=Buscar_Exponente(exp);
	if (!Es_Cero) {
		mem->poner_dato(dir,Coef,coef);
		if (coef==0) {
			mem->Delete_espacio(dir);
		}
	} else{
		cout<<"No Existe termino\n";
	}
}
void PolinomioM::Poner_Termino(int coef, int exp){
	   int	existe=-1;
	if (existe!=Nulo) {
		int aux=mem->new_espacio(Dato);
		if (aux!=Nulo) {
			mem->poner_dato(aux,Coef,coef);
			mem->poner_dato(aux,Exp,coef);
			mem->poner_dato(aux,Sig,Ptr_Poli);
			Ptr_Poli= aux;
		} else{
			cout<<"Error: Espacio de memoria\n";
        }
	} else{
		int nuevo_Coef= mem->obtener_dato(existe,Coef) + coef;
		mem->poner_dato(existe,Coef,nuevo_Coef);
		if (nuevo_Coef==0) {
			mem->Delete_espacio(existe);
		}
	}
}



int PolinomioM::Numero_Terminos(){
	return Nterminos;
}
int PolinomioM::Exponente(int ter){
   /*  dir = buscarterminoN (nroter)
 di dir <> nulo entonces
 retornar m.obtenerdato(dir,’->exp’)
 caso contrario
 // no existe ese termino
 */

	int dir= Buscar_Termino(ter);
	if (dir!=Nulo) {
		return mem->obtener_dato(dir,Exp);
	} else{
        cout<<"Error: No existe ese termino\n";
    }
}

