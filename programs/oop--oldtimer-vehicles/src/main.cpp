#include<iostream>
#include<cstring>
using namespace std;
class Exception{
private:
    char *noldtimer;
public:
    Exception(char *noldtimer){
        this->noldtimer=new char[strlen(noldtimer)+1];
        strcpy(this->noldtimer,noldtimer);
    }
    void pecati(){
        cout<<noldtimer;
    }
};
class Oldtimer{
private:
    char *model;
    char shasija[15];
    int mokjnost;
    bool sostojba;
    int godina;
public:

    Oldtimer(char *model="",char *shasija="",int mokjnost=0,bool sostojba=false,int godina=0){
        this->model=new char[strlen(model)+1];
        strcpy(this->model,model);
        strcpy(this->shasija,shasija);
        this->mokjnost=mokjnost;
        this->sostojba=sostojba;
        this->godina=godina;
    }
    Oldtimer(const Oldtimer &o){
        model=new char[strlen(model)+1];
        strcpy(model,o.model);
        strcpy(shasija,o.shasija);
        mokjnost=o.mokjnost;
        sostojba=o.sostojba;
        godina=o.godina;
    }
    ~Oldtimer(){
        delete [] model;
    }
    void pechati(){
        cout<<model<<"-"<<shasija<<endl;
    }


};

class OldMuseum{
private:
    char *ime;
    Oldtimer *eksponati;
    int brojvozila;
public:
    OldMuseum(char*ime="",Oldtimer*eksponanti=0,int brojvozila=0){
        this->ime=new char[strlen(ime)+1];
        strcpy(this->ime,ime);
        this->brojvozila=brojvozila;
        this->eksponati=new Oldtimer[brojvozila];
        for(int i=0;i<brojvozila;i++){
            this->eksponati[i]=eksponati[i];
        }
    }
    OldMuseum(const OldMuseum &o){
        ime=new char[strlen(ime)+1];
        strcpy(ime,o.ime);
        brojvozila=brojvozila;
        eksponati=new Oldtimer[brojvozila];
        for(int i=0;i<brojvozila;i++){
            eksponati[i]=o.eksponati[i];
        }
    }
    ~OldMuseum(){
        delete [] ime;
        delete [] eksponati;
    }
    friend ostream& operator<<(ostream &o,OldMuseum old){
        o<<old.ime<<endl;
        for(int i=0;i<old.brojvozila;i++){
            o<<old.eksponati[i]<<endl;
        }
        return o;
    }
    OldMuseum& operator+=(const OldMuseum& o){
        bool isti=false;
        for (int i=0;i<brojvozila;i++)
        if(!strcmp(o.eksponati[i].model,eksponati[i].model)==0){
            isti=true;
        }
        OldMuseum temp;
        temp=new OldMuseum[brojvozila];
        for (int i=0;i<brojvozila;i++){
            temp[i]=eksponati[i];
        }
        temp[brojvozila++]=o;
        delete [] eksponati;
        eksponati=temp;
    }
    friend bool &operator==(const OldMuseum& o,const OldMuseum &a){
        if(o.brojvozila==a.brojvozila){
            return true;
        }
        return false;
    }
    void print(){
        cout<<ime<<endl;
    }
};
void statistics(OldMuseum niza[],brojmuzei){
    OldMuseum muzejsonajstarovozilo;
    muzejsonajstarovozilo=niza[0];
    for(int i=0;i<brojmuzei;i++){
        for(j=0;j<niza.brojvozila;j++)
        if(niza[i].eksponati[j].godina>niza[i+1].eksponati.godina&&i!=j){
            muzejsonajstarovozilo=niza[i+1];
        }
    }
    muzejsonajstarovozilo.print();
    for(int i=0;i<muzejsonajstarovozilo.brojvozila;i++)
    muzejsonajstarovozilo.eksponati[i].pechati();


}
int main(){
    int test;
    cin >> test;
    if(test == 1){
        cout << "Testing class Oldtimer" << endl;
        char model[50], br_shasija[50];
        int mokjnost, godina;
        bool vozna_sostojba;
        cin >> model >> br_shasija >> mokjnost >> godina >> vozna_sostojba;
        Oldtimer a;
        Oldtimer b(model, br_shasija, mokjnost, vozna_sostojba, godina);
        cout << b.get_model() << endl;
        cout << b.get_br_shasija() << endl;
    }
    else if(test == 2){
        cout << "Testing class Exception" << endl;
        char model[50], br_shasija[50];
        int mokjnost, godina;
        bool vozna_sostojba;
        cin >> model >> br_shasija >> mokjnost >> godina >> vozna_sostojba;
        Oldtimer o(model, br_shasija, mokjnost, vozna_sostojba, godina);
        catch(Exception e){
            e.pecati();
        }
        cout << o.get_model() << endl;
        cout << o.get_br_shasija() << endl;
    }
    else if(test == 3){
        cout << "Testing class OldMuseum constructor" << endl;
        char name[50];
        cin >> name;
        OldMuseum o(name);
        cout << name;
    }
    else if(test == 4){
        cout << "Testing class OldMuseum operator<< and operator+=" << endl;
        char model[50], br_shasija[50], name[50];
        int mokjnost, godina;
        bool vozna_sostojba;
        cin>>name;
        OldMuseum o(name);
        for(int i = 0; i < 2; i++){
            cin >> model >> br_shasija >> mokjnost >> godina >> vozna_sostojba;
            Oldtimer car(model, br_shasija, mokjnost, vozna_sostojba, godina);
            o+=car;
        }
        cout << o;
    }
    else if(test == 5){
        cout << "Testing class OldMuseum operator==" << endl;
        char model[50], br_shasija[50], name[50];
        int mokjnost, godina;
        bool vozna_sostojba;
        cin>>name;
        OldMuseum o1(name);
        cin>>name;
        OldMuseum o2(name);
        for(int i = 0; i < 2; i++){
            cin >> model >> br_shasija >> mokjnost >> godina >> vozna_sostojba;
            Oldtimer car(model, br_shasija, mokjnost, vozna_sostojba, godina);
            o1+=car;
            o2+=car;
        }
        cin >> model >> br_shasija >> mokjnost >> godina >> vozna_sostojba;
        Oldtimer car(model, br_shasija, mokjnost, vozna_sostojba, godina);
        o1+=car;
        if(o1 == o2){
            cout << "True";
        } else{
            cout<<"False";
        }
    }
    else if(test == 6){
        cout << "Testing statistics" << endl;
        OldMuseum niza[2];
        char model[50], br_shasija[50], name[50];
        int mokjnost, godina;
        bool vozna_sostojba;
        for(int i=0;i<2;i++){
            cin>>name;
            OldMuseum o2(name);
            niza[i]=o2;
            for(int j=0;j<2;j++){
                cin >> model >> br_shasija >> mokjnost >> godina >> vozna_sostojba;
                Oldtimer car(model, br_shasija, mokjnost, vozna_sostojba, godina);
                niza[i]+=car;
            }
        }
        statistics(niza,2);

    }
    return 0;
}
