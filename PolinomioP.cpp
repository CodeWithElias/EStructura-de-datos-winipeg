//---------------------------------------------------------------------------

#pragma hdrstop

#include "PolinomioP.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


PolinomioP::PolinomioP(){
	Ptr_Poli=NULL;
	Nterminos=0;
}


bool PolinomioP::Es_Cero(){
	return Nterminos==0;
}


int PolinomioP::Grado(){
	if (!Es_Cero()) {
		int max=Ptr_Poli->Expo;
		NodoPoli* aux=Ptr_Poli;
		while (aux!=NULL){
			if (aux->Expo>max) {
				max=aux->Expo;
			}
			// cambio de nodo o bagon
			aux=aux->sig;
		}
		return max;
	}
}



int PolinomioP::coeficiente(int exp){
	NodoPoli* dir = Buscar_Exponente(exp);
	if (dir != NULL)
		return dir->Coef;
	else
		cout << "POLINOMO NO TIENE ESTE TERMINO\n";
}



void PolinomioP::Asignar_coeficiente(int coefi, int exp){
	NodoPoli* dir=Buscar_Exponente(exp);
	if (dir!=NULL) {
		dir->Coef=coefi;
		if (coefi==0) {
		   	suprime(dir);
			Nterminos--;
		}
	}
}



void PolinomioP::Poner_termino(int coef, int exp){
	if (coef != 0 && exp >= 0) {
		NodoPoli* existe = Buscar_Exponente(exp);
		if (existe == NULL) { // Nueva Insercion
			NodoPoli* aux = new NodoPoli();
			if (aux != NULL) {
				aux->Coef = coef;
				aux->Expo = exp;
				aux->sig = Ptr_Poli;
				Ptr_Poli = aux;
				Nterminos++;
			}
			else
				cout << "NO EXISTE ESPACIO MEMORIA\n";
		}
		else { // Modificar
			int nuevo_coef = existe->Coef + coef;
			existe->Coef = nuevo_coef;
			if (nuevo_coef == 0) {
				if (existe == Ptr_Poli) { // Se elimina el primero
					Ptr_Poli = Ptr_Poli->sig;
				}
				else {
					NodoPoli* x = Ptr_Poli;
					NodoPoli* ant = NULL;
					while (x != NULL) {
						if (x == existe)
							break;
						ant = x;
						x = x->sig;
					}
					// --
					ant->sig = existe->sig;
				}
				delete(existe);
				Nterminos--;
			}
		}
	}
}



int PolinomioP::numero_terminos(){
	return Nterminos;
}



int PolinomioP::Exponente(int nroter){
	NodoPoli* dir = Buscar_Termino(nroter);
	if (dir != NULL)
		return dir->Expo;
	else
		cout << "NO EXISTE ESE NUMERO DE TERMINO\n";
}


PolinomioP PolinomioP::Sumar(PolinomioP* p1, PolinomioP* p2){
 /*	pr = new PolinomioP();
	for (int i = 1; i <= p1->numero_terminos(); i++) {
		int ex = p1->Exponente(i);
		int co = p1->coeficiente(ex);
		pr->Poner_termino(ex, co);
	}
	for (int i = 1; i <= p2->numero_terminos(); i++) {
		int ex = p2->Exponente(i);
		int co = p2->coeficiente(ex);
		pr->Poner_termino(ex, co);
	}*/
}




PolinomioP PolinomioP::Restar(PolinomioP* p1, PolinomioP* p2){}




PolinomioP PolinomioP::Multiplicar(PolinomioP* p1, PolinomioP* p2){}


void PolinomioP::suprime(NodoPoli* dir){
	if (dir==Ptr_Poli) {
		Ptr_Poli=Ptr_Poli->sig;
	} else{
		NodoPoli* aux=Ptr_Poli;
		NodoPoli* ant=NULL;
		while (aux!=NULL && ant !=dir){  // aqui ubica el nodo
			ant=aux;
			aux=aux->sig;
		}
		// aqui se elimina
		NodoPoli* ante=ant;
		ante->sig=aux->sig;
		delete(aux);
		Nterminos--;
	}
}


NodoPoli* PolinomioP::Buscar_Exponente(int Exp){
	NodoPoli* dir = Ptr_Poli;
	if (dir != NULL) {
		NodoPoli* dir_ex = NULL;
		while (dir != NULL && dir_ex == NULL) {
			if (dir->Expo == Exp)
				dir_ex = dir;
			dir = dir->sig;
		}
		return dir_ex;
	}
	else {
		return NULL;
	}
}



NodoPoli* PolinomioP::Buscar_Termino(int n){
	NodoPoli* dir=Ptr_Poli;
	if (dir!=NULL) {
		NodoPoli *dirTer=NULL;
		int nt=0;
		while ((dir!=NULL)&& (dirTer==NULL)){
			nt=nt+1;
			if (nt==n) {
				dirTer=dir;
			}
			dir=dir->sig;
		}
		return dirTer;
	} else{
		cout<<"No existe exponente\n";
	}
}



float PolinomioP::Evaluar(float x){
	float suma=0;
	for (int i=0; i < Nterminos; i++) {
		int exponente=Exponente(i+1);
		int Coeficiente=coeficiente(exponente);
		suma=suma + Coeficiente*pow (x,exponente);
	}
	return suma;
}



string PolinomioP::Mostrar(){
	string s = "";
	for (int i = 1; i <= numero_terminos(); i++) {
		int ex = Exponente(i);
		int co = coeficiente(ex);
		if (co > 0)
			s += "+";
		s += to_string(co) + "x^" + to_string(ex);
	}
	return s;
}



void PolinomioP::derivada(PolinomioP* p){
	for (int i=0; i < Nterminos; i++) {
		int exp=Exponente(i+1);
		int coef=coeficiente(exp);
		p->Poner_termino(coef*exp,exp-1);
	}
}
