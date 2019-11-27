#ifndef POLINOM_H
#define POLINOM_H

#include <iostream>
#include "Monom.h"

using namespace std;

class Polinom
{
protected:
    int nr_monoame;
    Monom* m;
public:
    Polinom();
    Polinom(int,Monom*);
    Polinom(const Polinom&);
    ~Polinom();
    int get_max(Monom*);
    virtual void afis()=0;
    int coprime(Monom*,int);
    virtual int Verificare_criteriu()=0;
    virtual void Tip_clasa()=0;
};

#endif // POLINOM_H

