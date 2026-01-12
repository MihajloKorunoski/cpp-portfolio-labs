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

    virtual ~Banka() {
    }

    void postavibanka(string imenabanka, string adresanabanka) {
        this->imenabanka = imenabanka;
        this->adresanabanka = adresanabanka;
    }

    void zemibanka(string &imenabanka, string &adresanabanka) {
        imenabanka = this->imenabanka;
        adresanabanka = this->adresanabanka;
    }

    static void postavikamatnastapka(double kstapka) {
        kamatnastapka = kstapka;
    }

    double zemikamatnastapka() {
        return kamatnastapka;
    }

    void prikazhibanka() {
        cout << left << setw(10) << " Banka: " << setw(20) << imenabanka << endl;
        cout << setw(10) << " Adresa: " << setw(15) << adresanabanka << endl;
        cout << setw(10) << " Kamatna stapka: " << kamatnastapka << "%" << endl;
        cout << endl;
    }
};

double Banka::kamatnastapka = 3;

class Smetka : public Banka {
private:
    long long smetkabroj;
    double saldo;
public:
    Smetka() {
        smetkabroj = 0;
        saldo = 0;
    }

    Smetka(long long smetkabroj, double saldo) {
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

    double zemikamata() {
        double kamata;
        kamata = saldo * zemikamatnastapka() / 100;
        return kamata;
    }

    void prikazhismetka() {
        cout << "Broj " << smetkabroj << " Saldo:" << right << setw(10) << saldo << " denari";
    }
};

class Klient : public Banka {
    friend int brojcifri(long long);

private:
    string imeiprezime;
    string adresa;
    long long embg;
    int brojnasmetki;
    Smetka *poknasmetki;
public:
    Klient() {
        imeiprezime = "";
        adresa = "";
        embg = brojnasmetki = 0;
        poknasmetki = nullptr;
    }

    Klient(string imeiprezime, string adresa, long long embg, int brojnasmetki, Smetka *poknasmetki) {
        postaviklient(imeiprezime, adresa, embg, brojnasmetki, poknasmetki);
    }

    Klient(string imeiprezime, string adresa, long long embg, int brojnasmetki, Smetka *poknasmetki, string imenabanka,
           string adresanabanka) : Banka(imenabanka, adresanabanka) {
        postaviklient(imeiprezime, adresa, embg, brojnasmetki, poknasmetki);
    }

    void postaviklient(string imeiprezime, string adresa, long long embg, int brojnasmetki, Smetka *poknasmetki) {
        this->imeiprezime = imeiprezime;
        this->adresa = adresa;
        this->embg = embg;
        this->brojnasmetki = brojnasmetki;
        this->poknasmetki = poknasmetki;
        for (int i = 0; i < brojnasmetki; i++) {
            this->poknasmetki[i] = poknasmetki[i];
        }
    }

    void zemiklient(string &imeiprezime, string &adresa, long long &embg, int &brojnasmetki, Smetka *poknasmetki) {
        imeiprezime = this->imeiprezime;
        adresa = this->adresa;
        embg = this->embg;
        brojnasmetki = this->brojnasmetki;
        poknasmetki = this->poknasmetki;
        for (int i = 0; i < brojnasmetki; i++) {
            poknasmetki[i] = this->poknasmetki[i];
        }
    }

    void postavismetki(Smetka *poknasmetki) {
        this->poknasmetki = poknasmetki;
        for (int i = 0; i < brojnasmetki; i++) {
            this->poknasmetki[i] = poknasmetki[i];
        }
    }

    void prikazhiklient() {
        cout << "\n" << left << setw(24) << imeiprezime << setw(24) << adresa << " EMBG: " << setw(14) << embg
             << "Smetki:" << brojnasmetki << endl;
        cout << "------------------------------------------------------------------------------------------------" << endl;
        double vkupnakamata = 0;
        for (int smetka = 0; smetka < brojnasmetki; smetka++) {
            cout << " Smetka: " << smetka + 1 << ": ";
            poknasmetki[smetka].prikazhismetka();
            cout << " Kamata: " << right << setw(12) << poknasmetki[smetka].zemikamata() << endl;
            vkupnakamata += poknasmetki[smetka].zemikamata();
        }
        cout << "------------------------------------------------------------------------------------------------" << endl;
        cout << setw(68) << "Vkupna kamata: " << right << setw(10) << vkupnakamata << endl;
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

int main() {
    string vlez;
    string imenabanka;
    string adresanabanka;
    cout << "Vnesete podatoci za bankata" << endl;
    cout << " Banka: ";
    getline(cin, imenabanka);
    cout << " Adresa: ";
    getline(cin, adresanabanka);
    Banka mojabanka(imenabanka, adresanabanka);

    Klient *klienti[100];
    Smetka smetki[100][10];
    Smetka *poknasmetki[100];
    for (int i = 0; i < 100; i++)
        poknasmetki[i] = smetki[i];

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
        cout << "\nVnesete podatoci za " << i + 1 << "-ot klient" << endl;
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
        brojnasmetki=stoi(vlez);
        cout << "Vnesete gi smetkite: " << endl;
        double saldo;
        for (int smetka = 0; smetka < brojnasmetki; smetka++) {
            cout << " Smetka " << smetka + 1 << ":";
            do {
                cout << " Broj na smetka(morat 15 cifri) : ";
                getline(cin, vlez);
                smetkabroj = stoll(vlez);
            } while (brojcifri(smetkabroj) != 15);
            cout << " Saldo: ";
            getline(cin, vlez);
            saldo=stod(vlez);
            poknasmetki[i][smetka] = {smetkabroj, saldo};
        }
        klienti[i] = new Klient(imeiprezime, adresa, embg, brojnasmetki, poknasmetki[i]);
    }
    system("CLS");
    mojabanka.prikazhibanka();
    for (int i = 0; i < brojnaklienti; i++) {
        cout << "\nKlient " << i + 1 << ": ";
        klienti[i]->prikazhiklient();
    }
    cout << endl;
    system("PAUSE");
    return 0;
}
