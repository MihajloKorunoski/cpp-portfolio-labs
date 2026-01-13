#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Firma {
private:
    string imenafirma;
    string adresanafirma;
    static double vrednostnachas;
public:
    Firma() {
        imenafirma = "";
        adresanafirma = "";
    }

    Firma(string imenafirma, string adresanafirma) {
        postavifirma(imenafirma, adresanafirma);
    }

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
    }

    void prikazhifirma() {
        cout << left << setw(10) << " Firma: " << setw(20) << imenafirma << endl;
        cout << setw(10) << " Adresa: " << setw(15) << adresanafirma << endl;
        cout << "Vrednost na prekuvremen chas" << vrednostnachas << endl;
    }
};

double Firma::vrednostnachas = 300;

string pechatenjebroj(double);

class Transakciskasmetka {
    friend string pechatenjebroj(double);

private:
    long long brojnasmetka;
    double saldo;
public:
    Transakciskasmetka(long long brojnasmetka = 0, double saldo = 0) {
        this->brojnasmetka = brojnasmetka;
        this->saldo = saldo;
    }

    long long zemibrojnasmetka() {
        return brojnasmetka;
    }

    void uplatinasmetka(double suma) {
        this->saldo += suma;
    }

    double isplatiodsmetka(double suma) {
        if (saldo > suma) {
            saldo -= suma;
            return suma;
        } else return 0;
    }

    double zemisaldo() {
        return saldo;
    }

    void prikazhismetka() {
        cout << "Smetka broj " << brojnasmetka << ", saldo: " << pechatenjebroj(zemisaldo()) << " denari." << endl;
    }
};

string pechatenjebroj(double broj) {
    string milioni, iljadi, edinici;
    int e = (int) (100 * broj) % 10;
    int d = (int) (10 * broj) % 10;
    string decimali = "," + to_string(d) + to_string(e);
    string vkupno = to_string((int) broj);
    int cifri = vkupno.length();
    string brojstring = "";
    if (cifri > 6) {
        milioni = vkupno.substr(0, cifri - 6);
        iljadi = vkupno.substr(cifri - 6, 3);
        edinici = vkupno.substr(cifri - 3, 3);
        brojstring += milioni + "." + iljadi + "." + edinici;
    }
    if ((cifri > 3) && (cifri <= 6)) {
        iljadi = vkupno.substr(0, cifri - 3);
        edinici = vkupno.substr(cifri - 3, 3);
    }
    if (cifri <= 3) {
        brojstring += vkupno.substr();
    }
    return brojstring + decimali;
}

class Vraboten : public Firma, public Transakciskasmetka {
private:
    string imeiprezime;
    long long embg;
    double plata;
    int prekuvremenichasovi;
public:
    Vraboten() {
        imeiprezime = "";
        embg = 0;
        plata = 0.0;
        prekuvremenichasovi = 0;
    }

    Vraboten(string imeiprezime, long long embg, double plata, int prekuvremenichasovi, string imenafirma,
             string adresanafirma, long long brojnasmetka, double saldo = 0) : Firma(imenafirma, adresanafirma),
                                                                               Transakciskasmetka(brojnasmetka, saldo) {
        postavivraboten(imeiprezime, embg, plata, prekuvremenichasovi);
    }

    void postavivraboten(string imeiprezime, long long embg, double plata, int prekuvremenichasovi) {
        this->imeiprezime = imeiprezime;
        this->embg = embg;
        this->plata = plata;
        this->prekuvremenichasovi = prekuvremenichasovi;
    }

    void zemivraboten(string &imeiprezime, long long &embg, double &plata, int &prekuvremenichasovi) {
        imeiprezime = this->imeiprezime;
        embg = this->embg;
        plata = this->plata;
        prekuvremenichasovi = this->prekuvremenichasovi;
    }

    double zaisplata() {
        return plata + prekuvremenichasovi * Firma::zemivrednostnachas();
    }

    void prikazhivraboten() {
        cout << left << setw(20) << imeiprezime << right << setw(14) << embg << setw(10) << plata << setw(5) <<
             prekuvremenichasovi << setw(10) << zaisplata() << setw(16) << zemibrojnasmetka() << endl;
    }
};

int brojcifri(long long broj) {
    int n;
    for (n = 0; broj > 0; broj /= 10, n++) {
    }
    return n;
}

int main() {
    string input;
    string imenafirma;
    string adresanafirma;
    cout << "Vnesete podatoci za firmata" << endl;
    cout << " Firma: ";
    getline(cin, imenafirma);
    cout << " Adresa: ";
    getline(cin, adresanafirma);
    Firma mojafirma;
    mojafirma.postavifirma(imenafirma, adresanafirma);

    int brojvraboteni;
    cout << "Vneste broj na vraboteni: ";
    getline(cin, input);
    brojvraboteni = stoi(input);
    cout << "\nVnesete podatoci za vrabotenite: \n";
    string imeiprezime;
    long long embg;
    double plata;
    int prekuvremenichasovi;
    long long brojnasmetka;
    double saldo;
    Vraboten vraboteni[100];
    for (int vraboten = 0; vraboten < brojvraboteni; vraboten++) {
        cout << "Vraboten" << vraboten + 1 << ":" << endl;
        cout << " Ime i prezime: ";
        getline(cin, imeiprezime);
        do {
            cout << " EMBG(mora 13 cifri): ";
            getline(cin, input);
            embg = stoll(input);
        } while (brojcifri(embg) != 13);
        cout << " Plata: ";
        getline(cin, input);
        plata = stod(input);
        cout << " Prekuvremeni chasovi: ";
        getline(cin, input);
        prekuvremenichasovi = stoi(input);
        do {
            cout << " Broj na smetka(mora 15 cifri): ";
            getline(cin, input);
            brojnasmetka = stoll(input);
        } while (brojcifri(brojnasmetka) != 15);
        vraboteni[vraboten] = {imeiprezime, embg, plata, prekuvremenichasovi, imenafirma, adresanafirma, brojnasmetka,
                               saldo};
    }
    int vrednostnachas;
    cout << " Vrednost na prekuvremen chas: ";
    cin >> vrednostnachas;
    mojafirma.postavivrednostnachas(vrednostnachas);
    system("CLS");

    mojafirma.prikazhifirma();
    cout << "\n" << setw(4) << " " << setw(25) << "Ime i prezime" << setw(9) << "EMBG" << right << setw(10) << "Plata"
         << setw(5) << "Prek" << setw(10)<<"Vkupno"<<setw(10)<<"Smetka"<<endl;
    cout<<"--------------------------------------------------------------------------------------------"<<endl;
    double vkupnaisplata=0;
    for(int vraboten=0;vraboten<brojvraboteni;vraboten++){
        cout<<setw(2)<<vraboten+1<<": ";
        vraboteni[vraboten].prikazhivraboten();
        vkupnaisplata+=vraboteni[vraboten].zaisplata();
    }
    cout<<"--------------------------------------------------------------------------------------------"<<endl;
    cout<<setw(53)<<"Vkupno isplateno: "<<right<<setw(10)<<vkupnaisplata<<endl;

    cout<<endl;
    system("PAUSE");
    return 0;
}





















