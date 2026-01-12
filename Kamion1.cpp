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
    static const double gustina;
    static const double ambalaza;
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
const double PaketPijalok::gustina=0.8;
const double PaketPijalok::ambalaza=0.2;
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
