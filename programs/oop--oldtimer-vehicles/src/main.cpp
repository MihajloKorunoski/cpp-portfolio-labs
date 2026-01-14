#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

class Exception {
private:
    char *noldtimer;

public:
    Exception(const char *noldtimer = "") {
        this->noldtimer = new char[strlen(noldtimer) + 1];
        strcpy(this->noldtimer, noldtimer);
    }

    Exception(const Exception &other) {
        noldtimer = new char[strlen(other.noldtimer) + 1];
        strcpy(noldtimer, other.noldtimer);
    }

    Exception &operator=(const Exception &other) {
        if (this != &other) {
            delete[] noldtimer;
            noldtimer = new char[strlen(other.noldtimer) + 1];
            strcpy(noldtimer, other.noldtimer);
        }
        return *this;
    }

    ~Exception() {
        delete[] noldtimer;
    }

    void pecati() const {
        cout << noldtimer;
    }
};

class Oldtimer {
private:
    char *model;
    char shasija[15];
    int mokjnost;
    bool sostojba;
    int godina;

    void setModel(const char *novModel) {
        delete[] model;
        model = new char[strlen(novModel) + 1];
        strcpy(model, novModel);
    }

public:
    Oldtimer(const char *model = "", const char *shasija = "", int mokjnost = 0, bool sostojba = false,
             int godina = 0)
        : model(nullptr), mokjnost(mokjnost), sostojba(sostojba), godina(godina) {
        setModel(model);
        strncpy(this->shasija, shasija, sizeof(this->shasija) - 1);
        this->shasija[sizeof(this->shasija) - 1] = '\0';
    }

    Oldtimer(const Oldtimer &o) : model(nullptr) {
        setModel(o.model);
        strcpy(shasija, o.shasija);
        mokjnost = o.mokjnost;
        sostojba = o.sostojba;
        godina = o.godina;
    }

    Oldtimer &operator=(const Oldtimer &o) {
        if (this != &o) {
            setModel(o.model);
            strcpy(shasija, o.shasija);
            mokjnost = o.mokjnost;
            sostojba = o.sostojba;
            godina = o.godina;
        }
        return *this;
    }

    ~Oldtimer() {
        delete[] model;
    }

    const char *get_model() const {
        return model;
    }

    const char *get_br_shasija() const {
        return shasija;
    }

    int get_godina() const {
        return godina;
    }

    bool get_sostojba() const {
        return sostojba;
    }

    void pechati() const {
        cout << model << "-" << shasija << endl;
    }

    friend ostream &operator<<(ostream &o, const Oldtimer &oldtimer) {
        o << oldtimer.model << "-" << oldtimer.shasija;
        return o;
    }
};

class OldMuseum {
private:
    char *ime;
    Oldtimer *eksponati;
    int brojvozila;

public:
    OldMuseum(const char *ime = "", Oldtimer *eksponanti = nullptr, int brojvozila = 0) {
        this->ime = new char[strlen(ime) + 1];
        strcpy(this->ime, ime);
        this->brojvozila = brojvozila;
        this->eksponati = new Oldtimer[brojvozila];
        for (int i = 0; i < brojvozila; i++) {
            this->eksponati[i] = eksponanti[i];
        }
    }

    OldMuseum(const OldMuseum &o) {
        ime = new char[strlen(o.ime) + 1];
        strcpy(ime, o.ime);
        brojvozila = o.brojvozila;
        eksponati = new Oldtimer[brojvozila];
        for (int i = 0; i < brojvozila; i++) {
            eksponati[i] = o.eksponati[i];
        }
    }

    OldMuseum &operator=(const OldMuseum &o) {
        if (this != &o) {
            delete[] ime;
            delete[] eksponati;
            ime = new char[strlen(o.ime) + 1];
            strcpy(ime, o.ime);
            brojvozila = o.brojvozila;
            eksponati = new Oldtimer[brojvozila];
            for (int i = 0; i < brojvozila; i++) {
                eksponati[i] = o.eksponati[i];
            }
        }
        return *this;
    }

    ~OldMuseum() {
        delete[] ime;
        delete[] eksponati;
    }

    int get_brojvozila() const {
        return brojvozila;
    }

    const Oldtimer &get_eksponat(int index) const {
        return eksponati[index];
    }

    friend ostream &operator<<(ostream &o, const OldMuseum &old) {
        o << old.ime << endl;
        for (int i = 0; i < old.brojvozila; i++) {
            o << old.eksponati[i] << endl;
        }
        return o;
    }

