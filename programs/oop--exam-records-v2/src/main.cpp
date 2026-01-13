#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

class Lice {
private:
    string ime, prezime;
    long long embg;
    string adresa;
public:
    Lice() = default;

    Lice(string ime, string prezime, long long embg, string adresa) {
        this->ime = ime;
        this->prezime = prezime;
        this->embg = embg;
        this->adresa = adresa;
    }

    const string &getIme() const {
        return ime;
    }

    void setIme(const string &ime) {
        Lice::ime = ime;
    }

    const string &getPrezime() const {
        return prezime;
    }

    void setPrezime(const string &prezime) {
        Lice::prezime = prezime;
    }

    long long int getEmbg() const {
        return embg;
    }

    void setEmbg(long long int embg) {
        Lice::embg = embg;
    }

    const string &getAdresa() const {
        return adresa;
    }

    void setAdresa(const string &adresa) {
        Lice::adresa = adresa;
    }

    void prikazhilice() {
        cout << getIme() << " " << getPrezime() << "\n EMBG: " << getEmbg() << "\n Adresa: " << getAdresa() << endl;
    }
};

class Student : public Lice {
private:
    int indeks;
    string fakultet;
    int godina;
public:
    Student() = default;

    Student(int indeks, string fakultet, int godina, string ime, string prezime, long long embg, string adresa) : Lice(
            ime, prezime, embg, adresa) {
        this->indeks = indeks;
        this->fakultet = fakultet;
        this->godina = godina;

    }

    int getIndeks() const {
        return indeks;
    }

    void setIndeks(int indeks) {
        Student::indeks = indeks;
    }

    const string &getFakultet() const {
        return fakultet;
    }

    void setFakultet(const string &fakultet) {
        Student::fakultet = fakultet;
    }

    int getGodina() const {
        return godina;
    }

    void setGodina(int godina) {
        Student::godina = godina;
    }

    void prikazhistudent() {
        cout << "Student: \t" << getIndeks() << " " << getIme() << " " << getPrezime() << endl;
        cout << "Fakultet: \t" << getFakultet();
        cout << "\nGodina \t\t" << getGodina();
        cout << "\nEMBG: \t\t" << getEmbg();
        cout << "\nAdresa: \t" << getAdresa() << endl;
    }

    void prikazhistudentnasispit() {
        cout << left << setw(10) << getIndeks() << setw(15) << getIme() << setw(15) << getPrezime();
    }
};

class Profesor : public Lice {
private:
    string oblast;
    string akademskistepen;
public:
    Profesor() = default;

    Profesor(string oblast, string akademskistepen, string ime, string prezime, long long embg, string adresa) : Lice(
            ime, prezime, embg, adresa) {
        this->oblast = oblast;
        this->akademskistepen = akademskistepen;
    }

    const string &getOblast() const {
        return oblast;
    }

    void setOblast(const string &oblast) {
        Profesor::oblast = oblast;
    }

    const string &getAkademskistepen() const {
        return akademskistepen;
    }

    void setAkademskistepen(const string &akademskistepen) {
        Profesor::akademskistepen = akademskistepen;
    }

    void prikazhiprofesor() {
        cout << "\nProfesor: " << getAkademskistepen() << " ";
        prikazhilice();
        cout << " Oblast: " << getOblast() << endl;
    }

    void prikazhiprofesornaispit() {
        cout << getAkademskistepen() << " " << getIme() << " " << getPrezime();
    }
};

class Ispit {
private:
    string datum;
    string vreme;
    string prostorija;
public:
    const string &getDatum() const {
        return datum;
    }

    void setDatum(const string &datum) {
        Ispit::datum = datum;
    }

    const string &getVreme() const {
        return vreme;
    }

    void setVreme(const string &vreme) {
        Ispit::vreme = vreme;
    }

    const string &getProstorija() const {
        return prostorija;
    }

    void setProstorija(const string &prostorija) {
        Ispit::prostorija = prostorija;
    }

    virtual void prikazhiispit(string datum, string vreme, string prostorija, Ispit *ovojispit, Profesor profesor,
                               Student studenti[], int bodovi[], int brojnakandidati) = 0;
};

int ocena(int bodovi) {
    if (50 <= bodovi && bodovi < 55)
        return 6;
    if (55 <= bodovi && bodovi < 65)
        return 7;
    if (65 <= bodovi && bodovi < 85)
        return 8;
    if (85 <= bodovi && bodovi < 95)
        return 9;
    if (95 <= bodovi && bodovi < 100)
        return 10;
}

const int brojstudenti = 100;

class Predmet : public Ispit {
    friend int ocena(int);

    friend void vnesuvanjebodovi(Student[], int, int);

private:
    string imenapredmet;
    int kodnapredmet;
    Profesor profesor;
    Student *studenti;
    int brojnastudenti;
public:
    Predmet() = default;

