#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

class Tochka2d {
private:
    double x;
    double y;
public:
    Tochka2d() {

    }

    Tochka2d(double x, double y) {
        this->x = x;
        this->y = y;
    }

    double zemix() {
        return x;
    }

    double zemiy() {
        return y;
    }
};

class Tochka3d {
private:
    double x;
    double y;
    double z;
public:
    Tochka3d() {

    }

    Tochka3d(double x, double y, double z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    double zemix() {
        return x;
    }

    double zemiy() {
        return y;
    }

    double zemiz() {
        return z;
    }
};

class Geometriskafigura {
private:
    string boja;
public:
    Geometriskafigura() {
        boja = "";
    }

    Geometriskafigura(string boja) {
        postaviboja(boja);
    }

    void postaviboja(string boja) {
        this->boja = boja;
    }

    string prikazhiboja() {
        if (boja.compare("") != 0)
            return boja;
        else
            return "cherno-bela";
    }

    virtual void prikazhigeometriskafigura() = 0;
};

class Geometriskafigura2d : public Geometriskafigura, public Tochka2d {
private:
public:
    Geometriskafigura2d() {

    }

    Geometriskafigura2d(string boja, double x, double y) : Geometriskafigura(boja), Tochka2d(x, y) {

    }

    ~Geometriskafigura2d() {

    }

    double zemiobikolka() {

    }

    double zemiploshtina() {

    }

    void prikazhigeometriskafigura() {
        cout << " Centar: O" << "(" << zemix() << ", " << zemiy() << ") Boja: " << prikazhiboja() << endl;

    }
};

class Geometriskafigura3d : public Geometriskafigura, public Tochka3d {
private:
public:

    Geometriskafigura3d() {

    }

    Geometriskafigura3d(string boja, double x, double y, double z) : Geometriskafigura(boja), Tochka3d(x, y, z) {

    }

    ~Geometriskafigura3d() {

    }

    double zemiobikolka() {

    }

    double zemiploshtina() {

    }

    void prikazhigeometriskafigura() {
        cout << " Centar: O" << "(" << zemix() << ", " << zemiy() << ", " << zemiz() << ") Boja: " << prikazhiboja()
             << endl;

    }
};

class Krug : public Geometriskafigura2d {
private:
    double radius;
public:
    Krug();

    Krug(double, string, double, double);

    void postaviradius(double);

    double zemiradius();

    double zemiobikolka();

    double zemiploshtina();

    void prikazhigeometriskafigura();
};

Krug::Krug() {

}

Krug::Krug(double radius, string boja, double x, double y) : Geometriskafigura2d(boja, x, y) {
    postaviradius(radius);
}

void Krug::postaviradius(double radius) {
    this->radius = radius;
}

double Krug::zemiradius() {
    return radius;
}

double Krug::zemiobikolka() {
    return 2 * 3.14 * radius;
}

double Krug::zemiploshtina() {
    return 3.14 * pow(radius, 2);
}

void Krug::prikazhigeometriskafigura() {
    cout << " Krug: " << " r=" << radius << endl;
    Geometriskafigura2d::prikazhigeometriskafigura();
    cout << " Obikolka:  " << zemiobikolka() << endl;
    cout << " Ploshtina: " << zemiploshtina() << endl;
    cout << endl;
}

class Prizma : public Geometriskafigura3d {
private:
    double a, b, H;
public:
    Prizma();

    Prizma(double, double, double, string, double, double, double);

    ~Prizma() {}

    void postaviprizma(double, double, double);

    void zemiprizma(double &, double &, double &);

    double zemiploshtina();

    double zemivolumen();

    void prikazhigeometriskafigura();
};

Prizma::Prizma(double a, double b, double H, string boja, double x, double y, double z) : Geometriskafigura3d(boja, x,
                                                                                                              y, z) {
    postaviprizma(a, b, H);
}

void Prizma::postaviprizma(double a, double b, double H) {
    this->a = a;
    this->b = b;
    this->H = H;
}

void Prizma::zemiprizma(double &a, double &b, double &H) {
    a = this->a;
    b = this->b;
    H = this->H;
}

double Prizma::zemiploshtina() {
    return 2 * a * b + 2 * a * H + 2 * b * H;
}

double Prizma::zemivolumen() {
    return a * b * H;
}

void Prizma::prikazhigeometriskafigura() {
    cout << "Prizma: " << " a=" << a << ", b=" << b << ", H=" << H << endl;
    Geometriskafigura3d::prikazhigeometriskafigura();
    cout << " Povrshina: " << zemiploshtina() << endl;
    cout << " Volumen:   " << zemivolumen() << endl;
    cout << endl;
}

int main() {
    const int BROJ_FIGURI = 2;
    double radius = 1;
    string boja;
    cout << "Vnesete boja na krugot: ";
    cin >> boja;
    double x = 2;
    double y = 3;
    double z = 4;
    Krug mojkrug(radius, boja, x, y);

    double a = 1, b = 2, H = 3;
    cout << "Vnesete boja na prizmata: ";
    cin >> boja;
    Prizma mojaprizma(a, b, H, boja, x, y, z);
    Geometriskafigura *figuri[BROJ_FIGURI];
    figuri[0] = &mojkrug;
    figuri[1] = &mojaprizma;
    for (Geometriskafigura *figura : figuri) {
        figura->prikazhigeometriskafigura();
    }
    cout << endl;
    system("PAUSE");
    return 0;
}










