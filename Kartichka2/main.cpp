

/*Картичка Problem 2 (1 / 1)
Дадена е дел од дефиницијата на класата Karticka. За секоја картичка се чуваат информации за трансакциска сметка (низа од 15 знаци) , пин код (цел број) и дали има повеќе пин кодови (булова променлива).

За секој картичка може да се пресмета тежината за пробивање на картичката. Тежината на пробивање е бројот на цифрите на пин кодот.

Специјалните картички покрај еден задолжителен имаат уште неколку пин кодови . За овие корисници да се моделира соодветна класа SpecijalnaKaricka во која покрај дополнителните пин кодови (динамичко алоцирана низа од цели броеви) се чува и бројот на пин кодовите (цел број). Со дополнителните пин кодови се менува и тежината на пробивање на картичката и таа се зголемува за бројот на дополнителни пин кодови.

Максималниот број на дополнителни пин кодови кој може да има било која картичка е P. P има фиксна вредност 4 за сите картички и оваа вредност не може да се промени.

Во класите Karticka и SpecijalnaKarticka треба да се имплементираат потребните конструктори, функции за поставување и преземање и деструктор. (5 поени)

За сите објекти од класите треба да се обезбедат следните функции:

преоптоварен оператор << во кој се печатат информации за картичката во формат: smetka: tezina (5 поени)
tezinaProbivanje() – ја пресметува тежината за пробивање на картичката (5 поени)
Во класата SpecijalnaKarticka дефинирај ја функцијата:

преоптоварен оператор += за додавање на нов пин код (5 поени)
Ако се направи обид да се внесат повеќе од дозволениот број на пин кодови во безбедносниот код да се фрли исклучок (објект од класата OutOfBoundException). Фатете го исклучокот во главната функција каде што е потребно. Откако ќе го фатите отпечатете соодветна порака за грешка (_Brojot na pin kodovi ne moze da go nadmine dozvolenoto_) и справете се со исклучокот така да додадениот пин код не се зема предвид (10 поени)

Дадена е дел од дефиницијата на класата Banka во која се чуваат информаци за името на банката (низа од 30 знаци) и за картичките издадени од банката (низа од 20 покажувачи кон класата Karticka) како и бројот на такви картички.

Велиме дека картичката издадена од банката може да се пробие ако тежината за пробивање е најмногуLIMIT. Вредноста LIMIT е членка на класата Banka, има почетна вредност 7 и истата може да се промени со функцијата setLimit(). За сите банки оваа вредност е иста. (5 поени)

Во класата Banka имплементирај ги функциите:

функција pecatiKarticki() во која се печатат сите картички кои можат да се пробијат, секој во посебен ред. Претходно во првиот ред се печати: _Vo bankata XXXXX moze da se probijat kartickite:_ (5 поени).

функција dodadiDopolnitelenPin(char * smetka, int novPin) во која на картичката со дадена трансакциона сметка се додава нов дополнителен пин код. Ако тоа не е можно функцијата не прави ништо (15 поени).

Комплетна функционалност (5 поени) */

#include<iostream>
#include<cstring>

using namespace std;

class Karticka {
protected:
    char transakciskasmetka[16];
    int pinkod;
    bool pins;
    const int dopolnitelnipinkodovi = 4;
public:
    Karticka() = default;

    Karticka(char *transakciskasmetka, int pinkod) {
        strcpy(this->transakciskasmetka, transakciskasmetka);
        this->pinkod = pinkod;
        this->pins = false;
    }

    ~Karticka() = default;

    Karticka(const Karticka &K) {
        strcpy(transakciskasmetka, K.transakciskasmetka);
        pinkod = K.pinkod;
        pins = K.pinkod;
    }

    friend ostream &operator<<(ostream &out, const Karticka &object) {
        out << object.transakciskasmetka << ": " << object.tezhinaprobivanje();
        return out;
    }

    Karticka &operator=(const Karticka &K) {
        if (this != &K) {
            strcpy(transakciskasmetka, K.transakciskasmetka);
            pinkod = K.pinkod;
            pins = K.pins;
        }
        return *this;
    }

    virtual int tezhinaprobivanje() const {
        int temp = pinkod;
        int broj = 0;
        while (temp != 0) {
            temp = temp / 10;
            broj++;
        }
        return broj;
    }

    const char *getTransakciskasmetka() const {
        return transakciskasmetka;
    }

    bool isPins() const {
        return pins;
    }
};

