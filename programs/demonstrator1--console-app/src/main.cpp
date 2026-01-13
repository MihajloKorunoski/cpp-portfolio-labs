#include <iostream>
#include <cstring>
using namespace std;
class NoCourseException {
private:
    int indeks;
public:
    NoCourseException(int indeks) {
        this->indeks=indeks;
    }
    void print() {
        cout<<"Demonstratorot so indeks"<<indeks<<"ne drzi laboratoriski vezbi"<<endl;
    }
};
class Kurs {
private:
    char ime[20];
    int krediti;
public:
    Kurs()=default;
    Kurs(char *ime, int krediti) {
        this->krediti=krediti;
        strcpy(this->ime, ime);
    }
    Kurs(const Kurs &k) {
        krediti=k.krediti;
        strcpy(ime, k.ime);
    }
    Kurs& operator=(const Kurs &k) {
        if(this!=&k) {
            krediti=k.krediti;
            strcpy(ime, k.ime);
        }
        return *this;
    }
    ~Kurs()=default;
    void pechati () const {
        cout<<ime<<" "<<krediti<<" ECTS";
    }


};
class Student {
private:
    int indeks;
    int *ocenki;
    int brocenki;
public:
    Student()=default;
    Student(int indeks, int *ocenki, int brojocenki) {
        this->indeks=indeks;
        this->brocenki=brocenki;
        this->ocenki=new int[brocenki];
        for(int i=0; i<brocenki; i++) {
            this->ocenki[i]=ocenki[i];
        }
    }
    Student(const Student &s) {
        this->indeks=s.indeks;
        this->brocenki=s.brocenki;
        this->ocenki=new int[s.brocenki];
        for(int i=0; i<s.brocenki; i++) {
            this->ocenki[i]=s.ocenki[i];
        }
    }
    Student &operator=(const Student &s) {
        if(this!=&s) {
            this->indeks=s.indeks;
            this->brocenki=s.brocenki;
            this->ocenki=new int[s.brocenki];
            for(int i=0; i<s.brocenki; i++) {
                this->ocenki[i]=s.ocenki[i];
            }
        }
        return *this;
    }
    ~Student() {
        delete[]ocenki;
    }
    virtual int getBodovi() {
        float bodovi=0;
        for(int i=0; i<brocenki; i++) {
            if(ocenki[i]==5)
                bodovi++;
        }
        bodovi/=brocenki;
        bodovi*=100;
        return (int) bodovi;
    }
    const int getIndeks() const {
        return indeks;
    }
    virtual void pechati() {
        cout<<indeks;
    }
};
class Predavach {
private:
    char *ime;
    Kurs kursevi[10];
    int brkursevi;
public:
    Predavach()=default;
    Predavach(char *ime, Kurs *kursevi, int brkursevi) {
        this->brkursevi=brkursevi;
        for(int i=0; i<brkursevi; i++) {
            this->kursevi[i]=kursevi[i];
        }
        this->ime=new char[strlen(ime)+1];
        strcpy(this->ime,ime);
    }
    Predavach(const Predavach &p) {
        this->brkursevi=p.brkursevi;
        for(int i=0; i<p.brkursevi; i++) {
            this->kursevi[i]=p.kursevi[i];
        }
        this->ime=new char[strlen(p.ime)+1];
        strcpy(this->ime,p.ime);
    }
    Predavach &operator =(const Predavach &p) {
        if(this!=&p) {
            delete[]ime;
            this->brkursevi=p.brkursevi;
            for(int i=0; i<p.brkursevi; i++) {
                this->kursevi[i]=p.kursevi[i];
            }
            this->ime=new char[strlen(p.ime)+1];
            strcpy(this->ime,p.ime);
        }
        return *this;
    }
    ~Predavach() {
        delete[]ime;
    }
    const int getBrkursevi() const {
        return brkursevi;
    }
    void pechati() {
        cout<<": "<<ime<<" (";
        for(int i=0; i<brkursevi-1; i++) {
            kursevi[i].pechati();
            cout<<", ";
        }
        kursevi[brkursevi].pechati();
        cout<<")";
    }
    Kurs operator[](int i) const{
        if(i<brkursevi&&i>=0)
            return kursevi[i];
        else return Kurs();
    }

};
class Demonstrator : public Student, public Predavach {
private:
    int brchasovi;
public:
    Demonstrator(int indeks, int *ocenki, int brocenki,char *ime, Kurs *kursevi, int brkursevi,int brchasovi) :
            Student(indeks,ocenki,brocenki),
            Predavach(ime,kursevi,brkursevi) {
        this->brchasovi=brchasovi;
    }
    Demonstrator(const Demonstrator &d) : Student(d),Predavach(d) {
        this->brchasovi=d.brchasovi;
    }
    Demonstrator &operator =(const Demonstrator &d) {
        if(this!=&d) {
            brchasovi=d.brchasovi;
        }
        return *this;
    }
    int getBodovi() {
        if(brchasovi==0) {
            throw NoCourseException(getIndeks());
        }
        float pom=Student::getBodovi()+((20*brchasovi)/getBrkursevi());
        return (int) pom;
    }
    void pechati() {
        Student::pechati();
        if(getBrkursevi()==0) {
            return;
        } else {
            Predavach::pechati();
        }
    }
};
Student& vratiNajdobroRangiran(Student ** studenti, int n ) {
    Student *max = studenti[0];
    for(int i=0; i<n; i++) {
        try {
            if(studenti[i]->getBodovi()>max->getBodovi())
                max=studenti[i];
        } catch(NoCourseException &e) {
            e.print();
        }
    }
    return *max;
}
void pecatiDemonstratoriKurs (char* kurs, Student** studenti, int n) {
    for(int i=0; i<n; i++) {
        Demonstrator *d=dynamic_cast<Demonstrator*>(studenti[i]);
        if(d) {
            for(int j=0; j<d->getBrkursevi(); j++) {
                if(strcmp(kurs,(*d)[j].getIme())==0) {
                    d->pechati();
                    cout<<endl;
                    break;
                }
            }
        }
    }
}
int main() {

    Kurs kursevi[10];
    int indeks,brojKursevi, ocenki[20],ocenka,brojOcenki,tip,brojCasovi,krediti;
    char ime[20],imeIPrezime[50];

    cin>>tip;

    if (tip==1) { //test class Demonstrator
        cout<<"-----TEST Demonstrator-----"<<endl;
        cin>>indeks>>brojOcenki;
        for (int i=0; i<brojOcenki; i++) {
            cin>>ocenka;
            ocenki[i]=ocenka;
        }
        cin>>imeIPrezime>>brojKursevi;
        for (int i=0; i<brojKursevi; i++) {
            cin>>ime>>krediti;
            kursevi[i]=Kurs(ime,krediti);
        }
        cin>>brojCasovi;

        Demonstrator d(indeks,ocenki,brojOcenki,imeIPrezime,kursevi,brojKursevi,brojCasovi);
        cout<<"Objekt od klasata Demonstrator e kreiran";

    } else if (tip==2) { //funkcija pecati vo Student
        cout<<"-----TEST pecati-----"<<endl;
        cin>>indeks>>brojOcenki;
        for (int i=0; i<brojOcenki; i++) {
            cin>>ocenka;
            ocenki[i]=ocenka;
        }

        Student s(indeks,ocenki,brojOcenki);
        s.pechati();

    } else if (tip==3) { //funkcija getVkupnaOcenka vo Student
        cout<<"-----TEST getVkupnaOcenka-----"<<endl;
        cin>>indeks>>brojOcenki;
        for (int i=0; i<brojOcenki; i++) {
            cin>>ocenka;
            ocenki[i]=ocenka;
        }
        Student s(indeks,ocenki,brojOcenki);
        cout<<"Broj na bodovi: "<<s.getBodovi()<<endl;

    } else if (tip==4) { //funkcija getVkupnaOcenka vo Demonstrator
        cout<<"-----TEST getVkupnaOcenka-----"<<endl;
        cin>>indeks>>brojOcenki;
        for (int i=0; i<brojOcenki; i++) {
            cin>>ocenka;
            ocenki[i]=ocenka;
        }
        cin>>imeIPrezime>>brojKursevi;
        for (int i=0; i<brojKursevi; i++) {
            cin>>ime>>krediti;
            kursevi[i]=Kurs(ime,krediti);
        }
        cin>>brojCasovi;

        Demonstrator d(indeks,ocenki,brojOcenki,imeIPrezime,kursevi,brojKursevi,brojCasovi);
        cout<<"Broj na bodovi: "<<d.getBodovi()<<endl;

    } else if (tip==5) { //funkcija pecati vo Demonstrator
        cout<<"-----TEST pecati -----"<<endl;
        cin>>indeks>>brojOcenki;
        for (int i=0; i<brojOcenki; i++) {
            cin>>ocenka;
            ocenki[i]=ocenka;
        }
        cin>>imeIPrezime>>brojKursevi;
        for (int i=0; i<brojKursevi; i++) {
            cin>>ime>>krediti;
            kursevi[i]=Kurs(ime,krediti);
        }
        cin>>brojCasovi;

        Demonstrator d(indeks,ocenki,brojOcenki,imeIPrezime,kursevi,brojKursevi,brojCasovi);
        d.pechati();

    } else if (tip==6) { //site klasi
        cout<<"-----TEST Student i Demonstrator-----"<<endl;
        cin>>indeks>>brojOcenki;
        for (int i=0; i<brojOcenki; i++) {
            cin>>ocenka;
            ocenki[i]=ocenka;
        }
        cin>>imeIPrezime>>brojKursevi;
        for (int i=0; i<brojKursevi; i++) {
            cin>>ime>>krediti;
            kursevi[i]=Kurs(ime,krediti);
        }
        cin>>brojCasovi;

        Student *s=new Demonstrator(indeks,ocenki,brojOcenki,imeIPrezime,kursevi,brojKursevi,brojCasovi);
        s->pechati();
        cout<<"\nBroj na bodovi: "<<s->getBodovi()<<endl;
        delete s;


    } else if (tip==7) { //funkcija vratiNajdobroRangiran
        cout<<"-----TEST vratiNajdobroRangiran-----"<<endl;
        int k, opt;
        cin>>k;
        Student **studenti=new Student*[k];
        for (int j=0; j<k; j++) {
            cin>>opt; //1 Student 2 Demonstrator
            cin>>indeks>>brojOcenki;
            for (int i=0; i<brojOcenki; i++) {
                cin>>ocenka;
                ocenki[i]=ocenka;
            }
            if (opt==1) {
                studenti[j]=new Student(indeks,ocenki,brojOcenki);
            } else {
                cin>>imeIPrezime>>brojKursevi;
                for (int i=0; i<brojKursevi; i++) {
                    cin>>ime>>krediti;
                    kursevi[i]=Kurs(ime,krediti);
                }
                cin>>brojCasovi;
                studenti[j]=new Demonstrator(indeks,ocenki,brojOcenki,imeIPrezime,kursevi,brojKursevi,brojCasovi);
            }
        }
        Student& najdobar=vratiNajdobroRangiran(studenti,k);
        cout<<"Maksimalniot broj na bodovi e:"<<najdobar.getBodovi();
        cout<<"\nNajdobro rangiran:";
        najdobar.pechati();

        for (int j=0; j<k; j++) delete studenti[j];
        delete [] studenti;
    } else if (tip==8) { //funkcija pecatiDemonstratoriKurs
        cout<<"-----TEST pecatiDemonstratoriKurs-----"<<endl;
        int k, opt;
        cin>>k;
        Student **studenti=new Student*[k];
        for (int j=0; j<k; j++) {
            cin>>opt; //1 Student 2 Demonstrator
            cin>>indeks>>brojOcenki;
            for (int i=0; i<brojOcenki; i++) {
                cin>>ocenka;
                ocenki[i]=ocenka;
            }
            if (opt==1) {
                studenti[j]=new Student(indeks,ocenki,brojOcenki);
            } else {
                cin>>imeIPrezime>>brojKursevi;
                for (int i=0; i<brojKursevi; i++) {
                    cin>>ime>>krediti;
                    kursevi[i]=Kurs(ime,krediti);
                }
                cin>>brojCasovi;
                studenti[j]=new Demonstrator(indeks,ocenki,brojOcenki,imeIPrezime,kursevi,brojKursevi,brojCasovi);
            }
        }
        char kurs[20];
        cin>>kurs;
        cout<<"Demonstratori na "<<kurs<<" se:"<<endl;
        pecatiDemonstratoriKurs (kurs,studenti,k);
        for (int j=0; j<k; j++) delete studenti[j];
        delete [] studenti;

    }

    return 0;
}