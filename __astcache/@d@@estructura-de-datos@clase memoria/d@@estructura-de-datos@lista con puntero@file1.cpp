#include <iostream>
#include <string>
#include "Unit1.h"

using namespace std;

int main(){
	ListaP* list;
	list=new ListaP;
	list->insertar_primero(10);
	cout<<list->tostr()<<endl;
	system("pause");
return 0;
}

