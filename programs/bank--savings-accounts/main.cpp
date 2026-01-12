#include <iostream>
#include <string>
#include <iomanip>
#include <exception>
#include <typeinfo>

using namespace std;

class Bankarskasmetka {
private:
    string banka;
    long long smetka;
    double depozit;
    static double kamatnastapka;
public:
    Bankarskasmetka() {
        banka = "";
        smetka = 0;
        depozit = 0;
    }

    Bankarskasmetka(string banka, long long smetka, double depozit) {
        postavibankarskasmetka(banka, smetka, depozit);
    }

    void postavibankarskasmetka(string banka, long long smetka, double depozit) {
        this->banka = banka;
        this->smetka = smetka;
        this->depozit = depozit;
    }

    void zemibankarskasmetka(string &banka, long long &smetka, double &depozit) {
        banka = this->banka;
        smetka = this->smetka;
        depozit = this->depozit;
    }

    static void postavikamatnastapka(double kstapka) {
        kamatnastapka = kstapka;
    }

    double zemikamata() {
        return depozit * kamatnastapka / 100;
    }

    void prikazhibankarskasmetka() {
        cout << left << setw(12) << banka << setw(15) << smetka <<
             right << fixed << setprecision(2) << setw(15) << depozit << setw(12) << kamatnastapka;
    }
};

double Bankarskasmetka::kamatnastapka = 0;

class Shtedach : public Bankarskasmetka {
private:
    string imeiprezime;
    string adresa;
    long long embg;
public:
    Shtedach() {
        imeiprezime = "";
        adresa = "";
        embg = 0;
    }

    Shtedach(string imeiprezime, string adresa, long long embg, string banka, long long smetka, double depozit)
            : Bankarskasmetka(banka, smetka, depozit) {
        postavishtedach(imeiprezime, adresa, embg);
    }

    void postavishtedach(string imeiprezime, string adresa, long long embg) {
        this->imeiprezime = imeiprezime;
        this->adresa = adresa;
        this->embg = embg;
    }

    void zemishtedach(string &imeiprezime, string &adresa, long long &embg) {
        imeiprezime = this->imeiprezime;
        adresa = this->adresa;
        embg = this->embg;
    }

    void prikazhishtedach() {
        cout << "\n" << left << setw(24) << imeiprezime << setw(24) << adresa << " EMBG: " << setw(14) << embg;
    }
};

int brojcifri(long long embg) {
    int n = 0;
    while (embg > 0) {
        embg = embg / 10;
        n++;
    }
    return n;
}

bool iminja(string ime) {
    bool da = false;
    if (ime.compare("NLB") == 0 || ime.compare("STB") == 0 || ime.compare("KB") == 0) {
        da = true;
    }
    return da;
}


