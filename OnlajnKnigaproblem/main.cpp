#include <iostream>
#include <cstring>

using namespace std;
class NoGradeException {
private:
    char imenakniga[30];
public:
    NoGradeException(char *imenakniga) {
        strcpy(this->imenakniga,imenakniga);
    }
    void pechati() {
        cout<<"Knigata "<<imenakniga<<" nema ocenki od chitatelite";
    }
};
class Lice {
private:
    char ime[20];
    char drzava[20];
public:
    Lice(char *ime, char* drzava) {
        strcpy(this->ime, ime);
        strcpy(this->drzava, drzava);
    }
    Lice() {
        strcpy(this->ime, "");
        strcpy(this->drzava, "");
    }
    const char *getIme() const {
        return ime;
    }
    const char *getDrzhava() const {
        return drzava;
    }
};
class Kniga {
protected:
    Lice avtori[10];
    int brojAvtori;
    int *ocenki;
    int brojOcenki;
    char naziv[30];

public:
    Kniga(char *naziv, Lice *avtori, int brojAvtori, int *ocenki, int brojOcenki) {
        strcpy(this->naziv, naziv);
        this->brojAvtori = brojAvtori;
        for (int i = 0; i<brojAvtori; i++) this->avtori[i] = avtori[i];
        this->brojOcenki = brojOcenki;
        this->ocenki = new int[brojOcenki];
        for (int i = 0; i<brojOcenki; i++) this->ocenki[i] = ocenki[i];
    }

    Kniga(const Kniga &k) {
        strcpy(this->naziv, k.naziv);
        this->brojAvtori = k.brojAvtori;
        for (int i = 0; i<k.brojAvtori; i++) this->avtori[i] = k.avtori[i];
        this->brojOcenki = k.brojOcenki;
        this->ocenki = new int[k.brojOcenki];
        for (int i = 0; i<k.brojOcenki; i++) this->ocenki[i] = k.ocenki[i];
    }
    Kniga operator=(const Kniga &k) {
        if (&k == this) return *this;
        strcpy(this->naziv, k.naziv);
        this->brojAvtori = k.brojAvtori;
        for (int i = 0; i<k.brojAvtori; i++) this->avtori[i] = k.avtori[i];
        this->brojOcenki = k.brojOcenki;
        delete[] ocenki;
        this->ocenki = new int[k.brojOcenki];
        for (int i = 0; i<k.brojOcenki; i++) this->ocenki[i] = k.ocenki[i];
        return *this;
    }
    virtual float getVkupnaOcenka() {
        try {
            if(brojOcenki==0)
                throw NoGradeException(naziv);
        } catch(NoGradeException &o) {
            o.pechati();
        }

        float vkupnaocenka;
        for(int i=0; i<brojOcenki; i++) {
            vkupnaocenka+=ocenki[i];
        }
        vkupnaocenka/=brojOcenki;
        return vkupnaocenka;
    }
    virtual void pecati() {
        cout<<naziv<<endl<<"Avtori:"<<endl;
        for(int i=0; i<brojAvtori-1; i++) {
            cout<<avtori[i].getIme()<<" "<<avtori[i].getDrzhava()<<endl;
        }
        cout<<avtori[brojAvtori-1].getIme()<<" "<<avtori[brojAvtori-1].getDrzhava();
    }
    Lice operator[](int i) const {
        if(i<brojAvtori&&i>=0) {
            return avtori[i];
        } else
            return Lice();
    }
    int getBrojAvtori() const {
        return brojAvtori;
    }
    Lice * getAvtori(){
        return avtori;
    }
};
class VebStranica {
protected:
    char *url;
    int brojPristapuvanja;

public:
    VebStranica(char *url, int brojPristapuvanja) {
        this->brojPristapuvanja = brojPristapuvanja;
        this->url = new char[strlen(url) + 1];
        strcpy(this->url, url);
    }

    VebStranica(const VebStranica &v) {
        this->brojPristapuvanja = v.brojPristapuvanja;
        this->url = new char[strlen(v.url) + 1];
        strcpy(this->url, v.url);
    }

    VebStranica operator=(const VebStranica &v) {
        if (this == &v) return *this;
        this->brojPristapuvanja = v.brojPristapuvanja;
        delete[] url;
        this->url = new char[strlen(v.url) + 1];
        strcpy(this->url, v.url);
        return *this;
    }

