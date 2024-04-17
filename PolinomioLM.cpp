//---------------------------------------------------------------------------

#pragma hdrstop

#include "PolinomioLM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

PolinomioLM::PolinomioLM(){
	Pol= new ListaM();
}



bool PolinomioLM::EsCero(){
	return Pol->vacia();
}



int PolinomioLM::buscar_exponente(int exp){
	if (!Pol->vacia()) {
		int dir = Pol->siguiente(Pol->primero());
		if (dir!=Nulo) {
			int dir_exp=Nulo;
			while (dir!=Nulo && dir_exp==Nulo){
				if (Pol->recupera(dir)==exp) {
					dir_exp=dir;
				}
				if (dir==Pol->fin()) {
					break;
				}
				dir=Pol->siguiente(Pol->siguiente(dir));
			}
			return dir_exp;
		}
	} else{
		cout<<"POLINOMIO NO TIENE TERMINOS\n";
		return Nulo;
	}
}



int PolinomioLM::buscar_termino(int i){
	if (!Pol->vacia()) {
		int dir=Pol->primero();
		int nt=0;
		if (dir!=Nulo) {
			int dir_ter=Nulo;
			while (dir!=Nulo && dir_ter==Nulo){
				nt++;
				if (nt==i) {
					dir_ter=dir;
				}
				if (Pol->siguiente(dir)==Pol->fin()) {
					break;
				}
				dir=Pol->siguiente(Pol->siguiente(dir));
			}
			return dir_ter;
		}
	}else {
        cout<<"POLINOMIO NO TIENE TERMINOS\n";
		return Nulo;
    }
}



int PolinomioLM::Grado(){
	if (!EsCero()) {
		int dir = Pol->siguiente(Pol->primero());
		if (dir!=Nulo) {
			int max_grado = Pol->recupera(dir);
			while (dir!=Nulo){
				if (Pol->recupera(dir) > max_grado) {
					max_grado = Pol->recupera(dir);
				}
                if (dir==Pol->fin()) {
					break;
				}
				dir=Pol->siguiente(Pol->siguiente(dir));
			}
			return max_grado;
		}
	} else{
		cout<<"POLINOMIO NO TIENE TERMINOS\n";
	}
}




int PolinomioLM::Coeficiente(int exp){
	int dir = buscar_exponente(exp);
	if (dir != Nulo) {
		return Pol->recupera(Pol->anterior(dir));
	} else{
		cout <<" POLINOMIO NO TIENE ESTE TERMINO \n";
	}
}




void PolinomioLM::asignar_coeficiente(int coef,int exp){
	int dir = buscar_exponente(exp);
	if (dir!=Nulo) {
		int dir_coef = Pol->anterior(dir);
		Pol->modifica(dir_coef, coef);
		if (coef==0) {
			Pol->suprime(dir);
			Pol->suprime(dir_coef);
		}
	} else{
		cout <<" POLINOMIO NO TIENE ESTE TERMINO \n";
	}
}




void PolinomioLM::Poner_Termino(int coef, int exp){
	if (coef != 0 && exp >=0) {
		int dir_exp= buscar_exponente(exp);
		if (dir_exp!=Nulo) { // modifica
			int dir_coef= Pol->anterior(dir_exp);
			int nuevo_coef= Pol->recupera(dir_coef) + coef;
			Pol->modifica(dir_coef,nuevo_coef);
			if (nuevo_coef== 0) {
				Pol->suprime(dir_exp);
				Pol->suprime(dir_coef);
			}
		}else{  // insercion
			Pol->inserta_ultimo(exp);
			Pol->inserta(Pol->fin(),coef);
		}
	}
}




int PolinomioLM::Numero_Terminos(){
	return Pol->longitud()/2;
}




int PolinomioLM::Exponente(int nroter){
	int dir = buscar_termino(nroter);
	if (dir!= Nulo) {
		return Pol->recupera(Pol->siguiente(dir));
	} else {
		cout <<" POLINOMIO NO TIENE ESTE TERMINO \n";
    }
}
void PolinomioLM::sumar(PolinomioLM* p1, PolinomioLM* p2, PolinomioLM* &pr){
	pr= new PolinomioLM();
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




void PolinomioLM::restar(PolinomioLM* p1, PolinomioLM* p2, PolinomioLM* &pr){
		pr= new PolinomioLM();
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




void PolinomioLM::multiplicar(PolinomioLM* p1, PolinomioLM* p2, PolinomioLM* &pr){
}



string PolinomioLM::to_str(){
    string s="";
	for (int i=1; i <=Numero_Terminos(); i++) {
		int ex=Exponente(i);
		int co=Coeficiente(ex);
		if (co>0) {
			s+="+";
		}
		s+=to_string(co) + "x^" + to_string(ex);
	}
	return s;
}

