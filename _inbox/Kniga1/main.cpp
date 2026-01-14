#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

class Publikacija {
private:
    string vid;
public:
    Publikacija(string vid = "") {
        setVid(vid);
    }

    virtual ~Publikacija() = default;

    const string &getVid() const {
        return vid;
    }

    void setVid(const string &vid) {
        Publikacija::vid = vid;
    }

    virtual void prikazhipublikacija() {
        cout << left << setw(10) << "\n Vid: \t" << getVid() << endl;
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
        setImenaizdavach(imenaizdavach);
        setAdresa(adresa);
    }

    virtual ~Izdavach() = default;

    const string &getImenaizdavach() const {
        return imenaizdavach;
    }

    void setImenaizdavach(const string &imenaizdavach) {
        Izdavach::imenaizdavach = imenaizdavach;
    }

    const string &getAdresa() const {
        return adresa;
    }

    void setAdresa(const string &adresa) {
        Izdavach::adresa = adresa;
    }

    void prikazhiizdavach() {
        cout << setw(10) << " Izdavach:" << getImenaizdavach() << endl;
        cout << setw(10) << " Adresa: " << getAdresa() << endl;
    }
};

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
        setImeiprezime(imeiprezime);
        setZhanr(zhanr);
        setEmail(email);
    }

    virtual ~Avtor() = default;

    const string &getImeiprezime() const {
        return imeiprezime;
    }

    void setImeiprezime(const string &imeiprezime) {
        Avtor::imeiprezime = imeiprezime;
    }

    const string &getZhanr() const {
        return zhanr;
    }

    void setZhanr(const string &zhanr) {
        Avtor::zhanr = zhanr;
    }

    const string &getEmail() const {
        return email;
    }

    void setEmail(const string &email) {
        Avtor::email = email;
    }

    void prikazhiavtor() {
        cout << setw(10) << " Avtor: " << getImeiprezime() << endl;
        cout << setw(10) << " Zhanr: " << getZhanr() << endl;
        cout << setw(10) << " E-mail: " << getEmail() << endl;
    }
};

class Kniga : public Avtor, public Izdavach, public Publikacija {
private:
    string naslov;
    double cena;
    string isbn;
    int godinanaizdavanje;
public:
    Kniga() {
        naslov = "";
        cena = 0;
        isbn = "";
        godinanaizdavanje = 0;
    }

    Kniga(string naslov, double cena, string isbn, int godinanaizdavanje, string imeiprezime, string zhanr,
          string email,
          string imenaizdavach, string adresa, string vid) : Avtor(imeiprezime, zhanr, email),
                                                             Izdavach(imenaizdavach, adresa), Publikacija(vid) {
        setNaslov(naslov);
        setCena(cena);
        setIsbn(isbn);
        setGodinanaizdavanje(godinanaizdavanje);
    }

    const string &getNaslov() const {
        return naslov;
    }

    void setNaslov(const string &naslov) {
        Kniga::naslov = naslov;
    }

    double getCena() const {
        return cena;
    }

    void setCena(double cena) {
        Kniga::cena = cena;
    }

    const string &getIsbn() const {
        return isbn;
    }

    void setIsbn(const string &isbn) {
        Kniga::isbn = isbn;
    }

    int getGodinanaizdavanje() const {
        return godinanaizdavanje;
    }

    void setGodinanaizdavanje(int godinanaizdavanje) {
        Kniga::godinanaizdavanje = godinanaizdavanje;
    }

    void zemikniga(string &naslov, double &cena, string &isbn, int &godinanaizdavanje) {
        naslov = this->naslov;
        cena = this->cena;
        isbn = this->isbn;
        godinanaizdavanje = this->godinanaizdavanje;
    }

    virtual void prikazhipublikacija() {
        Publikacija::prikazhipublikacija();
        cout << left;
        cout << setw(10) << " Naslov: " << naslov << endl;
        prikazhiavtor();
        prikazhiizdavach();
        cout << setw(10) << " Godina: " << godinanaizdavanje << endl;
        cout << setw(10) << " ISBN: " << isbn << endl;
        cout << setw(10) << " Cena: " << cena << endl;
    }
};

class Vesnik : public Izdavach, public Publikacija {
private:
    string naslov;
    double cena;
public:
    Vesnik() {
        naslov = "";
        cena = 0;
    }

    Vesnik(string naslov, double cena, string imenaizdavach, string adresa, string vid) : Izdavach(imenaizdavach,
                                                                                                   adresa),
                                                                                          Publikacija(vid) {
        setNaslov(naslov);
        setCena(cena);
    }

    const string &getNaslov() const {
        return naslov;
    }

    void setNaslov(const string &naslov) {
        Vesnik::naslov = naslov;
    }

    double getCena() const {
        return cena;
    }

    void setCena(double cena) {
        Vesnik::cena = cena;
    }

    virtual void prikazhipublikacija() {
        Publikacija::prikazhipublikacija();
        cout << left;
        cout << setw(10) << " Naslov: " << getNaslov() << endl;
        prikazhiizdavach();
        cout << setw(10) << " Cena: " << getCena() << endl;
    }
};

class Uchebnik : public Kniga {
private:
    int klas;
public:
    Uchebnik() {
        klas = 0;
    }

    Uchebnik(int klas, string naslov, double cena, string isbn, int godinanaizdavanje, string imeiprezime, string zhanr,
             string email, string imenaizdavach, string adresa, string vid) : Kniga(naslov, cena, isbn,
                                                                                    godinanaizdavanje, imeiprezime,
                                                                                    zhanr, email, imenaizdavach, adresa,
                                                                                    vid) {
        setKlas(klas);
    }

