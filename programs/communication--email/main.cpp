#include <iostream>
#include <string>
#include <iomanip>
#include <exception>
#include <typeinfo>

using namespace std;

bool proveriemail(string email) {
    int pati = 0;
    int dolzhina = email.length();
    for (int i = 0; i < dolzhina; i++) {
        if (email.at(i) == '@')
            pati++;
    }
    if (pati == 1)
        return true;
    else
        return false;
}


class Email {
    friend bool proveriemail(string email);

private:
    string moeimeiprezime;
    string mojemail;
    string poraka;
public:
    Email() {
    }

    Email(string moeimeiprezime, string mojemail, string poraka) {
        postaviemail(moeimeiprezime, mojemail, poraka);
    }

    void postaviemail(string moeimeiprezime, string mojemail, string poraka) {
        this->moeimeiprezime = moeimeiprezime;
        this->mojemail = mojemail;
        this->poraka = poraka;
    }

    const string &getMoeimeiprezime() const;

    void setMoeimeiprezime(const string &moeimeiprezime);

    const string &getMojemail() const;

    void setMojemail(const string &mojemail);

    const string &getPoraka() const;

    void setPoraka(const string &poraka);

    void isprakjach() {
        cout << "Od:\t" << getMoeimeiprezime() << " <" << getMojemail() << ">" << endl;
    }

};

const string &Email::getMoeimeiprezime() const {
    return moeimeiprezime;
}

void Email::setMoeimeiprezime(const string &moeimeiprezime) {
    Email::moeimeiprezime = moeimeiprezime;
}

const string &Email::getMojemail() const {
    return mojemail;
}

void Email::setMojemail(const string &mojemail) {
    Email::mojemail = mojemail;
}

const string &Email::getPoraka() const {
    return poraka;
}

void Email::setPoraka(const string &poraka) {
    Email::poraka = poraka;
}

class Prijatel : public Email {
private:
    string imeiprezime;
    string email;
public:
    Prijatel() {
    }

    Prijatel(string imeiprezime, string email, string moeimeiprezime, string mojemail, string poraka) : Email(
            moeimeiprezime, mojemail, poraka) {
        this->imeiprezime = imeiprezime;
        this->email = email;
    }

    const string &getImeiprezime() const {
        return imeiprezime;
    }

    void setImeiprezime(const string &imeiprezime) {
        Prijatel::imeiprezime = imeiprezime;
    }

    const string &getEmail() const {
        return email;
    }

    void setEmail(const string &email) {
        Prijatel::email = email;
    }

    void primach() {
        cout << "Do:\t" << getImeiprezime() << " <" << getEmail() << ">" << endl;
    }
};

int main() {
    string vlez;
    string moeimeiprezime, mojemail, poraka;
    bool greshka = true;
    do {
        try {
            cout << "Vnesete vashe ime i prezime: ";
            getline(cin, moeimeiprezime);
            if (moeimeiprezime.length() == 0)
                throw length_error(moeimeiprezime);
            cout << "Vnesete ja vashata email adresa: ";
            getline(cin, mojemail);
            if (mojemail.length() == 0)
                throw length_error(mojemail);
            if (!proveriemail(mojemail))
                throw exception();
            cout << "Vnesete poraka: ";
            getline(cin, poraka);
            if (poraka.length() == 0)
                throw length_error(poraka);
            greshka = false;
        } catch (length_error &e) {
            cout << "\n\t Greshka: Nema string. Vnesete povtorno"
                 << e.what() << "\n\t Tip: " << typeid(e).name() << endl;
        } catch (exception &e) {
            cout << "\n\t Greshka: E_mail porakata morat da sodrzhit 1 znak @." << e.what() << "\n\t Tip: "
                 << typeid(e).name() << endl;
        }
    } while (greshka);

    Email *prijateli[100];

    int brojprijateli;
    greshka = true;
    do {
        try {
            cout << "\nVnesete broj prijateli na koi kje ja pratite porakata: ";
            getline(cin, vlez);
            if (!(brojprijateli = stoi(vlez)))
                throw bad_typeid();
            if (brojprijateli <= 0)
                throw brojprijateli;
            greshka = false;
        } catch (exception &e) {
            cout << "\n\t Greshka: Pogreshna vrednost. " << e.what() << "\n\t Tip: " << typeid(e).name() << endl;
        } catch (int &e) {
            cout << "\n\t Greshka: Nemate prijateli? ";
            cout << " Vnesovte " << e << "prijateli." << "\n\t Tip: " << typeid(e).name() << endl;
        }
    } while (greshka);

    string primachimeiprezime, primachemail;
    greshka = true;
    do {
        try {
            for (int i = 0; i < brojprijateli; i++) {
                cout << "\nPrimach" << i + 1 << ": " << endl;
                cout << " Ime i prezime: ";
                getline(cin, primachimeiprezime);
                if (primachimeiprezime.length() == 0)
                    throw length_error(primachimeiprezime);
                cout << " E_mail             :";
                getline(cin, primachemail);
                if (primachemail.length() == 0)
                    throw length_error(primachemail);
                if (!proveriemail(primachemail))
                    throw exception();
                prijateli[i] = new Prijatel(primachimeiprezime, primachemail, moeimeiprezime, mojemail, poraka);
            }
            greshka = false;
        } catch (length_error &e) {
            cout << "\n\t Greshka: Nema string. Vnesete ponovo." << e.what() << "\n\t Tip: " << typeid(e).name()
                 << endl;
        } catch (exception &e){
            cout << "\n\t Greshka: E_mail porakata morat da sodrzhit 1 znak @." << e.what() << "\n\t Tip: "
                 << typeid(e).name() << endl;
        }
    } while (greshka);

    for (int i = 0; i < brojprijateli; i++) {
        cout << "\nPoraka " << i + 1 << endl;
        prijateli[i]->isprakjach();
        ((Prijatel *) prijateli[i])->primach();
        cout << "Poraka:\t" << prijateli[i]->getPoraka();
        cout << endl;
    }
    cout << endl;
    system("PAUSE");
    return 0;
}

















