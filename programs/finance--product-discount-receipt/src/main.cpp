#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

string pechatenjebroj(double);

class TransakciskaSmetka {
    friend string pechatenjebroj(double);

private:
    long long brojnasmetka;
    double saldo;
public:
    TransakciskaSmetka(long long brojnasmetka = 0, double saldo = 0) {
        this->brojnasmetka = brojnasmetka;
        this->saldo = saldo;
    }

    long long zemibrojnasmetka() {
        return brojnasmetka;
    }

    void uplatinasmetka(double suma) {
        this->saldo += suma;
    }

    double isplatiotsmetka(double suma) {
        if (saldo > suma) {
            saldo -= suma;
            return suma;
        } else return 0;
    }

    double zemisaldo() {
        return saldo;
    }

    void prikazhismetka() {
        cout << "Smetka broj " << brojnasmetka << ", saldo:"
             << pechatenjebroj(zemisaldo()) << " denari." << endl;
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
    if (cifri > 3 && cifri <= 6) {
        iljadi = vkupno.substr(0, cifri - 3);
        edinici = vkupno.substr(cifri - 3, 3);
        brojstring += iljadi + "." + edinici;
    }
    if (cifri <= 3) {
        brojstring += vkupno.substr();
    }
    return brojstring + decimali;
}

class Produkt : TransakciskaSmetka {
private:
    string shifra;
    string imenaproduktot;
    double cena;
    double kolichina;
    int popust;
    static int opshtpopust;
public:
    Produkt() {
        shifra = "";
        imenaproduktot = "";
        cena = 0;
        kolichina = 0;
    }

    Produkt(string shifra, string imenaproduktot, double cena, double kolichina, int popust, long long brojnasmetka,
            double saldo)
            : TransakciskaSmetka(brojnasmetka, saldo) {
        postaviprodukt(shifra, imenaproduktot, cena, kolichina, popust);
    }

    void postaviprodukt(string shifra, string imenaproduktot, double cena, double kolichina, int popust) {
        this->shifra = shifra;
        this->imenaproduktot = imenaproduktot;
        this->cena = cena;
        this->kolichina = kolichina;
        this->popust = popust;
    }

    void zemiprodukt(string &shifra, string &imenaproduktot, double &cena, double &kolichina, int &popust) {
        shifra = this->shifra;
        imenaproduktot = this->imenaproduktot;
        cena = this->cena;
        kolichina = this->kolichina;
        popust = this->popust;
    }

    static double zemiopshtpopust() {
        return opshtpopust;
    }

    void prikazhiprodukt() {
        cout << left << setw(6) << shifra << setw(20) << imenaproduktot << right << setw(10) << setprecision(2) << fixed
             << cena << setw(10) << kolichina << setw(10) << opshtpopust << "%" << setw(10) << popust << "%";
    }
};

int Produkt::opshtpopust = 2;

const int redici = 6;
const int koloni = 3;

const string shifri[redici][koloni] = {
        {"A111", "Leb",                "0"},
        {"A112", "Mleko",              "5"},
        {"B111", "Pasta",              "5"},
        {"B112", "Krema",              "5"},
        {"C111", "Vino",               "10"},
        {"C112", "Mastika strumichka", "15"}
};

int main() {
    long long brojnasmetka;
    double saldo;
    string shifra;
    string imenaprodukt;
    double cena;
    double kolichina;
    int popust;
    int brojprodukti;
    Produkt produkti[100];
    string input;

    cout << "Vnesete podatoci" << endl;
    cout << "Transakciska smetka: ";
    getline(cin, input);
    brojnasmetka = stoll(input);
    cout<<"Saldo: ";
    getline(cin,input);
    saldo=stod(input);
    TransakciskaSmetka moja(brojnasmetka, saldo);

    cout << "Kolku produkti(<=6)? ";
    getline(cin, input);
    brojprodukti = stoi(input);
    for (int i = 0; i < brojprodukti; i++) {
        cout << "\nProdukt " << i + 1 << endl;
        int j;
        bool nema = true;
        while (nema) {
            cout << "Shifra na produktot(A111, A112, B111, B112, C111, C112): ";
            getline(cin, shifra);
            j = 0;
            while ((j < redici) && (shifra.compare(shifri[j][0]) != 0)) {
                j++;
            }
            if (j < redici)
                nema = false;
        }
        imenaprodukt = shifri[j][1];
        popust = stoi(shifri[j][2]);
        cout << "\t" << imenaprodukt << endl;
        cout << " Cena: ";
        getline(cin, input);
        cena = stod(input);
        cout << " Kolichina: ";
        getline(cin, input);
        kolichina = stod(input);

        produkti[i] = {shifra, imenaprodukt, cena, kolichina, popust, brojnasmetka, saldo};
    }
    cout << "\n\t\t\t\tPRODUKTI:" << endl;
    cout << "-----------------------------------------------------------------------------------------" << endl;
    cout << left << setw(6) << "Shifra" << setw(20) << "Produkt"
         << setw(10) << "       Cena" << setw(10) << "   Kolichina" << setw(10) << "       Opsht  " << setw(10)
         << "    Popust" << "    Vkupno" << endl;
    cout << "--------------------------------------------------------popust---------------------------" << endl;
    double vkupno;
    double zaplakjanje = 0;
    for (int i = 0; i < brojprodukti; i++) {
        produkti[i].zemiprodukt(shifra, imenaprodukt, cena, kolichina, popust);
        int j = -1;
        do {
            j++;
        } while (shifra.compare(shifri[j][0]) != 0);
        popust = stoi(shifri[j][2]);
        vkupno = cena * kolichina*(100 - (popust + Produkt::zemiopshtpopust())) / 100;
        produkti[i].prikazhiprodukt();
        cout<<setw(10)<<right<<pechatenjebroj(vkupno)<<endl;
        zaplakjanje+=vkupno;
    }
    cout << "-----------------------------------------------------------------------------------------" << endl;
    cout << "Za plakjanje-----------------------------------------------------------------------------" << endl;
    cout<<setw(10)<<right<<pechatenjebroj(zaplakjanje)<<endl;
    cout<<endl;
    moja.prikazhismetka();
    if(moja.isplatiotsmetka(zaplakjanje)!=0)
        cout<<"\tUSPESHNA NAPLATA!"<<endl;
    else
        cout<<"\tNEUSPESHNA NAPLATA: nema dovolno pari na smetkata!"<<endl;
    moja.prikazhismetka();

    cout<<endl;
    system("PAUSE");
    return 0;
}










