#include <iostream>
#include <string>
#include "UMemoria.h"
using namespace std;
	void menu();

int main(){
	menu();
	system ("pause");
	return 0;
}

void menu(){
	CSMemoria *mem;
	int opcion;
	do {
		cout<<"1.-CREAR"<<endl;
		cout<<"2.-PEDIR ESPACIO"<<endl;
		cout<<"3.-LIBERAR ESPACIO"<<endl;
		cout<<"4.-PONER DATO"<<endl;
		cout<<"5.-MOSTRAR MEMORIA"<<endl;
		cout<<"6.-SALIR"<<endl;
		cout<<"OPCION:";
		cin>>opcion;
		  switch (opcion) {
			case 1: {
					mem=new CSMemoria();
					cout<<"MEMORIA CREADA"<<endl;
					} break;
			 case 2: {
					string ids;
					cout<<"IDS: ";
					cin.ignore();
					getline(cin,ids);
					mem->new_espacio(ids);
					} break;
			case 3: {
					int dir_delete;
					cout<<"LIBERAR ESPACIO DIR: ";
					cin>>dir_delete;
					mem->Delete_espacio(dir_delete);
					} break;
			case 4: {
					int dir, valor;
					string id;
					cout<<"DIRECCION: ";
					cin>>dir;
					cout<<"ID: ";
					cin.ignore();
					getline(cin,id);
					cout<<"VALOR: ";
					cin>>valor;
					mem->poner_dato(dir,id,valor);
					} break;
			case 5: {
					mem->mostrar_memoria();
					} break;
		  }
	}while (opcion!=6);
}
