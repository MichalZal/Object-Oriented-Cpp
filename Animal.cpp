#include<iostream>
#include<windows.h>
using namespace std;

class Zwierze
{  
    public:
    string gatunek;
    string imie;
    int wiek;

    void dodaj_zwierze()
    {
        cout << "DODAWANIE NOWEGO ZWIERECIA DO BAZY: " << endl;
        cout << "Podaj gatunek: ";
        cin >> gatunek;
        cout << endl;

        cout << "Podaj imie: ";
        cin >> imie;
        cout << endl;

        cout << "Podaj wiek: ";
        cin >> wiek;
        cout << endl;
    }

    void daj_glos()
    {
        cout << endl;
        if (gatunek =="kot") cout << imie << " powiedzial: Miau";
        else if (gatunek =="krowa") cout << imie << " powiedzial: Muuu";
        else if (gatunek =="swinia") cout << imie << " powiedzial: Chrum";
        else cout << "Nieznany gatunek";
    }


    void pokaz_dane()
    {
        cout << "Gatunek: " << gatunek << endl;
        cout << "imie: " << imie << endl;
        cout << "wiek: " << wiek << endl;
    }
 
};


int main(void)
{
    Zwierze krowa;
    krowa.dodaj_zwierze();
    Sleep(2000);
    
    krowa.pokaz_dane();
    Sleep(2000);
    
    krowa.daj_glos();
    Sleep(2000);
}
