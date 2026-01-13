#ifndef KRUG_H
#define KRUG_H

#include<iostream>
#include "Cilinder.h"
using namespace std;

class Krug
{
		const double PI = 3.1415;
	private:
		double radius;
	public:
		Krug();
		Krug(double);
		void postaviradius(double);
		double zemiradius();
		double zemiperimetar();
		double zemiploshtina();
		void prikazhikrug();
		double povrshinanacilinder(Cilinder&);
		double volumennacilinder(Cilinder&);
};
Krug::Krug(){
}
Krug::Krug(double radius){
	this->radius=radius;
}
void Krug::postaviradius(double radius){
	this->radius=radius;
}
double Krug::zemiradius(){
	return radius;
}
double Krug::zemiperimetar(){
	return 2*radius*PI;
}
double Krug::zemiploshtina(){
	return radius*radius*PI;
}
void Krug::prikazhikrug(){
	cout<<"Perimeter: "<<zemiperimetar()<<"\tPloshtina: "<<zemiploshtina()<<endl;
}
double Krug::povrshinanacilinder(Cilinder &c){
	double p=2*zemiploshtina()+zemiperimetar()*c.zemivisina();
	return p;
}
double Krug::volumennacilinder(Cilinder &c){
	double v=zemiploshtina()*c.zemivisina();
	return v;
}

#endif
























