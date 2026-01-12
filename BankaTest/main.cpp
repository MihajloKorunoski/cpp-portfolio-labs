//.h file code:

#include <string>
#include <vector>
#include <iostream>
#include <type_traits>
#include "rectangularvectors.h"
#include "closeable_interface.h"

//JAVA TO C++ CONVERTER NOTE: Forward class declarations:
namespace tangible { template<typename T>class RefObject; }

class Banka : public Closeable
{
private:
    std::wstring imenabanka;
    std::wstring adresanabanka;
    static double kamatnastapka;
public:
    Banka();

    Banka(const std::wstring &imenabanka, const std::wstring &adresanabanka);

    virtual void close();

    void postavibanka(const std::wstring &imenabanka, const std::wstring &adresanabanka);

    void zemibanka(tangible::RefObject<std::wstring> *imenabanka, tangible::RefObject<std::wstring> *adresanabanka);

    static void postavikamatnastapka(double kstapka);

    double zemikamatnastapka();

    void prikazhibanka();
};


class Smetka : public Banka
{
private:
    long long smetkabroj = 0;
    double saldo = 0;
public:
    Smetka();

    Smetka(long long smetkabroj, double saldo);

    void postavismetka(long long smetkabroj, double saldo);

    void zemismetka(tangible::RefObject<long long> *smetkabroj, tangible::RefObject<double> *saldo);

    double zemikamata();

    void prikazhismetka();
};

class Klient : public Banka
{
private:
    int brojcifri(long long broj);

    std::wstring imeiprezime;
    std::wstring adresa;
    long long embg = 0;
    int brojnasmetki = 0;
    std::vector<Smetka*> poknasmetki;
public:
    Klient();

    Klient(const std::wstring &imeiprezime, const std::wstring &adresa, long long embg, int brojnasmetki, Smetka *poknasmetki);

    Klient(const std::wstring &imeiprezime, const std::wstring &adresa, long long embg, int brojnasmetki, Smetka *poknasmetki, const std::wstring &imenabanka, const std::wstring &adresanabanka);

    void postaviklient(const std::wstring &imeiprezime, const std::wstring &adresa, long long embg, int brojnasmetki, std::vector<Smetka*> &poknasmetki);

    void zemiklient(tangible::RefObject<std::wstring> *imeiprezime, tangible::RefObject<std::wstring> *adresa, tangible::RefObject<long long> *embg, tangible::RefObject<int> *brojnasmetki, std::vector<Smetka*> &poknasmetki);

    void postavismetki(std::vector<Smetka*> &poknasmetki);

    void prikazhiklient();
};

namespace <missing>
{

class GlobalMembers
{
public:
    static void main(std::vector<std::wstring> &args);
};

//Helper class added by C++ to Java Converter:

}
namespace tangible
{

    //----------------------------------------------------------------------------------------
    //	Copyright © 2006 - 2020 Tangible Software Solutions, Inc.
    //	This class can be used by anyone provided that the copyright notice remains intact.
    //
    //	This class provides the ability to initialize and delete array elements.
    //----------------------------------------------------------------------------------------
    class Arrays final
    {
    public:
        static std::vector<Klient*> initializeWithDefaultKlientInstances(int length);

        static std::vector<Smetka*> initializeWithDefaultSmetkaInstances(int length);

        template<typename T>
        static void deleteArray(std::vector<T> &array)
        {
            static_assert(std::is_base_of<java.io.Closeable, T>::value, L"T must inherit from java.io.Closeable");

            for (auto element : array)
            {
                if (element != nullptr)
                {
                    element->close();
                }
            }
        }
    };

    //Helper class added by C++ to Java Converter:

}
namespace tangible
{

    //----------------------------------------------------------------------------------------
    //	Copyright © 2006 - 2020 Tangible Software Solutions, Inc.
    //	This class can be used by anyone provided that the copyright notice remains intact.
    //
    //	This class is used to replicate the ability to pass arguments by reference in Java.
    //----------------------------------------------------------------------------------------
    template<typename T>
    class RefObject final
    {
    public:
        T argValue;
        RefObject(T refArg)
        {
            argValue = refArg;
        }
    };
}

//Helper class added by Java to C++ Converter:

