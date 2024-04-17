#include <iostream>
#include <string>
#include "UMemoria.h"
#include "ListaM.h"
#include "ListaP.h"
#include "PolinomioM.h"
#include "PolinomioP.h"
#include "ConjuntoV.h"
using namespace std;
	void menu();
	void menu1();

int main(){

	ConjuntoV* a=new ConjuntoV();
	ConjuntoV* b=new ConjuntoV();
	ConjuntoV* c=new ConjuntoV();

	a->inserta(1);
	a->inserta(2);
	a->inserta(3);
	a->inserta(4);
	b->inserta(6);
	b->inserta(1);
	b->inserta(9);
	b->inserta(8);

	cout<<a->tostr()<<endl;
	cout<<b->tostr()<<endl;
	cout<<c->tostr()<<endl;

	//menu(); // menu de la memorioa y la lista
	//menu1(); // menu de la lista puntero
	system ("pause\n");
	return 0;
}


void menu(){
	ListaM *list;
	CSMemoria *mem;
	int opcion;
	do {
		cout << "1.CREAR MEMORIA\n";
		cout << "2.PEDIR ESPACIO\n";
		cout << "3.CREAR LISTA\n";
		cout << "4.MOSTRAR MEMORIA\n";
		cout << "5.MOSTRAR LISTA\n";
		cout << "6.INSERTAR DIR PRIMERO \n L.INSERTAR(L,PRIMERO,DATO)\n";
		cout << "7.INSERTAR DIR FIN\n";
		cout << "8.INSERTAR SIGUIENTE DIR PRIMERO\n L.INSERTAR(L,SIGUIENTE,DATO)\n";
		cout << "9.ELIMINAR ANTERIOR FIN\n";
		cout << "10.INSERTAR ANTERIOR FIN\n";
		cout << "11.LIBERAR ESPACIO\n";
		cout << "12.Salir\n";
		cout << "Opcion: ";
		cin >> opcion;
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
					list = new ListaM(mem);
					} break;
			case 4: {
					mem->mostrar_memoria();

					} break;
			case 5: {
					cout << list->to_str() << endl;
					} break;
			case 6: {
                    int e;
					cout << "Dato: ";
					cin >> e;
					list->inserta_primero(e);
					} break;
			case 7: {
                    int e;
					cout << "Dato: ";
					cin >> e;
					list->inserta_ultimo(e);
					} break;
			case 8: {
					int e;
					cout << "Dato: ";
					cin >> e;
					list->inserta(list->siguiente(list->primero()),e);
					} break;
			case 9: {
					list->suprime(list->anterior(list->fin()));
					} break;
			case 10:{
					int x;
					cout << "Dato: ";
					cin >> x;
					list->inserta(list->anterior(list->fin()),x);
					} break;
			case 11:{
					int x;
					cout << "Dato: ";
					cin >> x;
					mem->Delete_espacio(x);
					}break;
		  }
	}while (opcion!=12);
}


//MENU DE LA LISTA CON PUNTERO
void menu1(){
	ListaP* lis;

		int opcion;
	do {
		cout << "1.CREAR LISTA\n";
		cout << "2.MOSTRAR LISTA\n";
		cout << "3.INSERTAR DIR PRIMERO \n L.INSERTAR(L,PRIMERO,DATO)\n";
		cout << "4.INSERTAR DIR FIN\n";
		cout << "5.INSERTAR SIGUIENTE DIR PRIMERO\n L.INSERTAR(L,SIGUIENTE,DATO)\n";
		cout << "6.ELIMINAR ANTERIOR FIN\n";
		cout << "7.INSERTAR ANTERIOR FIN\n";
		cout << "8.Salir\n";
		cout << "Opcion: ";
		cin >> opcion;
		  switch (opcion) {
			case 1: {
					lis = new ListaP;
					} break;
			case 2: {
					cout << lis->tostr() << endl;
					} break;
			case 3: {
					int e;
					cout << "Dato: ";
					cin >> e;
					lis->insertar_primero(e);
					} break;
			case 4: {
					int e;
					cout << "Dato: ";
					cin >> e;
					lis->insertar_ultimo(e);
					} break;
			case 5: {
					int e;
					cout << "Dato: ";
					cin >> e;
					lis->insertar(lis->siguiente(lis->primero()),e);
					} break;
			case 6: {
					lis->suprime(lis->anterior(lis->fin()));
					} break;
			case 7:{
					int x;
					cout << "Dato: ";
					cin >> x;
					lis->insertar(lis->anterior(lis->fin()),x);
					} break;
		  }
	}while (opcion!=8);
}

