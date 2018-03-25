#include "hist.h"
#include <string>
#include <iostream>
#include <cstdio>
#include <ostream>
// objasnienia do czego sluza poszczegolne metody, znajduja sie w pliku hist.h
int hist::filosc(std::string tekst, char cyfra)
{
    int ilosc=0;
    int j=tekst.size();
    for (int i=0; i<j; i++) // przesuwa sie po tekscie w poszukiwaniu cyfry
    {
        if (tekst[i]==cyfra)
        {
            ilosc++;
        }
    }
    return ilosc;
}
double hist::fczestotliwosc(std::string tekst, int ilosc) // liczy 1 na ile razy dana cyfra wystapila w tekscie
{
    int o=tekst.size();
    double frq=(double(o))/(double(ilosc));
    return frq;
}
hist::hist(std::string txt)
{
    int j;
    iloscall=0;
    tekst=txt;
    for(int i=0; i<10; i++) // wypelnienie pol klasy
    {
        j=i+48; // zamiana liczby na jej wartosc w tablicy ASCII
        ilosc[i]=filosc(tekst, j);
        czestotliwosc[i]=fczestotliwosc(tekst, ilosc[i]); // wystapienia 1 na wartosc funkcji
        iloscall+=ilosc[i];
    }
    czestotliwoscall=fczestotliwosc(tekst, iloscall);
}
void hist::dopisanie(std::string txt)
{
    tekst+=txt;
    int j;
    for(int i=0; i<10; i++) // ten sam proces co wyzej, aktualizacja statystyk
    {
        j=i+48;
        ilosc[i]=filosc(tekst, j);
        czestotliwosc[i]=fczestotliwosc(tekst, ilosc[i]);
        iloscall+=ilosc[i];
    }
    czestotliwoscall=fczestotliwosc(tekst, iloscall);
}
void hist::wyswietlstatystykicyfry(int cyfra) // wyswietlanie statystyki pojedynczej cyfry
{
    std::cout<<"Liczba "<<cyfra<<" wystapila w tekscie "<<ilosc[cyfra]<<" raz(y), z czestotliwoscia srednio 1 na "<<czestotliwosc[cyfra]<<" znak(u/i/ow)."<<std::endl;
}
hist operator+(hist a, hist b)
{
    a.tekst+=b.tekst;
    for(int i=0; i<10; i++)
    {
        a.ilosc[i]+=b.ilosc[i];
        a.czestotliwosc[i]=a.fczestotliwosc(a.tekst, a.ilosc[i]);
    }
    a.iloscall+=b.iloscall;
    a.czestotliwoscall=a.fczestotliwosc(a.tekst, a.iloscall);
    return a;
}
hist hist::operator+=(hist b)
{
    tekst+=b.tekst;
    for(int i=0; i<10; i++)
    {
        ilosc[i]+=b.ilosc[i];
        czestotliwosc[i]=b.fczestotliwosc(tekst, ilosc[i]);
    }
    iloscall+=b.iloscall;
    czestotliwoscall=fczestotliwosc(tekst, iloscall);
    return *this;
}
std::ostream &    operator<<(std::ostream & a, hist &b)
{
    a<<"Aktualna tresc tekstu:"<<std::endl<<std::endl<<b.tekst<<std::endl<<std::endl;
    if(b.iloscall!=0)
    {
        a<<"Wszystkie liczby wystapily w tekscie, lacznie "<<b.iloscall<<" raz(y), z czestotliwoscia srednio 1 na "<<b.czestotliwoscall<<" znak(u/i/ow)."<<std::endl;
    }
    else // jesli w tekscie nie ma zadnej liczby, nie ma sensu wypisywanie szczegolowych statystyk
    {
        a<<"W tekscie nie pojawila sie zadna liczba."<<std::endl;
        return a;
    }
    for(int i=0; i<10; i++)
    {
        if(b.ilosc[i]!=0)
        {
            a<<"Liczba "<<i<<" wystapila w tekscie "<<b.ilosc[i]<<" raz(y), z czestotliwoscia srednio 1 na "<<b.czestotliwosc[i]<<" znak(u/i/ow)."<<std::endl;
        }
        else
        {
            a<<"Liczba "<<i<<" nie pojawila sie w tekscie."<<std::endl; // zeby uniknac sformulowania "1 na inf"
        }
    }
    return a;
}
bool operator==(hist a, hist b) // przeladowanie operatora == do porownywania histogramow
{
    for(int i=0; i<10; i++)
    {
        if(a.ilosc[i]!=b.ilosc[i])
        {
            return false;
        }
    }
    return true;
}
bool operator!=(hist a, hist b) // przeladowanie operatora != do porownywania histogramow
{
    for(int i=0; i<10; i++)
    {
        if(a.ilosc[i]!=b.ilosc[i])
        {
            return true;
        }
    }
    return false;
}

// Piotr Dabrowski, source klasy histogramu i przeladowan operatorow
