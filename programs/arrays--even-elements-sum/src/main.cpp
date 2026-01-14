#include <iostream>
using namespace std;
int main ()
{
	int i,n,m,k, a[50],b[50];
	cout<<"Vnesi kolku chlena kje bide nizata: ";
	m=0;
	cin>>n;
	cout<<"Vnesi gi chlenovite na nizata:"<<endl;
	for (i=0; i<n; i++)
		cin>>a[i];
	for (i=0; i<n; i++) {
		if (a[i]%2==0){
			b[m]=a[i];
			m++;
		}
	}
	cout<<"Parni broevi vo nizata a se:"<<endl;
	for (i=0; i<m; i++)
		cout<<b[i]<<",";
	cout<<endl;
	cout<<"A nivniot zbir iznesuva:"<<endl;
	k=0;
	for(i=0; i<m; i++)
		k=k+b[i];
	cout<<k<<endl;
	return 0;
}
