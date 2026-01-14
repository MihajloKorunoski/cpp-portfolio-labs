#include<iostream>
#include<cstring>
using namespace std;

class Drone{
private:
    char proizvoditel[50];
    char*verzija;
    int godina;
    double cena;
public:
    virtual double get_cena()=0;
};
class RacingDrone: public Drone{
private:
    double maksbrzina;
public:
    RacingDrone(char *proizvoditel="",char* verzija="",int godina=0,double cena=0.0, double maksbrzina=0.0): Drone(proizvoditel,verzija,godina,cena){
        strcpy(this->proizvoditel,proizvoditel);
        this->verzija=new char[strlen(verzija)+1];
        strcpy(this->verzija,verzija);
        this->godina=godina;
        this->cena=cena;
        this->maksbrzina=maksbrzina;
    }
    ~RacingDrone{
        delete [] verzija;
    }
    double get_cena(){
        if(maksbrzina<15.0)
        return cena+(cena*0.10);
        return cena+(cena*0.25);
    }
    friend ostream& operator<<(ostream &o,RacingDrone rgd){
        o<<rgd.proizvoditel<<rgd.verzija<<rgd.godina<<rgd.get_cena()<<endl;
        return o;
    }

};
class VideographyDrone: public Drone{
private:
    bool rezolucija;
    int fps;
public:
    VideographyDrone(char *proizvoditel="",char* verzija="",int godina=0,double cena=0.0, bool rezolucija=false,int fps=0): Drone(proizvoditel,verzija,godina,cena){
        strcpy(this->proizvoditel,proizvoditel);
        this->verzija=new char[strlen(verzija)+1];
        strcpy(this->verzija,verzija);
        this->godina=godina;
        this->cena=cena;
        this->rezolucija=rezolucija;
        this->fps=fps;
    }
    ~RacingDrone{
        delete [] verzija;
    }
    double get_cena(){
        if(rezolucija)
        cena=cena+(cena*0.05);
        if(fps>30)
        cena=cena+(cena*0.10);
        return cena;
    }
    friend ostream& operator<<(ostream &o,VideographyDrone vgd){
        o<<vgd.proizvoditel<<vgd.verzija<<vgd.godina<<vgd.fps<<vgd.get_cena()<<endl;
        return o;
    }
};

bestDrone(Drone **drones,int brojdronovi){
}
//Your code goes here!

int main () {
	int testCase;
	cin>>testCase;

	char proizvoditel [200];
	char verzija [200];
	int godina;
	double cena;
	double brzina;
	bool resolution;
    int fps;

	if (testCase==1) {
		cout<<"Testing RacingDrone class, operator << and get_price"<<endl;
		cin>>proizvoditel>>verzija>>godina>>cena>>brzina;
		RacingDrone r (proizvoditel, verzija,godina,cena,brzina);
		cout<<r;
		cout<<"Price: "<<r.get_cena()<<endl;
	}
    else if (testCase==2){
        cout<<"Testing VideographyDrone class, operator << and get_price"<<endl;
		cin>>proizvoditel>>verzija>>godina>>cena>>resolution>>fps;
		VideographyDrone v (proizvoditel, verzija,godina,cena,resolution,fps);
		cout<<v;
		cout<<"Price: "<<v.get_cena()<<endl;
    }
    else if (testCase==3){
        cout<<"Testing operator <"<<endl;
        cin>>proizvoditel>>verzija>>godina>>cena>>brzina>>resolution>>fps;
		VideographyDrone v (proizvoditel, verzija,godina,cena,resolution,fps);
        RacingDrone r (proizvoditel, verzija,godina,cena,brzina);
        cout<<"More expensive is:"<<endl;
        if(v>r){
            cout<<v;
        }else{
            cout<<r;
        }
    }
    else if (testCase==4){
        cout<<"Testing bestDrone function"<<endl;
        Drone **drones;
        int num;
        cin>>num;
        drones = new Drone*[num];
        int type;
        for(int i=0;i<num;i++){
            cin>>type;
            if(type==1){
                cin>>proizvoditel>>verzija>>godina>>cena>>brzina;
                drones[i]=new RacingDrone(proizvoditel, verzija,godina,cena,brzina);
            }
            else{
                cin>>proizvoditel>>verzija>>godina>>cena>>resolution>>fps;
		        drones[i]=new VideographyDrone(proizvoditel, verzija,godina,cena,resolution,fps);
            }
        }
        bestDrone(drones,num);
    }
    return 0;
}
