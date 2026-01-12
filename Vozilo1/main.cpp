#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Prozor {
public:
    Prozor() {

    }

    void zatvoriprozor() {
        cout << "\tZatvorete go prozorot." << endl;
    }

    void otvoriprozor() {
        cout << "\tOtvorete go prozorot." << endl;
    }
};

class Vrata {
private:
    Prozor prozor;
public:
    Vrata() {

    }

    Vrata(Prozor prozor) {
        this->prozor = prozor;
    }

    void izleguvanje() {
        prozor.zatvoriprozor();
        otvorivrata();
        cout << "\tIzlezete." << endl;
        zatvorivrata();
    }

    void vleguvanje() {
        otvorivrata();
        cout << "\tVlezete:" << endl;
        zatvorivrata();
        prozor.otvoriprozor();
    }

    void otvorivrata() {
        cout << "\tOtvorete ja vratata." << endl;
    }

    void zatvorivrata() {
        cout << "\tZatvorete ja vratata" << endl;
    }
};

class Trkalo {
private:
    string marka;
    int dimenzija;
    double atmosferi;
public:
    Trkalo() {

    }

    Trkalo(string marka, int dimenzija, double atmosferi) {
        this->marka = marka;
        this->dimenzija = dimenzija;
        this->atmosferi = atmosferi;
    }

    double zemiatmosferi() {
        return atmosferi;
    }

    void proveritrkalo(double atmosferi) {
        cout << "Proverete go trkaloto na " << atmosferi << " atmosferi." << endl;
    }

    void prikazhitrkalo() {
        cout << "Trkalo: " << endl;
        cout << "\t Marka:" << marka << endl;
        cout << "\t Dimenzija: " << dimenzija << endl;
        cout << "\tAtmosferi: " << atmosferi << endl;
    }
};

class Motor {
private:
    string tip;
    int jachina;
public:
    Motor() {

    }

    Motor(string tip, int jachina) {
        this->tip = tip;
        this->jachina = jachina;
    }

    void startuvaj() {
        cout << "\tGo startuvam motorot." << endl;
    }

    void iskluchi() {
        cout << "\tGo iskluchuvam motorot" << endl;
    }

    void gorivo() {
        cout << "\tProverete gorivo" << endl;
    }

    void antifriz() {
        cout << "\tProverete ja technosta za ladenje." << endl;
    }

    void prikazhiMotor() {
        cout << "Motor: " << endl;
        cout << "\tTip: " << tip << endl;
        cout << "\tJachina: " << jachina << endl;
    }
};

class Vozilo {
    friend void proverkanavozilo(Vozilo);

    friend void vleguvanje(Vozilo);

    friend void vozenje(Vozilo);

    friend void izleguvanje(Vozilo);

private:
    string marka;
    string tip;
    string boja;
    int brojnavrati;
    Motor motor;
    Trkalo trkala[4];
    Vrata vrati[5];
public:
    Vozilo() {

    }

    Vozilo(string marka, string tip, string boja, int brojnavrati, Motor motor, Trkalo trkala[], Vrata vrati[]) {
        this->marka = marka;
        this->tip = tip;
        this->boja = boja;
        this->brojnavrati = brojnavrati;
        this->motor = motor;
        for (int i = 0; i < 4; i++)
            this->trkala[i] = trkala[i];
        for (int i = 0; i < brojnavrati; i++)
            this->vrati[i] = vrati[i];
    }

    void vozi() {
        cout << "\tVozam." << endl;
        cout << "\tBrrrr :) Brrrr :) Brrrr :)" << endl;
    }

    void zastani() {
        cout << "\tZastanuvam." << endl;
    }

    void prikazhivozilo() {
        cout << "Karakteristiki na voziloto" << endl;
        cout << "\tMarka: " << marka << endl;
        cout << "\tTip: " << tip << endl;
        cout << "\tBoja: " << boja << endl;
        cout << "\tVrati" << brojnavrati << endl;
        motor.prikazhiMotor();
        trkala[0].prikazhitrkalo();
    }

    void proverkanavozilo(Vozilo moevozilo) {
        cout << "\nProverka na voziloto: " << endl;
        double atmosferi = moevozilo.trkala[0].zemiatmosferi();
        for (int i = 0; i < moevozilo.brojnavrati; i++) {
            cout << "\t Trkalo" << i + 1 << ": ";
            moevozilo.trkala[i].proveritrkalo(atmosferi);
        }
        moevozilo.motor.gorivo();
        moevozilo.motor.antifriz();
    }

    void vleguvanje(Vozilo moevozilo) {
        cout << "\nVleguvanje vo voziloto: " << endl;
        for (int i = 0; i < moevozilo.brojnavrati - 1; i++) {
            cout << "\nVrata" << i + 1 << ": \n";
            moevozilo.vrati[i].vleguvanje();
        }
    }

    void vozenje(Vozilo moevozilo) {
        cout << "\nVozenje: " << endl;
        moevozilo.motor.startuvaj();
        moevozilo.vozi();
        moevozilo.zastani();
        moevozilo.motor.iskluchi();
    }

    void izleguvanje(Vozilo moevozilo) {
        cout << "\nIzleguvanje ot voziloto: " << endl;
        for (int i = 0; i < moevozilo.brojnavrati - 1; i++) {
            cout << "\nVrata" << i + 1 << ": \n";
            moevozilo.vrati[i].izleguvanje();
        }

    }
};

int main() {
    string kolamarka, kolatip, kolaboja, motortip;
    int motorjachina;
    string trkalomarka;
    int trkalodimenzija;
    double trkaloatmosferi;
    int brojnavrati;
    cout << "Vnesete podatoci za kolata: " << endl;
    cout << "\tMarka: ";
    cin >> kolamarka;
    cout << "\tTip: ";
    cin >> kolatip;
    cout << "\nBoja:";
    cin >> kolaboja;
    cout << "\tBroj na vrati: ";
    cin >> brojnavrati;

    cout << "Vnesete podatoci za motorot: " << endl;
    cout << "\tTip: ";
    cin >> motortip;
    cout << "\tJachina: ";
    cin >> motorjachina;
    Motor motor(motortip, motorjachina);

    cout << "Vnesete podatoci za trkalata: " << endl;
    cout << "\tMarka: ";
    cin >> trkalomarka;
    cout << "\tDimenzija: ";
    cin >> trkalodimenzija;
    cout << "\tAtmosferi: ";
    cin >> trkaloatmosferi;
    Trkalo trkala[4];
    for (int i = 0; i < 4; i++) {
        trkala[i] = {trkalomarka, trkalodimenzija, trkaloatmosferi};
    }
    Prozor prozor;
    Vrata vrati[5];
    for (int i = 0; i < brojnavrati; i++) {
        vrati[i] = {prozor};
    }
    Vozilo moevozilo(kolamarka, kolatip, kolaboja, brojnavrati, motor, trkala, vrati);

    system("CLS");

    moevozilo.prikazhivozilo();
    moevozilo.proverkanavozilo(moevozilo);
    moevozilo.vleguvanje(moevozilo);
    moevozilo.vozenje(moevozilo);
    moevozilo.izleguvanje(moevozilo);

    cout << endl << endl;
    system("PAUSE");
    return 0;
}





























