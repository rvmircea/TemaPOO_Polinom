#include "Polinom.h"
#include "Monom.h"
#include <stdlib.h>
#include <vector>

Polinom::Polinom()
{
    nr_monoame = 1;
    m=new Monom;

    //cout<<"Sunt un polinom \n";
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

void Polinom::afis()
{
    cout<<nr_monoame<<endl;

    cout<<m[0].g_coef()<<"X^"<<m[0].g_grad();

    for(int i=1; i<nr_monoame; i++)
    {
        if(m[i].g_coef() < 0)
            cout<<" -"<<m[i].g_coef()<<"*X^"<<m[i].g_grad()<<" ";
        else
            cout<<" +"<<m[i].g_coef()<<"*X^"<<m[i].g_grad()<<" ";
    }

}

Polinom::~Polinom()
{
    delete m;
}

int coprime(Monom *m,int nr)
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
        int  auy = abs( int(m[i+1].g_coef()) );

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

int Polinom::criteriu()
{
    int temp = 0;
    int mxm = get_max(m);

    if(nr_monoame == 1)
    {
        cout<<"Polinom ireductibil, nu poate fi scris ca produs de polinaome neconstante\n";
        return -1;
    }

    for(int i=0; i<nr_monoame; i++)
    {
        try
        {
            if(m[i].g_coef() != int(m[i].g_coef()))
            {
                throw m[i].g_coef();
            }
        }
        catch (float e)
        {
            cout<<"Coeficienti care nu sunt intregi! ";
            return 0;
        }
    }

    if(coprime(m,nr_monoame) != 1)
        {
            //cout<<"Nu sunt prime intre ele, nu se poate aplica criteriul in continuare\n\n";
                return -1;
        }


    if(m[nr_monoame - 1].g_grad() != 0)
    {
        cout<<"\nPolinomul nu poate fi scris ca produs de polinoame neconstante\n";
        return 1;
    }

    vector<int> prime;
    prime.push_back(2);

    for(int i=3; i < mxm; i++)
    {
        bool ok=true;
        for(int j=0; j<prime.size() && prime[j]*prime[j] <= i; j++)
        {
            if(i % prime[j] == 0)
            {
                ok=false;
                break;
            }
        }
        if(ok)
        {
            prime.push_back(i);
        }
    }

    vector<int>::iterator i = prime.begin();

    for(i = prime.begin(); i != prime.end(); i++)
    {
        for(int j =0; j<nr_monoame; j++)
        {
            if( (int(m[j].g_coef()) % (*i)) == 0  )
            {
                if(int(m[0].g_coef()) % (*i) != 0 )
                {
                   if( (int(m[nr_monoame - 1].g_coef()) % ((*i) *(*i))) != 0)
                    {
                        temp  = 1;
                    }
                }
            }

        }
    }

    if(temp == 1)
    {
       // cout<<"Polinomul este ireductibil!" ;
          return 1;
    }
    else
        {
           // cout<<"Polinom reductibil";
            return 0;
        }

}



