#include <iostream>
#include<string>
#include<iomanip>

using namespace std;

class Profesor {
private:
    string imenaprofesor, prezimenaprofesor;
public:
    Profesor();

    Profesor(string, string);

    void postaviimenaprofesor(string);

    void postaviprezimenaprofesor(string);

    string zemiimenaprofesor();

    string zemiprezimenaprofesor();

    void prikazhiprofesor();

};

Profesor::Profesor() {

}

Profesor::Profesor(string imenaprofesor, string prezimenaprofesor) {
    this->imenaprofesor = imenaprofesor;
    this->prezimenaprofesor = prezimenaprofesor;
}

void Profesor::postaviimenaprofesor(string imenaprofesor) {
    this->imenaprofesor = imenaprofesor;
}

void Profesor::postaviprezimenaprofesor(string prezimenaprofesor) {
    this->prezimenaprofesor = prezimenaprofesor;
}

string Profesor::zemiimenaprofesor() {
    return imenaprofesor;
}

string Profesor::zemiprezimenaprofesor() {
    return prezimenaprofesor;
}

void Profesor::prikazhiprofesor() {
    cout << "\tProfesor:    " << zemiimenaprofesor() << " " << zemiprezimenaprofesor() << endl;
}

class Predmet : public Profesor {
private:
    string predmet;
    int kod;
    int ocena;
public:
    Predmet();

    Predmet(string, int, int, string, string);

    void postavipredmet(string);

    string zemipredmet();

    void postavikod(int);

    int zemikod();

    void postaviocena(int);

    int zemiocena();

    void prikazhipredmet();
};

Predmet::Predmet() {
    predmet = "", kod = 0, ocena = 0;
}

Predmet::Predmet(string predmet, int kod, int ocena, string imenaprofesor, string prezimenaprofesor) :
        Profesor(imenaprofesor, prezimenaprofesor) {
    this->predmet = predmet;
    this->kod = kod;
    this->ocena = ocena;
}

void Predmet::postavipredmet(string predmet) {
    this->predmet = predmet;
}

string Predmet::zemipredmet() {
    return predmet;
}

void Predmet::postavikod(int kod) {
    this->kod = kod;
}

int Predmet::zemikod() {
    return kod;
}

void Predmet::postaviocena(int ocena) {
    this->ocena = ocena;
}

int Predmet::zemiocena() {
    return ocena;
}

void Predmet::prikazhipredmet() {
    cout << "\tPredmet:     " << zemipredmet();
    cout << "\n\tKod:         " << zemikod();
    cout << "\n\tOcena:       " << zemiocena();
    cout << endl;
    prikazhiprofesor();
}

int main() {
    string imenaprofesor, prezimenaprofesor;
    string pom;
    string predmet;
    int kod;
    int ocena;
    int brojnapredmeti;
    Predmet predmeti[15];
    cout << "Vnesete broj na predmeti: ";
    getline(cin, pom);
    brojnapredmeti = stoi(pom);
    for (int i = 0; i < brojnapredmeti; i++) {
        cout << "Vnesete ime na predmet: ";
        getline(cin, predmet);
        cout << "Vnesete ime na profesor: ";
        getline(cin, imenaprofesor);
        cout << "Vnesete prezime na profesor: ";
        getline(cin, prezimenaprofesor);
        cout << "Vnesete kod na predmet: ";
        getline(cin, pom);
        kod=stoi(pom);
        cout << "Vnesete ocena za predmet: ";
        getline(cin, pom);
        ocena=stoi(pom);
        predmeti[i] = {predmet, kod, ocena, imenaprofesor, prezimenaprofesor};
        cout << endl;
    }

    Predmet *pokpredmeti[15];
    for (int i = 0; i < brojnapredmeti; i++)
        pokpredmeti[i] = &predmeti[i];

    for (int i = 0; i < brojnapredmeti; i++) {
        cout << "Predmet " << i + 1 << ":" << endl;
        pokpredmeti[i]->prikazhipredmet();
        cout << endl;
    }

    double prosek = 0;
    for (int i = 0; i < brojnapredmeti; i++) {
        prosek += pokpredmeti[i]->zemiocena();
    }
    prosek /= brojnapredmeti;
    cout << fixed << setprecision(2);
    cout << "\nProsek: " << prosek << endl;

    cout << endl;
    system("pause");
    return 0;
}














