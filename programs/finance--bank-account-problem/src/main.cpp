#include <iostream>
#include<cstring>
#include<cstdlib>

using namespace std;
class PostoeckaSmetka{
private:
    char *msg;
public:
    PostoeckaSmetka(const char *msg = "") {
        this->msg = new char[strlen(msg) + 1];
        strcpy(this->msg, msg);
    }

    ~PostoeckaSmetka() {
        delete[] msg;
    }

    void print() {
        cout << msg;
    }
};

class Smetka{
private:
    char *broj;
    int cena;
    char *mesec;
    bool status;
public:
    Smetka(const char *broj="", int cena=0, const char *mesec="",bool status=false){
        this->broj=new char[strlen(broj)+1];
        strcpy(this->broj,broj);
        this->cena=cena;
        this->mesec=new char[strlen(mesec)+1];
        strcpy(this->mesec,mesec);
        this->status=status;
    }
    Smetka(const Smetka &s){
        broj=new char[strlen(s.broj)+1];
        strcpy(broj,s.broj);
        cena=s.cena;
        mesec=new char[strlen(s.mesec)+1];
        strcpy(mesec,s.mesec);
        status=s.status;
    }
    Smetka &operator=(const Smetka &s){
        if(this!=&s){
            delete[]broj;
            delete[]mesec;
            broj=new char[strlen(s.broj)+1];
            strcpy(broj,s.broj);
            cena=s.cena;
            mesec=new char[strlen(s.mesec)+1];
            strcpy(mesec,s.mesec);
            status=s.status;
        }
        return *this;
    }
    ~Smetka(){
        delete[]broj;
        delete[]mesec;
    }

    const char*getBroj() const{
        return broj;
    }
    const char*getMesec() const{
        return mesec;
    }
    const int getCena() const{
        return cena;
    }
    const bool getStatus() const{
        return status;
    }
    friend bool operator==(const Smetka &p, const Smetka &v){
        return strcmp(p.broj,v.broj)==0;
    }
    friend ostream &operator<<(ostream &o, const Smetka &s){
        o<<s.broj<<"("<<s.mesec<<")"<<" - "<<s.cena<<endl;
        return o;
    }
};

class KorisnichkiProfil{
private:
    char ime[30];
    Smetka smetki[30];
    int n;
public:
    KorisnichkiProfil(const char *ime = "\n"){
        strcpy(this->ime,ime);
        n=0;
    }
    ~KorisnichkiProfil()=default;
    KorisnichkiProfil &operator+=(Smetka s){
        for(int i=0; i<n; i++){
            if(smetki[i]==s)
                throw PostoeckaSmetka("Smetkata vekje postoi");
        }
        smetki[n++]=s;
        return *this;
    }
    friend ostream& operator<<(ostream&o, KorisnichkiProfil &k){
        o<<"Neplateni smetki na korisnikot "<<k.ime<<" se:"<<endl;
        for(int i=0;i<k.n;i++){
            if(!k.smetki[i].getStatus())
                o<<k.smetki[i];
        }
        return o;
    }
    int vkupnacena(int m, int y){
        int vkupno=0;
        char month[3], year[5];
        for(int i=0;i<n;i++){
            strncpy(month,smetki[i].getMesec(),2);
            strncpy(year,smetki[i].getMesec()+3,4);
            int smonth=stoi(month);
            int syear=stoi(year);
            if(smonth==m&&syear==y){
                vkupno+=smetki[i].getCena();
            }
        }
        return vkupno;
    }
};

int main() {
    char broj[50], mesec[8], ime[50];
    int cena, n;
    bool status;


    int tip;
    cin >> tip;

    if (tip == 1) {
        cout << "-----Test Smetka & operator <<-----" << endl;
        cin >> broj >> cena >> mesec >> status;
        Smetka s(broj, cena, mesec, status);
        cout << s;
    } else if (tip == 2) {
        cout << "-----Test Smetka & operator == -----" << endl;
        cin >> broj >> cena >> mesec >> status;
        Smetka s1(broj, cena, mesec, status);
        cin >> broj >> cena >> mesec >> status;
        Smetka s2(broj, cena, mesec, status);
        if (s1 == s2) cout << "Isti se" << endl;
        else cout << "Ne se isti" << endl;

    } else if (tip == 3) {
        cout << "-----Test KorisnichkiProfil & operator += & << -----" << endl;
        cin >> ime >> n;
        KorisnichkiProfil kp(ime);
        for (int i = 0; i < n; i++) {
            cin >> broj >> cena >> mesec >> status;
            Smetka s(broj, cena, mesec, status);
            kp += s;
        }
        cout << kp;
    } else if (tip == 4) {
        cout << "-----Test KorisnichkiProfil & operator += & vkupnaCena -----" << endl;
        cin >> ime >> n;
        KorisnichkiProfil kp(ime);
        for (int i = 0; i < n; i++) {
            cin >> broj >> cena >> mesec >> status;
            Smetka s(broj, cena, mesec, status);
            try {
                kp += s;
            } catch (PostoeckaSmetka exc) {
                exc.print();
            }
        }
        int m, y;
        cin >> m >> y;
        cout << "Vkupnata cena za mesec " << m << " i godina " << y << " e:";
        cout << kp.vkupnacena(m, y) << endl;
    } else if (tip == 5) {
        cout << "-----Test Exception -----" << endl;
        cin >> ime >> n;
        KorisnichkiProfil kp(ime);
        for (int i = 0; i < n; i++) {
            cin >> broj >> cena >> mesec >> status;
            Smetka s(broj, cena, mesec, status);
            try {
                kp += s;
            } catch (PostoeckaSmetka exc) {
                exc.print();
            }
        }
        cout << kp;

    } else if (tip == 6) {
        cout << "-----Test all -----" << endl;
        cin >> ime >> n;
        KorisnichkiProfil kp(ime);
        for (int i = 0; i < n; i++) {
            cin >> broj >> cena >> mesec >> status;
            Smetka s(broj, cena, mesec, status);
            try {
                kp += s;
            } catch (PostoeckaSmetka exc) {
                exc.print();
            }
        }
        cout << kp;
        int m, y;
        cin >> m >> y;
        cout << "Vkupnata cena za mesec " << m << " i godina " << y << " e:";
        cout << kp.vkupnacena(m, y) << endl;

    }

    return 0;
}
