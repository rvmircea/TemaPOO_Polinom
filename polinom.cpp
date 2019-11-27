#include "Polinom.h"
#include "Monom.h"
#include <stdlib.h>
#include <vector>


//constructori
Polinom::Polinom()
{
    nr_monoame = 1;
    m=new Monom;
}

Polinom::Polinom(const Polinom& p)
{
    nr_monoame=p.nr_monoame;
    m = new Monom;
    *m = *(p.m);
}

Polinom::Polinom(int nr,Monom* mn)
{
    nr_monoame = nr;
    m=mn;
    m = new Monom;
    *m = *(mn);
}
//destructor
Polinom::~Polinom()
{
    delete m;
}

//metode
void Polinom::afis()
{
    cout<<nr_monoame<<endl;

    cout<<m[0];

    for(int i=1; i<nr_monoame; i++)
    {
        if(m[i].g_coef() < 0)
            cout<<" -"<<m[i];
        else
            cout<<" +"<<m[i];
    }

}


//Functia verifica daca coeficientii polinomului sunt corpimi
int Polinom::coprime(Monom *m,int nr)
{
    int temp;
    int ok = 0;
    if(nr == 1)
    {
        cout<<"Nu se poate aplica cmmdc pe un singur coeficient! ";
        return 0;
    }

    for(int i=0; i<nr-1; i++)
    {

        int aux = abs( int(m[i].g_coef()) );
        int auy = abs( int(m[i+1].g_coef()) );

        if(aux == auy)
            return 0;

        while(aux != auy)
        {
            if(aux > auy)
                aux = aux - auy;
            if(auy > aux)
                auy= auy- aux;
        }
        if(aux == 1)
        {
            ok = 1;
        }
    }

    if(ok == 1)
        return 1;

    return 0;
}
//Functia returneaza coeficientul cu valoarea cea mai mare din polinom
int Polinom::get_max(Monom *m)
{
    int mxm = m[0].g_coef();

    for(int i=1; i<nr_monoame; i++)
    {
        if(m[i].g_coef() > mxm)
            mxm = m[i].g_coef();
    }
    return mxm;
}

