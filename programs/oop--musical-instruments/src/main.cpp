#include <iostream>
#include <cstring>
using namespace std;
class InstrumentTypeAlreadyExists{
private:
    char message[100];
public:
    InstrumentTypeAlreadyExists(char *message){
        strcpy_s(this->message, sizeof(this->message), message);
    }
    void print(){
        cout<<message<<endl;
    }
};
class MusicalInstrument {
private:
    char *ime;
    char vid[10];
    int cena;
    int godina;
    bool vrednost;
public:
    MusicalInstrument() {}
    MusicalInstrument(char *ime, char *vid, int cena, int godina,bool vrednost) {
        this->ime=new char[strlen(ime)+1];
        strcpy_s(this->ime, strlen(ime)+1, ime);
        strcpy_s(this->vid, sizeof(this->vid), vid);
        this->cena=cena;
        this->godina=godina;
        this->vrednost=vrednost;
    }
    MusicalInstrument(const MusicalInstrument &o) {
        this->ime=new char[strlen(o.ime)+1];
        strcpy_s(this->ime, strlen(o.ime)+1, o.ime);
        strcpy_s(this->vid, sizeof(this->vid), o.vid);
        this->cena=o.cena;
        this->godina=o.godina;
        this->vrednost=o.vrednost;
    }
    ~MusicalInstrument() {
        delete [] ime;
    }
    MusicalInstrument &operator =(const MusicalInstrument &o) {
        if(this!=&o) {
            delete[]ime;
            this->ime=new char[strlen(o.ime)+1];
            strcpy_s(this->ime, strlen(o.ime)+1, o.ime);
            strcpy_s(this->vid, sizeof(this->vid), o.vid);
            this->cena=o.cena;
            this->godina=o.godina;
            this->vrednost=o.vrednost;
        }
        return *this;
    }
    const char *getName() const {
        return ime;
    }
    const int getPrice() const {
        return cena;
    }
    const int getAge() const {
        return godina;
    }
    const char *getVid() const {
        return vid;
    }
    friend ostream &operator<<(ostream &o,const MusicalInstrument &instrument) {
        o<<instrument.ime<<" - "<<instrument.vid<<endl<<instrument.godina<<", "<<instrument.cena;
        return o;
    }

    friend int &operator+=(MusicalInstrument &ins,int a) {
        ins.cena+=a;
        return ins.cena;
    }

    bool isValuable() const { return vrednost; }
};
class Band {
private:
    char ime[100];
    MusicalInstrument *instrumenti;
    int brojinstrumenti;
public:
    Band() {}
    Band(char *ime) {
        strcpy_s(this->ime, sizeof(this->ime), ime);
        this->instrumenti=new MusicalInstrument[brojinstrumenti];
        this->brojinstrumenti=0;
        this->instrumenti=nullptr;
    }
    Band(const Band &b) {
        strcpy_s(this->ime, sizeof(this->ime), b.ime);
        this->instrumenti=new MusicalInstrument[b.brojinstrumenti];
        this->brojinstrumenti=0;
        this->instrumenti=nullptr;
    }
    Band &operator =(const Band &b) {
        if(this!=&b) {
            strcpy_s(this->ime, sizeof(this->ime), b.ime);
            delete []instrumenti;
            this->brojinstrumenti=0;
            this->instrumenti=nullptr;
        }
        return *this;
    }
    const char *getName() const{
        return ime;
    }
    ~Band(){
        delete [] instrumenti;
    }
    void setIme(const char *ime) {
        strcpy_s(this->ime, sizeof(this->ime), ime);
    }
    friend ostream &operator<<(ostream &o,const Band &b) {
        o<<b.ime<<endl;
        for(int i=0; i<b.brojinstrumenti; i++) {
            o<<b.instrumenti[i];
            o<<endl;
        }
        return o;
    }
    Band &operator +=(const MusicalInstrument &a){
        MusicalInstrument *temp = new MusicalInstrument[brojinstrumenti+1];
        for(int i=0;i<brojinstrumenti;i++){
            if(strcmp(instrumenti[i].getVid(),a.getVid())==0){
                throw InstrumentTypeAlreadyExists("Instrument type already exists");
            } else
            temp[i]=instrumenti[i];
        }
        temp[brojinstrumenti++]=a;
        delete [] instrumenti;
        instrumenti=temp;
        return *this;
    }

   friend bool operator ==(const Band &a, const Band &b){
        if(a.brojinstrumenti==b.brojinstrumenti){
            for(int i=0;i<a.brojinstrumenti;i++){
                if(a.instrumenti[i].getPrice()==b.instrumenti[i].getPrice())
                    return true;
            }
        }
        else
            return false;
    }

