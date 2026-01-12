#include<iostream>
#include<cmath>
using namespace std;

class Tochka{
	private:
		double x;
		double y;
	public:
		Tochka(){
		}
		Tochka(double a, double b){
			postaviTochka(a,b);
		}
		void postaviTochka(double a, double b){
			postavix(a);
			postaviy(b);
		}
		void postavix(double a){
			x=a;
		}
		void postaviy(double b){
			y=b;
		}
		double zemix(){
			return x;
		}
		double zemiy(){
			return y;
		}
		void prikazhitochka(){
			cout<<"("<<zemix()<<","<<zemiy()<<")";
		}
		Tochka operator/(Tochka B){
			double cx=(zemix()+B.zemix())/2;
			double cy=(zemiy()+B.zemiy())/2;
			return Tochka(cx,cy);
		}
		double operator -(Tochka B){
			double dx=zemix()-B.zemix();
			double dy=zemiy()-B.zemix();
			double d=sqrt(pow(dx,2)+pow(dy,2));
			return d;
		}
};
int main(){
	Tochka A(5,8);
	Tochka B(0,0);
	B.postaviTochka(-2,3);
	
	Tochka C=A/B;
	
	cout<<"Na otsechkata AB: ";
	cout<<"A("<<A.zemix()<<","<<A.zemiy()<<"), ";
	cout<<"B("<<B.zemix()<<","<<B.zemiy()<<")";
	cout<<"\nsredna tochka e C("<<C.zemix()<<","<<C.zemiy()<<")"<<endl;
	
	cout<<"\nDolzhina na otsechkata AB e: "<<A-B<<endl;
	cout<<endl;
	system("PAUSE");
	return 0;
	
}






















