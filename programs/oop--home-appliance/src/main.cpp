#include<iostream>
#include<string.h>
using namespace std;

class HomeAppliance{
protected:
    char proizvoditel[70];
    char klasa[5];
    int kapacitet;
    double osnovnacena;
public:
    HomeAppliance(char *proizvoditel, char *klasa, int kapacitet, double osnovnacena){
        strcpy(this->proizvoditel,proizvoditel);
        strcpy(this->klasa,klasa);
        this->kapacitet=kapacitet;
        this->osnovnacena=osnovnacena;
    }
    HomeAppliance(const HomeAppliance &a){
        strcpy(this->proizvoditel,a.proizvoditel);
        strcpy(this->klasa,a.klasa);
        this->kapacitet=a.kapacitet;
        this->osnovnacena=a.osnovnacena;
    }
    HomeAppliance &operator=(const HomeAppliance &a){
        if(this!=&a){
            strcpy(this->proizvoditel,a.proizvoditel);
            strcpy(this->klasa,a.klasa);
            this->kapacitet=a.kapacitet;
            this->osnovnacena=a.osnovnacena;
        }
        return *this;
    }
    ~HomeAppliance(){}
    virtual double prodazhnaCena()=0;
    friend bool operator > (const HomeAppliance &a, const HomeAppliance &b){
        if(a.prodazhnaCena()>b.prodazhnaCena){
            return true;
        } else
        return false;
    }
};
class Dishwasher : public HomeAppliance{
private:
    int programi;
public:
    Dishwasher(char *proizvoditel, char *klasa, int kapacitet, double osnovnacena, int programi): HomeAppliance(proizvoditel,klasa,kapacitet,osnovnacena){
        this->programi=programi;
    }
    Dishwasher(const Dishwasher &a): HomeAppliance(a){
        this->programi=programi;
    }
    Dishwasher &operator = (const Dishwasher &a){
        if(this!=&a){
            strcpy(this->proizvoditel,proizvoditel);
            strcpy(this->klasa,klasa);
            this->kapacitet=kapacitet;
            this->osnovnacena=osnovnacena;
            this->programi=programi;
        }
        return *this;
    }
    ~Dishwasher(){}
    double prodazhnaCena(){
        double prodazhnaCena=osnovnacena;
        if(strcmp(*klasa,"A++")||strcmp(*klasa,"A+++")){
            prodazhnaCena=prodazhnaCena+(prodazhnaCena*0.10);
        }
        if(programi>4){
            prodazhnaCena=prodazhnaCena+(prodazhnaCena*0.15);
        }
        return prodazhnaCena;
    }
    friend ostream &operator<<(ostream &o, const Dishwasher &d){
        o<<d.proizvoditel<<", "<<d.klasa<<", "<<d.kapacitet<<", "<<d.programi<<", "<<d.prodazhnaCena();
        return o;
    }
};
class WashingMachine : public HomeAppliance{
private:
    int vrtezhi;
public:
    WashingMachine(char *proizvoditel, char *klasa, int kapacitet, double osnovnacena, int vrtezhi): HomeAppliance(proizvoditel,klasa,kapacitet,osnovnacena){
        this->vrtezhi=vrtezhi;
    }
    WashingMachine(const WashingMachine &a): HomeAppliance(a){
        this->vrtezhi=vrtezhi;
    }
    WashingMachine &operator = (const WashingMachine &a){
        if(this!=&a){
            strcpy(this->proizvoditel,proizvoditel);
            strcpy(this->klasa,klasa);
            this->kapacitet=kapacitet;
            this->osnovnacena=osnovnacena;
            this->vrtezhi=vrtezhi;
        }
        return *this;
    }
    ~WashingMachine(){}
    double prodazhnaCena(){
        double prodazhnaCena=osnovnacena;
        if(strcmp(*klasa,'A++')||strcmp(*klasa,'A+++')){
            prodazhnaCena=prodazhnaCena+(prodazhnaCena*0.15);
        }
        if(vrtezhi>800){
            prodazhnaCena=prodazhnaCena+(prodazhnaCena*0.20);
        }
        return prodazhnaCena;
    }
    friend ostream &operator<<(ostream &o, const WashingMachine &w){
        o<<w.proizvoditel<<", "<<w.klasa<<", "<<w.kapacitet<<", "<<w.vrtezhi<<", "<<w.prodazhnaCena();
        return o;
    }
};

