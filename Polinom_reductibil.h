#ifndef POLINOMREDUCTIBIL_H
#define POLINOMREDUCTIBIL_H

#include "Polinom.h"

using namespace std;

class Polinom_reductibil:public Polinom
{
public:

    Polinom_reductibil();

    //apel explicit constructor parametrizat din baza Polinom
    Polinom_reductibil(int nr, Monom* mono):Polinom(nr,mono)
    {
        nr_monoame=nr,m=mono;
    }
    //apel explicit constructor copiere din baza Polinom
    Polinom_reductibil(const Polinom_reductibil& p):Polinom(p)
    {
        nr_monoame=p.nr_monoame;
        m=p.m;
    }
    ~Polinom_reductibil();

    void afis();
    int Verificare_criteriu();
    void Tip_clasa();
};

#endif // POLINOMIREDUCTIBIL_H
