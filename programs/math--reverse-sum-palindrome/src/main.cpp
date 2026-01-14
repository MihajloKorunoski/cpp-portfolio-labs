#include<iostream>
using namespace std;
int obraten(int, int);

int main()
{
	int broj;
	int zbir;
	cout<<"Vnesi edin broj"<<endl;
	cin>>broj;
	cout<<"Obraten broj ot vneseniot broj et: "<<obraten(broj, 0)<<endl;
	zbir=broj+obraten(broj,0);
	cout<<"zbir na brojot i negoviot obraten et: "<<zbir<<endl;
	if (zbir==obraten(zbir,0))
	{
		cout<<"Zbirot et palindrom"<<endl;
	}
	else
	{
		cout<<"Zbirot ne et palindrom"<<endl;
	}
	return 0;
}
int obraten(int broj,int n)
{
	if(broj==0)
	{
		return n;
	}
	else
	{
		int nd= broj%10;
		int np= n*10+nd;
		
		return obraten(broj/10,np);
	}
}