int main(){
  int test;
  cin >> test;
  if(test == 1){
      cout << "Testing classes" << endl;
      int p_type;
      char model[70];
      char energyClass[5];
      int capacity;
      double basic_price;
      int progCount;
      int spinSpeed;

      HomeAppliance *cc;

      cin>>p_type;

      //cin >> model ;
      cin.get();
      cin.getline(model, 70);
      cin >> energyClass >> capacity >> basic_price;

      if (p_type==1){
        cin >> progCount;
        cc = new Dishwasher(model, energyClass, capacity, basic_price, progCount);
        cout << *(dynamic_cast<Dishwasher*>(cc));
        }
      else if (p_type ==2){
          cin >> spinSpeed;
          cc = new WashingMachine(model, energyClass, capacity, basic_price, spinSpeed);
          cout << *(dynamic_cast<WashingMachine*>(cc));
    }
  }

  else if(test == 2){
    cout << "Testing operator > and price" << endl;
      int p_type;
      char model[70];
      char energyClass[5];
      int capacity;
      double basic_price;
      int progCount;
      int spinSpeed;

      HomeAppliance *cc1, *cc2 ;

      cin>>p_type;
      cin.get();
      cin.getline(model, 70);
      cin >> energyClass >> capacity >> basic_price;

      if (p_type==1){
          cin >> progCount;
          cc1 = new Dishwasher(model, energyClass, capacity, basic_price, progCount);

      }
      else if (p_type ==2){
          cin >> spinSpeed;
          cc1 = new WashingMachine(model, energyClass, capacity, basic_price, spinSpeed);
      }

      cin>>p_type;

      cin.get();
      cin.getline(model, 70);
      cin >> energyClass >> capacity >> basic_price;

      if (p_type==1){
          cin >> progCount;
          cc2 = new Dishwasher(model, energyClass, capacity, basic_price, progCount);

      }
      else if (p_type ==2){
          cin >> spinSpeed;
          cc2 = new WashingMachine(model, energyClass, capacity, basic_price, spinSpeed);
      }

    if (*cc1 > *cc2){
      Dishwasher* tc;
      WashingMachine *mc;

      tc = dynamic_cast<Dishwasher*>(cc1);
      mc = dynamic_cast<WashingMachine*>(cc1);

      cout<< "More expensive product is:" << endl;
      if (tc){
        cout << *tc;
      }
      if (mc){
        cout << *mc;
      }
    } else {
      Dishwasher* tc;
      WashingMachine *mc;

      tc = dynamic_cast<Dishwasher*>(cc2);
      mc = dynamic_cast<WashingMachine*>(cc2);

      cout<< "More expensive product is:"<<endl;
      if (tc){
        cout << *tc;
      }
      if (mc){
        cout << *mc;
      }
    }

  }
  else if(test == 3){

      int p_type;
      char model[70];
      char energyClass[5];
      int capacity;
      double basic_price;
      int progCount;
      int spinSpeed;

    cout << "Testing method mostExpensive()" << endl;
    int n;
    cin >> n;
    HomeAppliance **ha = new HomeAppliance*[n];
    for(int i = 0; i < n; i++){
      cin>>p_type;

        cin.get();
        cin.getline(model, 70);
        cin >> energyClass >> capacity >> basic_price;

        if (p_type==1){
            cin >> progCount;
            ha[i] = new Dishwasher(model, energyClass, capacity, basic_price, progCount);

        }
        else if (p_type ==2){
            cin >> spinSpeed;
            ha[i] = new WashingMachine(model, energyClass, capacity, basic_price, spinSpeed);
        }
    }
      mostExpensive(ha, n);
  }
    return 0;
}
