#include "Polinom_reductibil.h"

Polinom_reductibil::Polinom_reductibil()
{
    nr_monoame = 1;
    m=new Monom;
}

Polinom_reductibil::Polinom_reductibil(const Polinom_reductibil& p)
{
    nr_monoame=p.nr_monoame;
    m=p.m;
}

Polinom_reductibil::Polinom_reductibil(int nr,Monom* mn)
{
    nr_monoame = nr;

    m=mn;
     for(int i=0;i<nr;i++)
    {
        cout<<m[i];
        cout<<endl;
    }


}

void Polinom_reductibil::afis()
{
     cout<<nr_monoame<<endl;
    for(int i=0;i<nr_monoame;i++)
    {
        cout<<m[i].g_coef()<<"*X^"<<m[i].g_grad()<<endl;
    }



}
Polinom_reductibil::~Polinom_reductibil()
{
    delete m;
}

int Polinom_reductibil::Verificare_criteriu()
{

}


