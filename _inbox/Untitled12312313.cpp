#include<iostream>
using namespace std;
int lsearch(int Arr[], int s, int VAL);
int main()
{
 int Arr[100],n,val,found;
 cout<<"Vnesi broj na elementi na nizata: \n";
 cin>>n;
 for(int i=0;i<n;i++)
 {
 cout<<"Vnesi element "<<i+1<<":";
 cin>>Arr[i];
 }
 cout<<"\nVnesi go brojot sto sakas da go prebaruvas ";
 cin>>val;
 found=lsearch(Arr,n,val);
 if(found==1)
 cout<<"\nElementot e pronajden\n";
 else
 cout<<"\nElementot ne e pronajden\n";
system("pause");
return 0;
}
int lsearch(int Arr[], int s, int VAL)
{
 for(int I=0; I<s; I++)
 {
 if(Arr[I]==VAL)
 return 1;
 }

}
