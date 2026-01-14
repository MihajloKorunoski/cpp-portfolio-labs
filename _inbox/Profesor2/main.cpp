#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Lice {
private:
    string ime;
    string prezime;
    long long matichenbroj;
public:
    Lice() {
        ime = " ";
        prezime = "";
        matichenbroj = 0;
    }

    Lice(string ime, string prezime, long long matichenbroj) {
        postavilice(ime, prezime, matichenbroj);
    }

    void postavilice(string ime, string prezime, long long matichenbroj) {
        this->ime = ime;
        this->prezime = prezime;
        this->matichenbroj = matichenbroj;
    }

    string zemiime() {
        return ime;
    }

    string zemiprezime() {
        return prezime;
    }

    long long zemimatichenbroj() {
        return matichenbroj;
    }

    void prikazhilice() {
        cout << left << zemiprezime() << " " << zemiime() << "\tEMBG:" << zemimatichenbroj() << endl;
    }
};

class Uchilishte {
private:
    string uchilishte;
    string mesto;
    string vid;
public:
    Uchilishte();

    Uchilishte(string, string, string);

    void postaviimenauchilishte(string);

    string zemiimenauchilishte();

    void postavimesto(string);

    string zemimesto();

    void postavivid(string);

    string zemivid();

    void prikazhiuchilishte();
};

Uchilishte::Uchilishte() {

}

Uchilishte::Uchilishte(string uchilishte, string mesto, string vid) {
    this->uchilishte = uchilishte;
    this->mesto = mesto;
    this->vid = vid;
}

void Uchilishte::postaviimenauchilishte(string uchilishte) {
    this->uchilishte = uchilishte;
}

string Uchilishte::zemiimenauchilishte() {
    return uchilishte;
}

void Uchilishte::postavimesto(string mesto) {
    this->mesto = mesto;
}

string Uchilishte::zemimesto() {
    return mesto;
}

void Uchilishte::postavivid(string vid) {
    this->vid = vid;
}

string Uchilishte::zemivid() {
    return vid;
}

void Uchilishte::prikazhiuchilishte() {
    cout << "\nUchilishte: " << zemivid() << "\t" << zemiimenauchilishte() << " . " << zemimesto() << endl;
}

class Profesor : public Lice {
private:
    string struka;
public:
    Profesor();

    Profesor(string, string, long long, string);

    void postavistruka(string);

    string zemistruka();

    void prikazhiprofesor();
};

Profesor::Profesor() {

}

Profesor::Profesor(string ime, string prezime, long long matichenbroj, string struka) : Lice(ime, prezime,
                                                                                             matichenbroj) {
    postavistruka(struka);
}

void Profesor::postavistruka(string struka) {
    this->struka = struka;
}

string Profesor::zemistruka() {
    return struka;
}

void Profesor::prikazhiprofesor() {
    cout << "\tProfesor:             ";
    prikazhilice();
    cout << "\tStruka:               " << zemistruka() << endl;
}

class Predmet : public Profesor {
private:
    string predmet;
    int kod;
public:
    Predmet();

    Predmet(string, int, string, string, long long, string);

    void postavipredmet(string);

    string zemipredmet();

    void postavikod(int);

    int zemikod();

    void prikazhipredmet();
};

Predmet::Predmet() {
    predmet = "", kod = 0;
}

Predmet::Predmet(string predmet, int kod, string ime, string prezime, long long matichenbroj, string struka) : Profesor(
        ime, prezime, matichenbroj, struka) {
    this->predmet = predmet;
    this->kod = kod;
}

void Predmet::postavipredmet(string predmet) {
    this->predmet = predmet;
}

string Predmet::zemipredmet() {
    return predmet;
}

void Predmet::postavikod(int kod) {
    this->kod = kod;
}

int Predmet::zemikod() {
    return kod;
}

void Predmet::prikazhipredmet() {
    cout << "\tIme na predmet:       " << zemipredmet()
         << "\n\tKod:                  " << zemikod() << endl;
    prikazhiprofesor();
}

class Uchenik : public Lice, public Uchilishte {
    friend double prosek(int, int oceni[]);

private:
    string klas;
    int brojvodnevnik;
    int brojpredmeti;
    Predmet predmeti[15];
public:
    Uchenik();

    Uchenik(string, int, int, Predmet[], string, string, long long, string, string, string);

    void postaviklas(string);

    string zemiklas();

    void postavibrojvodnevnik(int);

    int zemibrojvodnevnik();

    void postavibrojpredmeti(int);

    int zemibrojpredmeti();

    void prikazhiuchenik();
};

Uchenik::Uchenik() {

}

