#ifndef POLINOMIREDUCTIBIL_H
#define POLINOMIREDUCTIBIL_H

#include "Polinom.h"


using namespace std;

class Polinom_ireductibil:public Polinom
{
public:
    Polinom_ireductibil();
    //apel explicit constructor parametrizat din baza Polinom
    Polinom_ireductibil(int nr, Monom* mono):Polinom(nr,mono)
    {
        nr_monoame=nr,m=mono;
    }
    //aoel explicit constructor copiere din baza Polinom
    Polinom_ireductibil(const Polinom_ireductibil& p):Polinom(p)
    {
        nr_monoame=p.nr_monoame;
        m=p.m;
    }
    ~Polinom_ireductibil();

    void afis();
    int Verificare_criteriu();
    void Tip_clasa();
};

#endif // POLINOMIREDUCTIBIL_H