int main() {
    string vlez;
    string imeiprezime;
    string adresa;
    long long embg;
    Shtedach shtedachi[100];
    int brojnashtedachi;
    bool greshka = true;
    do {
        try {
            cout << "Vnesete broj na shtedachi: ";
            getline(cin, vlez);
            if (!(brojnashtedachi = stoi(vlez)))
                throw bad_typeid();
            if (brojnashtedachi <= 0)
                throw brojnashtedachi;
            greshka = false;
        } catch (exception &e) {
            cout << "\n\t Greshka: Pogreshna vrednost. " << e.what()
                 << "\n\t Tip: " << typeid(e).name() << endl;
        } catch (int &e) {
            cout << "\n\t Greshka: Nemate shtedachi? " << "Vnesovte " << e << " shtedachi."
                 << "\n\t Tip: " << typeid(e).name() << endl;
        }
    } while (greshka);
    cout << "Vnesete gi shtedachite: " << endl;
    greshka = true;
    do {
        try {
            for (int shtedach = 0; shtedach < brojnashtedachi; shtedach++) {
                cout << "\nShtedach " << shtedach + 1 << ":" << endl;
                cout << " Ime i prezime: ";
                getline(cin, imeiprezime);
                if (imeiprezime.length() == 0)
                    throw length_error(imeiprezime);
                cout << " Adresa: ";
                getline(cin, adresa);
                if (adresa.length() == 0)
                    throw length_error(adresa);
                cout << " EMBG (mora 13 cifri) : ";
                getline(cin, vlez);
                if (vlez.length() == 0) throw length_error(vlez);
                embg = stoll(vlez);
                if (brojcifri(embg) != 13)
                    throw embg;
                shtedachi[shtedach] = {imeiprezime, adresa, embg, "", 0, 0};
            }
            greshka = false;
        } catch (exception &e) {
            cout << "\n\t Greshka: Nema string. Vnesete ponovo." << e.what() << "\n\t Tip: " << typeid(e).name()
                 << endl;
        } catch (long long &e) {
            cout << "\n\t Greshka: Pogreshen embg= " << e << ". EMBG mora da ima 13 cifri." << "\n\t Tip: "
                 << typeid(e).name() << endl;
        }
    } while (greshka);

    string banka;
    long long smetka;
    double depozit;
    Bankarskasmetka *smetki[100][5];
    int brojnasmetki[100];
    cout << "\nVnesete gi smetkite za shtedachite" << endl;
    greshka = true;
    do {
        try {
            for (int shtedach = 0; shtedach < brojnashtedachi; shtedach++) {
                cout << "\nShtedach " << shtedach + 1 << ": ";
                cout << "Broj na smetki - ";
                getline(cin, vlez);
                if (vlez.length() == 0)
                    throw length_error(vlez);
                if (!(brojnasmetki[shtedach] = stoi(vlez)))
                    throw bad_typeid();
                if (brojnasmetki[shtedach] <= 0)
                    throw brojnasmetki[shtedach];
                for (int smetka1 = 0; smetka1 < brojnasmetki[shtedach]; smetka1++) {
                    cout << "\nSmetka: " << smetka1 + 1 << ": " << endl;
                    do {
                        cout << " Banka (NLB,STB,KB): ";
                        getline(cin, banka);
                        if(banka.length()==0)
                            throw length_error(banka);
                    } while (!iminja(banka));
                    cout << " Broj na smetka(mora 15 cifri) :";
                    getline(cin, vlez);
                    if (vlez.length() == 0)
                        throw length_error(vlez);
                    smetka = stoll(vlez);
                    if (brojcifri(smetka) != 15)
                        throw smetka;
                    cout << " Depozit: ";
                    getline(cin, vlez);
                    if (!(depozit = stod(vlez)))
                        throw bad_typeid();
                    if (depozit < 0)
                        throw depozit;
                    shtedachi[shtedach].zemishtedach(imeiprezime, adresa, embg);
                    smetki[shtedach][smetka1] = new Shtedach(imeiprezime, adresa, embg, banka, smetka, depozit);
                }
            }
            greshka = false;
        } catch (exception &e) {
            cout << "\n\t Greshka: Nema string. Vnesete povtorno." << e.what() << "\n\t Tip: " << typeid(e).name()
                 << endl;
        } catch (long long &e) {
            cout << "\n\t Greshka: Pogreshna smetka: " << e << ". Mora da ima 15 cifri. " << "\n\t Tip: "
                 << typeid(e).name() << endl;
        } catch (double &e) {
            cout << "\n\t Greshka: Negativna vrednost: " << e << ". Vnesete povtorno." << "\n\t Tip: "
                 << typeid(e).name() << endl;
        } catch (int &e) {
            cout << "\n\t Greshka: Negativna vrednost: " << e << ". Vnesete povtorno." << "\n\t Tip: "
                 << typeid(e).name() << endl;
        }
    } while (greshka);

    double kamatnastapkanlb, kamatnastapkastb, kamatnastapkakb;
    greshka=true;
    do{
        try{
            cout << "Vnesete kamatni stapki: " << endl;
            cout << "NLB: ";
            getline(cin,vlez);
            if(!(kamatnastapkanlb=stod(vlez)))
                throw bad_typeid();
            if(kamatnastapkanlb<0)
                throw kamatnastapkanlb;
            cout << "STB: ";
            if(!(kamatnastapkastb=stod(vlez)))
                throw bad_typeid();
            if(kamatnastapkastb<0)
                throw kamatnastapkastb;
            cout << "KB: ";
            if(!(kamatnastapkakb=stod(vlez)))
                throw bad_typeid();
            if(kamatnastapkakb<0)
                throw kamatnastapkakb;
            greshka=false;
        } catch (exception &e){
            cout<<"\n\t Greshka: Pogreshna vrednost. "<<e.what()<<"\n\t TIp: "<< typeid(e).name()<<endl;
        } catch (double &e) {
            cout<<"\n\t Greshka: Negativna kamata??? " << "Vnesete "<<e <<"."<<"\n\t Tip: "<<typeid(e).name()<<endl;
        }
    } while(greshka);


    for (int shtedach = 0; shtedach < brojnashtedachi; shtedach++) {
        cout << "\nShtedach " << shtedach + 1 << ": ";
        shtedachi[shtedach].prikazhishtedach();
        cout << "Smetki: " << brojnasmetki[shtedach] << endl;
        cout << "------------------------------------------------------------------------------------" << endl;
        cout << " R.b." << setw(15) << "   Banka" << setw(15) << "Smetka" << right << setw(15) << "Depozit" << setw(12)
             << "Kam.Stapka" << setw(15) << "Kamata" << endl;
        cout << "------------------------------------------------------------------------------------" << endl;
        double vkupnokamata = 0;
        for (int smetka1 = 0; smetka1 < brojnasmetki[shtedach]; smetka1++) {
            cout << setw(5) << right << smetka1 + 1 << "     ";
            smetki[shtedach][smetka1]->zemibankarskasmetka(banka, smetka, depozit);
            if (banka.compare("NLB") == 0)
                Bankarskasmetka::postavikamatnastapka(kamatnastapkanlb);
            if (banka.compare("STB") == 0)
                Bankarskasmetka::postavikamatnastapka(kamatnastapkastb);
            if (banka.compare("KB") == 0)
                Bankarskasmetka::postavikamatnastapka(kamatnastapkakb);
            smetki[shtedach][smetka1]->prikazhibankarskasmetka();
            cout << right << fixed << setprecision(2) << setw(15) << smetki[shtedach][smetka1]->zemikamata() << endl;
            vkupnokamata += smetki[shtedach][smetka1]->zemikamata();
        }
        cout << "------------------------------------------------------------------------------------" << endl;
        cout << setw(62) << "Vkupna kamata: " << right << setw(15) << vkupnokamata << endl;
    }
    cout << endl;
    system("PAUSE");
    return 0;
}



