    // Added methods for accessing instruments
    int getInstrumentCount() const { return brojinstrumenti; }
    const MusicalInstrument& getInstrument(int idx) const { return instrumenti[idx]; }
};


void oldest_valuable_instrument(Band *bands, int n) {
    int max_age = -1;
    const MusicalInstrument *oldest = nullptr;
    char band_name[100] = "";

    for (int i = 0; i < n; ++i) {
        Band &b = bands[i];
        int count = b.getInstrumentCount();
        for (int j = 0; j < count; ++j) {
            const MusicalInstrument &ins = b.getInstrument(j);
            if (ins.isValuable()) {
                if (ins.getAge() > max_age) {
                    max_age = ins.getAge();
                    oldest = &ins;
                    strcpy_s(band_name, sizeof(band_name), b.getName());
                }
            }
        }
    }
    if (oldest) {
        cout << "The oldest valuable instrument is:" << endl;
        cout << *oldest << endl;
        cout << "Band: " << band_name << endl;
    }
}

int main() {
    int test;
    cin >> test;
    if(test == 1) {
        cout << "Testing class MusicalInstrument" << endl;
        char name[50], type[50];
        int price, age;
        bool museumValue;
        cin >> name >> type >> price >> age >> museumValue;
        MusicalInstrument a;
        MusicalInstrument b(name, type, price, age, museumValue);
        a=b;
        cout << a.getName() << endl;
        cout << b.getPrice() << endl;
        cout << b.getAge() << endl;
    } else if(test == 2) {
        cout << "Testing operators += and << in the class MusicalInstrument" << endl;
        char name[50], type[50];
        int price, age;
        bool muaseumValue;
        cin >> name >> type >> price >> age >> muaseumValue;
        MusicalInstrument a(name, type, price, age, muaseumValue);
        a += 100;
        cout << a << endl;
    } else if(test == 3) {
        cout << "Testing class Band constructor" << endl;
        char name[50];
        cin >> name;
        Band b(name);
        cout << b.getName() << endl;
    } else if(test == 4) {
        cout << "Testing class Band operator<<" << endl;
        char ime[50], tip[50];
        int cena_cinenje, godini_starost;
        bool muzejska_vrednost;
        cin>>ime;
        Band b(ime);
        for(int i = 0; i < 2; i++) {
            cin >> ime >> tip >> cena_cinenje >> godini_starost >> muzejska_vrednost;
            MusicalInstrument a(ime, tip, cena_cinenje, godini_starost, muzejska_vrednost);
            b+=a;
        }
        cout << b;
    }
    else if(test == 5){
        cout << "Testing operator+= and class InstrumentTypeAlreadyExists" << endl;
        char name[50], type[50];
        int price, age;
        bool museumValue;
        cin>>name;
        Band band(name);
        cin >> name >> type >> price >> age >> museumValue;
        MusicalInstrument a(name, type, price, age, museumValue);
        cin >> name >> type >> price >> age >> museumValue;
        MusicalInstrument b(name, type, price, age, museumValue);

        band += a;
        try{
            band += b;
        }
        catch (InstrumentTypeAlreadyExists &o){
            o.print();
        }


        cout << band;
    }
    else if(test == 6){
        cout << "Testing class Band operator==" << endl;
        char name[50], type[50];
        int price, age;
        bool museumValue;
        cin>>name;
        Band band1(name);
        cin>>name;
        Band band2(name);
        for(int i = 0; i < 2; i++){
            cin >> name >> type >> price >> age >> museumValue;
            MusicalInstrument a(name, type, price, age, museumValue);
            band1+=a;
            band2+=a;
        }
        int c;
        cin>>c;
        if (c){
            cin >> name >> type >> price >> age >> museumValue;
            MusicalInstrument a(name, type, price, age, museumValue);
            band1+=a;
        }
        if(band1 == band2){
            cout << "True";
        } else{
            cout<<"False";
        }
    }
    else if(test == 7){
        cout << "Testing oldest_valuable_instrument" << endl;
        Band b[2];
        char name[50], type[50];
        int price, age;
        bool museumValue;
        for(int i=0;i<2;i++){
            cin>>name;
            b[i].setIme(name);
            for(int j=0;j<2;j++){
                cin >> name >> type >> price >> age >> museumValue;
                MusicalInstrument a(name, type, price, age, museumValue);
                b[i]+=a;
            }
        }
        oldest_valuable_instrument(b,2);

    }
    return 0;
}
