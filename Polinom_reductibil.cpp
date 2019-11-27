#include "Polinom_reductibil.h"

Polinom_reductibil::Polinom_reductibil()
{
    nr_monoame = 1;
    m=new Monom;
}
/*
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

*/
void Polinom_reductibil::afis()
{

    cout<<endl;
    cout<<m[0].g_coef()<<"*X^"<<m[0].g_grad();

    for(int i=1; i<nr_monoame; i++)
    {
        if(m[i].g_coef() < 0)
            cout<<" - "<<m[i].g_coef()<<"*X^"<<m[i].g_grad();
        else
            cout<<" + "<<m[i].g_coef()<<"*X^"<<m[i].g_grad();
    }
    cout<<endl;

}
Polinom_reductibil::~Polinom_reductibil()
{
    delete m;
}

void Polinom_reductibil::Verificare_criteriu()
{
     if(criteriu() == 1)
            cout<<endl<<"Nu este polinom reductibil";
        else if(criteriu() == 0)
            cout<<endl<<"Este polinom reductibil";
        else
            cout<<"Criteriul nu poate fi aplicat";
}
