#ifndef POLINOMIREDUCTIBIL_H
#define POLINOMIREDUCTIBIL_H

#include "Polinom.h"

using namespace std;

class Polinom_ireductibil:public Polinom
{
public:
    void criteriu();
    Polinom_ireductibil();
    Polinom_ireductibil(int,Monom*);
    Polinom_ireductibil(const Polinom&);
    ~Polinom_ireductibil();
     void afis();

};

#endif // POLINOMIREDUCTIBIL_H
