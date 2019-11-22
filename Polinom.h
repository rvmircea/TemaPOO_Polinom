#ifndef POLINOM_H
#define POLINOM_H
#include <iostream>
#include "Monom.h"

using namespace std;

class Polinom{
protected:
    int nr_monoame;
    Monom* m;
public:
    Polinom();
    Polinom(int,Monom*);
    Polinom(const Polinom&);
    ~Polinom();

    void afis();
    virtual void criteriu() =0;
};

#endif // POLINOM_H

