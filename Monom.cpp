#include "Monom.h"

Monom::Monom()
{
    grad=coef=0;
}

Monom::Monom(const Monom &x)
{
grad = x.grad;
coef = x.coef;
cout<<"\nCopiere a fost facuta cu succes! ";
}


Monom::Monom(int gr,float cf)
{
    grad=gr;
    coef=cf;
}

Monom::~Monom()
{
}

ostream& operator<<(ostream& out,Monom& m)
{
    out<<m.coef<<"*X^"<<m.grad<<" ";

    return out;
}

istream& operator>>(istream&in, Monom& m)
{
    cout<<"Cititi monomul: \n";
    cout<<"Coeficientul = ";
    cin>>m.coef;
    cout<<"Gradul = ";
    cin>>m.grad;

    return in;
}

/*
void Monom::afisare()
 {
     cout<<"Monom";
 }
*/

void Monom::operator=(const Monom &m)
{
    grad=m.grad;
    coef=m.coef;
}

int Monom::g_grad()
{
    return grad;
}

float Monom::g_coef()
{
    return coef;
}
