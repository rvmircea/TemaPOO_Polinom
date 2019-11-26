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
    m=p.m;
}

Polinom::Polinom(int nr,Monom* mn)
{
    nr_monoame = nr;

    m=mn;
    for(int i=0; i<nr; i++)
    {
        cout<<m[i];
        cout<<endl;
    }
}

void Polinom::afis()
{
    cout<<nr_monoame<<endl;
    for(int i=0; i<nr_monoame; i++)
    {
        cout<<m[i].g_coef()<<"*X^"<<m[i].g_grad()<<endl;
    }

}

Polinom::~Polinom()
{
    delete m;
}

int cmmdc(Monom *m,int nr)
{
    int temp;
    int ok = 1;
    if(nr == 1)
    {
        cout<<"Nu se poate aplica cmmdc pe un singur coeficient! ";
        return 0;
    }

    for(int i=0; i<nr-1; i++)
    {

        int aux = abs(m[i].g_coef());
        int  auy = abs(m[i+1].g_coef());
        while(aux != auy)
        {
            if(aux > auy)
                aux = aux - auy;
            if(auy > aux)
                auy= auy- aux;
        }
        if(aux == 1)
        {
            ok = 0;
        }
    }

    if(ok == 0)
    {
        cout<<"Numere prime intre ele ";
        return 1;
    }

}

/*int prim(int x)
{
    if(x < 2)
    {
        cout<<"Numarul nu este prim: "<<x<<endl;
        return 0;
    }
    if(x == 2)
        return 1;
    for(int i =2; i<= x/2 ;i++)
       {
           if(x % i == 0)
            return 0;
       }

    return 1;

}
*/
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
        cout<<"Polinom ireductibil";
        return 0;
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
            //cout<<endl<<m[j].g_coef()<<" "<<*i<<endl;
            if( (int(m[j].g_coef()) % (*i)) == 0  )
            {
                //cout<<"Aici 1 ";
                //cout<<"Mxm: "<<m[0].g_coef()<<" "<<*i<<endl;
                if(int(m[0].g_coef()) % (*i) != 0 )
                {

                   // cout<<"Aici 2 ";
                   // cout<<"Coeficientul cel mai mic: "<<int(m[nr_monoame - 1].g_coef())<<" i patrat: "<<(*i)  *  (*i)<<endl;
                    if( (int(m[nr_monoame - 1].g_coef()) % ((*i) *(*i))) != 0)
                    {
                        //cout<<"Aici 3 ";
                        temp  = 1;
                    }
                }
            }

        }
    }

    if(temp == 1)
    {
        cout<<"Polinomul este ireductibil!" ;
          return 1;
    }
    else
        {
            cout<<"Polinomul este reductibil";
            return 0;
        }

    /* if(ok == 1)
         cout<<"Exista numere prime "<<endl;
      if( cmmdc(m,nr_monoame) == 0)
         {
             cout<<"Criteriul nu poate fi aplicat ";
                 return 0;
         }
    */

}


/*int prim(Monom *m, int mxm)
{

     for(int i = 2; i<mxm ; i++ )
        for(int j = 2; j*j <= i;j++)
    {
        if(i % j ==0)
            return 0;
        else if (j+1 > sqrt(i))
        {

        }
    }

}
*/
