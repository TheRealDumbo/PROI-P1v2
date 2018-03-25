#include <iostream>
#include <ostream>
#include <string>
#include <cstdio>
#include "hist.h"
#include "menu.h"
// wszystkie metody i przeladowane operatory uzywane w funkcji menu sa opisane w plikach hist.h oraz hist.cpp
using namespace std;

int menu(hist a, hist b)
{
    string txt; // zmienna do dopisywania
    int ci=0; // zmienna do konwersji char na int
    char cd; // zmienna uzywana do nawigacji po menu
    while(1)
    {
        cout<<"Aby porownac histogramy, wczytaj 'p'"<<endl<<"Aby polaczyc histogramy, wczytaj 'm'"<<endl<<"Aby przejsc do opcji zwiazanych z tekstem 1., wczytaj 'd'"<<endl<<"Aby zakonczyc prace programu, wczytaj 'e'"<<endl;
        while(1)
        {
            cin>>cd;
            getchar();
            if(cd=='p')
            {
                cout<<"Wybierz sposob porownania:"<<endl<<"1 - =="<<endl<<"2 - !="<<endl;
                cin>>cd;
                getchar();
                if(cd=='1')
                    if(a==b)
                    {
                        cout<<"Histogramy sa jednakowe."<<endl;
                    }
                    else
                    {
                        cout<<"Histogramy sie roznia."<<endl;
                    }
                if(cd=='2')
                {
                    if(a!=b)
                    {
                        cout<<"Histogramy sie roznia."<<endl;
                    }
                    if(a==b)
                    {
                        cout<<"Histogramy sa jednakowe."<<endl;
                    }
                }
            }
            if(cd=='m')
            {
                cout<<"Wybierz sposob polaczenia:"<<endl<<"1 - +"<<endl<<"2 - +="<<endl;
                cin>>cd;
                getchar();
                if(cd=='1')
                {
                    a=a+b; // operator +
                }
                if(cd=='2')
                {
                    a+=b; // operator +=
                }
                cout<<"Jestes w polaczonym tekscie."<<endl<<"Aby sprawdzic statystyki konkretnej cyfry, wczytaj ta cyfre"<<endl<<"Aby sprawdzic histogram, wczytaj 'h'"<<endl<<"Aby kontynuowac wpisywanie tekstu, wczytaj 'k'"<<endl<<"Aby zakonczyc prace programu, wczytaj 'e'"<<endl;
                while(1)
                {
                    cin>>cd;
                    getchar();
                    if(cd=='h')
                    {
                        cout<<a;
                    }
                    if(cd=='k')
                    {
                        cout<<"Prosze wpisac tresc kontynuacji tekstu:"<<endl;
                        getline(cin, txt);
                        a.dopisanie(txt);
                    }
                    if(cd>47 && cd<58)
                    {
                        ci=cd-48;
                        a.wyswietlstatystykicyfry(ci);
                    }
                    if(cd=='e')
                    {
                        return 0;
                    }
                }

            }
            if(cd=='d')
            {
                break;
            }
            if(cd=='e')
            {
                return 0;
            }
        }
        cout<<"Jestes w tekscie nr 1."<<endl<<"Aby sprawdzic statystyki konkretnej cyfry, wczytaj ta cyfre"<<endl<<"Aby sprawdzic histogram, wczytaj 'h'"<<endl<<"Aby kontynuowac wpisywanie tekstu, wczytaj 'k'"<<endl<<"Aby przejsc do tekstu 2., wczytaj 'd'"<<endl;
        while(1)
        {
            cin>>cd;
            getchar();
            if(cd=='h')
            {
                cout<<a;
            }
            if(cd=='k')
            {
                cout<<"Prosze wpisac tresc kontynuacji tekstu:"<<endl;
                getline(cin, txt);
                a.dopisanie(txt);
            }
            if(cd>47 && cd<58)
            {
                ci=cd-48;
                a.wyswietlstatystykicyfry(ci);
            }
            if(cd=='d')
            {
                break;
            }
        }
        cout<<"Jestes w tekscie nr 2."<<endl<<"Aby sprawdzic statystyki konkretnej cyfry, wczytaj ta cyfre"<<endl<<"Aby sprawdzic histogram, wczytaj 'h'"<<endl<<"Aby kontynuowac wpisywanie tekstu, wczytaj 'k'"<<endl<<"Aby przejsc do opcji ogolnych, wczytaj 'd'"<<endl;
        while(1)
        {
            cin>>cd;
            getchar();
            if(cd=='h')
            {
                cout<<b;
            }
            if(cd=='k')
            {
                cout<<"Prosze wpisac tresc kontynuacji tekstu:"<<endl;
                getline(cin, txt);
                b.dopisanie(txt);
            }
            if(cd>47 && cd<58)
            {
                ci=cd-48;
                b.wyswietlstatystykicyfry(ci);
            }
            if(cd=='d')
            {
                break;
            }
        }
    }
    return 0;
}
