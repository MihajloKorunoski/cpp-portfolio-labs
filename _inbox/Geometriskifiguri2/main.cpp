#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

class Triagolnik {
private:
    double a, b, c;
public:
    Triagolnik() {

    }

    Triagolnik(double a, double b, double c) {
        postavistrani(a, b, c);
    }

    Triagolnik(double a, double b) {
        this->a = a;
        this->b = b;
    }

    Triagolnik(double a) {
        this->a = a;
    }

    ~Triagolnik() {}

    void postavistrani(double a, double b, double c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    void zemistrani(double a, double b, double c) {
        a = this->a;
        b = this->b;
        c = this->c;
    }

    double zemia() {
        return a;
    }

    double zemib() {
        return b;
    }

    double zemic() {
        return c;
    }
};

class Ramnostrantriagolnik : public Triagolnik {
private:
public:
    Ramnostrantriagolnik() {

    }

    Ramnostrantriagolnik(double a) : Triagolnik(a) {

    }

    ~Ramnostrantriagolnik() {

    }

    double zemiobikolka() {
        return 3 * zemia();
    }

    double zemiploshtina() {
        return zemia() * zemia() * sqrt(3) / 4;
    }

    void prikazhiramnostrantriagolnik() {
        cout << "\n\n Objekt ramnostran triagolnik: a=" << zemia();
        cout << "\n Obikolka:  O=" << zemiobikolka();
        cout << "\n Ploshtina: P=" << zemiploshtina();
    }
};

class Tetraedar : public Ramnostrantriagolnik {
private:
public:
    Tetraedar() {

    }

    Tetraedar(double a) : Ramnostrantriagolnik(a) {

    }

    ~Tetraedar() {
    }

    double zemipovrshina() {
        return 4 * zemiploshtina();
    }

    double zemivolumen() {
        return pow(zemia(), 3) * sqrt(2) / 12;
    }

    void prikazhitetraedar() {
        cout << "Objekt tetraedar: a=" << zemia();
        prikazhiramnostrantriagolnik();
        cout << "\n Povrshina: P=" << zemipovrshina();
        cout << "\n Volumen:   V=" << zemivolumen();
    }
};

int main() {
    double a;
    cout<<"Vnesete ja stranata na tetraedarot, a=";
    cin>>a;
    Tetraedar *tetraedarpok= new Tetraedar(a);
    tetraedarpok->prikazhitetraedar();
    cout<<endl<<endl;
    system("PAUSE");
    return 0;
}








