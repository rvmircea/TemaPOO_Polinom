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
    nr_monoame = nr;

    m=mn;
     for(int i=0;i<nr;i++)
    {
        cout<<m[i];
        cout<<endl;
    }


}

/*ostream& operator<<(ostream& out,Polinom p)
{

   out<<p.m;

    return out;
}
*/

void Polinom::afis()
{
     cout<<nr_monoame<<endl;
    for(int i=0;i<nr_monoame;i++)
    {
        cout<<m[i].g_coef()<<"*X^"<<m[i].g_grad()<<endl;
    }



}
Polinom::~Polinom()
{
    delete m;
}
