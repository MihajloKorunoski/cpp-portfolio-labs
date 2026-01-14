#include <iostream>
#include <cstring>

using namespace std;

class Potpisuvac
{
	private:
		char ime[20];
		char prezime[20];
		char embg[14];
	public:
	Potpisuvac()
	{	
	}
	Potpisuvac(char *ime, char* prezime, char* embg)
	{
		strncpy(this->ime, ime,20);
		strncpy(this->prezime, prezime,20);
		strncpy(this->embg, embg,14);
	}
	Potpisuvac(const Potpisuvac &src)
	{
		strncpy(this->ime, src.ime,20);
		strncpy(this->prezime, src.prezime,20);
		strncpy(this->embg, src.embg,14);
	}
	char* getEmbg()
	{
		return embg;
	}

};
class Dogovor
{
	private:
		int brojnadogovor;
		char kategorijanadogovor[50];
		Potpisuvac potpishuvachi[3];
	public:

		Dogovor(int brojnadogovor,char* kategorijanadogovor, Potpisuvac* potpishuvachi) :brojnadogovor(brojnadogovor)
		
		{
			strncpy(this->kategorijanadogovor, kategorijanadogovor, 50);
			{
				for(int i=0; i<3; i++)
				{
					this->potpishuvachi[i]=potpishuvachi[i];
				}
			}
		}
		bool proverka()
		{
			for (int i=0; i<3; i++)
			{
				for(int j=0; j<3; j++)
				{
					if ((strcmp(potpishuvachi[i].getEmbg(), potpishuvachi[j].getEmbg()) == 0)&&(i != j))
					return true;
				}
			}
			return false;
		}
};
int main()
{
    char embg[13], ime[20], prezime[20], kategorija[20];
    int broj, n;
    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> embg >> ime >> prezime;
    	Potpisuvac p1(ime, prezime, embg);
    	cin >> embg >> ime >> prezime;
    	Potpisuvac p2(ime, prezime, embg);
    	cin >> embg >> ime >> prezime;
    	Potpisuvac p3(ime, prezime, embg);
    	cin >> broj >> kategorija;
    	Potpisuvac p[3];
    	p[0] = p1; p[1] = p2; p[2] = p3;
    	Dogovor d(broj, kategorija, p);
        cout << "Dogovor " << broj << ":" << endl; 
    	if(d.proverka() == true)
    	    cout << "Postojat potpishuvaci so ist EMBG" << endl;
    	else
    	    cout << "Ne postojat potpishuvaci so ist EMBG" << endl;
    }
    return 0;
}
