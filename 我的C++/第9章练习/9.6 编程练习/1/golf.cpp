#include"golf.h"
#include<cstring>
#include<iostream>

void setgolf(golf& g, const char* name, int hc)
{
    g.handicap = hc;
    strcpy_s(g.fullname, Len, name);
}

void handicap(golf& g, int hc)
{
    g.handicap = hc;
}

void showgolf(const golf& g)
{
    using std::cout;
    using std::endl;

    cout << "Name: " << g.fullname << endl;
    cout << "Handicap: " << g.handicap << endl;
}

int setgolf(golf& g)
{
    using std::cin;
    using std::cout;
    using std::endl;

    char next;
    char flag;
    cout << "Enter a name:(empty line to quit)\n";
    cin.get(g.fullname, Len).get(next);
    while (cin)
    {
        while (next != '\n')
            cin.get();
        cout << "Enter a value for handicap: ";
        cin >> g.handicap;
        flag=cin.get();
        while (!cin)
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Please input a integer like 12,56\n";
            cin >> g.handicap;
            flag=cin.get();
        }
            return 1;
    }
    return 0;
}