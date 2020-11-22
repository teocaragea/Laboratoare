#include <iostream>

using namespace std;

class Produs{
protected:
 string nume;
 float pretBrut;
 public:
     void afisareBrand(){

     cout<<"Acest produs apartine EDI>.RL";

     }
   virtual float calculeazaPret()=0;
       friend ostream& operator<<(ostream& out,const Produs& p){

    out<<p.nume;
    return out;


   }
    friend istream& operator >>(istream& in, Produs&p){

        cout<<"Numele este: ";
        in>>p.nume;
        cout<<"Pretul brut este: ";
        in>>p.pretBrut;
        return in;

    }


};

class ProdusPersibail:public Produs{
    string dataExpirare;
public:

        float calculeazaPret(){

        return pretBrut+(40*pretBrut)/100;

    }

    friend ostream& operator<<(ostream& out,const ProdusPersibail& p)
    {
        out<<(Produs&)p;
        out<<" "<<p.dataExpirare;
      return out;

    }
    friend istream& operator >>(istream& in, ProdusPersibail&p){

    in>>(Produs&)p;
    cout<<"Dati data: ";
    in>>p.dataExpirare;
    return in;}


};

class ProdusNePerisbalil:public Produs{
    int garantie;
public:
    float calculeazaPret(){

        return pretBrut+(10*pretBrut)/100;

    }


    friend ostream& operator<<(ostream& out,const ProdusNePerisbalil& p)
    {
        out<<(Produs&)p;
        out<<" "<<p.garantie;
      return out;

    }
    friend istream& operator >>(istream& in, ProdusNePerisbalil&p){

    in>>(Produs&)p;
    cout<<"ani garantie: ";
    in>>p.garantie;
    return in;}






};

class ListaProduse
{
    Produs* p[100];
    int n;
public:
    ListaProduse()
    {
        p[0]=NULL;
        n=0;
    }
    void add(ProdusPersibail& produs)
    {   n++;
        p[n]=new ProdusPersibail();
        p[n]=&produs;

    }
    void add(ProdusNePerisbalil& produs)
    {   n++;
        p[n]=new ProdusNePerisbalil();
         p[n]=&produs;

    }
    void rmv()
    {
        p[n]=NULL;
        n--;
    }

    void rmv(int poz)
    {
        for(int i=poz;i<=n;i++)
            p[i]=p[i+1];
        p[n]=NULL;
        n--;
    }
    void afisare()
    {
        for(int i=1;i<=n;i++)
            cout<<*p[i]<<" ";
    }

};

int main()
{
    ListaProduse p;
    ProdusNePerisbalil pn;
    ProdusPersibail pp;
    cin>>pn>>pp;
    p.add(pn);
    p.add(pp);
    p.afisare();
    p.rmv(0);
    cout<<endl;
    p.afisare();



    return 0;
}


