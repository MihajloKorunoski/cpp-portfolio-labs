#include<iostream>
#include<cstring>

using namespace std;
class Masa{
	private:
		int lenght;
		int width;
	public:
		Masa():lenght(0),width(0){
		}
		Masa(int width, int lenght): lenght(lenght),width(width){
		}
		~Masa(){
		}
		void pechati(){
			cout<<"Masa: "<<width<<" "<<lenght<<endl;
		}
};
class Soba{
	private:
		Masa masa;
		int width;
		int lenght;
	public:
		Soba(){
		}
		Soba(int width, int lenght, Masa m):width(width),lenght(lenght),masa(m){
		}
		~Soba(){
		}
		void pechati(){
			cout<<"Soba: "<<width<<" "<<lenght<<" ";
			masa.pechati();
		}
};
class Kukja{
	private:
		char adresa[50];
		Soba soba;
	public:
		Kukja(){
		}
		Kukja(Soba soba, char *adresa): soba(soba){
			strncpy(this->adresa,adresa,50);
		}
		~Kukja(){
		}
		void pechati(){
			cout<<"Adresa: "<<adresa<<" ";
			soba.pechati();
		}	
};
int main(){
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		int masashirina,masadolzhina;
		cin>>masashirina;
		cin>>masadolzhina;
		Masa m(masashirina,masadolzhina);
		int sobashirina,sobadolzhina;
		cin>>sobashirina;
		cin>>sobadolzhina;
		Soba s(sobashirina,sobadolzhina,m);
		char adresa[30];
		cin>>adresa;
		Kukja k={s,adresa};
		k.pechati();
	}
	return 0;
}




































