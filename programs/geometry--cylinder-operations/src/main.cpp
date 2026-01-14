#include<iostream>
#include<cmath>
using namespace std;
const double PI=3.1415;

class Cilinder {
		friend double operator/(Cilinder, Cilinder);
		friend Cilinder operator*(Cilinder, Cilinder);
	private:
		double radius;
		double visina;
	public:
		Cilinder();
		Cilinder(double,double);
		void postaviradius(double);
		double zemiradius();
		void postavivisina(double);
		double zemivisina();
		double zemivolumen();
		double operator+(Cilinder);
		void prikazhiCilinder();
};

Cilinder::Cilinder(){
}
Cilinder::Cilinder(double radius,double visina){
	this->radius=radius;
	this->visina=visina;
}
void Cilinder::postaviradius(double radius){
	this->radius=radius;
}
double Cilinder::zemiradius(){
	return radius;
}
void Cilinder::postavivisina(double visina){
	this->visina=visina;
}
double Cilinder::zemivisina(){
	return visina;
}
double Cilinder::zemivolumen(){
	return radius*radius*PI*visina;
}
double Cilinder::operator+(Cilinder B){
	return this->zemivolumen()+B.zemivolumen();
}
void Cilinder::prikazhiCilinder(){
	cout<<"Cilinder: "<<"r="<<zemiradius()<<", h="<<zemivisina()<<"\nVolumen="<<zemivolumen()<<endl;
}
double operator/(Cilinder A, Cilinder B){
	return A.zemivolumen()+B.zemivolumen();
}
Cilinder operator*(Cilinder A, Cilinder B){
	double V= A/B;
	double visina=(A.zemivisina()+B.zemivisina())/2;
	double radius=sqrt(V/(visina*PI));
	return Cilinder(radius,visina);
}
int main(){
	
	Cilinder ovaj(3,4);
	Cilinder onaj(5,6);
	ovaj.prikazhiCilinder();
	onaj.prikazhiCilinder();
	
	cout<<"\nVkupniot volumen na dvata cilindri so operatorska fukncija chlenka e:"<<endl;
	cout<<ovaj.zemivolumen()<<" + "<<onaj.zemivolumen()<<" = "<<ovaj+onaj<<endl;
	
	cout<<"\nVkupniot volumen na dvata cilindri so prijatelska operatorska fukncija e:"<<endl;
	cout<<ovaj.zemivolumen()<<" + "<<onaj.zemivolumen()<<" = "<<ovaj/onaj<<endl;
	
	cout<<"\n Noviot cilindar so volumen ednakov na dvata cilindri i \nvisina ednakva na aritmetichkata sredina na visinite, \nso prijatelska operatorska funkcija e: \n"<<endl;
	Cilinder nov=ovaj*onaj;
	nov.prikazhiCilinder();
	
	cout<<endl;
	system("PAUSE");
	return 0;
}




























