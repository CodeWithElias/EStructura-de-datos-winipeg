//---------------------------------------------------------------------------

#pragma hdrstop

#include "ConjuntoL.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

ConjuntoL::ConjuntoL() {
	elem= new ListaP();
}



bool ConjuntoL::vacio() {
	return elem->vacio();
}




bool ConjuntoL::pertenece(int e) {
	if (!elem->vacio()) {
		NodoL* p=elem->primero();
		while (p!=NULL){
			int ele= elem->recupera(p);
			if (e==ele) {
				return true;
			}
			p=elem->siguiente(p);
		}
		return false;
	} else{
		//cout<<"ERROR: EL CONJUNTO NO TIENE ELEMENTOS\n";
		return false;
	}
}



void ConjuntoL::inserta(int e) {
	if (!pertenece(e)) {
		elem->insertar(elem->primero(),e);
	}
}




int ConjuntoL::cardinal() {
	return elem->Longitud();
}



int ConjuntoL::ordinal(int e) {
	if (!elem->vacio()) {
		int c=0;
		NodoL* p=elem->primero();
		while (p!=NULL){
			c++;
			int ele=elem->recupera(p);
			if (e==ele) {
				return c;
			}
			p=elem->siguiente(p);
		}
	}else{
		//cout<<"ERROR: EL CONJUNTO NO TIENE ELEMENTOS\n";
		return 0;
	}
}




void ConjuntoL::suprime(int e) {
	if (pertenece(e)) {
		NodoL* p=elem->primero();
		while (p!=NULL){
			int ele=elem->recupera(p);
			if (e==ele) {
				elem->suprime(p);
				return;
			}
			p=elem->siguiente(p);
		}
	}
}




int ConjuntoL::muestrea() {
	if (!vacio()) {
		int pos=rand()%cardinal()+1;
		NodoL* dir=elem->primero();
		int cont=0;
		for (int i=0; i < cardinal(); i++) {
			cont++;
			if (cont==pos) {
				return elem->recupera(dir);
			}
			dir=elem->siguiente(dir);
		}
	}
}




string ConjuntoL::to_str() {
	string s="{";
	NodoL* p=elem->primero();
	while (p!=NULL){
		int ele = elem->recupera(p);
		s +="e"+to_string(ele);
		if (p!=elem->fin()) {
			s +=",";
		}
		p=elem->siguiente(p);
	}
	return s+"}\n"+elem->tostr();;
}



void ConjuntoL::unir(ConjuntoL* b, ConjuntoL* c){
	c->reiniciar();
	ConjuntoL* aux= new ConjuntoL();
	ConjuntoL* a= this;
	// para insertar A en C
	while (a->vacio()==false){
		int r=a->muestrea();
		c->inserta(r);
		a->suprime(r);
		aux->inserta(r);
	}
	// para recuperar los datos de A
	while (aux->vacio()==false){
		int r=aux->muestrea();
		aux->suprime(r);
		a->inserta(r);
	}
	// para insertar B en C
		while (b->vacio()==false){
		int r=b->muestrea();
		c->inserta(r);
		b->suprime(r);
		aux->inserta(r);
	}
	// para recuperar los datos de B
	while (aux->vacio()==false){
		int r=aux->muestrea();
		aux->suprime(r);
		b->inserta(r);
	}
}



void ConjuntoL::intercectar(ConjuntoL* b, ConjuntoL* c){
	c->reiniciar();
	ConjuntoL* a=this;
	ConjuntoL* aux= new ConjuntoL();
	// inserto si el elemento pertenece a A y B
	while (a->vacio()==false){
		int r=a->muestrea();
		if (a->pertenece(r) && b->pertenece(r)) {
			c->inserta(r);
		}
		a->suprime(r);
		aux->inserta(r);
	}
	// recupero los elementos de A
	while (aux->vacio()==false){
		int r=aux->muestrea();
		aux->suprime(r);
		a->inserta(r);
	}
}




void ConjuntoL::reiniciar(){
	while (vacio()==false){
		int r=muestrea();
		suprime(r);
	}
}
