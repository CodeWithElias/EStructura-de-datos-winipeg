//---------------------------------------------------------------------------

#pragma hdrstop

#include "ColaM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)



ColaS::ColaS() {
	mem = new CSMemoria();
	ini = fin = Nulo;
}

ColaS::ColaS(CSMemoria* m) {
	mem = m;
	ini = fin = Nulo;
}

bool ColaS::vacia() {
	return ini == Nulo;
}

void ColaS::poner(int e) {
	int aux = mem->new_espacio(datosC);
	if (aux != Nulo) {
		mem->poner_dato(aux, elementoC, e);
		mem->poner_dato(aux, siguiC, Nulo);
		if (vacia()) {
			ini = fin = aux;
		}
		else {
			mem->poner_dato(fin, siguiC, aux);
			fin = aux;
		}
	}
}

void ColaS::sacar(int &e) {
	if (!vacia()) {
		e = mem->obtener_dato(ini, elementoC);
		int x = ini;
		if (ini == fin)
			ini = fin = Nulo;
		else
			ini = mem->obtener_dato(ini, siguiC);
		mem->Delete_espacio(x);
	}
}

int ColaS::primero() {
	if (!vacia())
		return mem->obtener_dato(ini, elementoC);
}

string ColaS::to_str() {
	string s = "<<";
	int e;
	ColaS* aux = new ColaS();
	while (!vacia()) {
		sacar(e);
		aux->poner(e);
		s += to_string(e);
		if (!vacia())
			s += ",";
	}
	while (!aux->vacia()) {
		aux->sacar(e);
		poner(e);
	}
	mem->mostrar_memoria();
	return s + "<<";

}