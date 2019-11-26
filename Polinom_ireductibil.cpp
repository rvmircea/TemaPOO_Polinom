#include "Polinom_ireductibil.h"

Polinom_ireductibil::Polinom_ireductibil()
{
    nr_monoame = 1;
    m=new Monom;
}

Polinom_ireductibil::Polinom_ireductibil(const Polinom_ireductibil& p)
{
    nr_monoame=p.nr_monoame;
    m=p.m;
}

Polinom_ireductibil::Polinom_ireductibil(int nr,Monom* mn)
{
    nr_monoame = nr;

    m=mn;
     for(int i=0;i<nr;i++)
    {
        cout<<m[i];
        cout<<endl;
    }
}

void Polinom_ireductibil::afis()
{
        cout<<nr_monoame<<endl;
        for(int i=0;i<nr_monoame;i++)
        {
            cout<<m[i].g_coef()<<"*X^"<<m[i].g_grad()<<endl;
        }
}
Polinom_ireductibil::~Polinom_ireductibil()
{
    delete m;
}

int Polinom_ireductibil::Verificare_criteriu()
{

}


