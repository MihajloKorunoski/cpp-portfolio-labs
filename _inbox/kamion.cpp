#include<iostream>
#include<cstring>
using namespace std;
 
class ExceptionNepravilnaRegistracija{
protected:
    char* text;
public:
    ExceptionNepravilnaRegistracija(char* t){
        text=new char[strlen(t)+1];
        strcpy(text,t);
    }
   
    void poraka(){
        cout<<text;
    }
};
 
class ImaMasa{
public:
    virtual double vratiMasa()=0;
    virtual void pecati()=0;
};
 
class PaketPijalok:public ImaMasa{
protected:
    double volumenEden;
    int kolicina;
    static const double gustina=0.8;
    static const double ambalaza=0.2;
public:
    PaketPijalok(double vol,int kol){
        kolicina=kol;
        volumenEden=vol;
    }
       
    double vratiMasa(){
        return (volumenEden*gustina+ambalaza)*getKolicina();
    }
   
    void pecati(){
   
    }
   
    int getKolicina(){
        return kolicina;
    }
   
};
 
class PaketSok:public PaketPijalok{
protected:
    bool daliGaziran;
public:
    PaketSok(double vol,int kol,bool g):PaketPijalok(vol,kol){
        daliGaziran=g;
    }
   
    double vratiMasa(){
        if(daliGaziran) return PaketPijalok::vratiMasa();
        return kolicina*0.1 + PaketPijalok::vratiMasa();
    }
   
    void pecati(){
        cout<<"Paket sok"<<endl;
        cout<<"kolicina "<<kolicina<<", so po "<<volumenEden*gustina<<" l(dm3)"<<endl;
    }
};
 
class PaketVino:public PaketPijalok{
protected:
    double procentAlkohol;
public:
    PaketVino(double vol,int kol,double proc):PaketPijalok(vol,kol){
        procentAlkohol=proc;
    }
   
    double vratiMasa(){
        return PaketPijalok::vratiMasa()*(0.9+procentAlkohol);
    }
   
    double getProcentAlkohol(){
        return procentAlkohol;
    }
   
    void pecati(){
        cout<<"Paket vino"<<endl;
        cout<<"kolicina "<<kolicina<<", "<<procentAlkohol*100<<"% alkohol od po "<<gustina*volumenEden<<" l(dm3)"<<endl;
    }
};
 
class Kamion{
protected:
    char* registracija;
    char* vozach;
    ImaMasa** im;
    int brPaketi;
public:
    Kamion(char* r,char* v){
        vozach=new char[strlen(v)+1];
        strcpy(vozach,v);
        this->registriraj(r);
        im=0;
        brPaketi=0;
    }
   
    Kamion(char* v){
        vozach=new char[strlen(v)+1];
        strcpy(vozach,v);
        im=0;
    }
   
    void registriraj(char* r){
        if(r[0]<65 || r[0]>90){
            throw ExceptionNepravilnaRegistracija("Pogresno vnesena registracija");
        }
        if(r[1]<65 || r[1]>90){
            throw ExceptionNepravilnaRegistracija("Pogresno vnesena registracija");
        }
        if(r[6]<65 || r[6]>90){
            throw ExceptionNepravilnaRegistracija("Pogresno vnesena registracija");
        }
        if(r[7]<65 || r[8]>90){
            throw ExceptionNepravilnaRegistracija("Pogresno vnesena registracija");
        }
        registracija=new char[strlen(r)+1];
        strcpy(registracija,r);
    }
   
    void dodadiElement(ImaMasa* i){
        ImaMasa** temp=im;
        im=new ImaMasa* [brPaketi+1];
        for(int i=0;i<brPaketi;i++){
            im[i]=temp[i];
        }
        delete [] temp;
        im[brPaketi++]=i;
    }
   
    double vratiVkupnaMasa(){
        double vkupnaMasa=0;
       
        for(int i=0;i<brPaketi;i++){
            vkupnaMasa+=im[i]->vratiMasa();
        }
       
        return vkupnaMasa;
   
    }
   
    void pecati(){
        cout<<"Kamion so registracija "<<registracija<<" i vozac "<<vozach<<" prenesuva: "<<endl;
        for(int i=0;i<brPaketi;i++){
            im[i]->pecati();
        }
    }
   
    Kamion pretovar(char* r,char* v){
        Kamion k(r,v);
        int maxMasaIndex=0;
        double maxMasa=im[0]->vratiMasa();
        for(int i=1;i<brPaketi;i++){
            if(im[i]->vratiMasa()>maxMasa){
                maxMasaIndex=i;
                maxMasa=im[i]->vratiMasa();
            }
        }
        k.im=im;
        k.brPaketi=brPaketi-1;
        for(int i=maxMasaIndex;i<k.brPaketi;i++){
            k.im[i]=k.im[i+1];
        }
        return k;
    }
};
 
