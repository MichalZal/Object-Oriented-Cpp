#include <iostream>
using namespace std;

class Prostokat;
class Punkt
{
   string nazwa;
   float x,y;
 
public:
    Punkt(string n, float xx, float yy)
    {
        nazwa=n;
        x=xx;
        y=yy;
    }      
   
   void wczytaj()
   {
    cout<<"Podaj x: "; cin>>x;
    cout<<"Podaj y: "; cin>>y;
    cout<<"Nazwa punktu: "; cin>>nazwa;       
   }
 
   friend void sedzia (Punkt &pkt, Prostokat &p);
 
};
 
class Prostokat
{
   string nazwa;
   float x,y,szerokosc,wysokosc;
 
public:
    Prostokat::Prostokat(string n,float xx,float yy,float s ,float w)
    {
        nazwa = n;
        x=xx;
        y=yy;
        szerokosc=s;
        wysokosc=w;
    }
   void wczytaj()
   {
    cout<<"Podaj x lewego dolnego naroznika: "; cin>>x;
    cout<<"Podaj y lewego dolnego naroznika: "; cin>>y;
    cout<<"Podaj szerokosc: "; cin>>szerokosc;
    cout<<"Podaj wysokosc: "; cin>>wysokosc;
    cout<<"Podaj nazwe prostokata: "; cin>>nazwa;
    cout<<endl<<"Nazwa obiektu: "<<nazwa;      
   }
 
   friend void sedzia (Punkt &pkt, Prostokat &p);
};


void sedzia(Punkt &pkt,Prostokat &p)
{
   p.nazwa="PODMIANA";
 
 if((pkt.x>=p.x)&&(pkt.x<=p.x+p.szerokosc)&&(pkt.y>=p.y)&&(pkt.y<=p.y+p.wysokosc))
 
    cout<<endl<<"Punkt "<<pkt.nazwa<<" nalezy do prostokata: "<<p.nazwa;
 
 else
 
    cout<<endl<<"Punkt "<<pkt.nazwa<<" lezy POZA prostokatem: "<<p.nazwa;
}
 


int main()
{
    Punkt pkt1("A",3,17);
    //pkt1.wczytaj();
 
    Prostokat p1("Prostokat",0,0,6,4);
    //p1.wczytaj();
 
    sedzia(pkt1,p1);
 
    p1.wczytaj();
 
    return 0;
}
