#ifndef POLINOMREDUCTIBIL_H
#define POLINOMREDUCTIBIL_H

#include "Polinom.h"

using namespace std;

class Polinom_reductibil:public Polinom
{
public:

    Polinom_reductibil();
    Polinom_reductibil(int,Monom*);
    Polinom_reductibil(const Polinom_reductibil&);
    ~Polinom_reductibil();
     void afis();
    int Verificare_criteriu();
};

#endif // POLINOMIREDUCTIBIL_H