    Predmet(string imenapredmet, int kodnapredmet,Profesor profesor,Student *studenti, int brojnastudenti) {
        this->imenapredmet = imenapredmet;
        this->kodnapredmet = kodnapredmet;
        this->profesor=profesor;
        this->brojnastudenti=brojnastudenti;
        this->studenti=studenti;
        for(int i=0;i<brojnastudenti;i++)
            this->studenti[i]=studenti[i];
    }

    const string &getImenapredmet() const {
        return imenapredmet;
    }

    void setImenapredmet(const string &imenapredmet) {
        Predmet::imenapredmet = imenapredmet;
    }

    int getKodnapredmet() const {
        return kodnapredmet;
    }

    void setKodnapredmet(int kodnapredmet) {
        Predmet::kodnapredmet = kodnapredmet;
    }

    void prikazhiispit(string datum, string vreme, string prostorija, Ispit *ovojispit, Profesor profesor,
                       Student studenti[], int bodovi[], int brojnakandidati) {
        cout << "\n\tREZULTATI OT ISPIT \n"
             << "\n Fakultet: \t" << studenti[0].getFakultet()
             << "\n Godina: \t" << studenti[0].getGodina()
             << "\n Predmet: \t" << ((Predmet *) ovojispit)->getKodnapredmet() << " "
             << ((Predmet *) ovojispit)->getImenapredmet()
             << "\n Datum: \t\t" << datum << "\nVreme: \t\t" << vreme
             << "\n Prostorija: \t" << prostorija
             << "\n Profesor: \t";
        profesor.prikazhiprofesornaispit();
        cout << endl << endl;
        cout << setw(4) << "" << setw(10) << "ID" << setw(15) << "Ime    " << setw(15) << "Prezime" << setw(11)
             << "Ocena" << endl;
        cout << "------------------------------------------------------------------------------------------------------"
             << endl;
        for (int i = 0; i < brojnakandidati; i++) {
            cout << right << setw(2) << i + 1 << ". ";
            studenti[i].prikazhistudentnasispit();
            cout << setw(4) << right << ocena(bodovi[i]) << endl;
        }
        cout << "------------------------------------------------------------------------------------------------------"
             << endl;
    }
};

void vnesuvanjebodovi(Student studenti[], int brojnakandidati, int bodovi[]) {
    cout << "\n\nVnesete bodovi na studentite (0 do 100): " << endl;
    for (int i = 0; i < brojnakandidati; i++) {
        do {
            studenti[i].prikazhistudentnasispit();
            cout << ". - bodovi:";
            cin >> bodovi[i];
        } while (!(bodovi[i] <= 100));
    }
}

bool proverkanapredmet(int kod, string &imenapredmet, int &kodnapredmet);

bool proverkanaprofesor(string profesorime, string profesorprezime, string &oblast, string &akademskistepen,
                        string &imenaprofesor, string &prezimenaprofesor, long long &embgnaprofesor,
                        string &adresanaprofesor);

void prikazhuvanjenaprofesor(Profesor profesor);

void prikazhuvanjenastudenti(Student studenti[], int brojnakandidati);

void kandidatizaispit(Student studenti[], int &brojnakandidati);

string vlez;

int main() {
    int kodnapredmet, kod;
    string imenapredmet;
    cout << "Vnesete kod na predmetot " << "(1234,2345,3456,4567,5678): ";
    getline(cin, vlez);
    kod = stoi(vlez);
    bool imapredmet = proverkanapredmet(kod, imenapredmet, kodnapredmet);
    if (!imapredmet) {
        cout << "Nema predmet so toj broj. " << endl;
        exit(1);
    }
    string oblast, akademskistepen, imenaprofesor, prezimenaprofesor, adresanaprofesor;
    long long embgnaprofesor;

    string profesorime, profesorprezime;
    cout << "Vnesete ime na profesor: ";
    getline(cin, profesorime);
    cout << "Vnesete prezime na profesor: ";
    getline(cin, profesorprezime);
    bool imaprofesor = proverkanaprofesor(profesorime, profesorprezime, oblast, akademskistepen, imenaprofesor,
                                          prezimenaprofesor, embgnaprofesor, adresanaprofesor);
    if (!imaprofesor) {
        cout << "Nema takov profesor. " << endl;
        exit(1);
    }

    Profesor profesor(oblast, akademskistepen, imenaprofesor, prezimenaprofesor, embgnaprofesor, adresanaprofesor);
    Student studenti[100];
    int brojnakandidati = 0;
    kandidatizaispit(studenti, brojnakandidati);
    int bodovi[100];
    vnesuvanjebodovi(studenti, brojnakandidati, bodovi);

    Ispit *ovojispit = new Predmet(imenapredmet, kodnapredmet,profesor,studenti,brojnakandidati);
    getline(cin, vlez);
    string datum, vreme, prostorija;
    cout << "\nVnesete datum na ispitot: ";
    getline(cin, datum);
    cout << "Vnesete vreme na ispitot: ";
    getline(cin, vreme);
    cout << "Vnesete prostorija na ispitot: ";
    getline(cin, prostorija);
    ovojispit->setDatum(datum);
    ovojispit->setVreme(vreme);
    ovojispit->setProstorija(prostorija);

    ovojispit->prikazhiispit(datum, vreme, prostorija, ovojispit, profesor, studenti, bodovi, brojnakandidati);
    cout << "\nDali sakate da vidite kompletni podatoci za profesorot (D,d,N,n)?";
    string dane;
    getline(cin, dane);
    if ((dane.compare("D") == 0) || (dane.compare("d") == 0))
        prikazhuvanjenaprofesor(profesor);
    cout << "\nDali sakate da vidite kompletni podatoci za nekoj student (D,d,N,n)?";
    getline(cin, dane);
    if ((dane.compare("D") == 0) || (dane.compare("d") == 0))
        prikazhuvanjenastudenti(studenti, brojnakandidati);
    cout << endl;
    system("PAUSE");
    return 0;
}

