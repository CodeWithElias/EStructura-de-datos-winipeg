﻿//---------------------------------------------------------------------------

#pragma hdrstop

#include "PilaM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)



PilaS::PilaS(){
	mem = new CSMemoria();
	tope = Nulo;
}

PilaS::PilaS(CSMemoria* m){
	mem = m;
	tope = Nulo;
}

bool PilaS::vacia(){
	return tope == Nulo;
}

void PilaS::meter(int e){
	int aux = mem->new_espacio(datosP);//new NodoP;
	if(aux != Nulo){
		mem->poner_dato(aux, elementoP, e);//aux->elemento = e;
		mem->poner_dato(aux, sigP, tope);//aux->sig = tope;
		tope = aux;
	}else
		cout << "ERROR NO HAY MEMORIA\n" << endl;
}

void PilaS::sacar(int& e){
	if(!vacia()){
		int x = tope;
		e = mem->obtener_dato(tope, elementoP);//tope->elemento;
		tope = mem->obtener_dato(tope, sigP);//tope->sig;
		mem->Delete_espacio(x);//delete(x);
	}
}

int PilaS::cima(){
	if(!vacia()){
		return mem->obtener_dato(tope, elementoP);//tope->elemento;
	}
}

string PilaS::to_str(){
	string r = "";
	PilaS* aux = new PilaS();
	while(!vacia()){
		int e;
		sacar(e);
		r += "| "+to_string(e)+" |\n";
		aux->meter(e);
	}
	while(!aux->vacia()){
		int e;
		aux->sacar(e);
		meter(e);
	}
	r += "+---+\n";
	return r;
}