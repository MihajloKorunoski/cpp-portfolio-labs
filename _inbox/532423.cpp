#include <iostream>
using namespace std;

main()
{
    int a[100],b[100],c[100];
    int i,p,q,n,k;
    p=0;//p e promenliva za indeksot na nizata so parni broevi
    q=0;//q e promenliva za indeksot na nizata so parni broevi

    //prvo, se vnesuva brojot na elementi na nizite
    cout << "Vnesi go brojot na elementi na nizata"<<endl;
    cout<<"n="; cin>>n;

    //vnesuvanje na elementite nizata
    cout << "Vnesete gi elementite na nizata: " << endl;
    for(i=0;i<n;i++)
    {
       cout<<"a["<<i<<"]=";
       cin >> a[i];
    }

     //kreiranje na dve novi nizi so parni, odnosno neparni broevi
    for(i=0;i<n;i++)
    {
       if(a[i]%2==0)
       {
           b[p]=a[i];
           p++;
       }
       else
       {
           c[q]=a[i];
           q++;
       }
    }  

    //pecatenje na nizata so parni broevi
    cout<<"Ima "<<p<<" parni elementi, i toa:"<<endl;
    for(k=0;k<p;k++)
       cout<<b[k]<<",";
    cout<<endl;     

    //pecatenje na nizata so neparni broevi
    cout<<"Ima "<<q<<" neparni elementi, i toa:"<<endl;
    for(k=0;k<q;k++)
       cout<<c[k]<<",";
    cout<<endl;       

cin.ignore(9999, '\n');
getchar();
return 0;
}
