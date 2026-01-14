#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
struct tocka2D
{
	float x;
	float y;
};
struct tocka3D
{
	float x;
	float y;
	float z;
};
float rastojanie(tocka2D t1, tocka2D t2)
{
	float rastojanie;
	rastojanie = sqrt(pow((t2.x - t1.x), 2) + pow((t2.y - t1.y), 2));
	return rastojanie;
}
float rastojanie3D(tocka3D t1, tocka3D t2)
{
	float rastojanie;
	rastojanie = sqrt(pow((t2.x - t1.x), 2) + pow((t2.y - t1.y), 2) + pow((t2.z - t1.z), 2));
	return rastojanie;
}
bool ista_prava(tocka2D t1, tocka2D t2, tocka2D t3)
{
	float k1, k2;
	k1 = (t2.y - t1.y) / (t2.x - t1.x);
	k2 = (t3.y - t1.y) / (t3.x - t1.x);
	if (k1 == k2)
		return true;
	else
		return false;

}
int main() {
	float x1, y1, x2, y2;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	tocka2D t1 = { x1, y1 };
	tocka2D t2 = { x2, y2 };
	cout << setprecision(2) << fixed << rastojanie(t1, t2) << endl;
	float z1, z2;
	cin >> z1 >> z2;
	tocka3D t3 = { x1, y1, z1 };
	tocka3D t4 = { x2, y2, z2 };
	cout << setprecision(2) << fixed << rastojanie3D(t3, t4) << endl;
	tocka2D t5 = { z1, z2 };
	cout << ista_prava(t1, t2, t5);
	return 0;
}