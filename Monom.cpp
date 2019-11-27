#include "Monom.h"

//Constructori
Monom::Monom()
{
    grad=coef=0;
}

Monom::Monom(const Monom &x)
{
grad = x.grad;
coef = x.coef;
}


Monom::Monom(int gr,float cf)
{
    grad=gr;
    coef=cf;
}
//destructor
Monom::~Monom()
{
}

//supraincarcarea operatorilor <<, >>,  =
ostream& operator<<(ostream& out,Monom& m)
{
    out<<m.coef<<"*X^"<<m.grad<<" ";

    return out;
}

istream& operator>>(istream&in, Monom& m)
{
    cout<<"\nCititi monomul: \n";
    cout<<"Coeficientul = ";
    cin>>m.coef;
    cout<<"Gradul = ";
    cin>>m.grad;

    return in;
}

void Monom::operator=(const Monom &m)
{
    grad=m.grad;
    coef=m.coef;
}

//Get-ere
int Monom::g_grad()
{
    return grad;
}

float Monom::g_coef()
{
    return coef;
}
