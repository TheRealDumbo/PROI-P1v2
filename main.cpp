#include <iostream>
#include <ostream>
#include <string>
#include <cstdio>
#include "hist.h"
#include "menu.h"

using namespace std;

int main()
{
    string txt11, txt22;
    cout<<"Prosze wpisac tekst nr 1"<<endl;
    getline(cin, txt11);
    cout<<"Prosze wpisac tekst nr 2"<<endl;
    getline(cin, txt22);
    hist txt1(txt11);
    hist txt2(txt22);
    menu(txt1, txt2);
}
// Piotr Dabrowski, funkcja main
