#ifndef MONOM_H
#define MONOM_H
#include <iostream>


using namespace std;

class Monom{
private:
    int grad;
    float coef;
public:
    Monom();
    Monom(int,float);
    Monom(const Monom&);
    ~Monom();

    //virtual void afisare() = 0;
    void operator =(const Monom&);

    void afis();
    friend ostream& operator<<(ostream&,Monom&);
    friend istream& operator>>(istream&,Monom&);

};



#endif // MONOM_H


