//---------------------------------------------------------------------------

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



int PolinomioM::Buscar_Exponente(int exp){
	int dir= Ptr_Poli;
	if (dir!=Nulo) {
		int dir_ex=Nulo;
		while (dir!=Nulo && Nulo){
			if (mem->obtener_dato(dir,Exp)==exp) {
				dir_ex=dir;
			}
			dir=mem->obtener_dato(dir,Sig);
		}
		return dir_ex;
	} else {
		cout <<"EXCEPCION NO EXISTE ESE TERMINO\n";
		return Nulo;
	}
}



int PolinomioM::Buscar_Termino(int n){
	int dir=Ptr_Poli;
	if (dir !=Nulo) {
		int dir_ter=Nulo;
		int nt=0;
		while (dir !=Nulo && dir_ter==Nulo){
			nt++;
			if (nt==n) {
				dir_ter=dir;
			}
			dir=mem->obtener_dato(dir,Sig);
		}
		return dir_ter;
	}  else {
		cout <<"EXCEPCION NO EXISTE ESE TERMINO\n";
		return Nulo;
	}
}



bool PolinomioM::Es_Cero(){
return Nterminos==0;
}



int PolinomioM::Grado(){
	int dir=Ptr_Poli;
	if (dir !=Nulo) {
		int MaxG=mem->obtener_dato(dir,Exp);
		while (dir!=Nulo){
			if (mem->obtener_dato(dir,Exp)>MaxG) {
				MaxG=mem->obtener_dato(dir,Exp);
			}
			dir=mem->obtener_dato(dir, Sig);
		}
		return MaxG;
	} else{
		cout<<"No Existe termino\n";
	}
}



int PolinomioM::Coeficiente(int exp){
	int dir=Buscar_Exponente(exp);
	if (dir !=Nulo) {
		return mem->obtener_dato(dir,Coef);
	} else{
		cout<<"No Existe termino\n";
	}
}



int PolinomioM::anterior(int dir){
	int x=Ptr_Poli;
	int ant =Nulo;
	while (x !=Nulo){
		if (x == dir) {
			return ant;
		}
		ant = x;
		x=mem->obtener_dato(x,Sig);
	}
	return Nulo;
}



void PolinomioM::Asignar_Coeficiente(int coef, int exp){
	int dir=Buscar_Exponente(exp);
	if (dir !=Nulo) {
		mem->poner_dato(dir,Coef,coef);
		if (coef==0) {
			if (dir == Ptr_Poli) {
				Ptr_Poli = mem->obtener_dato(Ptr_Poli,Sig);
			} else{
				int ant = anterior(dir);
				int dir_sig = mem->obtener_dato(dir,Sig);
				mem->poner_dato(ant,Sig,dir_sig);
			}
			mem->Delete_espacio(dir);
			Nterminos--;
		}
	} else{
		cout<<"No Existe termino\n";
	}
}





void PolinomioM::Poner_Termino(int coef, int exp){
	if (coef !=0 && exp>=0) {
		int existe= Buscar_Exponente(exp);
		if (existe==Nulo) {
			int aux=mem->new_espacio(Dato);
			if (aux!=Nulo) {
				mem->poner_dato(aux,Coef,coef);
				mem->poner_dato(aux,Exp,exp);
				mem->poner_dato(aux,Sig,Ptr_Poli);
				Ptr_Poli= aux;
				Nterminos++;
			} else{
				cout<<"Error: No Existe Espacio Memoria\n";
			}
		} else{ // modificar
			int nuevo_Coef= mem->obtener_dato(existe,Coef) + coef;
			mem->poner_dato(existe,Coef,nuevo_Coef);
			if (nuevo_Coef==0) {
				if (existe ==Ptr_Poli) {  // se elimina el primero
					Ptr_Poli = mem->obtener_dato(Ptr_Poli, Sig);
				}  else{
					int ant = anterior(existe);
					int existe_sig = mem->obtener_dato(existe,Sig);
					mem->poner_dato(ant,Sig,existe_sig);
				}
				mem->Delete_espacio(existe);
				Nterminos--;
			}
		}
	}
}



int PolinomioM::Numero_Terminos(){
	return Nterminos;
}



int PolinomioM::Exponente(int ter){
	int dir= Buscar_Termino(ter);
	if (dir!=Nulo) {
		return mem->obtener_dato(dir,Exp);
	} else{
		cout<<"Error: No existe ese termino\n";
	}
}



void PolinomioM::sumar(PolinomioM* p1, PolinomioM* p2, PolinomioM* &pr){
	pr = new PolinomioM();
	for (int i = 1; i <= p1->Numero_Terminos(); i++) {
		int ex = p1->Exponente(i);
		int co = p1->Coeficiente(ex);
		pr->Poner_Termino(co,ex);
	}
	for (int i = 1; i <= p2->Numero_Terminos(); i++) {
		int ex = p2->Exponente(i);
		int co = p2->Coeficiente(ex);
		pr->Poner_Termino(co,ex);
	}
}



void PolinomioM::restar(PolinomioM* p1, PolinomioM* p2, PolinomioM* &pr){
    pr = new PolinomioM();
	for (int i = 1; i <= p1->Numero_Terminos(); i++) {
		int ex = p1->Exponente(i);
		int co = p1->Coeficiente(ex);
		pr->Poner_Termino(co,ex);
	}
	for (int i = 1; i <= p2->Numero_Terminos(); i++) {
		int ex = p2->Exponente(i);
		int co = p2->Coeficiente(ex);
		pr->Poner_Termino(-co,ex);
	}
}




void PolinomioM::derivar(){
	int n = Numero_Terminos();
	int* exn = new int[n];
	int* con = new int[n];
	int c = 0;
	while (!Es_Cero()) {
		int ex = Exponente(1);
		int co = Coeficiente(ex);
		Poner_Termino(-co, ex);
		exn[c] = ex;
		con[c] = co;
		c++;
	}
	for (int i = 0; i < n; i++) {
		int ex = exn[i];
		int co = con[i];
		Poner_Termino(co*ex, ex - 1);
	}

}




string PolinomioM::to_str(){
	string s = "";
	for (int i = 1; i <= Numero_Terminos(); i++) {
		int ex = Exponente(i);
		int co = Coeficiente(ex);
		if (co > 0)
			s += "+";
		s += to_string(co) + "x^" + to_string(ex);
	}
	return s;
}

