#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Muzichkiinstrument {
private:
    string vid;
public:
    Muzichkiinstrument(string vid) {
        this->vid = vid;
    }

    virtual ~Muzichkiinstrument() = default;

    const string &getVid() const {
        return vid;
    }

    void setVid(const string &vid) {
        Muzichkiinstrument::vid = vid;
    }

    virtual void prikazhimuzichkiinstrument() {
        cout << left << "\t" << setw(10) << getVid();
    }

    virtual void sviri() = 0;
};

class Gitara : public Muzichkiinstrument {
private:
    string marka;
public:
    Gitara(string vid = "", string marka = "") : Muzichkiinstrument(vid) {
        setGitara(marka);
    }

    const string &getGitara() const {
        return marka;
    }

    void setGitara(const string &marka) {
        Gitara::marka = marka;
    }

    virtual void prikazhimuzichkiinstrument() {
        Muzichkiinstrument::prikazhimuzichkiinstrument();
        cout << left << "\t" << getGitara() << endl;
    }

    virtual void sviri() {
        prikazhimuzichkiinstrument();
    }
};

class Violina : public Muzichkiinstrument {
private:
    string marka;
public:
    Violina(string vid = "", string marka = "") : Muzichkiinstrument(vid) {
        setViolina(marka);
    }

    const string &getViolina() const {
        return marka;
    }

    void setViolina(const string &marka) {
        Violina::marka = marka;
    }

    virtual void prikazhimuzichkiinstrument() {
        Muzichkiinstrument::prikazhimuzichkiinstrument();
        cout << left;
        cout << "\t" << setw(10) << getViolina() << endl;
    }

    virtual void sviri() {
        prikazhimuzichkiinstrument();
    }
};

class Flejta : public Muzichkiinstrument {
private:
    string marka;
public:
    Flejta(string vid = "", string marka = "") : Muzichkiinstrument(vid) {
        setFlejta(marka);
    }

    const string &getFlejta() const {
        return marka;
    }

    void setFlejta(const string &marka) {
        Flejta::marka = marka;
    }

    virtual void prikazhimuzichkiinstrument() {
        Muzichkiinstrument::prikazhimuzichkiinstrument();
        cout << left;
        cout << "\t" << setw(10) << getFlejta() << endl;
    }

    virtual void sviri() {
        prikazhimuzichkiinstrument();
    }
};

int main() {
    const int brojgitari = 2;
    Gitara gitari[brojgitari];
    gitari[0] = {"Gitara", "Yamaha"};
    gitari[1] = {"Gitara", "Fender"};

    const int brojviolini = 2;
    Violina violini[brojviolini];
    violini[0] = {"Violina", "Stentor"};
    violini[1] = {"Violina", "Windsor"};

    const int brojflejti = 2;
    Flejta flejti[brojflejti];
    flejti[0] = {"Flejta", "Mendini"};
    flejti[1] = {"Flejta", "Hallelu"};

    const int brojmuzichkiinstrumenti = brojgitari+brojflejti+brojviolini;
    Muzichkiinstrument *instrumenti[brojmuzichkiinstrumenti];
    int i=0;
    for(int j=0; j<brojgitari;j++,i++){
        instrumenti[i]=&gitari[j];
    }
    for(int j=0; j<brojviolini;j++,i++){
        instrumenti[i]=&violini[j];
    }
    for(int j=0; j<brojflejti;j++,i++){
        instrumenti[i]=&flejti[j];
    }
    string orkestar[]={"Dedo", "Baba", "Tatko", "Majka", "Sin", "Kjerka"};
    cout<<"\tDomashen orkestar: \n"<<endl;
    i=0;
    for(Muzichkiinstrument *pok : instrumenti){
        cout<<left<<setw(10)<<orkestar[i]<<" sviri : ";
        pok->sviri();
        i++;
    }
    cout<<endl<<endl;
    system("PAUSE");
    return 0;
}



























