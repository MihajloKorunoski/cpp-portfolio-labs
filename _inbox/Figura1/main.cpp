#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Figura {
private:
    string boja;
public:
    Figura() = default;

    Figura(string boja) {
        this->boja = boja;
    }

    string zemiboja() {
        return boja;
    }

    virtual ~Figura() = default;

    virtual void crtanjefigura(string boja) = 0;
};

class FiguraKvadrat : public Figura {
private:
    int strana;
public:
    FiguraKvadrat() = default;

    FiguraKvadrat(int strana, string boja) : Figura(boja) {
        this->strana = strana;
    }

    virtual ~FiguraKvadrat() = default;

    virtual void crtanjefigura(string boja) {
        cout << "\nCrtanje kvadrat so strana " << strana << " i boja: " << boja << endl;
        for (int i = 1; i <= strana; i++) {
            for (int j = 1; j <= strana; j++)
                cout << "* ";
            cout << endl;
        }
    }
};

class FiguraKrug : public Figura {
private:
    int radius;
public:
    FiguraKrug() = default;

    FiguraKrug(int radius, string boja) : Figura(boja) {
        this->radius = radius;
    }

    virtual ~FiguraKrug() = default;

    virtual void crtanjefigura(string boja) {
        cout << "\nCrtanje kurg so radius " << radius << " i boja: " << boja << endl;
        int m[10] = {9, 6, 4, 3, 2, 2, 1, 1, 1, 0};
        for (int i = 0; i < radius; i++) {
            cout << setw(m[i]) << "";
            for (int j = 1; j <= 2 * (radius - m[i]); j++)
                cout << "*";
            cout << endl;
        }
        for (int i = 0; i < radius; i++) {
            cout << setw(m[9 - i]) << "";
            for (int j = 1; j <= 2 * (radius - m[9 - i]); j++)
                cout << "*";
            cout << endl;
        }
    }
};

class FiguraRamnostranTriagolnik : public Figura {
private:
    int strana;
public:
    FiguraRamnostranTriagolnik() = default;

    FiguraRamnostranTriagolnik(int strana, string boja) : Figura(boja) {
        this->strana = strana;
    }

    virtual ~FiguraRamnostranTriagolnik() = default;

    virtual void crtanjefigura(string boja) {
        cout << "\nCrtanje ramnostran triagolnik so strana " << strana << " i boja: " << boja << endl;
        for (int i = 1; i <= strana; i++) {
            cout << setw(strana - i) << "";
            for (int j = 1; j <= i; j++) {
                cout << "* ";
            }
            cout << endl;
        }
    }
};

int main() {
    const int BROJ_FIGURI = 3;
    FiguraKvadrat K(10, "sina");
    FiguraKrug R(10, "chervena");
    FiguraRamnostranTriagolnik T(10, "zelena");

    Figura *figuri[BROJ_FIGURI];
    figuri[0] = &K;
    figuri[1] = &R;
    figuri[2] = &T;
    for (Figura *f : figuri) {
        f->crtanjefigura(f->zemiboja());
    }
    cout << endl;
    system("PAUSE");
    return 0;
}
