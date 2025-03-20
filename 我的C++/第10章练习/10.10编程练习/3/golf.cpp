#include<cstring>
#include<iostream>
#include"golf.h"


Golf::Golf(const char* name, int hc)
{
    strcpy_s(fullname, Len, name);
    m_handicap = hc;
}

Golf::Golf()
{
    using std::cin;
    using std::cout;
    using std::endl;

    char next;
    char flag;
    
    cout << "Enter a name:(empty line to quit)\n";
    cin.get(fullname, Len).get(next);
    if (cin)
    {
        while (next != '\n')
            cin.get();
        cout << "Enter a value for handicap: ";
        cin >> m_handicap;
        flag = cin.get();
        while (!cin)
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Please input a integer like 12,56\n";
            cout << "Enter a value for handicap: ";
            cin >> m_handicap;
            flag = cin.get();
        }
    }
}

Golf::~Golf()
{}

void Golf::handicap(int hc)
{
    m_handicap = hc;
}

void Golf::showgolf() const
{
    using std::cout;
    using std::endl;

    cout << "Name: " << fullname << endl;
    cout << "Handicap: " << m_handicap << endl;
}

