#include <iostream>
#include <cstring>

using namespace std;

class SMS {
protected:
    int osnovnacena;
    char *sodrzhina;
    char broj[20];
public:
    SMS() = default;

    SMS(char *broj, char *sodrzhina, int osnovnacena) {
        this->osnovnacena = osnovnacena;
        this->sodrzhina = new char[strlen(sodrzhina) + 1];
        strcpy(this->sodrzhina, sodrzhina);
        strcpy(this->broj, broj);
    }

    SMS(const SMS &s) {
        osnovnacena = s.osnovnacena;
        sodrzhina = new char[strlen(s.sodrzhina) + 1];
        strcpy(sodrzhina, s.sodrzhina);
        strcpy(broj, s.broj);
    }

    SMS &operator=(const SMS &s) {
        if (this != &s) {
            delete[]sodrzhina;
            osnovnacena = s.osnovnacena;
            sodrzhina = new char[strlen(s.sodrzhina) + 1];
            strcpy(sodrzhina, s.sodrzhina);
            strcpy(broj, s.broj);
        }
        return *this;
    }

    ~SMS() {
        delete[]sodrzhina;
    }

    virtual float SMS_cena() = 0;

    bool operator < (SMS &s){
        return SMS_cena()<s.SMS_cena();
    }
    friend ostream &operator<<(ostream &o,SMS &s){
        o<<s.broj<<": "<<s.sodrzhina<<" - "<<s.SMS_cena()<<endl;
        return o;
    }
};

class RegularSMS : public SMS {
private:
    bool roaming;
public:
    RegularSMS() = default;

    RegularSMS(char *broj, char *sodrzhina, int osnovnacena, bool roaming) : SMS(broj, sodrzhina, osnovnacena) {
        this->roaming = roaming;
    }

    RegularSMS(const RegularSMS &s) : SMS(s) {
        roaming = s.roaming;
    }

    RegularSMS &operator=(const RegularSMS &s) {
        if (this != &s) {
            delete[]sodrzhina;
            osnovnacena = s.osnovnacena;
            sodrzhina = new char[strlen(s.sodrzhina) + 1];
            strcpy(sodrzhina, s.sodrzhina);
            strcpy(broj, s.broj);
            roaming = s.roaming;
        }
        return *this;
    }

    ~RegularSMS() = default;

    float SMS_cena() {
        int poraki=strlen(sodrzhina)/16+1;
        float cena=osnovnacena;
        if(roaming){
            cena=cena+(cena*1.2);
        } else {
            cena=cena+(cena*0.18);
        }
        return cena*poraki;
    }
};

class SpecialSMS : public SMS {
private:
    bool humanitarni;
public:
    SpecialSMS() = default;

    SpecialSMS(char *broj, char *sodrzhina, int osnovnacena, bool humanitarni) : SMS(broj, sodrzhina, osnovnacena) {
        this->humanitarni = humanitarni;
    }

    SpecialSMS(const SpecialSMS &s) : SMS(s) {
        humanitarni = s.humanitarni;
    }

    SpecialSMS &operator=(const SpecialSMS &s) {
        if (this != &s) {
            delete[]sodrzhina;
            osnovnacena = s.osnovnacena;
            sodrzhina = new char[strlen(s.sodrzhina) + 1];
            strcpy(sodrzhina, s.sodrzhina);
            strcpy(broj, s.broj);
            humanitarni = s.humanitarni;
        }
        return *this;
    }

    ~SpecialSMS() = default;

    float SMS_cena() {
        float cena=osnovnacena;
        if(!humanitarni){
            cena=cena+(cena*0.18);
        }
        return cena;
    }
};

void najskapaSMS (SMS** sms, int n){
    float cenar=0;
    float cenas=0;

    for(int i=0;i<n;i++){
        RegularSMS *a=dynamic_cast<RegularSMS*>(sms[i]);
        SpecialSMS *b=dynamic_cast<SpecialSMS*>(sms[i]);
        if(a){
            cenar+=sms[i]->SMS_cena();
        }
        if(b){
            cenas+=sms[i]->SMS_cena();
        }
    }
    float prv= sms[0]->SMS_cena();
    int index;
    for(int i=0;i<n;i++){
        if(sms[i]->SMS_cena()>prv){
            prv=sms[i]->SMS_cena();
            index=i;
        }
    }
    cout << "Vkupnata cena na regularni SMS poraki: " << cenar << endl;
    cout << "Vkupnata cena na specijalni SMS poraki: " << cenas << endl;
    cout << "Najskapa poraka e: " << endl;
    cout<<*sms[index];
}

int main() {

    char tel[20], msg[1000];
    int cena;
    float price;
    bool roam, hum;
    SMS **sms;
    int n;
    int tip;

    int testCase;
    cin >> testCase;

    if (testCase == 1) {
        cout << "====== Testing RegularSMS class ======" << endl;
        cin >> n;
        sms = new SMS *[n];

        for (int i = 0; i < n; i++) {
            cin >> tel;
            cin.get();
            cin.getline(msg, 1000);
            cin >> cena;
            cin >> roam;
            cout << "CONSTRUCTOR" << endl;
            sms[i] = new RegularSMS(tel, msg, cena, roam);
            cout << "OPERATOR <<" << endl;
            cout << *sms[i];
        }
        cout << "OPERATOR <" << endl;
        cout << "Rezultat od sporedbata e: " << endl;
        if (*sms[0] < *sms[1])
            cout << *sms[0];
        else
            cout << *sms[1];
    }
    if (testCase == 2) {
        cout << "====== Testing SpecialSMS class ======" << endl;
        cin >> n;
        sms = new SMS *[n];

        for (int i = 0; i < n; i++) {
            cin >> tel;
            cin.get();
            cin.getline(msg, 1000);
            cin >> cena;
            cin >> hum;
            cout << "CONSTRUCTOR" << endl;
            sms[i] = new SpecialSMS(tel, msg, cena, hum);
            cout << "OPERATOR <<" << endl;
            cout << *sms[i];
        }
        cout << "OPERATOR <" << endl;
        cout << "Rezultat od sporedbata e: " << endl;
        if (*sms[0] < *sms[1])
            cout << *sms[0];
        else
            cout << *sms[1];
    }
    if (testCase == 3) {
        cout << "====== Testing method najskapaSMS() ======" << endl;
        cin >> n;
        sms = new SMS *[n];

        for (int i = 0; i < n; i++) {

            cin >> tip;
            cin >> tel;
            cin.get();
            cin.getline(msg, 1000);
            cin >> cena;
            if (tip == 1) {

                cin >> roam;

                sms[i] = new RegularSMS(tel, msg, cena, roam);

            } else {
                cin >> hum;

                sms[i] = new SpecialSMS(tel, msg, cena, hum);
            }
        }

        najskapaSMS(sms, n);
    }
    for (int i = 0; i < n; i++) delete sms[i];
    delete[] sms;
    return 0;
}
