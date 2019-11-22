#ifndef POLINOMREDUCTIBIL_H
#define POLINOMREDUCTIBIL_H

#include "Polinom.h"

using namespace std;

class Polinom_reductibil:public Polinom
{
public:
    void criteriu();
    Polinom_reductibil();
    Polinom_reductibil(int,Monom*);
    Polinom_reductibil(const Polinom&);
    ~Polinom_reductibil();
     void afis();

};

#endif // POLINOMIREDUCTIBIL_H
