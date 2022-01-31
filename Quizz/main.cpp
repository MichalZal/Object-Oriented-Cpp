#include<iostream>
#include<Windows.h>
#include<fstream>
#include<cstdlib>
#include<string>

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
                for (int i = 3; i < 0; i--) 
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
            if(odpowiedz==poprawna)
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

    for (int i = 0; i < 4; i++)
    {
        quiz[i].nr_pytania = i+1;
        quiz[i].wczytaj();
        Sleep(2000);

        quiz[i].zadaj();
        Sleep(2000);

        quiz[i].sprawdz();
        Sleep(2000);
    }


    return 0;
}