#include <string>
#include <vector>

int main(int argc, char **argv)
{
    std::vector<std::wstring> args(argv + 1, argv + argc);
    <missing>::GlobalMembers::main(args);
}

//Helper class added by Java to C++ Converter:

class Closeable
{
public:
    virtual void close() = 0;
};

//Helper class added by Java to C++ Converter:

//----------------------------------------------------------------------------------------
//	Copyright © 2007 - 2020 Tangible Software Solutions, Inc.
//	This class can be used by anyone provided that the copyright notice remains intact.
//
//	This class includes methods to convert multidimensional arrays to C++ vectors.
//----------------------------------------------------------------------------------------
#include <vector>

class RectangularVectors
{
public:
    static std::vector<std::vector<Smetka*>> RectangularSmetkaVector(int size1, int size2)
    {
        std::vector<std::vector<Smetka*>> newVector(size1);
        for (int vector1 = 0; vector1 < size1; vector1++)
        {
            newVector[vector1] = std::vector<Smetka*>(size2);
        }

        return newVector;
    }
};

//.cpp file code:

#include "snippet.h"

double Banka::kamatnastapka = 3;

Banka::Banka()
{
    imenabanka = L"";
    adresanabanka = L"";
}

Banka::Banka(const std::wstring &imenabanka, const std::wstring &adresanabanka)
{
    postavibanka(imenabanka, adresanabanka);
}

void Banka::close()
{
}

void Banka::postavibanka(const std::wstring &imenabanka, const std::wstring &adresanabanka)
{
    this->imenabanka = imenabanka;
    this->adresanabanka = adresanabanka;
}

void Banka::zemibanka(tangible::RefObject<std::wstring> *imenabanka, tangible::RefObject<std::wstring> *adresanabanka)
{
    imenabanka->argValue = this->imenabanka;
    adresanabanka->argValue = this->adresanabanka;
}

void Banka::postavikamatnastapka(double kstapka)
{
    kamatnastapka = kstapka;
}

double Banka::zemikamatnastapka()
{
    return kamatnastapka;
}

void Banka::prikazhibanka()
{
    printf(L"%-10d", L" Banka: ");
    printf(L"%-20d", imenabanka);
    printf(L"%d", L"\n");
    printf(L"%-10d", L" Adresa: ");
    printf(L"%-15d", adresanabanka);
    printf(L"%d", L"\n");
    printf(L"%-10d", L" Kamatna stapka: ");
    printf(L"%d", kamatnastapka);
    printf(L"%d", L"%");
    printf(L"%d", L"\n");
    printf(L"%d", L"\n");
}

Smetka::Smetka()
{
    smetkabroj = 0;
    saldo = 0;
}

Smetka::Smetka(long long smetkabroj, double saldo)
{
    postavismetka(smetkabroj, saldo);
}

void Smetka::postavismetka(long long smetkabroj, double saldo)
{
    this->smetkabroj = smetkabroj;
    this->saldo = saldo;
}

void Smetka::zemismetka(tangible::RefObject<long long> *smetkabroj, tangible::RefObject<double> *saldo)
{
    smetkabroj->argValue = this->smetkabroj;
    saldo->argValue = this->saldo;
}

double Smetka::zemikamata()
{
    double kamata;
    kamata = saldo * zemikamatnastapka() / 100;
    return kamata;
}

void Smetka::prikazhismetka()
{
    std::wcout << L"Broj ";
    std::wcout << smetkabroj;
    std::wcout << L" Saldo:";
    printf(L"%10d", saldo);
    printf(L"%d", L" denari");
}

int Klient::brojcifri(long long broj)
{
    int n = 0;
    while (broj > 0)
    {
        broj /= 10;
        n++;
    }
    return n;
}

Klient::Klient()
{
    imeiprezime = L"";
    adresa = L"";
    embg = brojnasmetki = 0;
    poknasmetki = std::vector<Smetka*>();
}

Klient::Klient(const std::wstring &imeiprezime, const std::wstring &adresa, long long embg, int brojnasmetki, Smetka *poknasmetki)
{
    postaviklient(imeiprezime, adresa, embg, brojnasmetki, poknasmetki);
}

