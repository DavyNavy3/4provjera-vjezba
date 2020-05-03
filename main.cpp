#include <iostream>
#include<math.h>
#include<algorithm>
#include<utility>
#include<numeric>
#include<string>
using namespace std;

bool negativan(double broj)
{
    if(broj<0)
    {
        return true;
    }
    return false;
}

bool tekuci(unsigned long long broj)
{
    if(broj/10000000 == 32)
    {
        return true;
    }
    return false;
}

bool pretraga_klijenta(int broj_klijenata, unsigned long long int polje_br_racuna[], string polje_prezime_ime[], double saldo[], string pretraga)
{
    int j = 0;
    for(int i=0; i<broj_klijenata; i++)
    {
        if(polje_prezime_ime[i] == pretraga)
        {
            cout << endl << "========================= TRAZENI RACUN =========================" << endl;
            cout << "Broj racuna: " << polje_br_racuna[i] << endl << "Iznos: " << saldo[i]<< " HRK" << endl;
            cout << "=================================================================" << endl;
            j++;
        }
    }
    if(j==0)
    {
        return false;
    }
    return true;
}

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
            double suma;
            int broj_negativnih, broj_tekucih;
            string najveci;
            cout << endl << "============================= PODACI =============================" << endl;
            for(int i=0; i<broj_klijenata; i++)
            {
                cout << polje_br_racuna[i] << ", " << polje_prezime_ime[i] << ", " << saldo[i] << " HRK" << endl;
            }
            suma = accumulate(saldo, saldo+broj_klijenata, 0.0);
            int max_indeks = max_element(saldo, saldo+broj_klijenata)-saldo;
            najveci = polje_prezime_ime[max_indeks];
            broj_negativnih = count_if(saldo, saldo+broj_klijenata, negativan);
            broj_tekucih = count_if(polje_br_racuna, polje_br_racuna+broj_klijenata, tekuci);
            cout << endl << "UKUPNO: " << suma << " HRK | NAJVECI: " << najveci << " | BR NEGATIVNIH: " << broj_negativnih << " | BR TEKUCIH: " << broj_tekucih << endl;
            cout << "==================================================================" << endl << endl;
        }
        else if(odabir==3)
        {
            cout << "Unesite ime i prezime koje pretrazujete: ";
            string pretraga;
            cin.ignore();
            getline(cin, pretraga);
            if(pretraga_klijenta(broj_klijenata, polje_br_racuna, polje_prezime_ime, saldo, pretraga)==false)
            {
                cout << "GRESKA: Takvih racuna nema." << endl;
            }
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
            cout << "Zatvaranje programa..." << endl;
            break;
        }
        else
        {
            cout << "GRESKA: Krivi unos." << endl;
        }
    }
    return 0;
}
