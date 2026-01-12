#include <iostream>
#include "Krug.h"
using namespace std;

int main() {
	double r=5, h=4;
	Cilinder c(r,h);
	Krug k(r);
	c.prikazhicilinder();
	cout<<"\nPovrshina = "<<k.povrshinanacilinder(c)<<"\nVolumen = "<<k.volumennacilinder(c)<<endl;
	cout<<endl;
	system("PAUSE");
	return 0;
}