Klient::Klient(const std::wstring &imeiprezime, const std::wstring &adresa, long long embg, int brojnasmetki, Smetka *poknasmetki, const std::wstring &imenabanka, const std::wstring &adresanabanka) : Banka(imenabanka, adresanabanka)
{
    postaviklient(imeiprezime, adresa, embg, brojnasmetki, poknasmetki);
}

void Klient::postaviklient(const std::wstring &imeiprezime, const std::wstring &adresa, long long embg, int brojnasmetki, std::vector<Smetka*> &poknasmetki)
{
    this->imeiprezime = imeiprezime;
    this->adresa = adresa;
    this->embg = embg;
    this->brojnasmetki = brojnasmetki;
    this->poknasmetki = poknasmetki;
    for (int i = 0; i < brojnasmetki; i++)
    {
//C++ TO JAVA CONVERTER TODO TASK: The following line was determined to be a copy assignment (rather than a reference assignment) - this should be verified and a 'copyFrom' method should be created:
//ORIGINAL LINE: this->poknasmetki[i] = poknasmetki[i];
        this->poknasmetki[i]->copyFrom(poknasmetki[i]);
    }
}

void Klient::zemiklient(tangible::RefObject<std::wstring> *imeiprezime, tangible::RefObject<std::wstring> *adresa, tangible::RefObject<long long> *embg, tangible::RefObject<int> *brojnasmetki, std::vector<Smetka*> &poknasmetki)
{
    imeiprezime->argValue = this->imeiprezime;
    adresa->argValue = this->adresa;
    embg->argValue = this->embg;
    brojnasmetki->argValue = this->brojnasmetki;
    poknasmetki = this->poknasmetki;
    for (int i = 0; i < brojnasmetki->argValue; i++)
    {
//C++ TO JAVA CONVERTER TODO TASK: The following line was determined to be a copy assignment (rather than a reference assignment) - this should be verified and a 'copyFrom' method should be created:
//ORIGINAL LINE: poknasmetki[i] = this->poknasmetki[i];
        poknasmetki[i]->copyFrom(this->poknasmetki[i]);
    }
}

void Klient::postavismetki(std::vector<Smetka*> &poknasmetki)
{
    this->poknasmetki = poknasmetki;
    for (int i = 0; i < brojnasmetki; i++)
    {
//C++ TO JAVA CONVERTER TODO TASK: The following line was determined to be a copy assignment (rather than a reference assignment) - this should be verified and a 'copyFrom' method should be created:
//ORIGINAL LINE: this->poknasmetki[i] = poknasmetki[i];
        this->poknasmetki[i]->copyFrom(poknasmetki[i]);
    }
}

