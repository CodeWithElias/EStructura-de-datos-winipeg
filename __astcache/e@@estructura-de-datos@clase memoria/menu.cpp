#include <iostream>
#include <string>
#include <locale>
#include "UMemoria.h"

#include "ListaM.h"
#include "ListaP.h"
#include "ListaV.h"

#include "PolinomioV.h"
#include "PolinomioM.h"
#include "PolinomioP.h"
#include "PolinomioLM.h"
#include "PolinomioM.h"

#include "ConjuntoV.h"
#include "ConjuntoL.h"
#include "ConjuntoP.h"
#include "ConjuntoL.h"
#include "ConjuntoM.h"

using namespace std;


	void menu();

	void menu_ListaV();
	void menu_ListaP();

	void PolinomioPtr();
	void menu_PolinomioVec();
	void menu_PolinomioLisMen();
	void PolinomioMem();

	void menu_conjuntoPtr();
	void ConjuntoLis();
	void menu_ConjuntoMen();







	// procedimiento para encontrar el punto maximo
	   // arreglar el codigo
	void punto_max(PolinomioP* p, int a, int b, float desplazamiento);

int main(){


	//menu_conjuntoPtr();
	//menu_ListaV();// menu lista con vector
	//ConjuntoLis();  // menu del conjunto lista
	//menu(); // menu de la memorioa y la lista
	//menu_ListaP(); // menu de la lista puntero
	//menu_PolinomioVec();
	//menu_PolinomioLisMen();
	PolinomioMem();
	//PolinomioPtr(); // menu del polinomio puntero
	//menu_ConjuntoMen();

	system ("pause\n");
	return 0;
}



void punto_max(PolinomioP* p, int a, int b, float desplazamiento){
	float max_x=a;
	float max_y=p->Evaluar(a);
	for (float x=a; x <= b; x= x+desplazamiento) {
		float y=p->Evaluar(x);
		if (y>max_y) {
			max_x=x;
			max_y=y;
		}
	}
	cout<<"("+to_string(max_x)+ "," +to_string(max_y)+")\n";
}

	// MENU MENORIA Y LISTA-MEMORIA
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
		  system ("pause\n");
		  system("cls");

	}while (opcion!=12);
}

/*----------------------------------------------------------------------------*/

  // MENU LISTA CON VECTORES     //// completar el menu
void menu_ListaV(){
	ListaV* lis;

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
					lis = new ListaV;
					} break;
			case 2: {
					cout << lis->to_str() << endl;
					} break;
			case 3: {
					int e;
					cout << "Dato: ";
					cin >> e;
					lis->inserta_primero(e);
					} break;
			case 4: {
					int e;
					cout << "Dato: ";
					cin >> e;
					lis->inserta_ultimo(e);
					} break;
			case 5: {
					int e;
					cout << "Dato: ";
					cin >> e;
					lis->inserta(lis->siguiente(lis->primero()),e);
					} break;
			case 6: {
					lis->suprime(lis->anterior(lis->fin())); // en observacion
					} break;
			case 7: {
					int x;
					cout << "Dato: ";
					cin >> x;
					lis->inserta(lis->anterior(lis->fin()),x);
					} break;
		  }
			system ("pause\n");
			system("cls");
	}while (opcion!=8);

}

/*----------------------------------------------------------------------------*/

//MENU DE LA LISTA CON PUNTERO
void menu_ListaP(){
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
			case 7: {
					int x;
					cout << "Dato: ";
					cin >> x;
					lis->insertar(lis->anterior(lis->fin()),x);
					} break;
		  }
			system ("pause\n");
			system("cls");
	}while (opcion!=8);
}

/*----------------------------------------------------------------------------*/