int main()
{
    char ime[20], reg[9];
    double vol;
    int kol;
    bool g;
    double proc;
    try{
            cin>>reg;
            cin>>ime;
            Kamion A(reg, ime);
            ImaMasa **d = new ImaMasa*[5];
            cin>>vol>>kol;
            cin>>g;
            d[0] = new PaketSok(vol, kol, g);
            cin>>vol>>kol;
            cin>>proc;
            d[1] = new PaketVino(vol, kol, proc);
            cin>>vol>>kol;
            cin>>proc;
            d[2] = new PaketVino(vol, kol, proc);
            cin>>vol>>kol;
            cin>>g;
            d[3] = new PaketSok(vol, kol, g);
            cin>>vol>>kol;
            cin>>proc;
            d[4] = new PaketVino(vol, kol, proc);
 
            A.dodadiElement(d[0]);
            A.dodadiElement(d[1]);
            A.dodadiElement(d[2]);
            A.dodadiElement(d[3]);
            A.dodadiElement(d[4]);
            A.pecati();
            cout<<"Vkupna masa: "<<A.vratiVkupnaMasa()<<endl;
            cin>>reg;
            cin>>ime;
            Kamion B = A.pretovar(reg, ime);
            B.pecati();
            cout<<"Vkupna masa: "<<B.vratiVkupnaMasa()<<endl;
    }catch(ExceptionNepravilnaRegistracija e){
            e.poraka();
    }
    return 0;
}
/*
Камион Problem 1 (2 / 22)
Сите елементи кои ги превезуваат камионите имаат одредена маса. Имплементирајте апстрактна класа ImaMasa од која што ќе наследуваат сите класи кои имаат маса. Во оваа класа треба да се дефинираат методите:

double vratiMasa() враќа маса изразена во kg
void pecati() печати информации за соодветниот објект
Нека еден камион превезува пијалоци и тоа: пакет сокови и пакет вина. Да се дефинираат класите PaketSok и PaketVino кои ги имплементираат методите од апстрактната класа ImaMasa. При тоа да се земе предвид дека класите PaketSok и PaketVino се изведени од класата PaketPijalok. Притоа да се земат дадените податоци:

Класа PaketPijalok:

членови:
volumenEden double
kolicina int
методи:
double vratiMasa()
void pecati()
int getKolicina()
Класа PaketSok:

членови:
volumenEden double
kolicina int
daliGaziran bool
методи:
double vratiMasa()
void pecati()
Класа PaketVino:

членови:
volumenEden double
kolicina int
procentAlkohol double
методи:
double vratiMasa()
double getProcentAlkohol()
void pecati()
Еден пијалок има маса пресметана како производ на волуменот и густината (0.8kg/dm3) и масата на амбалажата (0.2kg). Овие податоци за густината и за масата на амбалажата да се стават како статички податоци за класата PaketPijalok. Масата на пакетот е производ на масата на еден пијалок и количината на пијалоци која ја има во пакетот. Соковите кои не се газирани имаат дополнителна маса од 0.1kg по пијалок. За вината, масата се добива како производ од масата на пакетот пресметан по правилата за секој пијалок помножен со коефициентот: (0.9+procentAlkohol).

Покрај овие класи, да се имплементира класата Kamion. За еден камион се чуваат информации за:

регистрацијата char*
возачот char*
елементите кои ги превезува камионот (низа од покажувачи од ImaMasa)
Во класата Kamion покрај методите set и get дефинирајте ги и следните методи:

Kamion(char* ) конструктор со кој се генерира празен камион (без товар) и само возач
void registriraj(char*) се додава регистрацијата на камионот
void dodadiElement(ImaMasa) се додава нов елемент во камионот
double vratiVkupnaMasa() се враќа вкупната маса на товарот кој го пренесува камионот
void pecati() се печатат сите елементи во камионот заедно со регистрацијата и името на возачот
Kamion pretovar(char* , char* ) се врши претовар во нов камион, но во новиот покрај тоа што се менуваат регистрацијата и името на возачот (аргументи), се отстранува пакетот со најголема маса.
Со помош на правилата за справување со исклучоци да се модифицира програмата така што ќе се запазат следните правила: - Регистрацијата има 8 карактери, така што првите два и последните два мора да бидат букви. Да се определи каде ќе се фрли соодветниот исклучок. Онаму каде што ќе се фати исклучокот, ќе се отпечати "Pogresno vnesena registracija!".

*/