void Klient::prikazhiklient()
{
    std::wcout << L"\n";
    printf(L"%-24d", imeiprezime);
    printf(L"%-24d", adresa);
    printf(L"%d", L" EMBG: ");
    printf(L"%-14d", embg);
    printf(L"%d", L"Smetki:");
    printf(L"%d", brojnasmetki);
    printf(L"%d", L"\n");
    printf(L"%d", L"------------------------------------------------------------------------------------------------");
    printf(L"%d", L"\n");
    double vkupnakamata = 0;
    for (int smetka = 0; smetka < brojnasmetki; smetka++)
    {
        printf(L"%d", L" Smetka: ");
        printf(L"%d", smetka + 1);
        printf(L"%d", L": ");
        poknasmetki[smetka]->prikazhismetka();
        printf(L"%d", L" Kamata: ");
        printf(L"%12d", poknasmetki[smetka]->zemikamata());
        printf(L"%d", L"\n");
        vkupnakamata += poknasmetki[smetka]->zemikamata();
    }
    printf(L"%d", L"------------------------------------------------------------------------------------------------");
    printf(L"%d", L"\n");
    printf(L"%68d", L"Vkupna kamata: ");
    printf(L"%10d", vkupnakamata);
    printf(L"%d", L"\n");
}
namespace <missing>
{

void GlobalMembers::main(std::vector<std::wstring> &args)
{
    std::wstring vlez;
    std::wstring imenabanka;
    std::wstring adresanabanka;
    std::wcout << L"Vnesete podatoci za bankata";
    std::wcout << L"\n";
    std::wcout << L" Banka: ";
    Scanner tempVar(System::in);
    imenabanka = (&tempVar)->nextLine();
    std::wcout << L" Adresa: ";
    Scanner tempVar2(System::in);
    adresanabanka = (&tempVar2)->nextLine();
    Banka *mojabanka = new Banka(imenabanka, adresanabanka);

    std::vector<Klient*> klienti = tangible::Arrays::initializeWithDefaultKlientInstances(100);
//JAVA TO C++ CONVERTER NOTE: The following call to the 'RectangularVectors' helper class reproduces the rectangular array initialization that is automatic in Java:
//ORIGINAL LINE: Smetka[][] smetki = new Smetka[100][10];
    std::vector<std::vector<Smetka*>> smetki = RectangularVectors::RectangularSmetkaVector(100, 10);
    std::vector<Smetka*> poknasmetki = tangible::Arrays::initializeWithDefaultSmetkaInstances(100);
    for (int i = 0; i < 100; i++)
    {
        poknasmetki[i] = smetki[i];
    }

    int brojnaklienti;
    std::wstring imeiprezime;
    std::wstring adresa;
    long long embg;
    int brojnasmetki;
    long long smetkabroj;
    std::wcout << L"\nBroj na klienti: ";
    Scanner tempVar3(System::in);
    vlez = (&tempVar3)->nextLine();
    brojnaklienti = std::stoi(vlez);
    for (int i = 0; i < brojnaklienti; i++)
    {
        std::wcout << L"\nVnesete podatoci za ";
        std::wcout << i << 1;
        std::wcout << L"-ot klient";
        std::wcout << L"\n";
        std::wcout << L" Ime i prezime: ";
        Scanner tempVar4(System::in);
        imeiprezime = (&tempVar4)->nextLine();
        std::wcout << L" Adresa: ";
        Scanner tempVar5(System::in);
        adresa = (&tempVar5)->nextLine();
        do
        {
            std::wcout << L" EMBG (mora 13 cifri) : ";
            Scanner tempVar6(System::in);
            vlez = (&tempVar6)->nextLine();
            embg = std::stoll(vlez);
        } while (brojcifri(embg) != 13);
        std::wcout << L" Broj na smetki: ";
        Scanner tempVar7(System::in);
        vlez = (&tempVar7)->nextLine();
        brojnasmetki = std::stoi(vlez);
        std::wcout << L"Vnesete gi smetkite: ";
        std::wcout << L"\n";
        double saldo;
        for (int smetka = 0; smetka < brojnasmetki; smetka++)
        {
            std::wcout << L" Smetka ";
            std::wcout << smetka << 1;
            std::wcout << L":";
            do
            {
                std::wcout << L" Broj na smetka(morat 15 cifri) : ";
                Scanner tempVar8(System::in);
                vlez = (&tempVar8)->nextLine();
                smetkabroj = std::stoll(vlez);
            } while (brojcifri(smetkabroj) != 15);
            std::wcout << L" Saldo: ";
            Scanner tempVar9(System::in);
            vlez = (&tempVar9)->nextLine();
            saldo = std::stod(vlez);
            poknasmetki[i][smetka] = {smetkabroj, saldo};
        }
        klienti[i] = new Klient(imeiprezime, adresa, embg, brojnasmetki, poknasmetki[i]);
    }
    system(L"CLS");
    mojabanka->prikazhibanka();
    for (int i = 0; i < brojnaklienti; i++)
    {
        std::wcout << L"\nKlient ";
        std::wcout << i << 1;
        std::wcout << L": ";
        klienti[i]->prikazhiklient();
    }
    std::wcout << L"\n";
    system(L"PAUSE");

    delete mojabanka;
}
}
namespace tangible
{

    std::vector<Klient*> Arrays::initializeWithDefaultKlientInstances(int length)
    {
        std::vector<Klient*> array(length);
        for (int i = 0; i < length; i++)
        {
            array[i] = new Klient();
        }
        return array;
    }

    std::vector<Smetka*> Arrays::initializeWithDefaultSmetkaInstances(int length)
    {
        std::vector<Smetka*> array(length);
        for (int i = 0; i < length; i++)
        {
            array[i] = new Smetka();
        }
        return array;
    }
}
namespace tangible
{
}
