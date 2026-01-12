#include<iostream>
#include<string>
using namespace std;
class Univerzitet{
		friend void novoime(Univerzitet &);
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
			cout<<"Grad:        "<<zemigrad()<<endl;
		}
};
void novoime(Univerzitet &u){
	string ime;
	cout<<"\nVnesete novo ime na Univerzitetot: ";
	getline(cin,ime);
	u.imenauniverzitet=ime;
}
int main(){
	string ime="Makedonski Univerzitet";
	string grad="Skopje";
	
	Univerzitet mojuniverzitet(ime,grad);
	mojuniverzitet.prikazhiuniverzitet();
	
	novoime(mojuniverzitet);
	mojuniverzitet.prikazhiuniverzitet();
	
	cout<<endl;
	system("PAUSE");
	return 0;
}
