#include "Polinom.h"
#include "Monom.h"

Polinom::Polinom()
{
    nr_monoame = 1;
    m=new Monom;
}

Polinom::Polinom(const Polinom& p)
{
    nr_monoame=p.nr_monoame;
    m=p.m;
}

Polinom::Polinom(int nr,Monom* mn)
{
    mn = new Monom[nr];
    cout<<"cititi monoamele care alcatuiesc polinomul: \n";
    for(int i=0;i<nr;i++)
    {
        cin>>mn[i];
        cout<<endl;
    }
}



Polinom::~Polinom()
{
    delete[] m;
}
