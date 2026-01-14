#include<iostream>
#include<array>
#include<cmath>
using namespace std;

class Polinom{
		friend void operator!(Polinom&);
	private:
		int stepen;
		double *a;
	public:
		Polinom(){
		}
		Polinom(int stepen, double *a){
			this->stepen=stepen;
			this->a=a;
			for(int i=0;i<=stepen;i++)
				this->a[i]=a[i];
		}
		~Polinom(){
		}
		int zemistepen(){
			return stepen;
		}
		Polinom operator +(Polinom vtor){
			!*this;
			!vtor;
			int i;
			int min=this->stepen;
			int max=vtor.stepen;
			if(this->stepen>vtor.stepen){
				max=this->stepen;
				min=vtor.stepen;
			}
			Polinom c;
				c.a=new double[max];
			for(i=0;i<=min;i++){
				c.a[i]=this->a[i]+vtor.a[i];
			}
			if(this->stepen<=vtor.stepen)
				for(i=min+1;i<=vtor.stepen;i++)
					c.a[i]=vtor.a[i];
			else
				for(i=min+1;i<=this->stepen;i++)
					c.a[i]=this->a[i];
			c.stepen=max;
			!c;
			return c;
		}
		void prikazhipolinom(){
			for(int i=0;i<=stepen;i++){
				(a[i]>=0) ? cout<<" + " : cout<<" - ";
				cout<<abs(a[i])<<"x^"<<stepen-i;
			}
			cout<<endl;
		}
};

void operator!(Polinom &p){
	int n=p.stepen;
	double pom;
	for (int i=0;i<(n+1)/2;i++){
		pom=p.a[i];
		p.a[i]=p.a[n-i];
		p.a[n-i]=pom;
	}
}
int main(){
	double a[]={1,-2,0,0,5};
	int n=sizeof(a)/sizeof(a[0])-1;
	double *p=a;
	Polinom prv(n,p);
	cout<<"Prv polinom: \t\t";
	prv.prikazhipolinom();
	
	double b []={3,0,-3,4};
	int m=sizeof(b)/sizeof(b[0])-1;
	double *q=b;
	Polinom vtor(m,q);
	cout<<"Vtor polinom: \t\t";
	vtor.prikazhipolinom();
	
	Polinom zbir;
	zbir=prv+vtor;
	cout<<"Zbir na polinomite: \t";
	zbir.prikazhipolinom();
	
	cout<<endl;
	system("PAUSE");
	return 0;
}





