// MENU CONJUNTO CON LISTA PUNTERO
void ConjuntoLis(){

	ConjuntoL* a;
	ConjuntoL* b;
	ConjuntoL* c;

		int opcion;
	do {
		cout << "1.CREAR CONJUNTO A\n";
		cout << "2.CREAR CONJUNTO B\n";
		cout << "3.CREAR CONJUNTO C\n";
		cout << "4.INSERTAR ELEMENTO\n";
		cout << "5.MOSTRAR CONJUNTO\n";
		cout << "6.UNION DE CONJUNTO A Y B\n";
		cout << "7.INTERCECCION DE CONJUNTO A Y B\n";
		cout << "8.Salir\n";
		cout << "Opcion: ";
		cin >> opcion;
		  switch (opcion) {
			case 1: {
					a=new ConjuntoL();
					} break;
			case 2: {
					b=new ConjuntoL();
					} break;
			case 3: {
					c=new ConjuntoL();
					} break;
			case 4: {
					int e;
					cout << "Dato: ";
					cin >> e;

					int conj;
					cout << "Escriva 1 para conjunto A:  \n";
					cout << "Escriva 2 para conjunto B:  \n";
					cout << "Escriva 3 para conjunto C:  \n";
					cin >> conj;

					if (conj==1) {
						a->inserta(e);
					} else if (conj==2) {
								b->inserta(e);
						   } else if (conj==3) {
										c->inserta(e);
								  }
					} break;
			case 5: {

					int conj;
					cout << "Escriva 1 para conjunto A:  \n";
					cout << "Escriva 2 para conjunto B:  \n";
					cout << "Escriva 3 para conjunto C:  \n";
					cin >> conj;

					if (conj==1) {
						cout<<a->to_str()<<endl;
					} else if (conj==2) {
								cout<<b->to_str()<<endl;
						   } else if (conj==3) {
										cout<<c->to_str()<<endl;
								  }
					} break;
			case 6: {
					a->unir(b,c);
					} break;
			case 7: {
					a->intercectar(b,c);
					} break;
		  }
		  //system("cls");  // limpia la consola
			system ("pause\n");
			system("cls");
	}while (opcion!=8);
}

/*----------------------------------------------------------------------------*/

// MENU POLINOMIO CON PUNTERO
void PolinomioPtr(){

	PolinomioP* pol;

		int opcion;
	do {
		cout << "1.CREAR POLINOMIO\n";
		cout << "2.PONER TERMINO\n";
		cout << "3.MOSTRAR POLINOMIO\n";
		cout << "4.ENCONTRAR COORDENADA MAXIMA\n";
		cout << "5.SALIR\n";
		cout << "Opcion: ";
		cin >> opcion;
		  switch (opcion) {
			case 1: {
					pol = new PolinomioP();
					} break;
			case 2: {
					int c;
					cout << "Coeficiente: ";
					cin >> c;
					int e;
					cout << "Exponente: ";
					cin >> e;
					pol->Poner_termino(c,e);
					} break;
			case 3: {
					int e;
					cout << pol->Mostrar()<<endl;
					} break;
			case 4: {
					int a;
					cout << "Ingrese el punto A: ";
					cin >> a;

					int b;
					cout << "Ingrese el punto B: ";
					cin >> b;

					float des;
					cout << "Ingrese el desplazamiento: ";
					cin >> des;
					punto_max(pol, a , b , des);

					} break;
		  }
			system ("pause\n");

			system("cls");
	}while (opcion!=5);
}


/*----------------------------------------------------------------------------*/

// MENU CONJUNTO CON PUNTEROS
void menu_conjuntoPtr(){
	ConjuntoPtr* a;
	ConjuntoPtr* b;
	ConjuntoPtr* c;

		int opcion;
	do {
		cout << "1.CREAR CONJUNTO A\n";
		cout << "2.CREAR CONJUNTO B\n";
		cout << "3.CREAR CONJUNTO C\n";
		cout << "4.INSERTAR ELEMENTO\n";
		cout << "5.MOSTRAR CONJUNTO\n";
		cout << "6.UNION DE CONJUNTO A Y B\n";
		cout << "7.INTERCECCION DE CONJUNTO A Y B\n";
		cout << "8.Salir\n";
		cout << "Opcion: ";
		cin >> opcion;
		  switch (opcion) {
			case 1: {
					a=new ConjuntoPtr();
					} break;
			case 2: {
					b=new ConjuntoPtr();
					} break;
			case 3: {
					c=new ConjuntoPtr();
					} break;
			case 4: {
					int e;
					cout << "Dato: ";
					cin >> e;

					int conj;
					cout << "Escriva 1 para conjunto A:  \n";
					cout << "Escriva 2 para conjunto B:  \n";
					cout << "Escriva 3 para conjunto C:  \n";
					cin >> conj;

					if (conj==1) {
						a->inserta(e);
					} else if (conj==2) {
								b->inserta(e);
						   } else if (conj==3) {
										c->inserta(e);
								  }
					} break;
			case 5: {

					int conj;
					cout << "Escriva 1 para conjunto A:  \n";
					cout << "Escriva 2 para conjunto B:  \n";
					cout << "Escriva 3 para conjunto C:  \n";
					cin >> conj;

					if (conj==1) {
						cout<<a->toStr()<<endl;
					} else if (conj==2) {
								cout<<b->toStr()<<endl;
						   } else if (conj==3) {
										cout<<c->toStr()<<endl;
								  }
					} break;
			case 6: {
					a->unir(b,c);
					} break;
			case 7: {
					a->interseccion(a,b,c);
					} break;
		  }
		  //system("cls");  // limpia la consola
			system ("pause\n");
			system("cls");
	}while (opcion!=8);
}


