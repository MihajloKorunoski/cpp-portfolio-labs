#include<iostream>
using namespace std;

const double PI=3.14;
double ploshtinanakrug(double r){
	return r*r*PI;
}
class Cilindar{
	friend double ploshtinanakrug(double);
	private:
		double radius;
		double visina;
	public:
		Cilindar(double radius, double visina){
			this->radius=radius;
			this->visina=visina;
		}
		double zemipovrshinanacilindar(){
			return 2*ploshtinanakrug(radius)+2*radius*PI*visina;
		}
		double zemivolumennacilindar(){
			return ploshtinanakrug(radius)*visina;
		}
};
class Topka{
	friend double ploshtinanakrug(double);
	private:
		double radius;
	public:
		Topka(double radius){
			this->radius=radius;
		}
		double zemipovrshinanatopka(){
			return 4*ploshtinanakrug(radius);
		}
		double zemivolumennatopka(){
			return 4*ploshtinanakrug(radius)*radius/3;
		}
};

int main(){
	double r,h;
	cout<<"Vnesete go radiusot na topkata: ";
	cout<<"r=";
	cin>>r;
	Topka moja(r);
	cout<<"\nTopka so radius "<<r<<" ima:"<<"\nPloshtina: "<<moja.zemipovrshinanatopka()<<"\nVolumen: "<<moja.zemivolumennatopka()<<endl;
	cout<<"Vnesete go radiusot na cilindarot: ";
	cout<<"r=";
	cin>>r;
	cout<<"Vnesete ja visinata na cilindarot: ";
	cout<<"h=";
	cin>>h;
	Cilindar ovaj(r,h);
	cout<<"\nCilindarot so radius "<<r<<" i visina "<<h<<" ima:"<<"\nPloshtina: "<<moja.zemipovrshinanatopka()<<"\nVolumen: "<<moja.zemivolumennatopka()<<endl;
	
	cout<<endl;
	return 0;
}

























