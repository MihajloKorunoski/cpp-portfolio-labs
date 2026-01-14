#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Firma {
private:
    string imenafirma;
    string adresanafirma;
    static double vrednostnachas;
    static int bonus;
public:
    Firma() {
        imenafirma = "";
        adresanafirma = "";
    }

    Firma(string imenafirma, string adresanafirma) {
        postavifirma(imenafirma, adresanafirma);
    }

    virtual ~Firma() = default;

    void postavifirma(string imenafirma, string adresanafirma) {
        this->imenafirma = imenafirma;
        this->adresanafirma = adresanafirma;
    }

    void zemifirma(string &imenafirma, string &adresanafirma) {
        imenafirma = this->imenafirma;
        adresanafirma = this->adresanafirma;
    }

    static void postavivrednostnachas(double chas) {
        vrednostnachas = chas;
    }

    double zemivrednostnachas() {
        return vrednostnachas;
    };

    static void postavibonus(int bon) {
        bonus = bon;
    }

    int zemibonus() {
        return bonus;
    }

    void prikazhifirma() {
        cout << left << setw(10) << " Firma: " << setw(20) << imenafirma << endl;
        cout << setw(10) << " Adresa: " << setw(15) << adresanafirma << endl;
    }
};

double Firma::vrednostnachas = 300;
int Firma::bonus = 10;

class Vraboten {
    friend int brojcifri(long long);

private:
    string imeiprezime;
    long long embg;
    double plata;
public:
    Vraboten() {
        imeiprezime = "";
        embg = 0;
        plata = 0.0;
    }

    Vraboten(string imeiprezime, long long embg, double plata) {
        postavivraboten(imeiprezime, embg, plata);
    }

    void postavivraboten(string imeiprezime, long long embg, double plata) {
        this->imeiprezime = imeiprezime;
        this->embg = embg;
        this->plata = plata;
    }

    void zemivraboten(string &imeiprezime, long long &embg, double &plata) {
        imeiprezime = this->imeiprezime;
        embg = this->embg;
        plata = this->plata;
    }

    double zemiplata() {
        return plata;
    }

    virtual double zaisplata() = 0;

    virtual void prikazhivraboten() {
        cout << left << setw(25) << imeiprezime << setw(14) << embg << right << fixed << setprecision(2) << setw(10)
             << zemiplata();
    }
};

int brojcifri(long long broj) {
    int n = 0;
    while (broj > 0) {
        broj /= 10;
        n++;
    }
    return n;
}

class Programer : public Vraboten, public Firma {
private:
    string rabotnomesto;
    int prekuvremenichasovi;
public:
    Programer() {
        rabotnomesto = "";
        prekuvremenichasovi = 0;
    }

    Programer(string rabotnomesto, int prekuvremenichasovi, string imeiprezime, long long embg, double plata,
              string imenafirma, string adresanafirma) : Vraboten(imeiprezime, embg, plata),
                                                         Firma(imenafirma, adresanafirma) {
        postaviprogramer(rabotnomesto, prekuvremenichasovi);
    }

    void postaviprogramer(string rabotnomesto, int prekuvremenichasovi) {
        this->rabotnomesto = rabotnomesto;
        this->prekuvremenichasovi = prekuvremenichasovi;
    }

    string zemiprogramer(string &rabotnomesto, int &prekuvremenichasovi) {
        rabotnomesto = this->rabotnomesto;
        prekuvremenichasovi = this->prekuvremenichasovi;
    }

    virtual double zaisplata() {
        return zemiplata() + prekuvremenichasovi * zemivrednostnachas();
    }

    virtual void prikazhivraboten() {
        Vraboten::prikazhivraboten();
        cout << " " << left << setw(10) << rabotnomesto << right << setw(2) << prekuvremenichasovi << fixed
             << setprecision(2) << setw(12) << zaisplata() << endl;
    }
};

class Menadzher : public Vraboten, public Firma {
private:
    string funkcija;
public:
    Menadzher() {
        funkcija = "";
    }

    Menadzher(string funkcija, string imeiprezime, long long embg, double plata,
              string imenafirma, string adresanafirma) : Vraboten(imeiprezime, embg, plata),
                                                         Firma(imenafirma, adresanafirma) {
        postavimenadzher(funkcija);
    }

