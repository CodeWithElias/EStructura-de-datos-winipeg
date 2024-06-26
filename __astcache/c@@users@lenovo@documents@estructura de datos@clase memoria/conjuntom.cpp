﻿//---------------------------------------------------------------------------

#pragma hdrstop
#include "ConjuntoM.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

// dir->dato => mem->obtener_dato(dir, datoCJ);
// dir->sig => mem->obtener_dato(dir,sigCJ);
// dir->dato = valor   => mem->poner_dato(dir, datoCJ, valor);
// dir->sig = valor   => mem->poner_dato(dir, sigCJ, valor);

ConjuntoS::ConjuntoS() {
	cant = 0;
	ptr_conj = Nulo;
	mem = new CSMemoria();
}

ConjuntoS::ConjuntoS(CSMemoria* m) {
	cant = 0;
	ptr_conj = Nulo;
	mem = m;
}

bool ConjuntoS::vacio() {
	return cant == 0; // ptr_conj == Nulo;
}

bool ConjuntoS::pertenece(int e) {
	int pc = ptr_conj;
	while (pc != Nulo) {
		if (mem->obtener_dato(pc, datoCJ) == e) // pc->dato == e
				return true;
		pc = mem->obtener_dato(pc, sigCJ); // pc = pc->sig
	}
	return false;
}

void ConjuntoS::inserta(int e) {
	if (!pertenece(e)) {
		int dir = mem->new_espacio(datosCJ);
		if (dir != Nulo) {
			mem->poner_dato(dir, datoCJ, e); // dir->dato = e;
			mem->poner_dato(dir, sigCJ, ptr_conj); // dir->sig = ptr_conj;
			ptr_conj = dir;
			cant++;
		}
		else
			cout << "ERROR NO EXISTE ESPACIO MEMORIA\n";
	}
	else
		cout << "ERROR YA EXISTE EL ELEMENTO\n";
}

int ConjuntoS::cardinal() {
	return cant;
}

int ConjuntoS::ordinal(int e) {
	int cont = 0;
	int pc = ptr_conj;
	while (pc != Nulo) {
		cont++;
		if (cont == e)
			return cont;
		pc = mem->obtener_dato(pc, sigCJ);
	}
	return 0;
}

void ConjuntoS::suprime(int e) {
	if (pertenece(e)) {
		int dir;
		if (e == mem->obtener_dato(ptr_conj, datoCJ)) { // ptr_conj->dato
			dir = ptr_conj;
			ptr_conj = mem->obtener_dato(ptr_conj, sigCJ); // ptr_conj->sig;
		}
		else {
			int pc = ptr_conj;
			int ant;
			while (pc != Nulo) {
				if (e == mem->obtener_dato(pc, datoCJ)) { // pc->dato
					dir = pc;
					break;
				}
				ant = pc;
				pc = mem->obtener_dato(pc, sigCJ); // pc->sig;
			}
			int pc_sig = mem->obtener_dato(pc, sigCJ); // pc->sig
			mem->poner_dato(ant, sigCJ, pc_sig); // ant->sig = pc_sig;
			mem->poner_dato(pc, sigCJ, Nulo); // pc->sig = Nulo;
		}
		cant--;
		mem->Delete_espacio(dir); // delete(dir);
	}
}

int ConjuntoS::muestrea() {
	if (!vacio()) {
		int lug = (rand() % cardinal()) + 1;
		int dir = ptr_conj;
		int cont = 0;
		for (int i = 1; i <= cardinal(); i++) {
			cont++;
			if (cont == lug)
				return mem->obtener_dato(dir, datoCJ); // dir->dato;
			dir = mem->obtener_dato(dir, sigCJ); // dir = dir->sig;
		}
	}
}

string ConjuntoS::to_str() {
	string s = "{";
	int p = ptr_conj;
	int c = 0;
	while (p != Nulo) {
		c++;
		int ele = mem->obtener_dato(p, datoCJ); // p->dato;
		s += to_string(ele);
		if (c < cant)
			s += ",";
		p = mem->obtener_dato(p, sigCJ); // p->sig;
	}
	return s + "}";
}