void kandidatizaispit(Student studenti[], int &brojnakandidati) {
    ifstream datstudenti("datstudenti.dat");
    if (!datstudenti) {
        cout << "Nema datoteka " << "datstudenti.dat" << endl;
        exit(1);
    }

    int indeks, godina;
    string fakultet, imenastudent, prezimenastudent, adresanastudent;
    long long embgnastudent;
    cout << "Vnesete fakultet: ";
    getline(cin, fakultet);
    cout << "Vnesete godina: ";
    getline(cin, vlez);
    godina=stoi(vlez);
    int i = -1;
    do {
        i++;
        datstudenti >> indeks >> imenastudent >> prezimenastudent >> embgnastudent >> adresanastudent;
        studenti[i] = {indeks, fakultet, godina, imenastudent, prezimenastudent, embgnastudent, adresanastudent};
    } while (!datstudenti.eof());
    datstudenti.close();
    brojnakandidati = i;
}

bool proverkanapredmet(int kod, string &imenapredmet, int &kodnapredmet) {
    ifstream datpredmeti("datpredmeti.dat");
    if (!datpredmeti) {
        cout << "Nemat datoteka " << "datpredmeti.dat" << endl;
        exit(1);
    }
    bool imapredmet = false;
    do {
        getline(datpredmeti, vlez);
        kodnapredmet=stoi(vlez);
        getline(datpredmeti, imenapredmet);
        getline(datpredmeti, vlez);
        if (kodnapredmet == kod) {
            imapredmet = true;
            break;
        }
    } while (!datpredmeti.eof());
    datpredmeti.close();
    return imapredmet;
}

bool proverkanaprofesor(string profesorime, string profesorprezime, string &oblast, string &akademskistepen,
                        string &imenaprofesor, string &prezimenaprofesor, long long &embgnaprofesor,
                        string &adresanaprofesor) {
    ifstream datprofesori("datprofesori.dat");
    if (!datprofesori) {
        cout << "Nemat datoteka " << "datprofesori.dat" << endl;
        exit(1);
    }
    bool imaprofesor = false;
    do {
        getline(datprofesori, oblast);
        datprofesori >> akademskistepen >> imenaprofesor >> prezimenaprofesor >> embgnaprofesor;
        datprofesori >> vlez;
        getline(datprofesori, adresanaprofesor);
        getline(datprofesori, vlez);
        if ((profesorime.compare(imenaprofesor) == 0) && (profesorprezime.compare(prezimenaprofesor) == 0)) {
            imaprofesor = true;
            break;
        }
    } while (!datprofesori.eof());
    datprofesori.close();
    return imaprofesor;
}

void prikazhuvanjenastudenti(Student studenti[], int brojnakandidati) {
    int indekS;
    cout << "\n\tPrikazhuvanje podatoci na studenti." << endl;
    int i;
    do {
        cout << "\nVnesete indeks. (Za kraj vnesete 999999) : ";
        getline(cin, vlez);
        indekS = stoi(vlez);
        i = 0;
        while ((i < brojnakandidati) && indekS != studenti[i].getIndeks())
            i++;
        if (i < brojnakandidati)
            studenti[i].prikazhistudent();
        else
            cout << "Nema student so toj indeks.";
        cout << endl;
    } while (indekS != 999999);
}

void prikazhuvanjenaprofesor(Profesor profesor) {
    cout << "\n\tPrikazhuvanje podatoci za profesor." << endl;
    profesor.prikazhiprofesor();
}





















