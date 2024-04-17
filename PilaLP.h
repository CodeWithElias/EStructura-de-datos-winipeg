
   // FUNCIONA Y ESTA PROBADO

//---------------------------------------------------------------------------

#ifndef PilaLPH
#define PilaLPH
//---------------------------------------------------------------------------


#include <iostream>
#include <string>
#include "ListaP.h"

using namespace std;

class PilaL{
    private:
        ListaP* L;
    public:
        PilaL();
        bool vacia();
        void meter(int e);
        void sacar(int& e);
        int cima();
        string to_str();
};

#endif
