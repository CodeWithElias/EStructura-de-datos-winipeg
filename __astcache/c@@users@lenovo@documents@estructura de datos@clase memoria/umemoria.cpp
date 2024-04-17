        // FUNCIONA Y ESTA PROBADO

//---------------------------------------------------------------------------

#pragma hdrstop

#include "UMemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

int Numero_Ids(string cadena){
	int cantidad=0;
	for (int i = 0; i < cadena.length(); i++) {
		if (cadena[i]==',') {
			cantidad ++;
		}
	}
	if (!cadena.empty()) {
		cantidad+=1;
	} else{
		cantidad+=0;
	}
	return cantidad;
}

string Obtener_Id(string cadena, int n){
	string palabra="";
	int contador=0;
	int i=0;
	while (contador<n-1 && i<cadena.length()){
		if (cadena.at(i)==',') {   // at : compara con y devuelve verdadero si son iguales
			contador ++;
			cadena= cadena.substr(i+1,cadena.length()-(cadena.substr(0,i).length()));
			i=-1;
		}
		i++;
	}
	i=0;
	while (cadena[i]!=',' && i<cadena.length()){
		i++;
	}
	palabra=cadena.substr(0,i);
	return palabra;
}
  // ELIMINA LA FLECHA AL INICIO DE UNA PALABRA
void EliminarFlechas(string &cadena){
	int pos=0;
	if (cadena!="") {
		while (cadena[pos]!='-' && cadena[pos+1]!='>'){
			pos++;
		}
		cadena=cadena.substr(pos+2,cadena.length()-(cadena.substr(0,pos+1).length()));
	}
}


	CSMemoria::CSMemoria(){  // crear   CONSTRUCTOR
		mem=new NodoMem[Max];
		for (int i = 0; i < Max; i++) {
			mem[i].link=i+1;
		}
		mem[Max-1].link=-1;
		this ->libre=0;
	}

	direccion_mem CSMemoria::new_espacio(string cadena){
		int cant=Numero_Ids(cadena);
		if (cant<=Espacio_disponible()) {
			int dir=libre;
			int d=libre;
			for (int i=1; i<= cant-1; i++) {
				mem[d].id=Obtener_Id(cadena,i);
				d=mem[d].link;
			}
			libre=mem[d].link;
			mem[d].link=-1;
			mem[d].id=Obtener_Id(cadena, cant);
			return dir;
		} else{
			cout<<"ERROR: ESPACIO INSUFICIENTE\n";
        }
	}


	void CSMemoria::Delete_espacio(direccion_mem dir){
		int x=dir;
		while (mem[x].link != -1){
			x=mem[x].link;
		}
		mem[x].link=libre;
		libre=dir;
	}


	void CSMemoria::poner_dato(direccion_mem dir, string id, int valor){
		int z=dir;
		EliminarFlechas(id);
		while (z!=Nulo){
			if (mem[z].id==id) {
				mem[z].dato=valor;
			}
			z=mem[z].link;
		}
	}

	int CSMemoria::obtener_dato(direccion_mem dir, string id){
		int z=dir;
		bool ex=false;
		EliminarFlechas(id);
		while (z!=Nulo){
			if (mem[z].id==id) {
				return mem[z].dato;
			}
			z=mem[z].link;
		}
	}

	int CSMemoria::Espacio_disponible(){
		int x = libre;
		int c=0;
		while (x!=Nulo){
			c++;
			x=mem[x].link;
		}
		return c;
	}

	int CSMemoria::Espacio_ocupado(){
		return (Max-Espacio_disponible());
	}

	bool CSMemoria::dir_libre(direccion_mem dir){
		int x= libre;
		bool c=false;
		while ((x!=Nulo) && (c==false)){
			if (x==dir) {
				c= true;
			}
			x=mem[x].link;
		}
		return c;
	}

	void CSMemoria::mostrar_memoria(){
		string cab="| DIR |  DATO  |    ID    |E| LINK |\n";
		string lin="+"+string(cab.length()-3,'-')+"+\n";
		string out= lin + cab + lin;
		int edir =3,edat=8,eid=10;
		for (int i=0; i < Max; i++) {
			string ocup=!dir_libre(i)?"DO":"";
			string lib=dir_libre(i)?"L":" ";
			int rel = edir-to_string(i).length();
			string dir=" "+string(rel,'0')+to_string(i)+" ";
			rel = edat-to_string(mem[i].dato).length();
			string dat = string(rel,' ')+ to_string(mem[i].dato);
			rel = eid - mem[i].id.length();
			string id = string(rel,' ')+ mem[i].id;
			rel =edir - to_string(mem[i].link).length();
			string lnk = " "+ string(rel, ' ')+ to_string(mem[i].link)+" ";
			out += "|" + dir + "|" + dat + "|" + id + "|" + lib + "|" + lnk + "|" + ocup +"\n";
		}
		out +=lin;
		out +="Libre = " + to_string(libre) + "\n";
		out +="Espacios Libres = " + to_string(Espacio_disponible()) +  "\n";
		out +="Espacios Ocupados = " + to_string(Espacio_ocupado()) +  "\n";
		cout << out;
	}
