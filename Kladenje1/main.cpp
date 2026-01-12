#include <iostream>
using namespace std;
int funkcija(int profit){
    int kladba=100;
    int profit2=100;
    int zaguba=100;
    while(profit>100){
        kladba=kladba*2+profit2;
        profit2*=2;
        zaguba=zaguba+kladba;
        profit=profit/2;
    }
    return zaguba;
}
int main() {
    int kladba=0;
    int zaguba=0;
    int profit=0;
    for(int i=0;i<10;i++){
        cin>>profit;
        kladba=funkcija(profit);
        cout<<kladba;
    }
}
