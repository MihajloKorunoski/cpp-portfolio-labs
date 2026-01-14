#include <iostream>
#include <cstring>

using namespace std;

class NBAPlayer {
protected:
    char *name;
    char team[40];
    double points;
    double assists;
    double rebounds;
    void copy(const NBAPlayer &p) {
    	this->name=new char[strlen(p.name)+1];
        strcpy(this->name, p.name);
        strcpy(this->team, p.team);
        this->points=p.points;
        this->assists=p.assists;
        this->rebounds=p.rebounds;
    }
public:
    NBAPlayer (const char *name="", const char *team="", double points=0, double assists=0, double rebounds=0) {
    	this->name=new char[strlen(name)+1];
        strcpy(this->name, name);
        strcpy(this->team, team);
        this->points=points;
        this->assists=assists;
        this->rebounds=rebounds;
    }
    NBAPlayer (const NBAPlayer &p) {
    	copy(p);
    }
    NBAPlayer &operator = (const NBAPlayer &p) {
        if (this!=&p) {
        	delete [] name;
            copy(p);
        }
        return *this;
    }
    float rating () {
    	return points/100.0*45+assists/100.0*30+rebounds/100.0*25;
    }
    void print () {
    	cout<<name<<" - "<<team<<endl;
        cout<<"Points: "<<points<<endl;
        cout<<"Assists: "<<assists<<endl;
        cout<<"Rebounds: "<<rebounds<<endl;
        cout<<"Rating: "<<rating()<<endl;
    }
    ~NBAPlayer () {
    	delete [] name;
    }
};

class AllStarPlayer : public NBAPlayer {
    double playerPoints;
    double playerAssists;
    double playerRebounds;
public:
    AllStarPlayer () {}
    AllStarPlayer (const NBAPlayer &p, double playerPoints, double playerAssists, double playerRebounds)
        : NBAPlayer(p) {
        this->playerPoints=playerPoints;
        this->playerAssists=playerAssists;
        this->playerRebounds=playerRebounds;
    }
    AllStarPlayer (const char *name, const char *team, double points, double assists, double rebounds, 
        double playerPoints, double playerAssists, double playerRebounds)
        : NBAPlayer (name, team, points, assists, rebounds) {
        	this->playerPoints=playerPoints;
        	this->playerAssists=playerAssists;
        	this->playerRebounds=playerRebounds;
        }
    AllStarPlayer (const AllStarPlayer &player) : NBAPlayer (player) {
    	this->playerPoints=player.playerPoints;
        this->playerAssists=player.playerAssists;
        this->playerRebounds=player.playerRebounds;
    }
    AllStarPlayer &operator = (const AllStarPlayer &player) {
        if (this!=&player) {
            this->name=new char[strlen(player.name)+1];
        	strcpy(this->name, player.name);
        	strcpy(this->team, player.team);
        	this->points=player.points;
        	this->assists=player.assists;
        	this->rebounds=player.rebounds;
            this->playerPoints=player.playerPoints;
        	this->playerAssists=player.playerAssists;
        	this->playerRebounds=player.playerRebounds;
        }
        return *this;
    }
    float rating () {
    	return (allStarRating()+NBAPlayer::rating())/2.0;
    }
    float allStarRating () {
    	return playerPoints/100.0*30+playerAssists/100.0*40+playerRebounds/100.0*30;
    }
    void print () {
    	NBAPlayer::print();
        cout<<"All Star Rating: "<<allStarRating()<<endl;
        cout<<"New Rating: "<<rating()<<endl;
    }
    ~AllStarPlayer () {}
};





int main() {

  char name[50];
  char team[40];
  double points;
  double assists;
  double rebounds;
  double allStarPoints;
  double allStarAssists;
  double allStarRebounds;

  NBAPlayer * players = new NBAPlayer[5];
  AllStarPlayer * asPlayers = new AllStarPlayer[5];
  int n;
  cin >> n;

  if (n == 1) {

    cout << "NBA PLAYERS:" << endl;
    cout << "=====================================" << endl;
    for (int i = 0; i < 5; ++i) {
      cin >> name >> team >> points >> assists >> rebounds;
      players[i] = NBAPlayer(name,team,points,assists,rebounds);
      players[i].print();
    }
  }
  else if (n == 2) {

    for (int i=0; i < 5; ++i){
      cin >> name >> team >> points >> assists >> rebounds;
      cin >> allStarPoints >> allStarAssists >> allStarRebounds;
      players[i] = NBAPlayer(name,team,points,assists,rebounds);
      asPlayers[i] = AllStarPlayer(players[i],allStarPoints,allStarAssists,allStarRebounds);
    }

    cout << "NBA PLAYERS:" << endl;
    cout << "=====================================" << endl;
    for (int i=0; i < 5; ++i)
      players[i].print();

    cout << "ALL STAR PLAYERS:" << endl;
    cout << "=====================================" << endl;
    for (int i=0; i < 5; ++i)
      asPlayers[i].print();

    }
    else if (n == 3) {

      for (int i=0; i < 5; ++i){
        cin >> name >> team >> points >> assists >> rebounds;
        cin >> allStarPoints >> allStarAssists >> allStarRebounds;
        asPlayers[i] = AllStarPlayer(name, team, points, assists, rebounds,
                                     allStarPoints,allStarAssists,allStarRebounds);
      }
      cout << "ALL STAR PLAYERS:" << endl;
      cout << "=====================================" << endl;
      for (int i=0; i < 5; ++i)
        asPlayers[i].print();

    }
    
    delete [] players;
    delete [] asPlayers;
}
