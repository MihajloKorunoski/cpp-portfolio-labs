#include <iostream>
using namespace std;
class Saat
{
private:
	int cas;
	int minuti;
	int sekundi;
public:
	Saat()
	{
		cas = minuti = sekundi = 0;
	}
	Saat(int cas, int minuti, int sekundi)
	{
		postaviSaat(cas, minuti, sekundi);
	}
	void postaviSaat(int cas, int minuti, int sekundi)
	{
		this->cas = cas;
		this->minuti = minuti;
		this->sekundi = sekundi;
	}
	void rabotiSaat(Saat &t)
	{
		for (; t.cas < 24;)
		{
			t.sekundi++;
			if (t.sekundi > 59)
			{
				t.minuti++;
				t.sekundi = 0;
				if (t.minuti > 59)
				{
					t.cas++;
					t.minuti = 0;
				}
			}
			if ((t.minuti == 0) && (t.sekundi == 0))
				prikazhivreme(t);
		}
	}
	void prikazhivreme(Saat &t)
	{
		(t.cas < 10) ? cout << endl : cout << endl;
		cout << "Tochno " << t.cas << " saatot." << endl;
	}
};
int main()
{
	system("Color A");
	Saat dziden;
	dziden.rabotiSaat(dziden);
	cout << endl << endl;
	return 0;
}
