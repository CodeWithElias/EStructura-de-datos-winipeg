//---------------------------------------------------------------------------

#pragma hdrstop

#include "PolinomioLP.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)



PolinomioLP::PolinomioLP(){
	Pol= new ListaP();
}



bool PolinomioLP::EsCero(){
	return Pol->vacio();
}



direccionP PolinomioLP::buscar_exponente(int exp){
	if (!Pol->vacio()) {
		direccionP dir = Pol->siguiente(Pol->primero());
		if (dir!=NULL) {
			direccionP dir_exp=NULL;
			while (dir!=NULL && dir_exp==NULL){
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
		return NULL;
	}
}



direccionP PolinomioLP::buscar_termino(int i){
	if (!Pol->vacio()) {
		direccionP dir=Pol->primero();
		int nt=0;
		if (dir!=NULL) {
			direccionP dir_ter=NULL;
			while (dir!=NULL && dir_ter==NULL){
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
		return NULL;
	}
}



int PolinomioLP::Grado(){
	if (!EsCero()) {
		direccionP dir = Pol->siguiente(Pol->primero());
		if (dir!=NULL) {
			int max_grado = Pol->recupera(dir);
			while (dir!=NULL){
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




int PolinomioLP::Coeficiente(int exp){
	direccionP dir = buscar_exponente(exp);
	if (dir != NULL) {
		return Pol->recupera(Pol->anterior(dir));
	} else{
		cout <<" POLINOMIO NO TIENE ESTE TERMINO \n";
	}
}




void PolinomioLP::asignar_coeficiente(int coef,int exp){
	direccionP dir = buscar_exponente(exp);
	if (dir!=NULL) {
		direccionP dir_coef = Pol->anterior(dir);
		Pol->modifica(dir_coef, coef);
		if (coef==0) {
			Pol->suprime(dir);
			Pol->suprime(dir_coef);
		}
	} else{
		cout <<" POLINOMIO NO TIENE ESTE TERMINO \n";
	}
}




void PolinomioLP::Poner_Termino(int coef, int exp){
	if (coef != 0 && exp >=0) {
		direccionP dir_exp= buscar_exponente(exp);
		if (dir_exp!=NULL) { // modifica
			direccionP dir_coef= Pol->anterior(dir_exp);
			int nuevo_coef= Pol->recupera(dir_coef) + coef;
			Pol->modifica(dir_coef,nuevo_coef);
			if (nuevo_coef== 0) {
				Pol->suprime(dir_exp);
				Pol->suprime(dir_coef);
			}
		}else{  // insercion
			Pol->insertar_ultimo(exp);
			Pol->insertar(Pol->fin(),coef);
		}
	}
}




int PolinomioLP::Numero_Terminos(){
	return Pol->Longitud()/2;
}




int PolinomioLP::Exponente(int nroter){
	direccionP dir = buscar_termino(nroter);
	if (dir!= NULL) {
		return Pol->recupera(Pol->siguiente(dir));
	} else {
		cout <<" POLINOMIO NO TIENE ESTE TERMINO \n";
	}
}
void PolinomioLP::sumar(PolinomioLP* p1, PolinomioLP* p2, PolinomioLP* &pr){
	pr= new PolinomioLP();
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




void PolinomioLP::restar(PolinomioLP* p1, PolinomioLP* p2, PolinomioLP* &pr){
		pr= new PolinomioLP();
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




void PolinomioLP::multiplicar(PolinomioLP* p1, PolinomioLP* p2, PolinomioLP* &pr){
}



string PolinomioLP::to_str(){
	string s="";
	for (int i=1; i <=Numero_Terminos(); i++) {
		int ex=Exponente(i);
		int co=Coeficiente(ex);
		if (co>0) {
			s+="+";
		}
		s+=to_string(co) + "x^" + to_string(ex);
	}
    cout <<Pol->tostr()<<endl;
	return s;
}





void PolinomioLP::poner_terminoEx(int coef, int exp){
	if (coef==0) {
		return;
	}

	if (Pol->vacio()) {
		Pol->insertar_primero(exp);
		Pol->insertar_ultimo(coef);
		for (int  i = 0; i < exp; i++) {
			Pol->insertar_ultimo(0);
		}
		return;
	}

	if (Pol->recupera(Pol->primero())<exp){
		int x= Pol->recupera(Pol->primero());
		for (int g=exp-x; g >0; g--) {
			if (g==1) {
				Pol->insertar_primero(coef);
				Pol->insertar_primero(exp);
			}  else {
				if (g==exp-x) {
					Pol->modifica(Pol->primero(),0);
				} else {
					Pol->insertar_primero(0);
				}
			}
		}
	} else {
		if (exp==Pol->recupera(Pol->primero())) {
			NodoL* ini= Pol->primero();
			NodoL* aux;
			for (int i=0; i <=exp; i++) {
				if (i==0 || i==1) {
					aux= ini;
					ini=Pol->siguiente(aux);
					Pol->suprime(aux);
				} else {
					aux=ini;
					if (Pol->recupera(ini) !=0) {
						int a =exp-i+1;
						Pol->insertar_primero(a);
						return;
					} else {
						ini=Pol->siguiente(aux);
						Pol->suprime(aux);
					}
				}
			}
		} else {
			NodoL* aux;
			NodoL* fin = Pol->fin();
			for (int h=0; h < Pol->recupera(Pol->primero()); h++) {
				if (h == exp) {
					int x= coef+ Pol->recupera(fin);
					Pol->modifica(fin, x);
					if (x==0) {

					}
					return;
				} else {
					aux=fin;
					fin=Pol->anterior(aux);
				}
			}
		}
	}
}
