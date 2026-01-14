#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

class Vozilo {
private:
    string vid;
    string marka;
    string tip;
    int godina;
    int jachinanamotor;
public:
    Vozilo(string vid = "", string marka = "", string tip = "", int godina = 0, int jachinanamotor = 0) {
        postavivozilo(vid, marka, tip, godina, jachinanamotor);
    }

    ~Vozilo() {
    }

    void postavivozilo(string vid, string marka, string tip, int godina, int jachinanamotor) {
        this->vid = vid;
        this->marka = marka;
        this->tip = tip;
        this->godina = godina;
        this->jachinanamotor = jachinanamotor;
    }

    void zemivozilo(string &vid, string &marka, string &tip, int &godina, int &jachinanamotor) {
        vid = this->vid;
        marka = this->marka;
        tip = this->tip;
        godina = this->godina;
        jachinanamotor = this->jachinanamotor;
    }

    virtual void prikazhivozilo() {
        cout << endl;
        cout << left << setw(30) << " Vid: " << vid << endl;
        cout << setw(30) << " Marka: " << marka << endl;
        cout << setw(30) << " Tip: " << tip << endl;
        cout << setw(30) << " Godina: " << godina << endl;
        cout << setw(30) << " Motor(Kw): " << jachinanamotor << endl;
    }

    virtual void vozi() = 0;
};

class Avtomobil : public Vozilo {
private:
    int vrati;
    string boja;
    string gorivo;
    double potroshuvachka;
    int zabrzuvanje;
public:
    Avtomobil(int vrati = 0, string boja = "", string gorivo = "", double potroshuvachka = 0.0, int zabrzuvanje = 0,
              string vid = "", string marka = "", string tip = "", int godina = 0, int jachinanamotor = 0) : Vozilo(vid,
                                                                                                                    marka,
                                                                                                                    tip,
                                                                                                                    godina,
                                                                                                                    jachinanamotor) {
        postaviavtomobil(vrati, boja, gorivo, potroshuvachka, zabrzuvanje);
    }

    ~Avtomobil() {

    }

    void postaviavtomobil(int vrati, string boja, string gorivo, double potroshuvachka, int zabrzuvanje) {
        this->vrati = vrati;
        this->boja = boja;
        this->gorivo = gorivo;
        this->potroshuvachka = potroshuvachka;
        this->zabrzuvanje = zabrzuvanje;
    }

    void zemiavtomobil(int &vrati, string &boja, string &gorivo, double &potroshuvachka, int zabrzuvanje) {
        vrati = this->vrati;
        boja = this->boja;
        gorivo = this->gorivo;
        potroshuvachka = this->potroshuvachka;
        zabrzuvanje = this->zabrzuvanje;
    }

    virtual void prikazhivozilo() {
        Vozilo::prikazhivozilo();
        cout << left << setw(30) << " Vrati: " << vrati << endl;
        cout << setw(30) << " Boja: " << boja << endl;
        cout << setw(30) << " Gorivo: " << gorivo << endl;
        cout << setw(30) << " Potroshuvachka(1/100km): " << potroshuvachka << endl;
        cout << setw(30) << " Zabrzuvanje(sek->100km/h): " << zabrzuvanje << endl;
        cout << endl;
        Avtomobil::vozi();
    }

    virtual void vozi() {
        cout << "AVTOMOBIL\n Avtomobilot e vo ispravna sostojba. Mozhe probno vozenje. \n" << endl;
    }
};

class Motor : public Vozilo {
private:
    int zabrzuvanje;
    int maksbrzina;
public:
    Motor(int zabrzuvanje = 0, int maksbrzina = 0, string vid = "", string marka = "", string tip = "", int godina = 0,
          int jachinanamotor = 0) : Vozilo(vid, marka, tip, godina, jachinanamotor) {
        postavimotor(zabrzuvanje, maksbrzina);
    }

    ~Motor() {

    }

    void postavimotor(int zabrzuvanje, int maksbrzina) {
        this->zabrzuvanje = zabrzuvanje;
        this->maksbrzina = maksbrzina;
    }

    void zemimotor(int &zabrzuvanje, int &maksbrzina) {
        zabrzuvanje = this->zabrzuvanje;
        maksbrzina = this->maksbrzina;
    }

    virtual void prikazhivozilo() {
        Vozilo::prikazhivozilo();
        cout << left << setw(30) << " Zabrzuvanje (sek->100km/h): " << zabrzuvanje << endl;
        cout << setw(30) << " MaksBrzina(km/h): " << maksbrzina << endl;
        cout << endl;
        Motor::vozi();
    }

    virtual void vozi() {
        cout << "MOTOR\n Motorot e vo ispravna sostojba. Mozhe probno vozenje. \n" << endl;
    }
};

int main() {
    string vid;
    string marka;
    string tip;
    int godina;
    int jachinanamotor;
    int vrati;
    string boja;
    string gorivo;
    double potroshuvachka;
    int zabrzuvanje;
    int maxbrzina;
    Vozilo *pokvozila[2];
    ifstream voziladat("vozila.dat");
    if (!voziladat) {
        cout << "Nemat datoteka za vozila" << endl;
        exit(1);
    }
    string vlez;
    string ailim;
    int i = -1;
    while (true) {
        i++;
        getline(voziladat, ailim);
        if (ailim == "KRAJ")
            break;
        getline(voziladat, vid);
        getline(voziladat, marka);
        getline(voziladat, tip);
        getline(voziladat, vlez);
        godina = stoi(vlez);
        getline(voziladat, vlez);
        jachinanamotor = stoi(vlez);
        getline(voziladat, vlez);
        zabrzuvanje = stoi(vlez);
        if (ailim.compare("Avtomobil") == 0) {
            getline(voziladat, vlez);
            vrati = stoi(vlez);
            getline(voziladat, boja);
            getline(voziladat, gorivo);
            getline(voziladat, vlez);
            potroshuvachka = stod(vlez);
            pokvozila[i] = new Avtomobil(vrati, boja, gorivo, potroshuvachka, zabrzuvanje, vid, marka, tip, godina,
                                         jachinanamotor);
        }
        if (ailim.compare("Motor") == 0) {
            getline(voziladat, vlez);
            maxbrzina = stoi(vlez);
            pokvozila[i] = new Motor(zabrzuvanje, maxbrzina, vid, marka, tip, godina, jachinanamotor);
        }
        getline(voziladat, vlez);
    }
    voziladat.close();
    int brojvozila = i;

    system("CLS");
    cout << "\n\tVOZEN PARK:" << endl;
    int v;
    for (v = 0; v < brojvozila; v++) {
        cout << "\nVozilo " << v + 1 << " : ";
        pokvozila[v]->prikazhivozilo();
    }

    cout << endl;
    system("PAUSE");
    return 0;
}

















