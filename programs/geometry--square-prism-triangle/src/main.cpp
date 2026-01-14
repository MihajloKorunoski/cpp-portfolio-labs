#include <iostream>
#include<string>
#include<cmath>

using namespace std;

class GeometriskaFigura {
private:
    string boja;
public:
    GeometriskaFigura() {
        boja = "";
    }

    GeometriskaFigura(string boja) {
        postaviboja(boja);
    }

    void postaviboja(string boja) {
        this->boja = boja;
    }

    virtual void prikazhiobjekt() = 0;

    string prikazhiboja() {
        if (boja.compare("") != 0)
            return boja;
        else
            return "cherno-bela";
    }
};

class Pravoagolnik : public GeometriskaFigura {
private:
    double dolzhina;
    double shirina;
public:
    Pravoagolnik();

    Pravoagolnik(double, double, string);

    void postavistrani(double, double);

    double zemidolzhina();

    double zemishirina();

    double zemiobikolka();

    double zemiploshtina();

    double zemidijagonala();

    void prikazhiobjekt();
};

Pravoagolnik::Pravoagolnik() : GeometriskaFigura() {
    dolzhina = 0;
    shirina = 0;
}

Pravoagolnik::Pravoagolnik(double dolzhina, double shirina, string boja) : GeometriskaFigura(boja) {
    postavistrani(dolzhina, shirina);
}

void Pravoagolnik::postavistrani(double dolzhina, double shirina) {
    this->dolzhina = dolzhina;
    this->shirina = shirina;
}

double Pravoagolnik::zemidolzhina() {
    return dolzhina;
}

double Pravoagolnik::zemishirina() {
    return shirina;
}

double Pravoagolnik::zemiobikolka() {
    return 2 * (zemidolzhina() + zemishirina());
}

double Pravoagolnik::zemiploshtina() {
    return zemidolzhina() * zemishirina();
}

double Pravoagolnik::zemidijagonala() {
    return sqrt(pow(zemidolzhina(), 2) + pow(zemishirina(), 2));
}

void Pravoagolnik::prikazhiobjekt() {
    cout << " Dolzhina:      " << zemidolzhina() << endl;
    cout << " Shirina:       " << zemishirina() << endl;
}

class Kvadrat : public Pravoagolnik {
private:
public:
    Kvadrat();

    Kvadrat(double, string);

    double zemidijagonala();

    void prikazhiobjekt();
};

Kvadrat::Kvadrat() {

}

Kvadrat::Kvadrat(double strana, string boja) : Pravoagolnik(strana, strana, boja) {

}

double Kvadrat::zemidijagonala() {
    return zemidolzhina() * sqrt(2);
}

void Kvadrat::prikazhiobjekt() {
    cout << "\nKvadrat: " << endl;
    cout << " Strana:       " << zemidolzhina() << endl;
    cout << " Obikolka:     " << zemiobikolka() << endl;
    cout << " Ploshtina:    " << zemiploshtina() << endl;
    cout << " Dijagonala:   " << zemidijagonala() << endl;
    cout << " Boja:         " << prikazhiboja() << endl;
    cout << endl;
}

class Kvadratnaprizma : public Kvadrat {
private:
    double visina;
public:
    Kvadratnaprizma();

    Kvadratnaprizma(double, double, string);

    double zemivisina();

    double zemipovrshinaprizma();

    double zemivolumenprizma();

    double zemidijagonalaprizma();

    void prikazhiobjekt();
};

Kvadratnaprizma::Kvadratnaprizma() {

}

Kvadratnaprizma::Kvadratnaprizma(double visina, double strana, string boja) : Kvadrat(strana, boja) {
    this->visina = visina;
}

double Kvadratnaprizma::zemivisina() {
    return visina;
}

double Kvadratnaprizma::zemipovrshinaprizma() {
    return 2 * zemiploshtina() + 4 * zemidolzhina() * zemivisina();
}

double Kvadratnaprizma::zemivolumenprizma() {
    return zemiploshtina() * zemivisina();
}

double Kvadratnaprizma::zemidijagonalaprizma() {
    double dijagonala = zemidijagonala();
    return sqrt(pow(zemivisina(), 2) + pow(dijagonala, 2));
}

void Kvadratnaprizma::prikazhiobjekt() {
    cout << "\nKvadratna prizma: " << endl;
    cout << " Strana:       " << zemidolzhina() << endl;
    cout << " Visina:       " << zemivisina() << endl;
    cout << " Ploshina:     " << zemipovrshinaprizma() << endl;
    cout << " Volumen:      " << zemivolumenprizma() << endl;
    cout << " Dijagonala:   " << zemidijagonalaprizma() << endl;
    cout << " Boja:         " << prikazhiboja() << endl;
    cout << endl;
}

class PravoagolenTriagolnik : public Pravoagolnik {
private:
public:
    PravoagolenTriagolnik() = default;

    PravoagolenTriagolnik(double a, double b, string boja) : Pravoagolnik(a, b, boja) {
    }

    ~PravoagolenTriagolnik() = default;

    void prikazhiobjekt() {
        cout << "\nPravoagolen triagolnik:" << endl;
        cout << " Strani:       a=" << zemidolzhina() << ", b=" << zemishirina() << ", c=" << zemidijagonala() << endl;
        cout << " Obikolka:     " << zemiobikolka() / 2 + zemidijagonala() << endl;
        cout << " Ploshtina:    " << zemiploshtina() / 2 << endl;
        cout << " Boja:         " << prikazhiboja() << endl;
        cout << endl;
    }
};

int main() {

    const int BROJ_FIGURI = 3;

    double a;
    string boja;
    cout << "Vnesete ja stranata na kvadratot: ";
    cout << "a=";
    cin >> a;
    cout << "Vnesete ja bojata na figurata(N-nema):";
    cin >> boja;
    if (boja.compare("N") == 0)
        boja = "";
    Kvadrat kvadrateden(a, boja);

    double H;
    cout << "Vnesete ja stranata na prizmata: ";
    cout << "a=";
    cin >> a;
    cout << "Vnesete ja visinata: ";
    cout << "H=";
    cin >> H;
    cout << "Vnesete ja bojata na figurata(N-nema):";
    cin >> boja;
    if (boja.compare("N") == 0)
        boja = "";
    Kvadratnaprizma kvadratnaprizma(H, a, boja);

    double b;
    cout << "Vnesete gi katetite na pravoagolen triagolnik: \n";
    cout << "a=";
    cin >> a;
    cout << "b=";
    cin >> b;
    cout << "Vnesete ja bojata na figurata(N-nema):";
    cin >> boja;
    if (boja.compare("N") == 0)
        boja = "";
    PravoagolenTriagolnik pravoagolenTriagolnik(a, b, boja);
    GeometriskaFigura *figuri[BROJ_FIGURI];
    figuri[0] = &kvadrateden;
    figuri[1] = &pravoagolenTriagolnik;
    figuri[2] = &kvadratnaprizma;

    for (GeometriskaFigura *figura : figuri)
        figura->prikazhiobjekt();

    cout << endl;
    system("PAUSE");
    return 0;
}

