    int getKlas() const {
        return klas;
    }

    void setKlas(int klas) {
        Uchebnik::klas = klas;
    }

    virtual void prikazhipublikacija() {
        Publikacija::prikazhipublikacija();
        cout << left;
        cout << setw(10) << " Klas:    " << getKlas() << endl;
        string naslov, isbn;
        double cena;
        int godinanaizdavanje;
        zemikniga(naslov, cena, isbn, godinanaizdavanje);
        cout << setw(10) << " Naslov:  " << naslov << endl;
        prikazhiavtor();
        prikazhiizdavach();
        cout << setw(10) << " Godina:  " << godinanaizdavanje << endl;
        cout << setw(10) << " ISBN:    " << isbn << endl;
        cout << setw(10) << " Cena:    " << cena << endl;
    }
};

void chitanjeknigi(Kniga knigi[], int &brojknigi);

void chitanjevesnici(Vesnik vesnici[], int &brojvesnici);

void chitanjeuchebnici(Uchebnik uchebnici[], int &brojuchebnici);

string naslov;
double cena;
string imeiprezime,zhanr,email;
string imenaizdavach, adresa, isbn;
int godinanaizdavanje;
string vid;
int klas;
string vlez;

int main() {

    Kniga knigi[100];
    int brojknigi;
    chitanjeknigi(knigi, brojknigi);

    Vesnik vesnici[100];
    int brojvesnici;
    chitanjevesnici(vesnici, brojvesnici);

    Uchebnik uchebnici[100];
    int brojuchebnici;
    chitanjeuchebnici(uchebnici, brojuchebnici);

    const int brojpublikacii = brojknigi + brojvesnici + brojuchebnici;

    Publikacija *publikacii[100];
    int i = 0;
    for (int j = 0; j < brojknigi; j++, i++) {
        publikacii[i] = &knigi[j];
    }
    for (int j = 0; j < brojvesnici; j++, i++) {
        publikacii[i] = &vesnici[j];
    }
    for (int j = 0; j < brojuchebnici; j++, i++) {
        publikacii[i] = &uchebnici[j];
    }

    cout << " Publikacii: " << endl;
    for (int i = 0; i < brojpublikacii; i++) {
        cout << "\n Publikacija " << i + 1 << ":";
        publikacii[i]->prikazhipublikacija();
    }

    cout << endl << endl;
    system("PAUSE");
    return 0;

}
void chitanjeknigi(Kniga knigi[], int &brojknigi) {
    ifstream datknigi("knigi.dat");
    if (!datknigi) {
        cout << "Nemat datoteka za knigi" << endl;
        exit(1);
    }
    int i=-1;
    while(true){
        i++;
        getline(datknigi,naslov);
        if(naslov=="KRAJ")
            break;
        getline(datknigi,zhanr);
        getline(datknigi,vlez);
        cena=stod(vlez);
        getline(datknigi,imeiprezime);
        getline(datknigi,email);
        getline(datknigi,imenaizdavach);
        getline(datknigi,adresa);
        getline(datknigi,isbn);
        getline(datknigi,vlez);
        godinanaizdavanje=stoi(vlez);
        getline(datknigi, vid);
        knigi[i]={naslov,cena,isbn,godinanaizdavanje,imeiprezime,zhanr,email,imenaizdavach,adresa,vid};
        getline(datknigi,vlez);
    }
    datknigi.close();
    brojknigi=i;
}

void chitanjevesnici(Vesnik vesnici[], int &brojvesnici) {
    ifstream datvesnici("vesnici.dat");
    if (!datvesnici) {
        cout << "Nemat datoteka za vesnici" << endl;
        exit(1);
    }
    int i=-1;
    while(true){
        i++;
        getline(datvesnici,naslov);
        if(naslov=="KRAJ")
            break;
        getline(datvesnici,vlez);
        cena=stod(vlez);
        getline(datvesnici,imenaizdavach);
        getline(datvesnici,adresa);
        getline(datvesnici,vid);
        vesnici[i]={naslov,cena,imenaizdavach,adresa,vid};
        getline(datvesnici,vlez);
    }
    datvesnici.close();
    brojvesnici=i;
}
void chitanjeuchebnici(Uchebnik uchebnici[], int &brojuchebnici) {
    ifstream datuchebnici("uchebnici.dat");
    if (!datuchebnici) {
        cout << "Nemat datoteka za uchebnici" << endl;
        exit(1);
    }
    int i=-1;
    while(true){
        i++;
        getline(datuchebnici,naslov);
        if(naslov=="KRAJ")
            break;
        getline(datuchebnici,vlez);
        klas=stoi(vlez);
        getline(datuchebnici,imeiprezime);
        getline(datuchebnici,zhanr);
        getline(datuchebnici,email);
        getline(datuchebnici,imenaizdavach);
        getline(datuchebnici,adresa);
        getline(datuchebnici,isbn);
        getline(datuchebnici,vlez);
        godinanaizdavanje=stoi(vlez);
        getline(datuchebnici, vid);
        getline(datuchebnici,vlez);
        cena=stod(vlez);
        uchebnici[i]={klas,naslov,cena,isbn,godinanaizdavanje,imeiprezime,zhanr,email,imenaizdavach,adresa,vid};
        getline(datuchebnici,vlez);
    }
    datuchebnici.close();
    brojuchebnici=i;
}

















