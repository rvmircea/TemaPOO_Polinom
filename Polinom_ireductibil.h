#ifndef POLINOMIREDUCTIBIL_H
#define POLINOMIREDUCTIBIL_H

#include "Polinom.h"

using namespace std;

class Polinom_ireductibil:public Polinom
{
public:


    Polinom_ireductibil();
    Polinom_ireductibil(int,Monom*);
    Polinom_ireductibil(const Polinom_ireductibil&);
    ~Polinom_ireductibil();
     void afis();
     int Verificare_criteriu();

};

#endif // POLINOMIREDUCTIBIL_H
