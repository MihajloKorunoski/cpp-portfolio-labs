#include <iostream>
using namespace std;
class saat{
	private:
		int chas;
		int minuti;
		int sekundi;
	public:
		saat()
		{
			chas=minuti=sekundi=0;
		}
		saat(int chas, int minuti, int sekundi)
		{
			postavisaat(chas,minuti,sekundi);
		}
		void postavisaat(int chas, int minuti, int sekundi)
		{
			this->chas=chas;
			this->minuti=minuti;
			this->sekundi=sekundi;
		}
		void rabotisaat(saat &t)
		{
			for(;t.chas<24;)
			{
				t.sekundi++;
				if(t.sekundi>59){
					t.minuti++;
					t.sekundi=0;
				}
				if(t.minuti>59)
				{
					t.chas++;
					t.minuti=0;
				}
				if((t.minuti==0)&&(t.sekundi==0))
				prikazhivreme(t);
			}
		}
		void prikazhivreme(saat &t){
			(t.chas<10) ? cout<<"\n" : cout<<"\n";
			cout<<"Tochno e "<<t.chas<<" saatot."<<endl;
		}
};
int main()
{
	saat dziden;
	dziden.rabotisaat(dziden);
	cout<<endl<<endl;
	return 0;
}










