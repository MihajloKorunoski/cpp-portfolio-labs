#include <iostream>
#include <cmath>

using namespace std;

class Tochka{
    friend double rastojanie(Tochka, Tochka);
private:
    double x;
    double y;
public:
    Tochka(){

    }
    Tochka(double a, double b){
        x=a;
        y=b;
    }
    void postavix(double a){
        x=a;
    }
    void postaviy(double b){
        y=b;
    }
    double zemix(){
        return x;
    }
    double zemiy(){
        return y;
    }
    void prikazhiTochka(char x){
        cout<<x<<"("<<zemix()<<","<<zemiy()<<")";
    }
};

class Otsechka{
    friend double dolzhina(Otsechka);
    friend Tochka srednatochka(Otsechka);
private:
    Tochka M;
    Tochka N;
public:
    Otsechka() {

    }
    Otsechka(Tochka A, Tochka B){
        postaviotsechka(A,B);
    }
    void postaviotsechka(Tochka A, Tochka B){
        M=A;
        N=B;
    }
    void postaviM(Tochka A){
        M=A;
    }
    void postaviN(Tochka B){
        N=B;
    }
    Tochka zemiM(){
        return M;
    }
    Tochka zemiN(){
        return N;
    }
    void prikazhiotsechka(char u, char v){
        zemiM().prikazhiTochka(u);
        cout<<"---";
        zemiN().prikazhiTochka(v);
    }
};
double rastojanie(Tochka A , Tochka B){
    double dx=A.zemix()-B.zemix();
    double dy=A.zemiy()-B.zemiy();
    double d= sqrt(pow(dx,2)+pow(dy,2));
    return d;
}
Tochka srednatochka(Otsechka AB){
    double x=(AB.M.zemix()+AB.N.zemix())/2;
    double y=(AB.M.zemiy()+AB.N.zemiy())/2;
    Tochka S(x,y);
    return S;
}
double dolzhina(Otsechka AB){
    double dx=AB.M.zemix()-AB.N.zemix();
    double dy=AB.M.zemiy()-AB.N.zemiy();
    double d=sqrt(pow(dx,2)+pow(dy,2));
    return d;
}
int main() {
    Tochka A(5,8);
    Tochka B(-2,3);
    Otsechka AB(A,B);
    Tochka E=srednatochka(AB);
    cout<<"Sredna tochka na otsechkata: \n";
    AB.prikazhiotsechka('A','B');
    cout<<" e ";
    E.prikazhiTochka('E');

    Tochka C(1,7);
    Tochka D(6,2);
    Otsechka CD(C,D);
    Tochka F=srednatochka(CD);
    cout<<"Sredna tochka na otsechkata: \n";
    CD.prikazhiotsechka('C','D');
    cout<<" e ";
    F.prikazhiTochka('F');

    Otsechka EF(E,F);
    cout<<endl;
    cout<<"Dolzhina na otsechkata AB e: "<<dolzhina(AB)<<endl;
    cout<<"Dolzhina na otsechkata AB e: "<<rastojanie(A,B)<<endl;
    cout<<"Dolzhina na otsechkata CD e: "<<dolzhina(CD)<<endl;
    cout<<"Dolzhina na otsechkata CD e: "<<rastojanie(C,D)<<endl;
    cout<<"Dolzhina na otsechkata EF e: "<<dolzhina(EF)<<endl;
    cout<<"Dolzhina na otsechkata EF e: "<<rastojanie(E,F)<<endl;

    cout<<endl<<endl;
    system("PAUSE");
    return 0;
}





















