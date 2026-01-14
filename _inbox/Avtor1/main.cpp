#include <iostream>
#include<string>
#include<iomanip>

using namespace std;

class Avtor {
private:
    string imeiprezime;
    string zhanr;
    string email;
public:
    Avtor() {
        imeiprezime = zhanr = email = "";
    }
    Avtor(string imeiprezime, string zhanr, string email) {
        postaviavtor(imeiprezime, zhanr, email);
    }

    void postaviavtor(string imeiprezime, string zhanr, string email) {
        this->imeiprezime = imeiprezime;
        this->zhanr = zhanr;
        this->email = email;
    }

    void zemiavtor(string &imeiprezime, string &zhanr, string &email) {
        imeiprezime = this->imeiprezime;
        zhanr = this->zhanr;
        email = this->email;
    }

    void prikazhiavtor() {
        cout << setw(10) << " Avtor: " << imeiprezime << endl;
        cout << setw(10) << " Zhanr: " << zhanr << endl;
        cout << setw(10) << " E-mail: " << email << endl;
    }
};

class Izdavach {
private:
    string imenaizdavach;
    string adresa;
public:
    Izdavach() {
        imenaizdavach = adresa = "";
    }

    Izdavach(string imenaizdavach, string adresa) {
        postaviizdavach(imenaizdavach, adresa);
    }

    void postaviizdavach(string imenaizdavach, string adresa) {
        this->imenaizdavach = imenaizdavach;
        this->adresa = adresa;
    }

    void zemiizdavach(string &imenaizdavach, string &adresa) {
        imenaizdavach = this->imenaizdavach;
        adresa = this->adresa;
    }

    void prikazhiizdavach() {
        cout << setw(10) << " Izdavach: " << imenaizdavach << endl;
        cout << setw(10) << " Adresa: " << adresa << endl;
    }
};

class Kniga : public Avtor, public Izdavach {
private:
    string naslov;
    double cena;
    string isbn;
    int godinanaizdavanje;
public:
    Kniga() {
        naslov = "";
        cena = 0;
    }

    Kniga(string naslov, double cena, string isbn, int godinanaizdavanje, string imeiprezime, string zhanr,
          string email, string imenaizdavach, string adresa) : Avtor(imeiprezime, zhanr, email),
                                                               Izdavach(imenaizdavach, adresa) {
        postavikniga(naslov, cena, isbn, godinanaizdavanje);
    }

    void postavikniga(string naslov, double cena, string isbn, int godinanaizdavanje) {
        this->naslov = naslov;
        this->cena = cena;
        this->isbn = isbn;
        this->godinanaizdavanje = godinanaizdavanje;
    }

    void zemikniga(string &naslov, double &cena, string &isbn, int &godinanaizdavanje) {
        naslov = this->naslov;
        cena = this->cena;
        isbn = this->isbn;
        godinanaizdavanje = this->godinanaizdavanje;
    }

    void postaviisbn(string isbn) {
        this->isbn = isbn;
    }

    string zemiisbn() {
        return isbn;
    }

    void postavigodinanaizdavanje(int godinanaizdavanje) {
        this->godinanaizdavanje = godinanaizdavanje;
    }

    int zemigodinanaizdavanje() {
        return godinanaizdavanje;
    }

    void prikazhikniga(Kniga ovaa) {
        cout << left << endl;
        cout << setw(10) << " Naslov: " << ovaa.naslov << endl;
        prikazhiavtor();
        prikazhiizdavach();
        cout << setw(10) << " Godina: " << ovaa.godinanaizdavanje << endl;
        cout << setw(10) << " ISBN: " << ovaa.isbn << endl;
        cout << setw(10) << " Cena: " << ovaa.cena << endl;
    }
};

int main() {
    const int brojknigi=3;
    Kniga knigi[brojknigi];
    knigi[0]={"C++ Osnovi na programiranje",234.5,"ISBN-10",2007,"Venko Gruevski",
              "Informatika","gjorgji@gocmar.mk","GOCMAR","Krushevska 100"};
    knigi[1]={"C++ Osnovi na degradiranje",212.5,"ISBN-10",2007,"Simjan Temjan Gruevski",
              "Informatika","gjorgji@gocmar.mk","GOCMAR","Krushevska 100"};
    knigi[2]={"Algoritmi i podatochni strukturi",4000.5,"ISBN-10",2020,"Simjan Temjan Gruevski",
              "Informatika","gjorgjijadamcheski@gocmar.mk","GOCMAR","Krushevska 100"};

    cout<<"\nKnigi:"<<endl;
    for(int i=0;i<brojknigi;i++){
        cout<<"\nKniga "<<i+1<<":";
        knigi[i].prikazhikniga(knigi[i]);
    }

    cout<<"\nKnigi:"<<endl;
    int i=0;
    for(Kniga ovaa : knigi){
        cout<<"\nKniga "<<++i<<":";
        ovaa.prikazhikniga(ovaa);
    }

    cout<<"\nKnigi:"<<endl;
    string naslov,isbn;
    double cena;
    int godina;
    for(int i=0;i<brojknigi;i++){
        knigi[i].zemikniga(naslov,cena,isbn,godina);
        cout<<i+1<<": ";
        cout<<setw(30)<<naslov<<setw(10)<<" Cena: "<<cena<<endl;
    }

    cout<<"\nAvtori"<<endl;
    string imeiprezime,zhanr,email;
    for(int i=0;i<brojknigi;i++){
        knigi[i].zemiavtor(imeiprezime,zhanr,email);
        cout<<i+1<<": ";
        cout<<setw(25)<<imeiprezime<<setw(10)<<" E-mail: "<<email<<endl;
    }

    cout<<endl<<endl;
    system("PAUSE");
    return 0;
}














