//---------------------------------------------------------------------------

#pragma hdrstop

#include "MatrizM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)



MatrizM::MatrizM(){
	mem = new CSMemoria();
	ptrmatd = Nulo;
	nt = 0;
	dimf =0;
	dimc = 0;
	rep = 0;
}



MatrizM::MatrizM(CSMemoria *m){
	mem = m;
	ptrmatd = Nulo;
	nt = 0;
	dimf=0;
	dimc=0;
	rep=0;
}



int MatrizM::anterior(int p){
	if (nt == 0 || p==ptrmatd) {
		return Nulo;
	} else{
		int x = ptrmatd;
		int ant = Nulo;
		while (x != Nulo){
			if(x == p ){
				return ant;
			}
			ant = x;
			x = mem->obtener_dato(x, at_sig);
		}

	}
}




void MatrizM::suprime(int p){
	if (nt == 0) {
		return;
	}else if (p == ptrmatd) {
		  int x = ptrmatd;
		  ptrmatd = mem->obtener_dato(ptrmatd, at_sig);
		  mem->Delete_espacio(x);
	}else{
		int ant = anterior(p);
		int p_sig = mem->obtener_dato(p, at_sig);
		mem->poner_dato(ant, at_sig, p_sig);
		mem->Delete_espacio(p);
	}
}



void MatrizM::dimensionar(int f,int c){
	dimf = f;
	dimc = c;
}




int MatrizM::dimension_Fila(){
	return dimf;
}




int MatrizM::dimension_Columna(){
	return dimc;
}




int MatrizM::buscar(int f, int c){
	int aux = ptrmatd;
	while (aux != Nulo){
		if (mem->obtener_dato(aux,at_fila) == f && mem->obtener_dato(aux, at_columna) == c) {
			return aux;

		}
		aux = mem->obtener_dato(aux, at_sig);
	}
	return Nulo;

}




void MatrizM::poner(int f, int c, int valor){
	if((f>=1 && f<=dimf) && (c>=1 && c<=dimc)){
		int dir = buscar(f,c);
		if(dir ==Nulo && valor !=rep){
			int x = mem->new_espacio(p_data);
			if(x!=Nulo){
				mem->poner_dato(x,at_fila,f);
				mem->poner_dato(x,at_columna,c);
				mem->poner_dato(x,at_dato,valor);
				mem->poner_dato(x,at_sig,ptrmatd);
				ptrmatd=x;
				nt++;
			}else{
				cout << "ERROR NO EXISTE ESPACIO EN MEMORIA\n";
			}
		}else {
		mem->poner_dato(dir,at_dato,valor);
			if(valor == rep){
				//metodo eliminar nodo
				suprime(dir);
				nt--;
			}
		}
		return;
	}
		cout << "ERROR DE RANGO\n";
}





int MatrizM::elemento(int f, int c){
	if((f>=1 && f<=dimf) && (c>=1 && c<=dimc)){
		int dir = buscar(f,c);
		if(dir!=Nulo){
			return mem->obtener_dato(dir,at_dato);
		}else{
			return rep;
		}
	}
}



void MatrizM::definir_valor_repetido(int valor){
	rep=valor;
}




void MatrizM::to_str(){
	string r = "";
	for (int i = 0; i < dimf; i++) {
		r += "|";
		for (int j = 0; j < dimc; j++) {
			r += to_string(elemento(i + 1, j + 1));
			if (j < dimc - 1)
				r += "	";
		}
		r += "|\n";
	}
	mem->mostrar_memoria();
	cout << r << endl;
}



void MatrizM::leer_archivo(){
	int nivel=1;
	new MatrizM(mem);
	ifstream archivo("Planos.txt");
	string linea;
	int f,c;
	bool fin=false;
	if (archivo.is_open()) {
		while (!archivo.eof() && !fin){
			getline(archivo,linea);
			c=linea.length();
			if (linea[0]-'0'==nivel) {
				f=0;

				while (getline(archivo,linea) && !fin){
					if (linea.length()>c) {
						c=linea.length();
					}

					if (linea[0]-'0'==nivel+1) {
						fin=true;
						f--;
					}
					f++;
				}
				dimensionar(f,c);
			}
		}
	}
	archivo.close();

	fin=false;
	int fila=1;
	char x=' ';
	ifstream archi("Planos.txt");
	if (archi.is_open()) {
		while (!archi.eof() && fila <= dimension_Fila()){
			getline(archi,linea);
			if (linea[0]-'0'==nivel) {
				while (getline(archi,linea) && fila <= dimension_Fila()){
					if (linea[0]-'0'==nivel+1) {
						fin=true;
					}else {
						for (int columna=1; columna <= linea.length(); columna++) {
							x=linea[columna-1];
							poner(fila,columna,linea[columna-1]);

						}
						fila++;
					}
				}
			}
		}
		archi.close();
	} else{
	cout<< "error al abrir el archivo"<< "Planos.txt" << endl;
	}
}