    ~VebStranica() {
        delete[] url;
    }
};
class OnlajnKniga: public Kniga, public VebStranica {
private:
    int brojsimnuvanja;
public:
    OnlajnKniga()=default;
    OnlajnKniga(char *naziv, Lice *avtori, int brojAvtori, int *ocenki, int brojOcenki,char *url, int brojPristapuvanja,int brojsimnuvanja) : Kniga(naziv,avtori,brojAvtori,ocenki,brojOcenki), VebStranica(url,brojPristapuvanja) {
        this->brojsimnuvanja=brojsimnuvanja;
    }
    OnlajnKniga(const OnlajnKniga &k) : Kniga(k), VebStranica(k) {
        this->brojsimnuvanja=k.brojsimnuvanja;
    }
    OnlajnKniga &operator =(const OnlajnKniga &k) {
        if (&k == this) return *this;
        strcpy(this->naziv, k.naziv);
        this->brojAvtori = k.brojAvtori;
        for (int i = 0; i<k.brojAvtori; i++) this->avtori[i] = k.avtori[i];
        this->brojOcenki = k.brojOcenki;
        delete[] ocenki;
        this->ocenki = new int[k.brojOcenki];
        for (int i = 0; i<k.brojOcenki; i++) this->ocenki[i] = k.ocenki[i];
        this->brojPristapuvanja = k.brojPristapuvanja;
        delete[] url;
        this->url = new char[strlen(k.url) + 1];
        strcpy(this->url, k.url);
        this->brojsimnuvanja=k.brojsimnuvanja;
        return *this;
    }
    float getVkupnaOcenka() {
        float vkupna=Kniga::getVkupnaOcenka();
        float pom=brojsimnuvanja/brojPristapuvanja;
        vkupna*=pom;
        return vkupna;
    }
    virtual void pecati() {
        Kniga::pecati();
        cout<<"url: "<<url<<endl;
    }
};
double prosechnaOcenka (char *avtor, Kniga** knigi, int n ) {
    float prosek=0;
    int br=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<knigi[i]->getBrojAvtori();j++){
            if(strcmp(avtor,knigi[i]->getAvtori()[j].getIme())==0)
            {
                prosek+=knigi[i]->getVkupnaOcenka();
                br++;
            }
        }
    }
    return prosek/br;
}
void pecatiOnlajnKnigi ( Kniga** knigi, int n) {
    for (int i=0; i<n; i++) {
        OnlajnKniga *a=dynamic_cast<OnlajnKniga*>(knigi[i]);
        if(a) {
            knigi[i]->pecati();
        }
    }
}
int main() {

    Lice avtori[10];
    int brojAvtori, ocenki[20], ocenka, brojOcenki, tip, brojPristapi, brojSimnuvanja;
    char naslov[20], ime[40], drzava[20], url[50];

    cin >> tip;

    if (tip == 1) { //test class OnlajnKniga
        cout << "-----TEST OnlajnKniga-----" << endl;
        cin >> naslov >> brojAvtori;
        for (int i = 0; i<brojAvtori; i++) {
            cin >> ime >> drzava;
            avtori[i] = Lice(ime, drzava);
        }
        cin >> brojOcenki;
        for (int i = 0; i<brojOcenki; i++) {
            cin >> ocenka;
            ocenki[i] = ocenka;
        }
        cin >> url >> brojPristapi >> brojSimnuvanja;


        OnlajnKniga ok(naslov, avtori, brojAvtori, ocenki, brojOcenki, url, brojPristapi, brojSimnuvanja);
        cout << "Objekt od klasata OnlajnKniga e kreiran";

    } else if (tip == 2) { //funkcija pecati vo kniga
        cout << "-----TEST pecati-----" << endl;
        cin >> naslov >> brojAvtori;
        for (int i = 0; i<brojAvtori; i++) {
            cin >> ime >> drzava;
            avtori[i] = Lice(ime, drzava);
        }
        cin >> brojOcenki;
        for (int i = 0; i<brojOcenki; i++) {
            cin >> ocenka;
            ocenki[i] = ocenka;
        }

        Kniga k(naslov, avtori, brojAvtori, ocenki, brojOcenki);
        k.pecati();

    } else if (tip == 3) { //funkcija getVkupnaOcenka vo kniga
        cout << "-----TEST getVkupnaOcenka-----" << endl;
        cin >> naslov >> brojAvtori;
        for (int i = 0; i<brojAvtori; i++) {
            cin >> ime >> drzava;
            avtori[i] = Lice(ime, drzava);
        }
        cin >> brojOcenki;
        for (int i = 0; i<brojOcenki; i++) {
            cin >> ocenka;
            ocenki[i] = ocenka;
        }

        Kniga k(naslov, avtori, brojAvtori, ocenki, brojOcenki);
        cout << "Vkupna ocenka: " << k.getVkupnaOcenka() << endl;

    } else if (tip == 4) { //funkcija getVkupnaOcenka vo OnlajnKniga
        cout << "-----TEST getVkupnaOcenka-----" << endl;
        cin >> naslov >> brojAvtori;
        for (int i = 0; i<brojAvtori; i++) {
            cin >> ime >> drzava;
            avtori[i] = Lice(ime, drzava);
        }
        cin >> brojOcenki;
        for (int i = 0; i<brojOcenki; i++) {
            cin >> ocenka;
            ocenki[i] = ocenka;
        }
        cin >> url >> brojPristapi >> brojSimnuvanja;

        OnlajnKniga ok(naslov, avtori, brojAvtori, ocenki, brojOcenki, url, brojPristapi, brojSimnuvanja);
        cout << "Vkupna ocenka: " << ok.getVkupnaOcenka() << endl;

    } else if (tip == 5) { //funkcija pecati vo OnlajnKniga
        cout << "-----TEST pecati -----" << endl;
        cin >> naslov >> brojAvtori;
        for (int i = 0; i<brojAvtori; i++) {
            cin >> ime >> drzava;
            avtori[i] = Lice(ime, drzava);
        }
        cin >> brojOcenki;
        for (int i = 0; i<brojOcenki; i++) {
            cin >> ocenka;
            ocenki[i] = ocenka;
        }
        cin >> url >> brojPristapi >> brojSimnuvanja;

        OnlajnKniga ok(naslov, avtori, brojAvtori, ocenki, brojOcenki, url, brojPristapi, brojSimnuvanja);
        ok.pecati();

    } else if (tip == 6) { //site klasi
        cout << "-----TEST Kniga i OnlajnKniga-----" << endl;
        cin >> naslov >> brojAvtori;
        for (int i = 0; i<brojAvtori; i++) {
            cin >> ime >> drzava;
            avtori[i] = Lice(ime, drzava);
        }
        cin >> brojOcenki;
        for (int i = 0; i<brojOcenki; i++) {
            cin >> ocenka;
            ocenki[i] = ocenka;
        }
        cin >> url >> brojPristapi >> brojSimnuvanja;

        Kniga *k = new OnlajnKniga(naslov, avtori, brojAvtori, ocenki, brojOcenki, url, brojPristapi, brojSimnuvanja);
        k->pecati();
        cout << "Vkupna ocenka: " << k->getVkupnaOcenka() << endl;
        delete k;


    } else if (tip == 7) { //funkcija prosechnaOcenka
        cout << "-----TEST prosechnaOcenka-----" << endl;
        int k, opt;
        cin >> k;
        Kniga **knigi = new Kniga*[k];
        for (int j = 0; j<k; j++) {
            cin >> opt; //1 kniga 2 onlajnkniga
            cin >> naslov >> brojAvtori;
            for (int i = 0; i<brojAvtori; i++) {
                cin >> ime >> drzava;
                avtori[i] = Lice(ime, drzava);
            }
            cin >> brojOcenki;
            for (int i = 0; i<brojOcenki; i++) {
                cin >> ocenka;
                ocenki[i] = ocenka;
            }
            if (opt == 1) {
                knigi[j] = new Kniga(naslov, avtori, brojAvtori, ocenki, brojOcenki);
            } else {
                cin >> url >> brojPristapi >> brojSimnuvanja;
                knigi[j] = new OnlajnKniga(naslov, avtori, brojAvtori, ocenki, brojOcenki, url, brojPristapi, brojSimnuvanja);
            }
        }
        cin >> ime;
        double prosecna=prosechnaOcenka(ime, knigi, k);
        cout << "Prosecna ocenka e za knigite na " << ime << " e " << prosecna;
        for (int j = 0; j<k; j++) delete knigi[j];
        delete[] knigi;
    } else if (tip == 8) { //funkcija pecatiOnlajnKnigi
        cout << "-----TEST pecatiOnlajnKnigi-----" << endl;
        int k, opt;
        cin >> k;
        Kniga **knigi = new Kniga*[k];
        for (int j = 0; j<k; j++) {
            cin >> opt; //1 kniga 2 onlajnkniga
            cin >> naslov >> brojAvtori;
            for (int i = 0; i<brojAvtori; i++) {
                cin >> ime >> drzava;
                avtori[i] = Lice(ime, drzava);
            }
            cin >> brojOcenki;
            for (int i = 0; i<brojOcenki; i++) {
                cin >> ocenka;
                ocenki[i] = ocenka;
            }
            if (opt == 1) {
                knigi[j] = new Kniga(naslov, avtori, brojAvtori, ocenki, brojOcenki);
            } else {
                cin >> url >> brojPristapi >> brojSimnuvanja;
                knigi[j] = new OnlajnKniga(naslov, avtori, brojAvtori, ocenki, brojOcenki, url, brojPristapi, brojSimnuvanja);
            }
        }
        pecatiOnlajnKnigi(knigi, k);
        for (int j = 0; j<k; j++) delete knigi[j];
        delete[] knigi;

    }


    return 0;
}