/*----------------------------------------------------------------------------*/

	// MENU POLINOMIO VECTOR
void menu_PolinomioVec(){
	PolinomioV* p=new PolinomioV();
	PolinomioV* p1=new PolinomioV();
	PolinomioV* p2=new PolinomioV();

	p->Poner_Termino(-3,2);
	p1->Poner_Termino(5,2);
	p2->sumar(p,p1,p2);

	cout << p2->to_str()<< endl;

}


/*----------------------------------------------------------------------------*/

		 // MENU CONJUNTO MEMORIA
void menu_ConjuntoMen(){

	CSMemoria *mem;
	ConjuntoS* a;
	ConjuntoS* b;
	ConjuntoS* c;

		int opcion;
	do {
		cout << "1.CREAR CONJUNTO A\n";
		cout << "2.CREAR CONJUNTO B\n";
		cout << "3.CREAR CONJUNTO C\n";
		cout << "4.CREAR MEMORIA\n";
		cout << "5.INSERTAR ELEMENTO\n";
		cout << "6.MOSTRAR CONJUNTO\n";
		cout << "7.UNION DE CONJUNTO A Y B\n";
		cout << "8.INTERCECCION DE CONJUNTO A Y B\n";
		cout << "9.MOSTRAR MEMORIA\n";
		cout << "10.Salir\n";
		cout << "Opcion: ";
		cin >> opcion;
		  switch (opcion) {
			case 1: {
					a=new ConjuntoS(mem);
					} break;
			case 2: {
					b=new ConjuntoS(mem);
					} break;
			case 3: {
					c=new ConjuntoS(mem);
					} break;
			case 4: {
					mem=new CSMemoria();
					cout<<"MEMORIA CREADA"<<endl;
					} break;
			case 5: {
					int e;
					cout << "Dato: ";
					cin >> e;

					int conj;
					cout << "Escriva 1 para conjunto A:  \n";
					cout << "Escriva 2 para conjunto B:  \n";
					cout << "Escriva 3 para conjunto C:  \n";
					cin >> conj;

					if (conj==1) {
						a->inserta(e);
					} else if (conj==2) {
								b->inserta(e);
						   } else if (conj==3) {
										c->inserta(e);
								  }
					} break;
			case 6: {

					int conj;
					cout << "Escriva 1 para conjunto A:  \n";
					cout << "Escriva 2 para conjunto B:  \n";
					cout << "Escriva 3 para conjunto C:  \n";
					cin >> conj;

					if (conj==1) {
						cout<<a->to_str()<<endl;
					} else if (conj==2) {
								cout<<b->to_str()<<endl;
						   } else if (conj==3) {
										cout<<c->to_str()<<endl;
								  }
					} break;
			case 7: {
					//a->unionC(a,b,c);
					} break;
			case 8: {
					//a->interseccion(a,b,c);
					} break;
			case 9: {
					mem->mostrar_memoria();
					} break;
		  }
		  //system("cls");  // limpia la consola
			system ("pause\n");
			system("cls");
	}while (opcion!=10);


}

/*----------------------------------------------------------------------------*/


		  // MENU POLINOMIO LISTA MEMORIA
void menu_PolinomioLisMen(){
	PolinomioLM* p=new PolinomioLM();
	PolinomioLM* p1=new PolinomioLM();
	PolinomioLM* p2=new PolinomioLM();

	p->Poner_Termino(5,1);

	p->Poner_Termino(-3,2);

	p->Poner_Termino(5,5);

	p1->Poner_Termino(8,2);

	p1->Poner_Termino(2,1);

	p2->sumar(p,p1,p2);
	cout << p2->to_str()<< endl;

}



/*----------------------------------------------------------------------------*/


		  // MENU POLINOMIO MEMORIA
void PolinomioMem(){
	CSMemoria* mem=new CSMemoria();

	PolinomioM* p=new PolinomioM(mem);
	PolinomioM* p1=new PolinomioM(mem);
	PolinomioM* p2=new PolinomioM(mem);


	p->Poner_Termino(5,1);

	p->Poner_Termino(-3,2);

	p1->Poner_Termino(5,5);

	p1->Poner_Termino(8,2);

	p->Poner_Termino(2,5);


	p2->sumar(p,p1,p2);
	cout << p2->to_str()<< endl;

}
