#include <iostream>
#include <string>

using namespace std;

bool proveriemail(string email) {
    int pati = 0;
    int dolzhina = email.length();
    for (int i = 0; i < dolzhina; i++) {
        if (email.at(i) == '@')
            pati++;
    }
    return pati == 1;
}


class Isprakjach {
    friend bool proveriemail(string email);

private:
    string moeimeiprezime;
    string mojemail;
    string poraka;
public:
    Isprakjach() = default;

    Isprakjach(string moeimeiprezime, string mojemail, string poraka) {
        postaviisprakjach(moeimeiprezime, mojemail, poraka);
    }

    void postaviisprakjach(string moeimeiprezime, string mojemail, string poraka) {
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

    virtual void ispratiporaka() = 0;

    void prikazhiisprakjach() {
        cout << "od\t" << getMoeimeiprezime() << " <" << getMojemail() << ">" << endl;
    }
};

const string &Isprakjach::getMoeimeiprezime() const {
    return moeimeiprezime;
}

void Isprakjach::setMoeimeiprezime(const string &moeimeiprezime) {
    Isprakjach::moeimeiprezime = moeimeiprezime;
}

const string &Isprakjach::getMojemail() const {
    return mojemail;
}

void Isprakjach::setMojemail(const string &mojemail) {
    Isprakjach::mojemail = mojemail;
}

const string &Isprakjach::getPoraka() const {
    return poraka;
}

void Isprakjach::setPoraka(const string &poraka) {
    Isprakjach::poraka = poraka;
}

class Primach : public Isprakjach {
private:
    string imeiprezime;
    string email;
public:
    Primach() {}

    Primach(string imeiprezime, string email, string moeimeiprezime, string mojemail, string poraka) : Isprakjach(
            moeimeiprezime, mojemail, poraka) {
        this->imeiprezime = imeiprezime;
        this->email = email;
    }

    const string &getImeiprezime() const {
        return imeiprezime;
    }

    void setImeiprezime(const string &imeiprezime) {
        Primach::imeiprezime = imeiprezime;
    }

    const string &getEmail() const {
        return email;
    }

    void setEmail(const string &email) {
        Primach::email = email;
    }
    virtual void ispratiporaka(){
        prikazhiisprakjach();
        cout<<"do\t";
        cout<<getImeiprezime()<<" <"<<getEmail()<<">"<<endl;
        cout<<"\t"<<getPoraka()<<endl;
    }
};

int main() {
    string vlez;
    string moeimeiprezime,mojemail,poraka;
    cout<<"Vnesete vashe ime i prezime: ";
    getline(cin,moeimeiprezime);
    do{
        cout<<"Vnesete ja vashata email adresa: ";
        getline(cin,mojemail);
    } while (!proveriemail(mojemail));
    cout<<" Vnesete poraka: ";
    getline(cin,poraka);

    Primach *primachi[100];
    int brojprimachi;
    cout<<"\nVnesete broj prijateli na koi kje ja pratite porakata: ";
    getline(cin,vlez);
    brojprimachi=stoi(vlez);
    string imeiprezime,email;
    for(int i=0;i<brojprimachi;i++){
        cout<<"\nPrimach "<<i+1<<": "<<endl;
        cout<<" Ime i prezime: ";
        getline(cin,imeiprezime);
        do{
            cout<<" E_mail          :";
            getline(cin,email);
        } while (!proveriemail(email));
        primachi[i]=new Primach(imeiprezime,email,moeimeiprezime,mojemail,poraka);
    }
    for(int i=0;i<brojprimachi;i++){
        cout<<"\nPrimach"<<i+1<<": "<<endl;
        primachi[i]->ispratiporaka();
    }
    cout<<endl;
    system("PAUSE");
    return 0;
}













