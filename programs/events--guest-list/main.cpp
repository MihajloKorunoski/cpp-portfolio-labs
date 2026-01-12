#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class PostoeckoLice {
private:
    char *msg;
public:
    PostoeckoLice(char *msg = "") {
        this->msg = msg;
    }

    ~PostoeckoLice() = default;

    void print() {
        cout << msg << endl;
    }
};

class Lice {
private:
    char ime[15];
    char prezime[15];
    char brojlichnakarta[9];
    char datumragjanje[11];
public:
    Lice(char *ime = "", char *prezime = "", char *brojlichnakarta = "", char *datumragjanje = "") {
        strcpy(this->ime, ime);
        strcpy(this->prezime, prezime);
        strcpy(this->brojlichnakarta, brojlichnakarta);
        strcpy(this->datumragjanje, datumragjanje);
    }

    Lice(const Lice &s) {
        strcpy(this->ime, s.ime);
        strcpy(this->prezime, s.prezime);
        strcpy(this->brojlichnakarta, s.brojlichnakarta);
        strcpy(this->datumragjanje, s.datumragjanje);
    }

    const Lice &operator=(const Lice &s) {
        if (this != &s) {
            strcpy(this->ime, s.ime);
            strcpy(this->prezime, s.prezime);
            strcpy(this->brojlichnakarta, s.brojlichnakarta);
            strcpy(this->datumragjanje, s.datumragjanje);
        }
        return *this;
    }

    bool operator==(Lice &s) {
        return strcmp(brojlichnakarta, s.brojlichnakarta) == 0;
    }

    friend ostream &operator<<(ostream &o, const Lice &s) {
        o << s.ime << " " << s.prezime << " " << s.brojlichnakarta << " " << s.datumragjanje;
        return o;
    }

    const char *getbrojlichnakarta() const {
        return brojlichnakarta;
    }

    const char *getDatum() const {
        return datumragjanje;
    }

};

class Auditorium {
private:
    char imenastan[50];
    Lice *lica;
    int br;
public:
    Auditorium(char *imenastan = "") {
        strcpy(this->imenastan, imenastan);
        lica = nullptr;
        br = 0;
    }

    Auditorium &operator+=(Lice &s) {
        Lice *tmp = new Lice[br + 1];
        for (int i = 0; i < br; i++) {
            tmp[i] = lica[i];
            if (strcmp(lica[i].getbrojlichnakarta(), s.getbrojlichnakarta()) == 0) {
                throw PostoeckoLice("Liceto e vekje prijaveno za nastanot!");
            }
        }
        delete[]lica;
        lica = tmp;
        lica[br++] = s;
        return *this;
    }

    friend ostream &operator<<(ostream &o, Auditorium &l) {
        o << l.imenastan << endl;
        for (int i = 0; i < l.br; i = i + 2) {
            o << l.lica[i] << endl;
        }
        return o;
    }

    void nagradeni(int m) {
        char mesec[3];
        for (int i = 0; i < br; i++) {
            strncpy(mesec, lica[i].getDatum() + 3, 2);
            int smesec = stoi(mesec);
            if (smesec == m) {
                cout << lica[i] << endl;
            }
        }
    }

    Auditorium &operator=(const Auditorium &a) {
        if (this != &a) {
            delete[]this->lica;
            this->lica = new Lice[br];
            for (int i = 0; i < br; i++) {
                this->lica[i] = a.lica[i];
            }
        }
        return *this;
    }

    ~Auditorium() {
        delete[]lica;
    }
};

int main() {

    char ime[15];
    char prezime[15];
    char lk[9];
    char datum[11];
    char naziv[50];
    int n;

    int tip;
    cin >> tip;

    if (tip == 1) {
        cout << "-----Test Lice & operator <<-----" << endl;
        cin >> ime >> prezime >> lk >> datum;
        Lice l(ime, prezime, lk, datum);
        cout << l;
    } else if (tip == 2) {
        cout << "-----Test Lice & operator == -----" << endl;
        cin >> ime >> prezime >> lk >> datum;
        Lice l1(ime, prezime, lk, datum);
        cin >> ime >> prezime >> lk >> datum;
        Lice l2(ime, prezime, lk, datum);
        if (l1 == l2) cout << "Isti se" << endl;
        else cout << "Ne se isti" << endl;
    } else if (tip == 3) {
        cout << "-----Test Auditorium, operator +=, operator << -----" << endl;
        cin.get();
        cin.getline(naziv, 49);
        cin >> n;
        Auditorium a(naziv);
        for (int i = 0; i < n; i++) {
            cin >> ime >> prezime >> lk >> datum;
            Lice l(ime, prezime, lk, datum);
            a += l;
        }
        cout << a;
    } else if (tip == 4) {
        cout << "-----Test KorisnichkiProfil, operator +=, nagradeni -----" << endl;
        cin.get();
        cin.getline(naziv, 49);
        cin >> n;
        Auditorium a(naziv);
        for (int i = 0; i < n; i++) {
            cin >> ime >> prezime >> lk >> datum;
            Lice l(ime, prezime, lk, datum);
            a += l;
        }
        int m;
        cin >> m;
        cout << "Nagradeni posetiteli:" << endl;
        a.nagradeni(m);

    } else if (tip == 5) {
        cout << "-----Test Exception -----" << endl;
        cin.get();
        cin.getline(naziv, 49);
        cin >> n;
        Auditorium a(naziv);
        for (int i = 0; i < n; i++) {
            cin >> ime >> prezime >> lk >> datum;
            Lice l(ime, prezime, lk, datum);
            try {
                a += l;
            } catch (PostoeckoLice &p) {
                p.print();
            }

        }
        cout << a;

    } else if (tip == 6) {
        cout << "-----Test All -----" << endl;
        cin.get();
        cin.getline(naziv, 49);
        cin >> n;
        Auditorium a(naziv);
        for (int i = 0; i < n; i++) {
            cin >> ime >> prezime >> lk >> datum;
            Lice l(ime, prezime, lk, datum);
            try {
                a += l;
            } catch (PostoeckoLice &p) {
                p.print();
            }
        }
        cout << a;
        int s;
        cin >> s;
        cout << "Nagradeni posetiteli:" << endl;
        a.nagradeni(s);

    }

    return 0;
}
