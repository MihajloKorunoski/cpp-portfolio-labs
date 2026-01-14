#include<iostream>
using namespace std;
int main()
{
	int a[100];
	int i;
	int n;
	int najmalbr;
	int najgolembr;
	cout<<"Vnesi kolku chlena kje imat nizata"<<endl;
	cin>>n;
	cout<<"Vnesi gi chlenovite na nizata"<<endl;
	for (i=0;i<n;i++)
	{
		cin>>a[i];
	}
	najmalbr=a[0];
	najgolembr=a[0];
	for (i=0;i<n-1;i++)
	{
		if(a[i]>a[i+1]||najmalbr>a[i])
		najmalbr=a[i+1];
		if(a[i]<a[i+1]||najgolembr<a[i])
		najgolembr=a[i+1];
	}
	for(i=0;i<n;i++)
	{
		if(a[i]==najmalbr)
		{
		a[i]=najgolembr;
		continue;
		}
		if(a[i]==najgolembr)
		{
		a[i]=najmalbr;
		continue;
		}
	}
	cout<<"Posle zamenata nizata izgleda:";
	for (i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
