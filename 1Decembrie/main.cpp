#include <iostream>
#include<list>
#include<iterator>

using namespace std;


class Automobil
{
    string marca;
    string model;
    string utilizare;
    string detalii;
public:
    Automobil()
    {
        this->marca="Anonim";
        this->model="modelS";
        this->utilizare="La nimic";
        this->detalii="Stoc";
    }
    Automobil(string marca,string model,string utilizare,string detalii)
    {
        this->marca=marca;
        this->model=model;
        this->utilizare=utilizare;
        this->detalii=detalii;
    }
    string getModel()
    {
        return this->model;
    }
    Automobil& operator=(const Automobil& automobil)
    {
        if(this!=&automobil)
        {
            this->marca=automobil.marca;
            this->model=automobil.model;
            this->utilizare=automobil.utilizare;
            this->detalii=automobil.detalii;
        }
        return *this;
    }
    virtual void afisare()
    {

    }



};
class Undercover:public Automobil
{
    string modificari;
    string armura;
    int indice;
public:
    Undercover():Automobil()
    {
        this->modificari="Nimic";
        this->armura="Tunica de 2 tone";
        this->indice=2;
    }
    Undercover(string marca,string model,string utilizare,string detalii,string modificari,string armura,int indice):Automobil(marca,model,utilizare,detalii)
    {
        this->modificari=modificari;
        this->armura=armura;
        this->indice=indice;
    }
    void afisare()
    {

        cout<<"Model:"<<this->getModel()<<" Modificari:"<<this->modificari<<" Armura"<<this->armura<<" Indice:"<<this->indice<<endl;
    }

};

class Interventie:public Automobil
{
    int nrPersoane;
    string arma;
public:
    Interventie():Automobil()
    {
        this->nrPersoane=0;
        arma="fara";
    }
    Interventie(int nrPersoane, string arma,string marca,string model,string utilizare,string detalii):Automobil(marca,model,utilizare,detalii)
    {
        this->nrPersoane=nrPersoane;
        this->arma=arma;
    }
    void afisare()
    {

        cout<<"Model:"<<this->getModel()<<"Numar de persoane:"<<this->nrPersoane<<" Arma:"<<this->arma<<endl;
    }

};

class EmisieReceptie:public Automobil
{
    int d1;
    int d2;
public:
    EmisieReceptie():Automobil()
    {
        d1=0;
        d2=0;
    }
    EmisieReceptie(int d1,int d2,string marca,string model,string utilizare,string detalii):Automobil(marca,model,utilizare,detalii)
    {
        this->d1=d1;
        this->d2=d2;
    }
    void afisare()
    {
        cout<<"Model:"<<this->getModel()<<" Distana de interceptie semnal acustic:"<<this->d1<<" Distanta de interceptie semnal video"<<this->d2<<endl;
    }

};

class ListaAutomobile
{
    list<Automobil*>v;
    int n;
public:
    ListaAutomobile()
    {
        n=0;
    }
    ListaAutomobile(list<Automobil*>v,int n)
    {
        this->n=n;
       this->v=v;
    }
    ListaAutomobile& operator+( Automobil& automobil)
    {
        v.push_back(&automobil);
        n++;
        return *this;
    }
    ListaAutomobile operator+(Undercover& automobil)
    {
        v.push_back(&automobil);
        n++;
        return *this;
    }
    ListaAutomobile operator+(EmisieReceptie& automobil)
    {

        v.push_back(&automobil);
        n++;
        return *this;
    }
    ListaAutomobile operator+(Interventie& automobil)
    {
       v.push_back(&automobil);
         n++;
        return *this;
    }
    void afisare()
    {
        v.back()->afisare();
        v.pop_back();
    }

};

int main()
{
    Interventie a2;
    EmisieReceptie a3;
    Undercover a4;
    ListaAutomobile p;
    p=p+a2;
    p=p+a3;
    p=p+a4;
    for(int i=0;i<3;i++)
        p.afisare();


    return 0;
}
