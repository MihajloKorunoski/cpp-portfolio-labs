#include <iostream>
using namespace std;
int rekurzija(int a[],int x,int i){
    if(i>(sizeof(a)/sizeof(a[0])))
        return -1;
    if(a[i]==x)
        return i;
    return rekurzija(a,x,i+1);

}
int main() {
    int n;
    int a[100];
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    int x;
    cin>>x;
    cout<<rekurzija(a,x,0);
    return 0;
}
