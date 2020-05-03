#include <iostream>
#include<math.h>
#include<algorithm>
#include<utility>
#include<numeric>
#include<string>
using namespace std;

int main()
{
    int odabir, broj_klijenata = 0;
    unsigned long long int *polje_br_racuna = new unsigned long long int[1000];
    string *polje_prezime_ime = new string[1000];
    double *saldo = new double[1000];
    while(1)
    {
        cout << endl << "======================== GLAVNI IZBORNIK ========================" << endl;
        cout << "Unesite 1 za unos novog racuna." << endl;
        cout << "Unesite 2 za ispis svih podataka." << endl;
        cout << "Unesite 3 za pretragu prema prezimenu i imenu." << endl;
        cout << "Unesite 4 za brisanje racuna." << endl;
        cout << "Unesite 5 za izmjenu podataka prema broju racuna." << endl;
        cout << "Unesite 6 za ispis sortirano prema prezimenu i imenu." << endl;
        cout << "Unesite 7 za izlaz iz programa." << endl;
        cout << "=================================================================" << endl;
        cout << "Unos: ";
        cin >> odabir;
        if(odabir==1)
        {
            unsigned long long int unos;
            while(1)
            {
                try
                {
                    cout << "Unesite broj racuna: ";
                    cin >> unos;
                    if(unos<1000000000 || unos>9999999999)
                    {
                        throw "GRESKA: Broj racuna mora imati deset znamenki.";
                    }
                    if(find(polje_br_racuna, polje_br_racuna+broj_klijenata, unos)!=(polje_br_racuna+broj_klijenata))
                    {
                        throw "GRESKA: Broj racuna mora biti jedinstven.";
                    }
                    break;
                }
                catch(const char *msg)
                {
                    cout << msg << endl;
                }
            }
            polje_br_racuna[broj_klijenata] = unos;
            cin.ignore();
            cout << "Unesite prezime i ime: ";
            getline(cin, polje_prezime_ime[broj_klijenata]);
            cout << "Unesite saldo: ";
            cin >> saldo[broj_klijenata];
            broj_klijenata++;
        }
        else if(odabir==2)
        {
        }
        else if(odabir==3)
        {
        }
        else if(odabir==4)
        {
        }
        else if(odabir==5)
        {
        }
        else if(odabir==6)
        {
        }
        else if(odabir==7)
        {
        }
        else
        {
            cout << "GRESKA: Krivi unos." << endl;
        }
    }
    return 0;
}