    OldMuseum &operator+=(const Oldtimer &o) {
        Oldtimer *temp = new Oldtimer[brojvozila + 1];
        for (int i = 0; i < brojvozila; i++) {
            temp[i] = eksponati[i];
        }
        temp[brojvozila] = o;
        delete[] eksponati;
        eksponati = temp;
        brojvozila++;
        return *this;
    }

    friend bool operator==(const OldMuseum &o, const OldMuseum &a) {
        return o.brojvozila == a.brojvozila;
    }

    void print() const {
        cout << ime << endl;
    }
};

void statistics(OldMuseum niza[], int brojmuzei) {
    int muzejsonajstar = 0;
    int najstaraGodina = INT_MAX;
    for (int i = 0; i < brojmuzei; i++) {
        for (int j = 0; j < niza[i].get_brojvozila(); j++) {
            int godina = niza[i].get_eksponat(j).get_godina();
            if (godina < najstaraGodina) {
                najstaraGodina = godina;
                muzejsonajstar = i;
            }
        }
    }

    niza[muzejsonajstar].print();
    for (int i = 0; i < niza[muzejsonajstar].get_brojvozila(); i++) {
        niza[muzejsonajstar].get_eksponat(i).pechati();
    }
}

int main() {
    int test;
    cin >> test;
    if (test == 1) {
        cout << "Testing class Oldtimer" << endl;
        char model[50], br_shasija[50];
        int mokjnost, godina;
        bool vozna_sostojba;
        cin >> model >> br_shasija >> mokjnost >> godina >> vozna_sostojba;
        Oldtimer a;
        Oldtimer b(model, br_shasija, mokjnost, vozna_sostojba, godina);
        cout << b.get_model() << endl;
        cout << b.get_br_shasija() << endl;
    } else if (test == 2) {
        cout << "Testing class Exception" << endl;
        char model[50], br_shasija[50];
        int mokjnost, godina;
        bool vozna_sostojba;
        cin >> model >> br_shasija >> mokjnost >> godina >> vozna_sostojba;
        Oldtimer o;
        try {
            o = Oldtimer(model, br_shasija, mokjnost, vozna_sostojba, godina);
        } catch (const Exception &e) {
            e.pecati();
        }
        cout << o.get_model() << endl;
        cout << o.get_br_shasija() << endl;
    } else if (test == 3) {
        cout << "Testing class OldMuseum constructor" << endl;
        char name[50];
        cin >> name;
        OldMuseum o(name);
        cout << name;
    } else if (test == 4) {
        cout << "Testing class OldMuseum operator<< and operator+=" << endl;
        char model[50], br_shasija[50], name[50];
        int mokjnost, godina;
        bool vozna_sostojba;
        cin >> name;
        OldMuseum o(name);
        for (int i = 0; i < 2; i++) {
            cin >> model >> br_shasija >> mokjnost >> godina >> vozna_sostojba;
            Oldtimer car(model, br_shasija, mokjnost, vozna_sostojba, godina);
            o += car;
        }
        cout << o;
    } else if (test == 5) {
        cout << "Testing class OldMuseum operator==" << endl;
        char model[50], br_shasija[50], name[50];
        int mokjnost, godina;
        bool vozna_sostojba;
        cin >> name;
        OldMuseum o1(name);
        cin >> name;
        OldMuseum o2(name);
        for (int i = 0; i < 2; i++) {
            cin >> model >> br_shasija >> mokjnost >> godina >> vozna_sostojba;
            Oldtimer car(model, br_shasija, mokjnost, vozna_sostojba, godina);
            o1 += car;
            o2 += car;
        }
        cin >> model >> br_shasija >> mokjnost >> godina >> vozna_sostojba;
        Oldtimer car(model, br_shasija, mokjnost, vozna_sostojba, godina);
        o1 += car;
        if (o1 == o2) {
            cout << "True";
        } else {
            cout << "False";
        }
    } else if (test == 6) {
        cout << "Testing statistics" << endl;
        OldMuseum niza[2];
        char model[50], br_shasija[50], name[50];
        int mokjnost, godina;
        bool vozna_sostojba;
        for (int i = 0; i < 2; i++) {
            cin >> name;
            OldMuseum o2(name);
            niza[i] = o2;
            for (int j = 0; j < 2; j++) {
                cin >> model >> br_shasija >> mokjnost >> godina >> vozna_sostojba;
                Oldtimer car(model, br_shasija, mokjnost, vozna_sostojba, godina);
                niza[i] += car;
            }
        }
        statistics(niza, 2);
    }
    return 0;
}
