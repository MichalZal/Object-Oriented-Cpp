#define _USE_MATH_DEFINES 
#include <iostream>
#include <cmath>
using namespace std;

class Ksztalt
{
public:

    virtual void oblicz_pole() = 0;
    // Czysta funkacja wirtualna
};

class Kolo:public Ksztalt
{
    float r;
    
public:
    Kolo(float x=1)
    {
        r = x;
    }

    virtual void oblicz_pole()
    {
        cout << "Pole kola:" << M_PI*r*r << endl;
    }
};

class Kwadrat:public Ksztalt
{
    float a;
public:
    Kwadrat(float x=1)
    {
        a = x;
        
    }

    virtual void oblicz_pole()
    {
        cout << "Pole kwadratu: " << a * a << endl;
    }
};

void endl()
{
    cout << endl;
}

void obliczenia(Ksztalt *x)
{
    x -> oblicz_pole();
}

int main(void)
{
    endl();
    Kolo k(1);

    Kwadrat kw(4);

    Ksztalt * wskaznik;

    wskaznik = &k;
    wskaznik -> oblicz_pole();
    
    wskaznik = &kw;
    wskaznik -> oblicz_pole();

    obliczenia(wskaznik);
    
    return 0;
}
