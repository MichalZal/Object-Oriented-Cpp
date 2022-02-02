#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
using namespace std;

class Punkt
{
    float x,y;
    string nazwa;

public:
    void wyswietl() 
    {
        cout << "Punkt: " << nazwa << "(" << x << "," << y << ")" << endl;

    }
    Punkt(string n="S", float a=0, float b=0)
    {
        nazwa = n;
        x = a;
        y = b;
    }
};

class Kolo :public Punkt
{   
protected:
    float r;
    string nazwa;

    public:
    void wyswietl() 
    {
        cout <<"Kolo o nazwie: " << nazwa << endl;
        cout << "Srodek kola: " << endl;
        Punkt::wyswietl();
        cout << "Promien: " << r << endl;
        cout << "Pole kola: " <<  M_PI *r*r<< endl; 

    }

    Kolo(string nk="Kolko", string np="S", float a=0, float b=0, float pr=1)
    :Punkt(np,a,b)
    {
        nazwa = nk;
        r = pr;
    }

};

class Kula:public Kolo
{
    string nazwa;
    float objetosc;
public:
    void wyswietl() 
    {
        cout << "KULA" << endl;
        cout << "Nazwa kuli: " << nazwa << endl;
        Punkt::wyswietl();
        objetosc = (4*M_PI *r*r*r)/3;
        cout << "Objetosc: " << objetosc << endl;
    }

    Kula(string nq="KULA", string np="S", float a=0, float b=0, float pr=1, float obj=1)
    :Kolo(nq, np, a, b, pr)
    {
        nazwa = nq;
        objetosc = obj;
    }



};

int main(void)
{    
    Kolo k1;
    k1.wyswietl();

    Kula q1("KULadajefula", "A", 1, 1, 2, 2);
    q1.wyswietl();


}
