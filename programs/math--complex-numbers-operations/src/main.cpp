#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

class Kompleksenbroj{
		friend ostream& operator<<(ostream& output, const Kompleksenbroj z);
	private:
		double realen,imaginaren;
	public:
		Kompleksenbroj(double realen=0.0, double imaginaren=0.0){
			this->realen=realen;
			this->imaginaren=imaginaren;
		}
		~Kompleksenbroj(){
		}
		Kompleksenbroj operator+(Kompleksenbroj b){
			return Kompleksenbroj(realen+b.realen,imaginaren+b.imaginaren);
		}
		Kompleksenbroj operator-(Kompleksenbroj b){
			return Kompleksenbroj(realen-b.realen,imaginaren-b.imaginaren);
		}
		Kompleksenbroj operator*(Kompleksenbroj b){
			return Kompleksenbroj(realen*b.realen-imaginaren*b.imaginaren, realen*b.imaginaren+imaginaren*b.realen);		
		}
		double operator$(){
			return sqrt(realen*realen+imaginaren*imaginaren);
		}
		Kompleksenbroj operator&(){
			return Kompleksenbroj(realen, -imaginaren);		
		}
		Kompleksenbroj operator/(Kompleksenbroj &b){
			Kompleksenbroj kolichnik;
			b=&b;
			kolichnik=(this->operator*(b));
			double bna2=pow(b.operator$(),2);
			kolichnik.realen/=bna2;
			kolichnik.imaginaren/=bna2;
			return kolichnik;	
		}
};

ostream& operator<<(ostream& output, const Kompleksenbroj z){
	output<<right<<z.realen;
	if(z.imaginaren>0){
		output<<"+j";
	} 
	else
		output<<"-j";
	output<<fabs(z.imaginaren);
	return output;
}

int main(){
	Kompleksenbroj a{1.0,2.0}, b{3.0,-4.0};
	cout<<"Za kompleksnite broevi: \na=";
	cout<<a;
	cout<<" i b=";
	cout<<b;
	cout<<endl<<endl;
	cout<<setw(20)<<"Zbirot      a + b = ";
	cout<<a+b<<endl;
	cout<<setw(20)<<"Razlikata   a - b = ";
	cout<<a-b<<endl;
	cout<<setw(20)<<"Proizvodot  a * b = ";
	cout<<a*b<<endl;
	cout<<setw(20)<<"Kolichnikot a / b = ";
	cout<<a/b<<endl;
	
	cout<<endl;
	system("PAUSE");
	return 0;
}





















