#include <iostream>
#include <cstring>

using namespace std;


class Decoratiune
{
    char *nume;
    char* culoare;
    bool reciclabila;
    float pret;
public:
    Decoratiune()
    {
        nume=NULL;
        culoare=NULL;
        reciclabila=false;
    }
    void setNume(char* nume)
    {
        if(this->nume!=NULL)
            delete[] this->nume;
        this->nume=new char[strlen(nume)+1];
        strcpy(this->nume,nume);
    }
    void setCuloare(char* culoare)
    {
        if(this->culoare!=NULL)
            delete[] this->culoare;
        this->culoare=new char[strlen(culoare)+1];
    }
    char* getNume()
    {
        return this->nume;
    }
    char* getculoare()
    {
        return this->culoare;
    }
    void setReciclabila(bool reciclabila)
    {
        this->reciclabila=reciclabila;
    }
    bool getReciclabila()
    {
        return this->reciclabila;
    }
    float Pret()
    {
        return this->pret;
    }
    void setPret(float pret)
    {
        this->pret=pret;
    }

    //friend ostream& operator<<(ostream& os,const Decoratiune& dec);
    friend ostream& operator<<(ostream& os,const Decoratiune& dec)
    {
        os<<dec.nume<<'\n';
        return os;
    }/*
    Decoratiune& operator=(const Decoratiune& dec)
    {
        if(this->nume!=NULL)
            delete[] this->nume;
        if(this->culoare!=NULL)
            delete[] this->culoare;
        this->nume=new char[strlen(dec.nume)+1];
        this->culoare=new char[strlen(dec.culoare)+1];
        strcpy(this->nume,dec.nume);
        strcpy(this->culoare,dec.culoare);
        this->reciclabila=dec.reciclabila;
        return *this;

    }*/

    ~Decoratiune()
    {
        if(this->culoare!=NULL)
            delete[] this->culoare;
        if(this->nume!=NULL)
            delete[] this->nume;
    }


};

class ListaProdue
{
    int nrDecoratiuni;
    Decoratiune decoratiuni[100];
public:
    ListaProdue()
    {
   nrDecoratiuni=0;
    }
    void setDecoratiune(int nrDecoratiuni,Decoratiune decoratiuni[100])
    {
        this->nrDecoratiuni=nrDecoratiuni;
        for(int i=1; i<=nrDecoratiuni; i++)
        {
            this->decoratiuni[i]=decoratiuni[i];
        }

    }
    Decoratiune getDecoratiune(int index)
    {
        return this->decoratiuni[index];
    }
    Decoratiune operator[](int i)
    {
        if(i>0 && i<=nrDecoratiuni)
            return this->decoratiuni[i];

    }
    ListaProdue& operator+(const Decoratiune& decoratiune)
    {
        this->nrDecoratiuni+=1;
        this->decoratiuni[nrDecoratiuni]=decoratiune;
        return *this;
    }
    ListaProdue& operator=(const ListaProdue& lp)
    {
        this->nrDecoratiuni=lp.nrDecoratiuni;
        for(int i=1;i<=nrDecoratiuni;i++)
            this->decoratiuni[i]=lp.decoratiuni[i];
        return *this;

    }
    ListaProdue remove(int index)
    {
        for(int i=1; i<nrDecoratiuni; i++)
            this->decoratiuni[i]=this->decoratiuni[i+1];
        nrDecoratiuni--;
        return *this;
    }
    int getNrDec()
    {
        return this->nrDecoratiuni;
    }
    float Pret()
    {
        if(nrDecoratiuni==1)
            return this->decoratiuni[1].Pret();
        else
        {
        float x=0;
        for(int i=1; i<=nrDecoratiuni; i++)
            x+=this->decoratiuni[i].Pret();
        return x;
        }
    }
    ~ListaProdue()
    {

    }
};

int main()
{
    Decoratiune a,a1;
    a.setNume("Dovleci");
    a.setCuloare("Portocaliu");
    a.setPret(22.02);
    a1.setNume("Lumanari");
    a1.setCuloare("Galben");
    a1.setPret(12.06);
    cout<<a;
    ListaProdue b;
    b=b+a;
    b=b+a1;
    cout<<b[1];
    cout<<b[1].Pret()<<endl;
    cout<<b.Pret()<<endl;
    b.remove(1);
    cout<<b.Pret();
    return 0;
}
