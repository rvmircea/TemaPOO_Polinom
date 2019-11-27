#include <iostream>
#include "Monom.h"
#include "Polinom.h"
#include "Polinom_reductibil.h"
#include "Polinom_ireductibil.h"
using namespace std;

//Functie de citire monoame
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
    int result;
    int nr_m;
    cout<<"Cititi nr monoame: ";
    cin>>nr_m;
    Monom *m;
    m=Citire(nr_m);

   Polinom *p;
   Polinom_ireductibil pi(nr_m,m);
   Polinom_reductibil pr(nr_m,m);
   p = &pr;
  //result =  p->Verificare_criteriu();
  /*
  if(result == 1)
            cout<<endl<<"\nPolinom ireductibil";
        else if(result == 0)
            cout<<endl<<"\nPolinom reductibil";
        else
            cout<<"Criteriul nu poate fi aplicat";
*/

   p->Tip_clasa();
    return 0;
}
