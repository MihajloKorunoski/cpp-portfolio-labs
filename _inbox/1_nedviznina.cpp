#include <iostream>
#include <cstring>

using namespace std;

class Nedviznina
{
  protected: 
    char *adresa;
    int kvadratura;
    int cenaNaKv;
  public:
    Nedviznina()
    {
    adresa = new char[0];
    }
    
    int cena()
    {
    return kvadratura*cenaNaKv;
    }
    
    void pecati()
    {
    cout << adresa << ", Kvadratura: " << kvadratura << ", Cena po Kvadrat: " << cenaNaKv << endl;
    }
    
    float danokNaImot()
    {
    return (float) (kvadratura*cenaNaKv*5) / 100;
    }
    
     friend istream &operator>>(istream &in, Nedviznina &c)
    {
        return in>>c.adresa>>c.kvadratura>>c.cenaNaKv;
    }
    
    char *getAdresa()
    {
    return adresa;
    }
};

class Vila: public Nedviznina {
    private:
    int danokL;
    public:
    Vila(){} 
    void pecati()
    {
        cout<<adresa<<", Kvadratura: "<<kvadratura<<", Cena po Kvadrat: "<<cenaNaKv<<", Danok na luksuz: "<<danokL<<endl;
    }
    float danokNaImot()
    {
        return Nedviznina::cena()*(5+danokL)/100;
    }
    friend istream &operator>>(istream &in, Vila &c)
    {
        return in>>c.adresa>>c.kvadratura>>c.cenaNaKv>>c.danokL;
    }
    char *getAdresa()
    {
        return adresa;
    }
};


int main(){
    Nedviznina n;
    Vila v;
    cin>>n;
    cin>>v;
    n.pecati();
    cout<<"Danok za: "<<n.getAdresa()<<", e: "<<n.danokNaImot()<<endl;
    v.pecati();
    cout<<"Danok za: "<<v.getAdresa()<<", e: "<<v.danokNaImot()<<endl;
    return 0;
}