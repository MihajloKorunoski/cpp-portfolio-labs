#include <iostream>
using namespace std;

template <typename T>
T bigger(T&a,T&b){
    if (a>b)
        return a;
    else
        return b;
}
int main(){
    int a=5;
    long b=6;
    cout<<bigger(a,b)<<endl;
    return 0;
}