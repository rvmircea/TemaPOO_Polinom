#ifndef MONOM_H
#define MONOM_H
#include <iostream>


using namespace std;

class Monom{
protected:
    int grad;
    float coef;
public:
    Monom();
    Monom(int,float);
    Monom(const Monom&);
    ~Monom();

    //virtual void afisare() = 0;
    void operator =(const Monom&);

    int g_grad();
    float g_coef();
    friend ostream& operator<<(ostream&,Monom&);
    friend istream& operator>>(istream&,Monom&);

};



#endif // MONOM_H


