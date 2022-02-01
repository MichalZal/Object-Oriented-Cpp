#include<iostream>
#include<Windows.h>
#include<fstream>
#include<cstdlib>
#include<string>
#include<algorithm>

using namespace std;

class Pytanie
{
    public:
    string tresc;
    string a,b,c,d;
    int nr_pytania;
    string poprawna;
    string odpowiedz;
    int punkt;

    void wczytaj()
    {
        fstream plik;
        plik.open("quiz.txt", ios::in);

        if (plik.good()==false)
        {
            cout << "Nie udalo sie otworzyc pliku ;(" << endl;
            for (int i = 3; i > 0; i--) 
            {
                cout << "Program wylaczy sie za " << i << " sekund" << endl;
                
            }
            exit(0);


        }
        
        int nr_linii=(nr_pytania - 1)*6+1;
        int aktualny_nr = 1;
        string linia;
       

        while (getline(plik, linia))
        {
            if(aktualny_nr==nr_linii) tresc = linia;
            if(aktualny_nr==nr_linii+1) a = linia;
            if(aktualny_nr==nr_linii+2) b = linia;
            if(aktualny_nr==nr_linii+3) c = linia;
            if(aktualny_nr==nr_linii+4) d = linia;
            if(aktualny_nr==nr_linii+5) poprawna = linia;
            aktualny_nr++;                      
        }
    
        plik.close();
    }


    void zadaj()
    {
        system("CLS");
        cout << endl << tresc << endl;
        cout << a << endl;
        cout << b << endl;
        cout << c << endl;
        cout << d << endl;
        cout << "-------------" << endl;
        cout << "twoja odpowiedz: ";
        cin >> odpowiedz;
    }

    void sprawdz()     
    {

        string odp_z_duzej = odpowiedz;
        string odp_z_malej = odpowiedz;
        transform(odp_z_duzej.begin(), odp_z_duzej.end(), odp_z_duzej.begin(), ::toupper);
        transform(odp_z_malej.begin(), odp_z_malej.end(), odp_z_malej.begin(), ::tolower);
        if(odp_z_malej==poprawna || odp_z_duzej==poprawna || odpowiedz==poprawna) 
        {
            cout << "Gratulacje zdobywasz punkt!" << endl;
            punkt = 1;
        }
        else if (odpowiedz!= poprawna)
        {
            punkt = 0;
            cout << "niestety nie zdobywasz punktu :(" << endl;
        }
    }            
};



int main(void)
{
    Pytanie quiz[5];
    
    int suma;
    
    while(true)
    {
        for (int i = 0; i < 4; i++)
        {
            quiz[i].nr_pytania = i+1;
            quiz[i].wczytaj();
            Sleep(500);

            quiz[i].zadaj();
            Sleep(500);

            quiz[i].sprawdz();
            Sleep(500);

            suma+= quiz[i].punkt;
        }   
        cout << endl << endl;
        cout << "Zdobyles " << suma << " punktow" << endl;
        cout << "KONIEC!";

        char wyb;
        cout << endl << "Again? (y/n)";
        cin >> wyb;
        suma = 0;

        if(wyb=='n' || wyb=='N')
        {
            cout << endl;
            for (int i = 3; i > 0; i--) 
            {
                cout << "Program wylaczy sie za " << i << " sekund" << endl;
                Sleep(1000);                           
            }
            exit(0);
        }
        else
        {
            cout << "XD";
        }
    } 

    return 0;
}
