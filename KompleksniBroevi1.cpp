#include <iostream>
#include <cmath>
using namespace std;

class KompleksenBroj{
	private:
		double realen;
		double imaginaren;
	public:
		KompleksenBroj(){
		}
		KompleksenBroj(double realen,double imaginaren){
			postaviKompleksenBroj(realen,imaginaren);
		}
		void postaviKompleksenBroj(double realen,double imaginaren){
			this->realen=realen;
			this->imaginaren=imaginaren;
		}
		void zemiKompleksenBroj(double &realen, double &imaginaren){
			realen=this->realen;
			imaginaren=this->imaginaren;
		}
		KompleksenBroj sobiranjeKompleksniBroevi(KompleksenBroj z1, KompleksenBroj z2){
			KompleksenBroj z;
			z.realen=z1.realen+z2.realen;
			z.imaginaren=z1.imaginaren+z2.imaginaren;
			return z;
		}
		KompleksenBroj odzemanjeKompleksniBroevi(KompleksenBroj z1, KompleksenBroj z2){
			KompleksenBroj z;
			z.realen=z1.realen-z2.realen;
			z.imaginaren=z1.imaginaren-z2.imaginaren;
			return z;
		}
		KompleksenBroj mnozhenjeKompleksniBroevi(KompleksenBroj z1, KompleksenBroj z2){
			KompleksenBroj z;
			z.realen=z1.realen*z2.realen-z1.imaginaren*z2.imaginaren;
			z.imaginaren=z1.realen*z2.imaginaren+z2.imaginaren*z2.realen;
			return z;
		}
		KompleksenBroj delenjeKompleksniBroevi(KompleksenBroj z1, KompleksenBroj z2){
			KompleksenBroj z;
			double z2ModulNa2=pow(z2.realen,2)+pow(z2.imaginaren,2);
			z=mnozhenjeKompleksniBroevi(z1, konjugiranjeKompleksenBroj(z2));
			z.realen/=z2ModulNa2;
			z.imaginaren/=z2ModulNa2;
			return z;
		}
		KompleksenBroj konjugiranjeKompleksenBroj(KompleksenBroj z){
			z.imaginaren= -z.imaginaren;
			return z;
		}
		void prikazhiKompleksenBroj(KompleksenBroj z){
			cout<<z.realen;
			z.imaginaren>=0 ? cout<< "+i"<<z.imaginaren : cout<<"-i"<<abs(z.imaginaren);
		}
};
int main(){
	double x,y;
	KompleksenBroj z1,z2,z;
	cout<<"Vnesete go prviot kompleksen broj vo forma x+iy "<<endl;
	cout<<"x=";
	cin>>x;
	cout<<"y=";
	cin>>y;
	z1={x,y};
	cout<<"Vnesete go vtoriot kompleksen broj vo forma x+iy "<<endl;
	cout<<"x=";
	cin>>x;
	cout<<"y=";
	cin>>y;
	z2={x,y};
	cout<<"Za kompleksnite broevi: ";
	cout<<"z1:";
	z1.prikazhiKompleksenBroj(z1);
	cout<<" i ";
	cout<<"z2:";
	z2.prikazhiKompleksenBroj(z2);
	cout<<endl<<"Zbirot e \t";
	z.prikazhiKompleksenBroj(z.sobiranjeKompleksniBroevi(z1,z2));
	cout<<endl<<"Razlikata e \t";
	z.prikazhiKompleksenBroj(z.odzemanjeKompleksniBroevi(z1,z2));
	cout<<endl<<"Proizvodot e \t";
	z.prikazhiKompleksenBroj(z.mnozhenjeKompleksniBroevi(z1,z2));
	cout<<endl<<"Kolichnikot e \t";
	z.prikazhiKompleksenBroj(z.delenjeKompleksniBroevi(z1,z2));
	
	cout<<endl<<endl;
	return 0;
	
}











