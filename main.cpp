#include <iostream>
#include "Monom.h"
#include "Polinom.h"
#include "Polinom_reductibil.h"
#include "Polinom_ireductibil.h"
using namespace std;

Monom* Citire(int nr_monoame)
{
    Monom *m;
    m = new Monom[nr_monoame];

    cin>>m[0];
    for(int i=1;i<nr_monoame; i++)
    {
        cin>>m[i];
        while(m[i-1].g_grad() <= m[i].g_grad())
        {
            cout<<"\nForma nepermisa, cititi din nou monomul: ";
            cin>>m[i];
        }
    }
    return m;
}

int main()
{
    int nr_m;
    cout<<"Cititi nr monoame: ";
    cin>>nr_m;
    Monom *m;
    m=Citire(nr_m);
    //Polinom *poli(nr_m,m);

    //Polinom_reductibil p(nr_m,m);
    //p.criteriu();
   // p.Verificare_criteriu();

   // p.afis();
   Polinom *p;
   Polinom_ireductibil pi(nr_m,m);
   Polinom_reductibil pr(nr_m,m);
   p = &pr;
   p->Verificare_criteriu();
   p->afis();
    return 0;
}
