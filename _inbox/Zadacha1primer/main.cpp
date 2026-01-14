#include<iostream>

using namespace std;

int main() {
    int n;
    int pom,pom2;
    pom=pom2=0;
    int a[100],b[100],c[100];
    cin>>n;
    for (int i=0;i<n;i++){
       cin>>a[i];
    }
    for (int i=0;i<n;i++) {
        if (i < 10){
            b[i] = a[i];
            pom++;
            continue;
        }
        c[i-10] = a[i];
        pom2++;
    }
    for (int i=0;i<pom;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
    if(n>=10){
        for (int i=0;i<pom2;i++){
            cout<<c[i]<<" ";
        }
    }
    return 0;
}
