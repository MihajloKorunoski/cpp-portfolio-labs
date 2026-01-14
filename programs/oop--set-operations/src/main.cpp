#include <iostream>
using namespace std;
class Mnozhestvo{
    friend Mnozhestvo operator+(Mnozhestvo A, Mnozhestvo B);
    friend Mnozhestvo operator*(Mnozhestvo A, Mnozhestvo B);
private:
    int brojelementi;
    double *x;
public:
    Mnozhestvo(){
    }
    Mnozhestvo(int brojelementi, double *x){
        this->brojelementi=brojelementi;
        this->x=x;
    };
    ~Mnozhestvo(){

    }
    int zemibrojelementi(){
        return brojelementi;
    }
    void operator%(double vrednost){
        this->x[brojelementi]=vrednost;
        this->brojelementi++;
    }
    void operator-(double vrednost){
        int i=0;
        while((i<brojelementi)&&(x[i]!=vrednost))
            i++;
        if (i<brojelementi){
            x[i]=x[brojelementi-1];
            this->brojelementi--;
        }
    }
    bool imaelement(double vrednost){
        bool imanema=false;
        int i=0;
        while((i<brojelementi)&&(x[i]!=vrednost))
            i++;
        if(i<brojelementi)
            imanema=true;
        return imanema;
    }
    void prikazhimnozhestvo(){
        if(brojelementi==0)
            cout<<"{}";
        else{
            cout<<"{";
            for(int i=0;i<brojelementi-1;i++)
                cout<<x[i]<<", ";
            cout<<x[brojelementi-1]<<"}";
        }
        cout<<endl;
    }
};
Mnozhestvo operator+(Mnozhestvo A, Mnozhestvo B){
    Mnozhestvo C=A;
    for(int i=0;i<B.brojelementi;i++)
        if(!A.imaelement(B.x[i]))
            C%(B.x[i]);
        return C;
}
Mnozhestvo operator*(Mnozhestvo A, Mnozhestvo B){
    double *p=new double[100];
    Mnozhestvo D(0,p);
    for(int i=0;i<B.brojelementi;i++)
        if(A.imaelement(B.x[i]))
            D%(B.x[i]);
        return D;
}
int main() {
    double a[]={1,2,3};
    int brojelementi=sizeof(a)/sizeof(a[0]);
    double *p=a;
    Mnozhestvo A(brojelementi,p);
    cout<<"Pochetno mnozhestvo: ";
    A.prikazhimnozhestvo();

    cout<<"\nDodavanje element vo mnozhestvo: ";
    A%(4);
    A.prikazhimnozhestvo();
    cout<<"\nBrisenje element ot mnozhestvo: ";
    A-(2);
    A.prikazhimnozhestvo();

    double b[] = {-1,2,3,5,4};
    brojelementi=sizeof(b)/sizeof(b[0]);
    double *q=b;
    Mnozhestvo B(brojelementi,q);

    cout<<"\nUnija na dve mnozhestva: "<<endl;
    cout<<"\tMnozhestvo A: ";
    A.prikazhimnozhestvo();
    cout<<"\tMnozhestvo B: ";
    B.prikazhimnozhestvo();
    Mnozhestvo C;
    C=A+B;
    cout<<"\tUnija    A+B: ";
    C.prikazhimnozhestvo();

    cout<<"\nPresek na dve mnozhestva: "<<endl;
    cout<<"\tMnozhestvo A: ";
    A.prikazhimnozhestvo();
    cout<<"\tMnozhestvo B: ";
    B.prikazhimnozhestvo();
    Mnozhestvo D;
    D=A*B;
    cout<<"\tPresek   A*B: ";
    D.prikazhimnozhestvo();

    cout<<endl;
    system("PAUSE");
    return 0;
}














