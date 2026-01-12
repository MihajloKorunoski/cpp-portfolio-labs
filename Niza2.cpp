#include<iostream>
#include<array>
using namespace std;

class Niza{
		friend Niza operator+=(Niza,Niza);
		friend void operator%=(Niza&,double);
	private:
		int brojelementi;
		double *x;
	public:
		Niza(){
		}
		Niza(int brojelementi, double *x){
			this->brojelementi=brojelementi;
			this->x=x;
			for(int i=0;i<brojelementi;i++)
				this->x[i]=x[i];
		}
		~Niza(){
		}
		int zemibrojelementi(){
			return brojelementi;
		}
		void operator%(double vrednost){
			this->x[brojelementi]=vrednost;
			this->brojelementi++;
		}
		Niza operator+(Niza b){
			int i;
			Niza c;
			int min=this->brojelementi,max=this->brojelementi;
			if (this->brojelementi<b.brojelementi)
				max=b.brojelementi;
			else
				min=b.brojelementi;
			c.x=new double[max];
			for(i=0;i<min;i++){
				c.x[i]=this->x[i]+b.x[i];
			}
			if(this->brojelementi<b.brojelementi)
				for(i=min;i<b.brojelementi;i++)
				c.x[i]=b.x[i];
			else
				for(int i=min;i<this->brojelementi;i++)
					c.x[i]=this->x[i];
			c.brojelementi=i;
			return c;
		}
		void prikazhiniza(){
			cout<<"Nizata ima "<<brojelementi<<" elementi i toa:"<<endl;
			for(int i=0;i<brojelementi;i++)
				cout<<x[i]<<" ";
			cout<<endl;
		}
};
void operator%=(Niza&a,double vrednost){
	a.x[a.brojelementi]=vrednost;
	a.brojelementi++;
}
Niza operator+=(Niza a,Niza b){
	int i;
	Niza c;
	int min=a.brojelementi,max=a.brojelementi;
	if (a.brojelementi<b.brojelementi)
		max=b.brojelementi;
	else
		min=b.brojelementi;
	c.x=new double[max];
	for(i=0;i<min;i++){
		c.x[i]=a.x[i]+b.x[i];
	}
	if(a.brojelementi<b.brojelementi)
		for(i=min;i<b.brojelementi;i++)
			c.x[i]=b.x[i];
	else
		for(int i=min;i<a.brojelementi;i++)
			c.x[i]=a.x[i];
	c.brojelementi=i;
	return c;
}

int main(){
	
	double x []={1,2,3};
	int brojelementi= sizeof(x)/sizeof(x[0]);
	double *p=x;
	Niza a(brojelementi,p);
	a.prikazhiniza();
	
	cout<<"\nDodavanje element vo niza so samostojna funkcija"<<endl;
	a%=4;
	operator%=(a,5);
	a.prikazhiniza();
	
	cout<<"\nDodavanje element vo niza so funkcija chlenka"<<endl;
	a%6;
	a.operator%(7);
	a.prikazhiniza();
	
	double y[]={11,12,13,14,15,16};
	brojelementi=sizeof(y)/sizeof(y[0]);
	double *q=y;
	Niza b(brojelementi,q);
	
	
	cout<<"\nSobiranje dve nizi so samostojna funkcija"<<endl;
	cout<<"\tPrva niza: "<<endl;
	a.prikazhiniza();
	cout<<"\tVtora niza: "<<endl;
	b.prikazhiniza();
	Niza c;
	c=a+=b;
	cout<<"\t Zbir na nizite: "<<endl;
	c.prikazhiniza();
	c=a;
	c=operator+=(a,b);
	c.prikazhiniza();
	
	
	cout<<"\nSobiranje dve nizi so funkcija chlenka"<<endl;
	cout<<"\tPrva niza: "<<endl;
	a.prikazhiniza();
	cout<<"\tVtora niza: "<<endl;
	b.prikazhiniza();
	Niza d;
	d=a+b;
	cout<<"\t Zbir na nizite: "<<endl;
	d.prikazhiniza();
	d=a;
	d=a.operator+(b);
	d.prikazhiniza();
	
	cout<<endl;
	system("PAUSE");
	return 0;
	
	
}






















