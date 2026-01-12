#ifndef CILINDER_H
#define CILINDER_H

#include<iostream>
using namespace std;

class Cilinder
{
		friend class Krug;
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
		void prikazhicilinder();
};

Cilinder::Cilinder(){
}
Cilinder::Cilinder(double radius, double visina){
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
void Cilinder::prikazhicilinder(){
	cout<<"Cilinder: "<<"r = "<<zemiradius()<<", h = "<<zemivisina();
}

#endif
























