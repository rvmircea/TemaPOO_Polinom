#include <iostream>
#include "Monom.h"
#include "Polinom.h"
#include "Polinom_reductibil.h"
using namespace std;

Monom* Citire(int nr_monoame)
{
    Monom *m;
    m = new Monom[nr_monoame];

    for(int i=0;i<nr_monoame; i++)
    {
        cin>>m[i];
    }
    return m;
}

int main()
{
    int nr_m;
    cout<<"Cititi nr monoame: ";
    cin>>nr_m;
    Monom *m;
    m=Citire(nr_m);
    //Polinom *poli(nr_m,m);

    Polinom_reductibil p(nr_m,m);
    p.criteriu();
   // p.afis();
    return 0;
}