class OutOfBoundException {
private:
    char *msg;
public:
    OutOfBoundException(const char *msg = "") {
        this->msg = new char[strlen(msg) + 1];
        strcpy(this->msg, msg);
    }

    ~OutOfBoundException() {
        delete[] msg;
    }

    void print() {
        cout << msg;
    }
};

class SpecijalnaKarticka : public Karticka {
private:
    int *niza;
    int br;
public:
    SpecijalnaKarticka() = default;

    SpecijalnaKarticka(char *transakciskasmetka, int pinkod) : Karticka(
            transakciskasmetka, pinkod) {
        this->br = 0;
        this->niza = new int[br];
        this->pins = true;
        for (int i = 0; i < this->br; i++) {
            this->niza[i] = niza[i];
        }
    }

    ~SpecijalnaKarticka() {
        delete[]niza;
    }

    SpecijalnaKarticka(const SpecijalnaKarticka &copy) : Karticka(copy) {
        br = copy.br;
        niza = new int[br];
        for (int i = 0; i < br; i++) {
            niza[i] = copy.niza[i];
        }
    }

    SpecijalnaKarticka &operator=(const SpecijalnaKarticka &op) {
        if (this != &op) {
            br = op.br;
            niza = new int[br];
            for (int i = 0; i < br; i++) {
                niza[i] = op.niza[i];
            }
        }
        return *this;
    }

    int tezhinaprobivanje() const {
        return Karticka::tezhinaprobivanje() + br;
    }

    SpecijalnaKarticka &operator+=(int nov) {
        if (!(br < dopolnitelnipinkodovi))
            throw OutOfBoundException("_Brojot na pin kodovi ne moze da go nadmine dozvolenoto_");
        else {
            int *temp = new int[br + 1];
            for (int i = 0; i < br; i++) {
                temp[i] = niza[i];
            }
            temp[br++] = nov;
            delete[] niza;
            niza = temp;
            return *this;
        }
    }
};

class Banka {
private:
    char naziv[30];
    Karticka *karticki[20];
    int broj;
    static int LIMIT;
public:
    Banka(char *naziv, Karticka **karticki, int broj) {
        strcpy(this->naziv, naziv);
        for (int i = 0; i < broj; i++) {
            if (karticki[i]->isPins()) {
                this->karticki[i] = new SpecijalnaKarticka(*dynamic_cast<SpecijalnaKarticka *>(karticki[i]));
            } else
                this->karticki[i] = new Karticka(*karticki[i]);
        }
        this->broj = broj;
    }

    ~Banka() {
        for (int i = 0; i < broj; i++) {
            delete karticki[i];
        }
    }

    static void setLIMIT(int a) {
        LIMIT = a;
    }

    void pecatiKarticki() {
        cout << "Vo bankata " << naziv << " mozhe da se probijat kartichkite:" << endl;
        for (int i = 0; i < broj; i++) {
            if (karticki[i]->tezhinaprobivanje() <= LIMIT)
                cout << *karticki[i] << endl;
        }
    }

    void dodadiDopolnitelenPin(char *smetka, int novpin) {
        for (int i = 0; i < broj; i++) {
            SpecijalnaKarticka *temp = dynamic_cast<SpecijalnaKarticka *>(karticki[i]);
            if (temp) {
                if (strcmp(temp->getTransakciskasmetka(), smetka) == 0) {
                    *temp += novpin;
                }
            }
        }
    }
};

int Banka::LIMIT = 7;

int main() {

    Karticka **niza;
    int n, m, pin;
    char smetka[16];
    bool daliDopolnitelniPin;
    cin >> n;
    niza = new Karticka *[n];
    for (int i = 0; i < n; i++) {
        cin >> smetka;
        cin >> pin;
        cin >> daliDopolnitelniPin;
        if (!daliDopolnitelniPin)
            niza[i] = new Karticka(smetka, pin);
        else
            niza[i] = new SpecijalnaKarticka(smetka, pin);
    }

    Banka komercijalna("Komercijalna", niza, n);
    for (int i = 0; i < n; i++) delete niza[i];
    delete[] niza;
    cin >> m;
    for (int i = 0; i < m; i++) {

        try {
            cin >> smetka >> pin;
            komercijalna.dodadiDopolnitelenPin(smetka, pin);
        }
        catch (OutOfBoundException &object) {
            object.print();
            cout << endl;
        }


    }

    Banka::setLIMIT(5);

    komercijalna.pecatiKarticki();

}