Uchenik::Uchenik(string klas, int brojvodnevnik, int brojpredmeti, Predmet predmeti[], string ime, string prezime,
                 long long matichenbroj, string uchilishte, string mesto, string vid) : Lice(ime, prezime,
                                                                                             matichenbroj),
                                                                                        Uchilishte(uchilishte, mesto,
                                                                                                   vid) {
    this->klas = klas;
    this->brojvodnevnik = brojvodnevnik;
    this->brojpredmeti = brojpredmeti;
    for (int i = 0; i < brojpredmeti; i++) {
        this->predmeti[i] = predmeti[i];
    }
}

void Uchenik::postaviklas(string klas) {
    this->klas = klas;
}

string Uchenik::zemiklas() {
    return klas;
}

void Uchenik::postavibrojvodnevnik(int brojvodnevnik) {
    this->brojvodnevnik = brojvodnevnik;
}

int Uchenik::zemibrojvodnevnik() {
    return brojvodnevnik;
}

void Uchenik::postavibrojpredmeti(int brojpredmeti) {
    this->brojpredmeti = brojpredmeti;
}

int Uchenik::zemibrojpredmeti() {
    return brojpredmeti;
}

void Uchenik::prikazhiuchenik() {
    prikazhilice();
    cout << "\nUchenik: ";
    prikazhilice();
    cout << zemiklas() << " klas, broj " << zemibrojvodnevnik() << endl;
    for (int i = 0; i < brojpredmeti; i++) {
        cout << "\nPredmet " << i + 1 << ":" << endl;
        predmeti[i].prikazhipredmet();
    }
}

double prosek(int brojpredmeti, int oceni[]) {
    double suma = 0;
    for (int i = 0; i < brojpredmeti; i++) {
        suma += oceni[i];
    }
    return suma / brojpredmeti;
}

int main() {
    string input;
    string uchilishte;
    string mesto;
    string vid;
    string imeuchenik;
    string prezimeuchenik;
    long long matichenbrojuchenik;
    string klas;
    int brojvodnevnik;
    int brojpredmeti;
    string imeprofesor;
    string prezimeprofesor;
    long long matichenbrojprofesor;
    string struka;
    string predmet;
    int kod;

    cout << "Vnesete podatoci za uchilishteto:" << endl;
    cout << "\tIme na uchilishte: ";
    getline(cin, uchilishte);
    cout << "\tMesto: ";
    getline(cin, mesto);
    cout << "\tVid (gimnazija, struchno ...): ";
    getline(cin, vid);

    cout << "Vnesete podatoci na uchenikot:" << endl;
    cout << "\tIme na uchenik: ";
    getline(cin, imeuchenik);
    cout << "\tPrezime na uchenik: ";
    getline(cin, imeuchenik);
    cout << "\tEMBG na uchenik: ";
    getline(cin, input);
    matichenbrojuchenik = stoll(input);
    cout << "\tKlas: ";
    getline(cin, klas);
    cout << "\tBroj vo dnevnik: ";
    getline(cin, input);
    brojvodnevnik = stoi(input);

    cout << "\nVnesete broj na predmeti: ";
    getline(cin, input);
    brojpredmeti = stoi(input);
    Predmet predmeti[15];
    for (int i = 0; i < brojpredmeti; i++) {
        cout << "\n Predmet " << i + 1 << endl;
        cout << "\t Ime na predmet:     ";
        getline(cin, predmet);
        cout << "\t Kod:                ";
        getline(cin, input);
        kod = stoi(input);
        cout << "\tIme na profesor:     ";
        getline(cin, imeprofesor);
        cout << "\tPrezime na profesor: ";
        getline(cin, prezimeprofesor);
        cout << "\tEMBG na profesor:    ";
        getline(cin, input);
        matichenbrojprofesor = stoll(input);
        cout << "\tStruka na profesor:  ";
        getline(cin, struka);
        predmeti[i] = {predmet, kod, imeprofesor, prezimeprofesor, matichenbrojprofesor, struka};
    }
    Uchenik jas(klas, brojvodnevnik, brojpredmeti, predmeti, imeuchenik, prezimeuchenik, matichenbrojuchenik,
                uchilishte, mesto, vid);
    system("CLS");
    jas.prikazhiuchenik();

    cout << "\nVnesete gi ocenite: " << endl;
    int oceni[15];
    for (int i = 0; i < brojpredmeti; i++) {
        cout << "Predmet " << i + 1 << ": " << predmeti[i].zemipredmet() << " - ocena ";
        cin >> oceni[i];
    }
    cout << "\nProsechna ocena e: " << prosek(brojpredmeti, oceni) << endl;

    cout << endl;
    system("PAUSE");
    return 0;
}













