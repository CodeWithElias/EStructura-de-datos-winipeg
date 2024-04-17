//---------------------------------------------------------------------------

#pragma hdrstop

#include "ListaV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#include <iostream>
#include <string>

ListaV::ListaV() {
	this->longi=NuloV;
	elementos =new int[MaxV];
}



direccionI ListaV::fin() {
	if (!vacia()) {
		return longi-1;
	} else {
		cout << "Error: Lista Vacia\n";
	}
}



direccionI ListaV::primero() {
	if (!vacia()) {
		return 0;
	}  else{
		cout << "Error: Lista Vacia\n";
		return -1;

	}
}



direccionI ListaV::siguiente(direccionI dir) {
	if (vacia()) {
		cout << "Error: Lista Vacia\n";
		return -1;
	} else{
		if (dir==longi-1) {
			cout << "Error: Direccion Erronea\n";
			return -1;
		} else{
			return dir+1;
		}
	}
}



direccionI ListaV::anterior(direccionI dir) {
	if (vacia()) {
		cout << "Error: Lista Vacia\n";
	} else{
		if (dir>0 && dir<=longi-1) {
			return dir-1;

		} else{
			cout << "Error: Direccion Erronea\n";
			return -1;
		}
	}
}



bool ListaV::vacia() {
	return longi==0;
}



int ListaV::recupera(direccionI dir) {
	if (vacia()) {
		cout << "Error: Lista Vacia\n";
	}  else{
		if (dir>=0 && dir<=longi-1) {
			return elementos[dir];
		}  else{
			cout << "Error: Direccion Erronea\n";
		}
	}
}



int ListaV::longitud() {
	return longi;
}



void ListaV::inserta(direccionI dir, int e) {
	if (longi==MaxV) {
		cout << "Error: Lista Llena\n";
		return ;
	}
	if (dir>=0 && dir<=longi-1) {
		for (int i=longi; i >dir; i--) {
			elementos[i]=elementos[i-1];
		}
		elementos[dir]=e;
		longi++;
	}  else{
		cout << "Error: Direccion Erronea\n";
	}

}



void ListaV::inserta_primero(int e) {
	if (longi==MaxV) {
		cout << "Error: Lista Llena\n";
		return ;
	}

	for (int i=longi; i >0; i--) {
		elementos[i]=elementos[i-1];
	}
	elementos[0]=e;
	longi++;
}



void ListaV::inserta_ultimo(int e) {
	if (longi==MaxV) {
		cout << "Error: Lista Llena\n";
	}  else{
		elementos[longi]=e;
		longi++;
	}
}



void ListaV::suprime(direccionI dir) {
	if (longi==0) {
		cout << "Error: Lista Vacia\n";
		return;
	}
	if (dir>=0 && dir<=longi-1) {
		for (int i=dir; i < longi-1; i++) {
			elementos[i]=elementos[i+1];
		}
		longi--;
	} else{
		cout << "Error: Direccion Erronea\n";
	}
}



void ListaV::modifica(direccionI dir, int e) {
	if (longi==0) {
		cout << "Error: Lista Vacia\n";
		return;
	}
	if (dir>=0 && dir<=longi-1) {
		elementos[dir]=e;
	} else{
		cout << "Error: Direccion Erronea\n";
    }

}



string ListaV::to_str(){
	string s="{";
	for (int i=0; i < longi; i++) {
		s+= to_string(elementos[i]);
		if (i<longi-1) {
            s+=",";
		}
	}
	return s+"}";
}

