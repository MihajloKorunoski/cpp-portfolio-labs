#include <iostream>
#include <cstring>
using namespace std;

class Masa
{
	private:
		int width;
		int lenght;
	public:
		Masa(): width(0), lenght(0){
		}
		Masa(int width, int lenght): lenght(lenght),width(width)
		{
		}
		~Masa()
		{
		}
		void pechati()
		{
			cout<<" Masa: "<<width<<" "<<lenght<<endl;
		}
};
class Soba
{
	private:
		Masa masa;
		int width;
		int lenght;
	public:
		Soba(int width, int lenght, Masa m): width(width), lenght(lenght),masa(m)
		{
		}
		Soba()
		{
		}
		~Soba()
		{
		}
		void pechati()
		{
			cout<<" Soba: "<<width<<" "<<lenght<<" ";
			masa.pechati();
		}
		
};
class Kukja
{
	private:
		char addressa[50];
		Soba soba;
	public:
		Kukja(Soba soba, char *addressa): soba(soba)
		{
			strncpy(this->addressa, addressa, 50);
		}
		Kukja()
		{
		}
		~Kukja()
		{
		}
		void pechati()
		{
			cout<<"Adresa: "<<addressa;
			soba.pechati();
		}
};
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
    	int masaSirina,masaDolzina;
        cin>>masaSirina;
        cin>>masaDolzina;
    	Masa m(masaSirina,masaDolzina);
    	int sobaSirina,sobaDolzina;
        cin>>sobaSirina;
        cin>>sobaDolzina;
    	Soba s(sobaSirina,sobaDolzina,m);
    	char adresa[30];
        cin>>adresa;
    	Kukja k(s,adresa);
    	k.pechati();
	}
    
    return 0;
}
