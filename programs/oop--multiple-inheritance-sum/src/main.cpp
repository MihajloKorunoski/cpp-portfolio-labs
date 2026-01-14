#include <iostream>

using namespace std;

class A {
    int x;
public:
    A(int b = 1) {
        x = b;
    }

    int zemix() {
        return x;
    }
//    {
//        cout<<"Konstruktor na osnovna"<<endl;
//    }
////    OOP(const OOP& m)
////    {
////        a = m.a;
////        cout<<"2 ";
////    }
////    OOP& operator=(const OOP& m){
////        a = m.a;
////        cout<<"3 ";
////        return *this;
////    }
};

class B {
    int y;
public:
    B(int c = 2) {
        y = c;
    }

//    {
//        cout<<"Konstruktor na Izvedena"<<endl;
//    }
//    ~Izvedena(){
//        cout<<"Destruktor na Izvedena"<<endl;
//    }
    int zemiy() {
        return y;
    }
};
class C: public A, public B{
public:
    void razlika(){
        cout<<"Razlikata e "<<zemiy()+zemix();
    }
};
int main() {
    C p;
    p.razlika();
    return 0;
}