    void postavimenadzher(string funkcija) {
        this->funkcija = funkcija;
    }

    void zemimenadzher(string &funkcija) {
        funkcija = this->funkcija;
    }

    virtual double zaisplata() {
        return (1 + (double) zemibonus() / 100) * zemiplata();
    }

    virtual void prikazhivraboten() {
        Vraboten::prikazhivraboten();
        cout << " " << left << setw(10) << funkcija << right << setw(2) << zemibonus() << fixed
             << setprecision(2) << setw(12) << zaisplata() << endl;
    }
};

int main() {
    string vlez;
    string imenafirma;
    string adresanafirma;
    cout << " Vnesete podatoci za firmata:" << endl;
    cout << " Firma: ";
    getline(cin, imenafirma);
    cout << " Adresa: ";
    getline(cin, adresanafirma);
    Firma mojafirma(imenafirma, adresanafirma);

    const int brojvraboteni = 2;
    Vraboten *vraboteni[brojvraboteni];

    cout << "\nVnesete podatoci za vrabotenite: " << endl;
    string imeiprezime;
    string rabotnomesto;
    string funkcija;
    long long embg;
    double plata;
    int prekuvremenichasovi;
    double saldo = 0;

    bool a, b;
    string pilim;
    for (int vraboten = 0; vraboten < brojvraboteni; vraboten++) {
        do {
            cout << "\n" << vraboten + 1 << ". (P-Programer, M-Menadzher):";
            getline(cin, pilim);
            a = (pilim.compare("P") == 0);
            b = (pilim.compare("M") == 0);
        } while (a + b != 1);
        cout << " Ime i prezime: ";
        getline(cin, imeiprezime);
        do {
            cout << " EMBG(mora 13 cifri): ";
            getline(cin, vlez);
            embg = stoll(vlez);
        } while (brojcifri(embg) != 13);
        cout << " Plata: ";
        getline(cin, vlez);
        plata = stod(vlez);
        if (pilim.compare("P") == 0) {
            cout << " Rabotno mesto: ";
            getline(cin, rabotnomesto);
            cout << " Prekuvremeni chasovi: ";
            getline(cin, vlez);
            prekuvremenichasovi = stoi(vlez);
            vraboteni[vraboten] = new Programer(rabotnomesto, prekuvremenichasovi, imeiprezime, embg, plata, imenafirma,
                                                adresanafirma);
        }
        if (pilim.compare("M") == 0) {
            cout << " Funkcija: ";
            getline(cin, funkcija);
            vraboteni[vraboten] = new Menadzher(funkcija, imeiprezime, embg, plata, imenafirma, adresanafirma);
        }
    }
    system("CLS");
    mojafirma.prikazhifirma();

    double vrednostnachas;
    cout << " Vrednost na prekuvremen chas vo den: ";
    cin >> vrednostnachas;
    mojafirma.postavivrednostnachas(vrednostnachas);
    int bonus;
    cout << " Vrednost na bonus (procent cel broj): ";
    cin >> bonus;
    mojafirma.postavibonus(bonus);

    cout << "\n" << setw(35) << " " << "ISPLATNA LISTA" << endl;
    cout
            << "------------------------------------------------------------------------------------------------------------"
            << endl;
    cout << "\n" << setw(4) << " " << setw(25) << "Ime i prezime" << setw(14) << "EMBG" << setw(10) << " Plata" << " "
         << setw(10) << "Rab.mesto" << setw(4) << "Chasa " << setw(10) << " Vkupno" << endl;
    cout << setw(54) << "" << setw(10) << "Funkcija" << setw(6) << "Bonus" << endl;
    cout
            << "------------------------------------------------------------------------------------------------------------"
            << endl;
    double vkupnoisplata = 0;
    for (int vraboten = 0; vraboten < brojvraboteni; vraboten++) {
        cout << right << setw(2) << vraboten + 1 << ": ";
        vraboteni[vraboten]->prikazhivraboten();
        vkupnoisplata += vraboteni[vraboten]->zaisplata();
    }
    cout
            << "------------------------------------------------------------------------------------------------------------"
            << endl;
    cout << setw(64) << "Vkupno isplateno: " << right << setw(14) << vkupnoisplata << endl;
    cout << endl;
    system("PAUSE");
    return 0;
}






















