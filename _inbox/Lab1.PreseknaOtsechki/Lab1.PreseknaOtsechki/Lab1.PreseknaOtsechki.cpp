#include<iostream>
#include <algorithm> 
using namespace std;
struct tocka
{
	double x;
	double y;
};
struct otsecka
{
	tocka t1;
	tocka t2;
};
bool naotsechka(tocka t1, tocka t2, tocka t3)
{
	if (t2.x <= max(t1.x, t3.x) && t2.x >= min(t1.x, t3.x) && t2.y <= max(t1.y, t3.y) && t2.y >= min(t1.y, t3.y))
		return true;
	else
		return false;
}
int orientacija(tocka t1, tocka t2, tocka t3)
{
	int vrednost;
	vrednost = ((t2.y - t1.y) * (t3.x - t2.x)) - ((t2.x - t1.x) * (t3.y - t2.y));
	if (vrednost == 0)
		return 0;
	else if (vrednost > 0)
		return 1;
	else if (vrednost < 0)
		return 2;
}
bool se_secat(otsecka o1, otsecka o2)
{
	int ori1, ori2, ori3, ori4;
	ori1 = orientacija(o1.t1, o1.t2, o2.t1);
	ori2 = orientacija(o1.t1, o1.t2, o2.t2);
	ori3 = orientacija(o2.t1, o2.t2, o1.t1);
	ori4 = orientacija(o2.t1, o2.t2, o1.t2);
	
	if (ori1 != ori2 && ori3 != ori4)
		return true;
	if (ori1 == 0 && naotsechka(o1.t1, o2.t1, o1.t2))
		return true;
	if (ori2 == 0 && naotsechka(o1.t1, o2.t2, o1.t2))
		return true;
	if (ori3 == 0 && naotsechka(o2.t1, o1.t1, o2.t2))
		return true;
	if (ori4 == 0 && naotsechka(o2.t1, o1.t2, o2.t2))
		return true;
	return false;

}
int main() {
	double x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	tocka t1 = { x1, y1 };
	tocka t2 = { x2, y2 };
	otsecka o1 = { t1, t2 };
	cin >> x1 >> y1 >> x2 >> y2;
	tocka t3 = { x1, y1 };
	tocka t4 = { x2, y2 };
	otsecka o2 = { t3, t4 };
	cout << se_secat(o1, o2);
	return 0;
}