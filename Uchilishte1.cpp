#include<iostream>
#include<string>
using namespace std;

class Uchilishte;

class Univerzitet{
		friend class Uchilishte;
	private:
		string imenauniverzitet,grad;
	public:
		Univerzitet(string imenauniverzitet,string grad){
			this->imenauniverzitet=imenauniverzitet;
			this->grad=grad;
		}
		string zemiimenauniverzitet(){
			return imenauniverzitet;
		}
		string zemigrad(){
			return grad;
		}
		void prikazhiuniverzitet(){
			cout<<"\nUniverzitet: "<<zemiimenauniverzitet()<<endl;
			cout<<"Grad:        "<<zemigrad()<<endl<<endl;
		}
};

class Uchilishte{
	private:
		string imenauchilishte;
	public:
		Uchilishte(string imenauchilishte){
			this->imenauchilishte=imenauchilishte;
		}
		string zemiimenauchilishte(){
			return imenauchilishte;
		}
		void prikazhiuchilishte(){
			cout<<"Uchilishte:  "<<zemiimenauchilishte()<<endl;
		}
		void novoime(Univerzitet & u){
			string ime;
			cout<<"\nVnesete novo ime na univerzitetot: ";
			getline(cin,ime);
			u.imenauniverzitet=ime;
			cout<<endl;
		}
};
int main(){
	
	string imenauniverzitet="Makedonski Univerzitet";
	string grad="Skopje";
	string imenauchilishte="R.J.Korchagin - Skopje";
	
	Univerzitet mojuniverzitet(imenauniverzitet,grad);
	mojuniverzitet.prikazhiuniverzitet();
	
	Uchilishte moeuchilishte(imenauchilishte);
	
	moeuchilishte.prikazhiuchilishte();
	moeuchilishte.novoime(mojuniverzitet);
	
	mojuniverzitet.prikazhiuniverzitet();
	cout<<endl;
	system("PAUSE");
	return 0;
}



























