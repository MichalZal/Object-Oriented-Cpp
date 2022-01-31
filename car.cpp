#include<iostream>
#include<windows.h>
using namespace std;

class Samochod
{
    public:
    string marka;
    string model;
    int rocznik;
    float przebieg;

    void wczytaj()
    {
        cout << "podaj marke samochodu: ";
        cin >> marka;
        Sleep(500);
        cout << endl;

        cout << "podaj marke model: ";
        cin >> model;
        Sleep(500);
        cout << endl;

        cout << "podaj marke rocznik: ";
        cin >> rocznik;
        Sleep(500);
        cout << endl;

        cout << "podaj marke przebieg: ";
        cin >> przebieg;
        Sleep(500);
        cout << endl;
        cout << endl;

    }

    void wypisz()
    {
        system("CLS");
        cout << "PARAMETRY SAMOCHODU:" << endl;
        cout << "Marka Samochodu: " << marka << endl;
        cout << "Model Samochodu: " << model << endl;
        cout << "Rocznik Samochodu: " << rocznik << endl;
        cout << "Przebieg Samochodu: " << przebieg << endl;
        cout << endl;
    }   

    void ryk()
    {
        if(marka=="mercedes" || marka=="bmw" || marka=="audi" || marka=="bugatti")
        {
            cout << endl << marka << " " << model << " jest potezny";
        }
        else 
        {
            cout << endl <<"gdzie ty takim gruzem chcesz cos zrobic??";
        }
        cout << endl;
    }


};




int main(void)
{
    Samochod amg;

    amg.wczytaj();
    Sleep(2000);

    amg.wypisz();
    Sleep(2000);

    amg.ryk();
    Sleep(2000);

    Samochod polonez;
    polonez.wczytaj();
    Sleep(2000);

    polonez.wypisz();
    Sleep(2000);

    polonez.ryk();
    Sleep(2000);
}
