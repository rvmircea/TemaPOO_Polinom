#include "Polinom_ireductibil.h"
#include <vector>


Polinom_ireductibil::Polinom_ireductibil()
{
    nr_monoame = 1;
    m=new Monom;
}

void Polinom_ireductibil::afis()
{
    cout<<endl;
    cout<<m[0];

    for(int i=1; i<nr_monoame; i++)
    {
        if(m[i].g_coef() < 0)
            cout<<" - "<<m[i];
        else
            cout<<" + "<<m[i];
    }
    cout<<endl;
}
Polinom_ireductibil::~Polinom_ireductibil()
{
    delete m;
}

int  Polinom_ireductibil::Verificare_criteriu()
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
        cout<<"Nu sunt prime intre ele, nu se poate aplica criteriul in continuare\n\n";
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
        if(int(m[0].g_coef()) % (*i) != 0 )
            for(int j =0; j<nr_monoame; j++)
            {
                if( (int(m[j].g_coef()) % (*i)) == 0  && (int(m[nr_monoame - 1].g_coef()) % ((*i) *(*i))) != 0)

                    temp  = 1;

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

void Polinom_ireductibil::Tip_clasa()
{
    cout<<"\nClasa Polinom Ireductibil\n";
}
