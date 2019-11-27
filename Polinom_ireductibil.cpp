#include "Polinom_ireductibil.h"

Polinom_ireductibil::Polinom_ireductibil()
{
    nr_monoame = 1;
    m=new Monom;
}

/*Polinom_ireductibil::Polinom_ireductibil(const Polinom_ireductibil& p)
{
    nr_monoame=p.nr_monoame;
    m=p.m;
}
*/
/*Polinom_ireductibil::Polinom_ireductibil(int nr,Monom* mn)
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
void Polinom_ireductibil::afis()
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
Polinom_ireductibil::~Polinom_ireductibil()
{
    delete m;
}

void  Polinom_ireductibil::Verificare_criteriu()
{
    int result = criteriu();
        if(result == 1)
            cout<<endl<<"\nPolinom ireductibil";
        else if(result == 0)
            cout<<endl<<"\nPolinom reductibil";
        else
            cout<<"Criteriul nu poate fi aplicat";

}
