#include <iostream>
#include<string>
using namespace std;

#define PI 3.1415926;
class Krug{
private:
    double r;
public:
    Krug(){

    }
    Krug(double r){
        this->r=r;
    }
    double zemiploshtina(){
        return r*r*PI;
    }
};
class Cilinder{
    friend double operator+(Cilinder,Cilinder);
private:
    double h;
    Krug K;
public:
    Cilinder(){

    }
    Cilinder(double h, Krug K){
        postavicilinder(h,K);
    }
    void postavicilinder(double h, Krug K){
        this->h=h;
        this->K=K;
    }
    double zemivolumen(){
        return K.zemiploshtina()*h;
    }
    void prikazhicilinder(){
        cout<<"Cilinder so osnova krug, P="<<K.zemiploshtina()<<"i H= "<<h<<endl;
    }
};
double operator +(Cilinder u, Cilinder v){
    return u.zemivolumen()+ v.zemivolumen();
}
int main(){
    double r=1;
    double H=2;
    Krug K1(r);
    Cilinder C1(H,K1);
    r=3; H=4;
    Krug K2(r);
    Cilinder C2(H, K2);
    C1.prikazhicilinder();
    cout<< " i "<<endl;
    C2.prikazhicilinder();
    cout<<"Imaat vkupen volumen: "<< C1+C2<<endl;

    cout<<endl;
    system("PAUSE");
    return 0;
}