#include<iostream>
using namespace std;
class Player{
	private:
		int id;
		static int next_id;
	public:
		Player(){
			id=next_id++;
		}
		int getId(){
			return id;
		}
};
int Player::next_id=1;

int main(){
	Player p1,p2,p3;
	cout<<p3.getId();
	return 0;
}
