#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Banka {
private:
    string imenabanka;
    string adresanabanka;
    static double kamatnastapka;
public:
    Banka() {
        imenabanka = "";
        adresanabanka = "";
    }

    Banka(string imenabanka, string adresanabanka) {
        postavibanka(imenabanka, adresanabanka);
    }

    virtual ~Banka() = default;

    void postavibanka(string imenabanka, string adresanabanka) {
        this->imenabanka = imenabanka;
        this->adresanabanka = adresanabanka;
    }

    void zemibanka(string imenabanka, string adresanabanka) {
        imenabanka = this->imenabanka;
        adresanabanka = this->adresanabanka;
    }

    static void postavikamatnastapka(double kstapka) {
        kamatnastapka = kstapka;
    }

    double zemikamatnastapka() {
        return kamatnastapka;
    }

    virtual void prikazhiklient() {
    }

    void prikazhibanka() {
        cout << left << setw(10) << " Banka: " << setw(20) << imenabanka << endl;
    }
};
double Banka::kamatnastapka=15;
class Klient : public Banka {
    friend int brojcifri(long long);

private:
    string imeiprezime;
    string adresa;
    long long embg;
    int brojnasmetki;
public:
    Klient() {
        imeiprezime = "";
        adresa = "";
        embg = brojnasmetki = 0;
    }

    Klient(string imeiprezime, string adresa, long long embg, int brojnasmetki) {
        postaviklient(imeiprezime, adresa, embg, brojnasmetki);
    }

    Klient(string imeiprezime, string adresa, long long embg, int brojnasmetki, string imenabanka,
           string adresanabanka) : Banka(imenabanka, adresanabanka) {
        postaviklient(imeiprezime, adresa, embg, brojnasmetki);
    }

    void postaviklient(string imeiprezime, string adresa, long long embg, int brojnasmetki) {
        this->imeiprezime = imeiprezime;
        this->adresa = adresa;
        this->embg = embg;
        this->brojnasmetki = brojnasmetki;
    }

    void zemiklient(string &imeiprezime, string &adresa, long long &embg, int &brojnasmetki) {
        imeiprezime = this->imeiprezime;
        adresa = this->adresa;
        embg = this->embg;
        brojnasmetki = this->brojnasmetki;
    }

    int zemibrojnasmetki() {
        return brojnasmetki;
    }

    virtual void prikazhiklient() {
        cout << "\n" << left << setw(24) << imeiprezime << setw(24) << adresa << " EMBG: " << setw(14) << embg
             << "Smetki: " << brojnasmetki << endl;
        cout << "-----------------------------------------------------------------------------------------------------"
             << endl;
    }

    virtual double zemikamata() {
        return 0;
    }

    virtual void prikazhismetka() {
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

class Smetka : public Klient {
private:
    long long smetkabroj;
    double saldo;
public:
    Smetka() {
        smetkabroj = saldo = 0;
    }

    Smetka(long long smetkabroj, double saldo) {
        postavismetka(smetkabroj, saldo);
    }

    Smetka(long long smetkabroj, double saldo, string imeiprezime, string adresa, long long embg, int brojnasmetki,
           string imenabanka, string adresanbanka) : Klient(imeiprezime, adresa, embg, brojnasmetki, imenabanka,
                                                            adresanbanka) {
        postavismetka(smetkabroj, saldo);
    }

    void postavismetka(long long smetkabroj, double saldo) {
        this->smetkabroj = smetkabroj;
        this->saldo = saldo;
    }

    void zemismetka(long long &smetkabroj, double &saldo) {
        smetkabroj = this->smetkabroj;
        saldo = this->saldo;
    }

    virtual double zemikamata() {
        double kamata;
        kamata = saldo * zemikamatnastapka() / 100;
        return kamata;
    }

    virtual void prikazhismetka() {
        cout << "Broj " << smetkabroj << "  Saldo" << right << setw(10) << saldo << " denari";
    }
};

int main() {
    string vlez;
    string imenabanka;
    string adresanabanka;
    cout << "Vnesete podatoci za bankata:" << endl;
    cout << " Banka: ";
    getline(cin, imenabanka);
    cout << " Adresa: ";
    getline(cin, adresanabanka);
    Banka mojabanka(imenabanka, adresanabanka);

    Banka *smetki[100][10];
    int brojnaklienti;
    string imeiprezime;
    string adresa;
    long long embg;
    int brojnasmetki;
    long long smetkabroj;
    cout << "\nBroj na klienti: ";
    getline(cin, vlez);
    brojnaklienti = stoi(vlez);
    for (int i = 0; i < brojnaklienti; i++) {
        cout << "\nVnesete podatoci za " << i + 1 << "ot klient" << endl;
        cout << " Ime i prezime: ";
        getline(cin, imeiprezime);
        cout << " Adresa: ";
        getline(cin, adresa);
        do {
            cout << " EMBG (mora 13 cifri) : ";
            getline(cin, vlez);
            embg = stoll(vlez);
        } while (brojcifri(embg) != 13);
        cout << " Broj na smetki: ";
        getline(cin, vlez);
        brojnasmetki = stoi(vlez);
        cout << "\nVnesete gi smetkite: " << endl;
        double saldo;
        for (int smetka = 0; smetka < brojnasmetki; smetka++) {
            cout << " Smetka " << smetka + 1 << ": ";
            do {
                cout << " Broj na smetka(mora 15 cifri) : ";
                getline(cin, vlez);
                smetkabroj = stoll(vlez);
            } while (brojcifri(smetkabroj) != 15);
            cout << " Saldo: ";
            getline(cin, vlez);
            saldo = stod(vlez);
            smetki[i][smetka] = new Smetka{smetkabroj, saldo, imeiprezime, adresa, embg, brojnasmetki, imenabanka,
                                           adresanabanka};
        }
    }
    mojabanka.prikazhibanka();
    Klient *ovojklient;
    for (int i = 0; i < brojnaklienti; i++) {
        cout << "\nKlient " << i + 1 << ": ";
        smetki[i][0]->prikazhiklient();
        brojnasmetki = ((Klient *) smetki[i][0])->zemibrojnasmetki();
        double vkupnokamata;
        for (int smetka = 0; smetka < brojnasmetki; smetka++) {
            ovojklient = (Klient *) smetki[i][smetka];
            cout << " Smetka: " << smetka + 1 << ": ";
            ovojklient->prikazhismetka();
            cout << " Kamata: " << right << setw(12) << ovojklient->zemikamata() << endl;
            vkupnokamata += ovojklient->zemikamata();
        }
        cout << "-----------------------------------------------------------------------------------------------------"
             << endl;
        cout << setw(68) << "Vkupna kamata: " << right << setw(10) << vkupnokamata << endl;
    }
    cout << endl;
    system("PAUSE");
    return 0;
}
