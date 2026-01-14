#include <iostream>
#include <cstring>

using namespace std;


class Ekipa {
protected:
    char ime[15];
    int brPorazi;
    int brPobedi;
public:
    // Konstruktori
    Ekipa() {};
    Ekipa (char *ime, int pob, int por) {
        strcpy(this->ime, ime);
        this->brPobedi = pob;
        this->brPorazi = por;

    };
    ~Ekipa() {};

    // metodi
    void pecati() {
        cout << "Ime: " << ime << " Pobedi: " << brPobedi << " Porazi: " << brPorazi << endl;
    };
};

class FudbalskaEkipa : public Ekipa {
    protected: 
    int crveniKartoni;
    int zholtiKartoni;
    int neresheni;
    
    public:
    // konstruktori
     FudbalskaEkipa (char *ime, int pob, int por, int cK, int zhK, int ner) :  Ekipa (ime, pob, por)
     {
         this->crveniKartoni = cK;
         this->zholtiKartoni = zhK;
         this->neresheni = ner;
     }
    ~FudbalskaEkipa(){};
    
    void pecati()
    {
    int poeni = 0;
        poeni += ((brPobedi*3)+neresheni);
        cout << "Ime: " << ime << " Pobedi: " << brPobedi << " Porazi: " << brPorazi << " Nereseni: " << neresheni << " Poeni: " << poeni << endl; 
    }
    

};



int main() {
    char ime[15];
    int pob,por,ck,zk,ner;
    cin>>ime>>pob>>por>>ck>>zk>>ner;
    FudbalskaEkipa f1(ime,pob,por,ck,zk,ner);
    f1.pecati();
    return 0;
}